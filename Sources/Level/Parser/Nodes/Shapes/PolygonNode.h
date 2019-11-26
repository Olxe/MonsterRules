#pragma once

#include "../Node.h"

namespace Parser
{
	class PolygoneNode: public Node
	{
	public:
		PolygoneNode(Node* parent = nullptr);
		~PolygoneNode();

		std::string GetPoints() const { return m_points; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:
		std::string m_points;
	};
}

