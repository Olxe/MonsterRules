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
	return m_properties[name];
}
