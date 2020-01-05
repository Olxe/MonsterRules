#include "ObjectBuilder.h"

namespace Builder
{
	ObjectBuilder::ObjectBuilder()
	{
	}

	ObjectBuilder::~ObjectBuilder()
	{
	}

	std::unique_ptr<ObjectTemplate> ObjectBuilder::BuildObject(Parser::ObjectNode* objectNode)
	{
		ObjectTemplate* obj;
		if (Parser::EllipseNode* ellipse = dynamic_cast<Parser::EllipseNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::ELLIPSE))) {
			obj = new Ellipse(objectNode);
		}
		else if (Parser::PolylineNode* polyline = dynamic_cast<Parser::PolylineNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::POLYLINE))) {
			obj = new Polygone(objectNode, polyline->GetPoints(), PolygoneType::POLYLINE);
		}
		else if (Parser::PolygoneNode* polygone = dynamic_cast<Parser::PolygoneNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::POLYGONE))) {
			obj = new Polygone(objectNode, polygone->GetPoints(), PolygoneType::POLYGONE);
		}
		else if (Parser::PointNode* point = dynamic_cast<Parser::PointNode*>(objectNode->GetFirstSpecificChild(Parser::NodeType::POINT))) {
			obj = new Point(objectNode);
		}
		else {
			obj = new ObjectTemplate(objectNode);
		}

		return std::unique_ptr<ObjectTemplate>(obj);
	}
}