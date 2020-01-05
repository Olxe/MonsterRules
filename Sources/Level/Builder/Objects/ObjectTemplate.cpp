#include "ObjectTemplate.h"

namespace Builder
{
	Builder::ObjectTemplate::ObjectTemplate(Parser::ObjectNode* object)
		: m_object(object)
	{
	}

	ObjectTemplate::~ObjectTemplate()
	{
	}

	Parser::PropertyNode Builder::ObjectTemplate::getProperty(std::string name) const
	{
		if (m_object) {
			if (Parser::PropertiesNode* properties = dynamic_cast<Parser::PropertiesNode*>(m_object->GetFirstSpecificChild(Parser::NodeType::PROPERTIES))) {
				return properties->GetProperty(name);
			}
		}
		return Parser::PropertyNode();
	}

	std::string Builder::ObjectTemplate::getName() const
	{
		if (m_object) {
			return m_object->GetName();
		}
		return std::string();
	}

	std::string Builder::ObjectTemplate::getType() const
	{
		if (m_object) {
			return m_object->GetType();
		}
		return std::string();
	}

	sf::Vector2f Builder::ObjectTemplate::getPosition() const
	{
		if (m_object) {
			return sf::Vector2f(m_object->GetX(), m_object->GetY());
		}
		return sf::Vector2f();
	}

	sf::Vector2f Builder::ObjectTemplate::getSize() const
	{
		if (m_object) {
			return sf::Vector2f(m_object->GetWidth(), m_object->GetHeight());
		}
		return sf::Vector2f();
	}

	float Builder::ObjectTemplate::getRotation() const
	{
		if (m_object) {
			return m_object->GetRotation();
		}
		return 0.0f;
	}
}