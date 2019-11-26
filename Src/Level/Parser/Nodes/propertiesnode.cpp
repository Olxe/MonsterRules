#include "propertiesnode.h"

using namespace Parser;

PropertiesNode::PropertiesNode(Node* parent)
	: Node(NodeType::PROPERTIES, parent)
{
}

PropertiesNode::~PropertiesNode()
{
}

PropertyNode* PropertiesNode::GetProperty(const std::string& name) const
{
    for(auto child : this->GetChildNodes()){
		PropertyNode* property = dynamic_cast<PropertyNode*>(child);
        if(property && property->GetName() == name){
            return property;
        }
    }
    return nullptr;
}

void PropertiesNode::ParseChildTag(const tinyxml2::XMLElement* eChild)
{
	std::string tagName = eChild->Value();

	if (tagName == "property") {
		this->AddChildNode(new PropertyNode(this), eChild);
	}
}