#include "imagenode.h"

using namespace Parser;

ImageNode::ImageNode(Node* parent)
    : Node(NodeType::IMAGE, parent)
	, m_width(0)
    , m_height(0)
{
}

ImageNode::~ImageNode()
{
}

void Parser::ImageNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	m_width = eAttribute->IntAttribute("width");
	m_height = eAttribute->IntAttribute("height");
	const char* source = eAttribute->Attribute("source");
	if (source) m_source = source;
}