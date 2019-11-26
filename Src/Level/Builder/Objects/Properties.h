#pragma once

#include <map>
#include <string>

namespace Builder
{
	class Properties
	{
	public:
		Properties();
		~Properties();

		void AddProperty(std::string name, std::string value);
		std::string GetProperty(std::string name);//const

	private:
		std::map< std::string, std::string > m_properties;
	};
}

