#include "tilesetnode.h"

using namespace Parser;

TilesetNode::TilesetNode(int firstgid, std::string source, Node* parent)
    : Node(NodeType::TILESET, parent)
	, m_firstgid(firstgid)
	, m_source(source)
    , m_tilewidth(0)
    , m_tileheight(0)
    , m_tilecount(0)
	, m_columns(0)
{
}

TilesetNode::~TilesetNode()
{
}

void Parser::TilesetNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	const char* name = eAttribute->Attribute("name");
	if (name) m_name = name;
	m_tilewidth = eAttribute->FloatAttribute("tilewidth");
	m_tileheight = eAttribute->FloatAttribute("tileheight");
	m_tilecount = eAttribute->IntAttribute("tilecount");
	m_columns = eAttribute->IntAttribute("columns");
}

void Parser::TilesetNode::ParseChildTag(const tinyxml2::XMLElement* eChild)
{
	std::string tagName = eChild->Value();
	if (tagName == "properties") {
		this->AddChildNode(new PropertiesNode(this), eChild);
	}
	else if (tagName == "image") {
		this->AddChildNode(new ImageNode(this), eChild);
	}
	else if (tagName == "tile") {
		this->AddChildNode(new TileNode(this), eChild);
	}
	else if (tagName == "grid") {
		this->AddChildNode(new GridNode(this), eChild);
	}
}
