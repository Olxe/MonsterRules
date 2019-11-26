#ifndef __OBJECTGROUPNODE__
#define __OBJECTGROUPNODE__

#include "Node.h"
#include "objectnode.h"

namespace Parser
{
	class ObjectGroupNode: public Node
	{
	public:
		ObjectGroupNode(Node* parent = nullptr);
		~ObjectGroupNode();

		int GetId() const { return m_id; }
		std::string GetName() const { return m_name; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override;

	private:
		int m_id;
		std::string m_name;
		std::vector< ObjectNode* > m_objects;
	};
}

#endif