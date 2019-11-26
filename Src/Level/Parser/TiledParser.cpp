#include "TiledParser.h"

using namespace Parser;

TiledParser::TiledParser()
	: m_map(nullptr)
{
}

TiledParser::~TiledParser()
{
	clearPtr(m_map);
}

MapNode* TiledParser::ParseTMX(std::string directory, std::string fileName)
{
	clearPtr(m_map);

	tinyxml2::XMLDocument document;
	tinyxml2::XMLError result = document.LoadFile((directory + fileName).c_str());
	if (result != tinyxml2::XML_SUCCESS) {
		std::cout << "Error loading : " + directory + fileName << std::endl;
		return nullptr;
	}

	tinyxml2::XMLElement* eMap = document.FirstChildElement("map");
	m_map = new MapNode(directory, nullptr);
	m_map->Parse(eMap);

	//PropertiesNode* properties = static_cast<PropertiesNode*>(m_map->GetFirstSpecificChild(NodeType::PROPERTIES));
	//PropertyNode* property = static_cast<PropertyNode*>(properties->GetProperty("dd"));

	return m_map;
}
