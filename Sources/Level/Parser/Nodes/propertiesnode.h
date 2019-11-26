#ifndef __PROPERTIESNODE__
#define __PROPERTIESNODE__

#include "Node.h"
#include "propertynode.h"

namespace Parser
{
	class PropertiesNode: public Node
	{
	public:
		PropertiesNode(Node* parent = nullptr);
		~PropertiesNode();

		PropertyNode* GetProperty(const std::string& name) const;

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override {}
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override;

	};
}

#endif