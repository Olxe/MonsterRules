#ifndef __LAYERNODE__
#define __LAYERNODE__

#include "Node.h"
#include "datanode.h"
#include "propertiesnode.h"

namespace Parser
{
	class LayerNode: public Node
	{
	public:
		LayerNode(Node* parent = nullptr);
		~LayerNode();

		int GetId() const { return m_id; }
		std::string GetName() const { return m_name; }
		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override;

	private:
		int m_id;
		std::string m_name;
		int m_width;
		int m_height;

	};
}

#endif