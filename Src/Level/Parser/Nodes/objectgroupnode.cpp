#include "objectgroupnode.h"

using namespace Parser;

ObjectGroupNode::ObjectGroupNode(Node* parent)
    : Node(NodeType::OBJECTGROUP, parent)
	, m_id(0)
{
}

ObjectGroupNode::~ObjectGroupNode()
{
}

void Parser::ObjectGroupNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	m_id = eAttribute->IntAttribute("id");
	const char* name = eAttribute->Attribute("name");
	if (name) m_name = name;
}

void Parser::ObjectGroupNode::ParseChildTag(const tinyxml2::XMLElement* eChild)
{
	std::string tagName = eChild->Value();

	if (tagName == "properties") {
		this->AddChildNode(new PropertiesNode(this), eChild);
	}
	else if (tagName == "object") {
		this->AddChildNode(new ObjectNode(this), eChild);
	}
}