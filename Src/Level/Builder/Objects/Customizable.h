#pragma once

#include "../../Parser/Nodes/propertiesnode.h"
#include "Properties.h"

namespace Builder
{
	class Customizable
	{
	public:
		Customizable();
		virtual ~Customizable();

		void SetProperties(Parser::PropertiesNode* propertiesNode);
		Properties GetProperties() { return m_properties; }

	private:
		Properties m_properties;

	};
}

