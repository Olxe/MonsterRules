#pragma once

#include <string>

namespace Builder 
{
	class Image
	{
	public:
		Image(std::string source, float width, float height);
		~Image();

		std::string GetSource() const { return m_source; }
		float GetWidth() const { return m_width; }
		float GetHeight() const { return m_height; }

	private:
		std::string m_source;
		float m_width;
		float m_height;

	};
}

