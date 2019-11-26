#include "layernode.h"

using namespace Parser;

LayerNode::LayerNode(Node* parent)
    : Node(NodeType::LAYER, parent)
	, m_id(0)
    , m_width(0)
    , m_height(0)
{
}

LayerNode::~LayerNode()
{
}

void LayerNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	m_id = eAttribute->IntAttribute("id");
	const char* name = eAttribute->Attribute("name");
	if (name) m_name = name;
	m_width = eAttribute->IntAttribute("width");
	m_height = eAttribute->IntAttribute("height");
}

void LayerNode::ParseChildTag(const tinyxml2::XMLElement* eChild)
{
	std::string tagName = eChild->Value();

	if (tagName == "properties") {
		this->AddChildNode(new PropertiesNode(this), eChild);
	}
	else if (tagName == "data") {
		this->AddChildNode(new DataNode(this), eChild);
	}
}
