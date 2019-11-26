#pragma once

#include "../Node.h"

namespace Parser
{
	class PolylineNode: public Node
	{
	public:
		PolylineNode(Node* parent = nullptr);
		~PolylineNode();

		std::string GetPoints() const { return m_points; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:
		std::string m_points;

	};
}
