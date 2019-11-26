#include "Customizable.h"

using namespace Builder;

Customizable::Customizable()
{
}

Customizable::~Customizable()
{
}

void Builder::Customizable::SetProperties(Parser::PropertiesNode* propertiesNode)
{
	for (auto properties_child_node : propertiesNode->GetChildNodes()) {
		if (Parser::PropertyNode* property = dynamic_cast<Parser::PropertyNode*>(properties_child_node)) {
			this->GetProperties().AddProperty(property->GetName(), property->ToString());
		}
	}
}
