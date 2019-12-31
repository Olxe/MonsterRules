#include "TilesetBuilder.h"

using namespace Builder;

TilesetBuilder::TilesetBuilder()
{
}

TilesetBuilder::~TilesetBuilder()
{
}

std::vector< Tile* > Builder::TilesetBuilder::Build(Parser::TilesetNode* tileset, std::string directory)
{
	std::vector< Tile* > tiles;
	std::string templateDirectory = directory + "Templates/";

	if (tileset->HasChild(Parser::NodeType::IMAGE)) {

		if (Parser::ImageNode* imageNode = dynamic_cast<Parser::ImageNode*>(tileset->GetFirstSpecificChild(Parser::NodeType::IMAGE))) {
			this->createTiles(tileset, templateDirectory, imageNode, tiles);
		}
		for (auto tileset_child_node : tileset->GetChildNodes()) {
			if (Parser::TileNode* tileNode = dynamic_cast<Parser::TileNode*>(tileset_child_node)) {
				this->updateTiles(tileNode, tiles);
			}
		}

	}
	else if (tileset->HasChild(Parser::NodeType::GRID)) {

		for (auto tileset_child_node : tileset->GetChildNodes()) {
			if (Parser::TileNode* tileNode = dynamic_cast<Parser::TileNode*>(tileset_child_node)) {
				if (Parser::ImageNode* imageNode = dynamic_cast<Parser::ImageNode*>(tileNode->GetFirstSpecificChild(Parser::NodeType::IMAGE))) {
					tiles.push_back(new Tile(tileNode->GetId(), tileset->GetFirstgid() + tileNode->GetId(),
						templateDirectory + imageNode->GetSource(), (float)imageNode->GetWidth(), (float)imageNode->GetHeight()));

					this->updateTiles(tileNode, tiles);
				}

			}
		}

	}

	return tiles;
}

void Builder::TilesetBuilder::createTiles(Parser::TilesetNode* tileset, std::string directory, Parser::ImageNode* imageNode, std::vector<Tile*>& tiles)
{
	int tile_width = tileset->GetTilewidth();
	int tile_height = tileset->GetTileheight();
	int image_width = imageNode->GetWidth();
	int image_height = imageNode->GetHeight();

	int columns = image_width / tile_width;
	int rows = image_height / tile_height;
	int id = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			tiles.push_back(new TilesetTile(id, tileset->GetFirstgid() + id, directory + imageNode->GetSource(), (float)tile_width, (float)tile_height, j, i));
			id++;
		}
	}
}

void Builder::TilesetBuilder::updateTiles(Parser::TileNode* tileNode, std::vector<Tile*>& tiles)
{
	int id = tileNode->GetId();

	for (auto tile : tiles) {
		if (tile->GetId() == id) {
			tile->SetType(tileNode->GetType());

			for (auto tile_child_node : tileNode->GetChildNodes()) {
				if (Parser::PropertiesNode* propertiesNode = dynamic_cast<Parser::PropertiesNode*>(tile_child_node))
				{
					tile->SetProperties(propertiesNode);
				}
				else if (Parser::ObjectGroupNode* objectgroup = dynamic_cast<Parser::ObjectGroupNode*>(tile_child_node)) {
					for (auto objectgroup_child_node : objectgroup->GetChildNodes()) {
						if (Parser::ObjectNode* objectNode = dynamic_cast<Parser::ObjectNode*>(objectgroup_child_node)) {
							this->createObject(objectNode, tile);
						}
					}
				}
			}
		}
	}
}

void Builder::TilesetBuilder::createObject(Parser::ObjectNode* objectNode, Tile* tile)
{ 
	ObjectTemplate* obj = nullptr;
	if (Parser::EllipseNode* ellipse = dynamic_cast<Parser::EllipseNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::ELLIPSE))) {
		obj = new Ellipse(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetWidth(), objectNode->GetHeight(), objectNode->GetRotation());
	}
	else if (Parser::PolylineNode* polyline = dynamic_cast<Parser::PolylineNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::POLYLINE))) {
		obj = new Polygone(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetRotation(), polyline->GetPoints(), PolygoneType::POLYLINE);
	}
	else if (Parser::PolygoneNode* polygone = dynamic_cast<Parser::PolygoneNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::POLYGONE))) {
		obj = new Polygone(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetRotation(), polygone->GetPoints(), PolygoneType::POLYGONE);
	}
	else if (Parser::PointNode* point = dynamic_cast<Parser::PointNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::POINT))) {
		obj = new Point(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(), objectNode->GetY());
	}
	else {
		obj = new ObjectTemplate(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetWidth(), objectNode->GetHeight(), objectNode->GetRotation());
	}

	if (Parser::PropertiesNode* properties = dynamic_cast<Parser::PropertiesNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::PROPERTIES))) {
		obj->SetProperties(properties);
	}
	tile->AddObject(obj);
}
