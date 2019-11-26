#include "Node.h"

using namespace Parser;

Node::Node(NodeType nodeType, Node* parent)
	: m_nodeType(nodeType)
	, m_parent(parent)
{
}

Node::~Node()
{
	clearVector(m_childNodes);
}

void Node::Parse(const tinyxml2::XMLNode* node)
{
	clearVector(m_childNodes);

	const tinyxml2::XMLElement* eCurrentNode = node->ToElement();
	this->ParseAttribute(eCurrentNode);

	for (const tinyxml2::XMLElement* eChild = eCurrentNode->FirstChildElement(); eChild != nullptr; eChild = eChild->NextSiblingElement())
	{
		this->ParseChildTag(eChild);
	}
}

Node* Node::GetFirstSpecificChild(NodeType nodeType) const
{
	for (auto it : m_childNodes) {
		if (it->GetType() == nodeType) {
			return it;
		}
	}
	return nullptr;
}

std::vector<Node*> Node::GetSpecificListOfChild(NodeType nodeType) const
{
	std::vector<Node*> list;
	for (auto it : m_childNodes) {
		if (it->GetType() == nodeType) list.push_back(it);
	}
	return list;
}

bool Parser::Node::HasChild(NodeType nodeType) const
{
	for (auto it : m_childNodes) {
		if (it->GetType() == nodeType) {
			return true;
		}
	}
	return false;
}

void Node::AddChildNode(Node* childNode, const tinyxml2::XMLElement* eNode)
{
	childNode->Parse(eNode);
	m_childNodes.push_back(childNode);
}
