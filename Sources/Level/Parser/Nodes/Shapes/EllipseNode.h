#pragma once

#include "../Node.h"

namespace Parser
{
	class EllipseNode: public Node
	{
	public:
		EllipseNode(Node* parent = nullptr);
		~EllipseNode();

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override {}
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:

	};
}

