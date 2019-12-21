#pragma once

#include <vector>

#include "../../../Tools/ToolsFunction.h"
#include "Customizable.h"
#include "Object.h"

namespace Builder
{
	class Tile: public Customizable
	{
	public:
		Tile(int id, int gid, std::string source, float width, float height);
		virtual ~Tile();

		void AddObject(Object* object) { m_objects.push_back(object); }//create obj ?
		std::vector<Object*> GetObjects() { return m_objects; }
		void SetType(std::string value) { m_type = value; }

		int GetId() const { return m_id; }
		int GetGid() const { return m_gid; }
		std::string GetType() const { return m_type; }
		std::string GetSource() const { return m_source; }
		float GetWidth() const { return m_width; }
		float GetHeight() const { return m_height; }

	private:
		int m_id;
		int m_gid;
		std::string m_type;
		std::string m_source;
		float m_width;
		float m_height;
		std::vector<Object*> m_objects;
	};

}
