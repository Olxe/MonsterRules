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

	if (tileset->HasChild(Parser::NodeType::IMAGE)) {

		if (Parser::ImageNode* imageNode = dynamic_cast<Parser::ImageNode*>(tileset->GetFirstSpecificChild(Parser::NodeType::IMAGE))) {
			this->createTiles(tileset, directory + "Templates/", imageNode, tiles);
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
					directory + "Templates/" + imageNode->GetSource(), (float)imageNode->GetWidth(), (float)imageNode->GetHeight()));

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
	std::string image_path = directory + imageNode->GetSource();

	int columns = image_width / tile_width;
	int rows = image_height / tile_height;
	int id = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			tiles.push_back(new TilesetTile(id, tileset->GetFirstgid() + id, image_path, (float)tile_width, (float)tile_height, j, i));
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
	for (auto object_child_node : objectNode->GetChildNodes()) {
		Object* obj = nullptr;
		if (Parser::EllipseNode* ellipseNode = dynamic_cast<Parser::EllipseNode*>(object_child_node))
		{
			obj = new Ellipse(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetWidth(), objectNode->GetHeight(), objectNode->GetRotation());
		}
		else if (Parser::PolylineNode* polylineNode = dynamic_cast<Parser::PolylineNode*>(object_child_node))
		{
			obj = new Polyline(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetRotation(), polylineNode->GetPoints());
		}
		else if (Parser::PolygoneNode* polygoneNode = dynamic_cast<Parser::PolygoneNode*>(object_child_node)) {
			obj = new Polygone(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetRotation(), polygoneNode->GetPoints());
		}
		else if (Parser::PointNode* pointNode = dynamic_cast<Parser::PointNode*>(object_child_node)) {
			obj = new Point(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(), objectNode->GetY());
		}
		else {
			obj = new Object(objectNode->GetName(), objectNode->GetType(), objectNode->GetX(),
			objectNode->GetY(), objectNode->GetWidth(), objectNode->GetHeight(), objectNode->GetRotation());
		}

		if (obj) {
			if (Parser::PropertiesNode* properties = dynamic_cast<Parser::PropertiesNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::PROPERTIES))) {
				obj->SetProperties(properties);
			}
			
			tile->AddObject(obj);
		}
	}
}
