#pragma once

#include <string>
#include <vector>

#include "../tinyxml2.h"
#include "../../../Tools/utility.h"

namespace Parser 
{
	enum class NodeType
	{
		MAP,
		TILESET,
		LAYER,
		OBJECTGROUP,
		PROPERTIES,
		PROPERTY,
		GRID,
		TILE,
		IMAGE,
		OBJECT,
		DATA,
		ELLIPSE,
		POLYGONE,
		POLYLINE,
		POINT
	};

	class Node
	{
	public:
		Node(NodeType nodeType, Node* parent = nullptr);
		virtual ~Node();

		virtual void Parse(const tinyxml2::XMLNode* node);

		NodeType GetType() const { return m_nodeType;  }
		Node* GetParent() const { return m_parent; }
		std::vector< Node* > GetChildNodes() const { return m_childNodes; }
		Node* GetFirstSpecificChild(NodeType nodeType) const;
		std::vector<Node*> GetSpecificListOfChild(NodeType nodeType) const;
		bool HasChild(NodeType nodeType) const;

	protected:
		virtual void ParseAttribute(const tinyxml2::XMLElement* eAttribute) = 0;
		virtual void ParseChildTag(const tinyxml2::XMLElement* eChild) = 0;
		void AddChildNode(Node* childNode, const tinyxml2::XMLElement* eNode);

	private:
		NodeType m_nodeType;
		Node* m_parent;
		std::vector< Node* > m_childNodes;

	};
}


