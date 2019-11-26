#include "PolylineNode.h"

using namespace Parser;

PolylineNode::PolylineNode(Node* parent)
	: Node(NodeType::POLYLINE, parent)
{
}

PolylineNode::~PolylineNode()
{
}

void Parser::PolylineNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	const char* points = eAttribute->Attribute("points");
	if (points) m_points = points;
}
