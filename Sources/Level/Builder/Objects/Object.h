#pragma once

#include <string>

#include "Customizable.h"

namespace Builder
{
	class Object: public Customizable
	{
	public:
		Object(std::string name, std::string type, float x, float y, float width, float height, float rotation);
		virtual ~Object();

		void SetName(std::string name);
		void SetPosition(float x, float y);
		void SetSize(float width, float height);
		void SetRotation(float rotation);

		std::string GetName() const { return m_name; }
		std::string GetType() const { return m_type; }
		float GetX() const { return m_x; }
		float GetY() const { return m_y; }
		float GetWidth() const { return m_width; }
		float GetHeight() const { return m_height; }
		float GetRotation() const { return m_rotation; }

	private:
		std::string m_name;
		std::string m_type;
		float m_x;
		float m_y;
		float m_width;
		float m_height;
		float m_rotation;
	};
}

