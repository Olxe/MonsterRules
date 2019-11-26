#include "mapnode.h"

using namespace Parser;

MapNode::MapNode(std::string TMXDirectory, Node* parent)
    : Node(NodeType::MAP, parent)
	, m_width(0)
    , m_height(0)
    , m_tilewidth(0)
    , m_tileheight(0)
    , isInfinite(false)
	, m_directory(TMXDirectory)
{
}

MapNode::~MapNode()
{
}

void MapNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	m_width = eAttribute->IntAttribute("width");
	m_height = eAttribute->IntAttribute("height");
	m_tilewidth = eAttribute->IntAttribute("tilewidth");
	m_tileheight = eAttribute->IntAttribute("tileheight");
	isInfinite = eAttribute->BoolAttribute("infinite");
}

void MapNode::ParseChildTag(const tinyxml2::XMLElement* eChild)
{
	std::string tagName = eChild->Value();

	if (tagName == "properties") {
		this->AddChildNode(new PropertiesNode(this), eChild);
	}
	else if (tagName == "tileset") {
		this->parseTileset(eChild);
	}
	else if (tagName == "objectgroup") {
		this->AddChildNode(new ObjectGroupNode(this), eChild);
	}
	else if (tagName == "layer") {
		this->AddChildNode(new LayerNode(this), eChild);
	}
}

void MapNode::parseTileset(const tinyxml2::XMLElement* eTileset)
{
	int firstgid = eTileset->IntAttribute("firstgid");
	const char* source = eTileset->Attribute("source");
	if (!source) {
		display("Error parsing tileset node. Bad source attribute.");
		return;
	}

	tinyxml2::XMLDocument document;
	tinyxml2::XMLError result = document.LoadFile((m_directory + source).c_str());
	if (result != tinyxml2::XML_SUCCESS) {
		std::cout << "Error loading : " + (std::string)source << std::endl;
		return;
	}

	const tinyxml2::XMLElement* eTilesetNewDoc = document.FirstChildElement("tileset");
	this->AddChildNode(new TilesetNode(firstgid, source, this), eTilesetNewDoc);
}
