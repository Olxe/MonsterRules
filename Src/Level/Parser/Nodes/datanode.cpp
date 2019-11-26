#include "datanode.h"

using namespace Parser;

DataNode::DataNode(Node* parent)
	: Node(NodeType::DATA, parent)
{
}

DataNode::~DataNode()
{
}

void DataNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	const char* encoding = eAttribute->Attribute("encoding");
	if (encoding) m_encoding = encoding;
	const char* data = eAttribute->GetText();
	if (data) m_data = data;
}