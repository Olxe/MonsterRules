#pragma once

#include <string>

#include "../../Parser/Nodes/objectnode.h"

namespace Builder
{
	class ObjectTemplate
	{
	public:
		ObjectTemplate(Parser::ObjectNode* object);
		virtual ~ObjectTemplate();

		Parser::PropertyNode getProperty(std::string name) const;
		std::string getName() const;
		std::string getType() const;
		virtual sf::Vector2f getPosition() const;
		sf::Vector2f getSize() const;
		float getRotation() const;

	protected:
		Parser::ObjectNode* m_object;

	};
}

