#include "PointNode.h"

using namespace Parser;

PointNode::PointNode(Node* parent)
	: Node(NodeType::POINT, parent)
{
}

PointNode::~PointNode()
{
}