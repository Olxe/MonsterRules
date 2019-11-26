#pragma once

#include "../Node.h"

namespace Parser
{
	class PointNode: public Node
	{
	public:
		PointNode(Node* parent = nullptr);
		~PointNode();

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override {}
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:

	};
}

