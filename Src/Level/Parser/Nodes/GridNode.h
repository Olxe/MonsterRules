#pragma once

#include "Node.h"

namespace Parser
{
	class GridNode: public Node
	{
	public:
		GridNode(Node* parent = nullptr);
		~GridNode();

		std::string GetOrientation() const { return m_orientation; }
		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:
		std::string m_orientation;
		int m_width;
		int m_height;
	};
}
