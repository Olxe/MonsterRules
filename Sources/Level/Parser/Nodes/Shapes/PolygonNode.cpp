#include "PolygonNode.h"

using namespace Parser;

PolygoneNode::PolygoneNode(Node* parent)
	: Node(NodeType::POLYGONE, parent)
{
}

PolygoneNode::~PolygoneNode()
{
}

void Parser::PolygoneNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	const char* points = eAttribute->Attribute("points");
	if (points) m_points = points;
}
