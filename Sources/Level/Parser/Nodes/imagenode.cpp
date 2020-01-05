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
	m_width = eAttribute->FloatAttribute("width");
	m_height = eAttribute->FloatAttribute("height");
	const char* source_ = eAttribute->Attribute("source");
	if (source_) m_source = source_;
}