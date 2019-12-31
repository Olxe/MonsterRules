#include "ObjectGroupBuilder.h"

using namespace Builder;

ObjectGroupBuilder::ObjectGroupBuilder(Parser::ObjectGroupNode* objectGroup, std::vector< Tile* >& tiles, int& unique_id)
{
	for (auto it : objectGroup->GetSpecificListOfChild(Parser::NodeType::OBJECT)) {
		if (Parser::ObjectNode* objNode = dynamic_cast<Parser::ObjectNode*>(it)) {

			if (objNode->GetGid() > 0) {
				Tile* tile = this->getTileWithGid(objNode->GetGid(), tiles);
				SceneObject* sceneObject = new SceneObject(unique_id, objNode->GetName(), objNode->GetType(), objNode->GetX(), objNode->GetY(),
					objNode->GetWidth(), objNode->GetHeight(), objNode->GetRotation(), tile);

				if (Parser::PropertiesNode* propertiesNode = dynamic_cast<Parser::PropertiesNode*>(objNode->GetFirstSpecificChild(Parser::NodeType::PROPERTIES))){
					sceneObject->SetProperties(propertiesNode);
				}
				
				m_layout.push_back(sceneObject);
			}
			else {
				ObjectTemplate* object;
				if (Parser::EllipseNode* ellipseNode = dynamic_cast<Parser::EllipseNode*>(objNode))
				{
					object = new Ellipse(objNode->GetName(), objNode->GetType(), objNode->GetX(),
						objNode->GetY(), objNode->GetWidth(), objNode->GetHeight(), objNode->GetRotation());
				}
				else if (Parser::PolylineNode* polylineNode = dynamic_cast<Parser::PolylineNode*>(objNode))
				{
					object = new Polygone(objNode->GetName(), objNode->GetType(), objNode->GetX(),
						objNode->GetY(), objNode->GetRotation(), polylineNode->GetPoints(), PolygoneType::POLYLINE);
				}
				else if (Parser::PolygoneNode* polygoneNode = dynamic_cast<Parser::PolygoneNode*>(objNode)) {
					object = new Polygone(objNode->GetName(), objNode->GetType(), objNode->GetX(),
						objNode->GetY(), objNode->GetRotation(), polygoneNode->GetPoints(), PolygoneType::POLYGONE);
				}
				else if (Parser::PointNode* pointNode = dynamic_cast<Parser::PointNode*>(objNode)) {
					object = new Point(objNode->GetName(), objNode->GetType(), objNode->GetX(), objNode->GetY());
				}
				else {
					object = new ObjectTemplate(objNode->GetName(), objNode->GetType(), objNode->GetX(),
						objNode->GetY(), objNode->GetWidth(), objNode->GetHeight(), objNode->GetRotation());
				}

				if (Parser::PropertiesNode* propertiesNode = dynamic_cast<Parser::PropertiesNode*>(objNode->GetFirstSpecificChild(Parser::NodeType::PROPERTIES))) {
					object->SetProperties(propertiesNode);
				}

				m_layout.push_back(object);
			}
			unique_id++;
		}
	}
}

ObjectGroupBuilder::~ObjectGroupBuilder()
{
	clearVector(m_layout);
}