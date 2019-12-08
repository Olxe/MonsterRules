#include "Properties.h"

using namespace Builder;

Properties::Properties()
{
}

Properties::~Properties()
{
}

void Builder::Properties::AddProperty(std::string name, std::string value)
{

	m_properties[name] = value;
}

std::string Builder::Properties::GetProperty(std::string name)
{
	//std::cout << m_properties.size() << std::endl;
	//for (auto it = m_properties.begin(); it != m_properties.end(); it++)
	//{
	//	std::cout << it->first  // string (key)
	//		<< ':'
	//		<< it->second   // string's value 
	//		<< std::endl;
	//}
	return m_properties[name];
}
