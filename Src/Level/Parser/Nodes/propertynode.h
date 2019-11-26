#ifndef __PROPERTYNODE__
#define __PROPERTYNODE__

#include "Node.h"

namespace Parser
{
	enum class Type
	{
		BOOL,
		COLOR,
		FLOAT,
		FILE,
		INT,
		STRING
	};

	class PropertyNode: public Node
	{
	public:
		PropertyNode(Node* parent = nullptr);
		~PropertyNode();

		std::string GetName() { return m_name; }

		bool ToBool(bool defaultValue = false) const;
		float ToFloat(float defaultValue = 0.f) const;
		int ToInt(int defaultValue = 0) const;
		std::string ToString() const;

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:
		std::string m_name;
		std::string m_value;
		Type m_type;
	};
}

#endif