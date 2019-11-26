#include "GridNode.h"

using namespace Parser;

GridNode::GridNode(Node* parent)
	: Node(NodeType::GRID, parent)
{
}

GridNode::~GridNode()
{
}

void Parser::GridNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	const char* orientation = eAttribute->Attribute("orientation");
	if (orientation) m_orientation = orientation;
	m_width = eAttribute->IntAttribute("width");
	m_height = eAttribute->IntAttribute("height");
}
