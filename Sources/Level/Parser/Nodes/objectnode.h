#ifndef __OBJECTNODE__
#define __OBJECTNODE__

#include "Node.h"
#include "propertiesnode.h"
#include "Shapes/EllipseNode.h"
#include "Shapes/PolygonNode.h"
#include "Shapes/PolylineNode.h"
#include "Shapes/PointNode.h"

namespace Parser
{
	class ObjectNode: public Node
	{
	public:
		ObjectNode(Node* parent = nullptr);
		~ObjectNode();

		int GetId() const { return m_id; };
		int GetGid() const { return m_gid; };
		std::string GetName() const { return m_name; };
		std::string GetType() const { return m_type; };
		float GetX() const { return m_x; };
		float GetY() const { return m_y; };
		float GetWidth() const { return m_width; };
		float GetHeight() const { return m_height; };
		float GetRotation() const { return m_rotation; };
		bool GetIsVisible() const { return isVisible; };

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override;

	private:
		int m_id;
		int m_gid;
		std::string m_name;
		std::string m_type;
		float m_x;
		float m_y;
		float m_width;
		float m_height;
		float m_rotation;
		bool isVisible;
	};
}

#endif