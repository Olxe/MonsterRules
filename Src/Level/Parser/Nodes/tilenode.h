#ifndef __TILENODE__
#define __TILENODE__

#include "Node.h"
#include "propertiesnode.h"
#include "objectgroupnode.h"
#include "imagenode.h"

namespace Parser
{
	class TileNode: public Node
	{
	public:
		TileNode(Node* parent = nullptr);
		~TileNode();

		int GetId() const { return m_id; }
		std::string GetType() const { return m_type; };

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override;

	private:
		int m_id;
		std::string m_type;
	};
}

#endif