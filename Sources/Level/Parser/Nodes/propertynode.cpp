#include "propertynode.h"

using namespace Parser;

PropertyNode::PropertyNode(Node* parent)
	: Node(NodeType::PROPERTY, parent)
    , m_type(Type::STRING)
{
}

PropertyNode::~PropertyNode()
{
}

bool PropertyNode::ToBool(bool defaultValue) const
{
    if(m_type == Type::BOOL) return m_value.compare("false");

    return defaultValue;
}

float PropertyNode::ToFloat(float defaultValue) const
{
    if(m_type == Type::FLOAT) return std::stof(m_value);

    return defaultValue;
}

int PropertyNode::ToInt(int defaultValue) const
{
    if(m_type == Type::INT) return std::stoi(m_value);

    return defaultValue;
}

std::string PropertyNode::ToString() const
{
    return m_value;
}

void PropertyNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	const char* name = eAttribute->Attribute("name");
	const char* value = eAttribute->Attribute("value");
	const char* type = eAttribute->Attribute("type");

	if (name) m_name = name;
	if (value) m_value = value;

	if (type) {
		if (strcmp(type, "bool") == 0) m_type = Type::BOOL;
		if (strcmp(type, "color") == 0) m_type = Type::COLOR;
		if (strcmp(type, "float") == 0) m_type = Type::FLOAT;
		if (strcmp(type, "file") == 0) m_type = Type::FILE;
		if (strcmp(type, "int") == 0) m_type = Type::INT;
	}
}
