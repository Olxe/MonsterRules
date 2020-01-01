#include "ObjectGroupBuilder.h"

using namespace Builder;

ObjectGroupBuilder::ObjectGroupBuilder(Parser::ObjectGroupNode* objectGroup, std::vector< Tile* >& tiles, int& unique_id)
{
	for (auto it : objectGroup->GetSpecificListOfChild(Parser::NodeType::OBJECT)) {
		if (Parser::ObjectNode* objectNode = dynamic_cast<Parser::ObjectNode*>(it)) {

			if (objectNode->GetGid() > 0) {
				Tile* tile = this->getTileWithGid(objectNode->GetGid(), tiles);
				SceneObject* sceneObject = new SceneObject(unique_id, objectNode->GetName(), objectNode->GetType(), objectNode->GetX(), objectNode->GetY(),
					objectNode->GetWidth(), objectNode->GetHeight(), objectNode->GetRotation(), tile);

				if (Parser::PropertiesNode* propertiesNode = dynamic_cast<Parser::PropertiesNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::PROPERTIES))){
					sceneObject->SetProperties(propertiesNode);
				}
				
				m_layout.push_back(sceneObject);
			}
			else {
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

				m_layout.push_back(obj);
			}
			unique_id++;
		}
	}
}

ObjectGroupBuilder::~ObjectGroupBuilder()
{
	clearVector(m_layout);
}