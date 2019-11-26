#include "tilenode.h"

using namespace Parser;

TileNode::TileNode(Node* parent)
    : Node(NodeType::TILE, parent)
	, m_id(0)
{
}

TileNode::~TileNode()
{
}

void TileNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	m_id = eAttribute->IntAttribute("id");
	const char* type = eAttribute->Attribute("type");
	if (type) m_type = type;
}

void TileNode::ParseChildTag(const tinyxml2::XMLElement* eChild)
{
	std::string tagName = eChild->Value();

	if (tagName == "properties") {
		this->AddChildNode(new PropertiesNode(this), eChild);
	}
	else if (tagName == "image") {
		this->AddChildNode(new ImageNode(this), eChild);
	}
	else if (tagName == "objectgroup") {
		this->AddChildNode(new ObjectGroupNode(this), eChild);
	}
}
