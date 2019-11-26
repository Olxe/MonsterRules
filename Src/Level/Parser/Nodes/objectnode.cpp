#include "objectnode.h"

using namespace Parser;

ObjectNode::ObjectNode(Node* parent)
    : Node(NodeType::OBJECT, nullptr)
	, m_id(0)
    , m_gid(0)
    , m_x(0.f)
    , m_y(0.f)
    , m_width(0.f)
    , m_height(0.f)
    , m_rotation(0.f)
    , isVisible(true)
{
}

ObjectNode::~ObjectNode()
{
}

void Parser::ObjectNode::ParseAttribute(const tinyxml2::XMLElement* eAttribute)
{
	m_id = eAttribute->IntAttribute("id");
	m_gid = eAttribute->IntAttribute("gid");
	m_x = eAttribute->FloatAttribute("x");
	m_y = eAttribute->FloatAttribute("y");
	m_width = eAttribute->FloatAttribute("width");
	m_height = eAttribute->FloatAttribute("height");
	m_rotation = eAttribute->FloatAttribute("rotation");
	isVisible = eAttribute->BoolAttribute("visible", true);

	const char* name = eAttribute->Attribute("name");
	const char* type = eAttribute->Attribute("type");
	if (name) m_name = name;
	if (type) m_type = type;
}

void Parser::ObjectNode::ParseChildTag(const tinyxml2::XMLElement* eChild)
{
	std::string tagName = eChild->Value();

	if (tagName == "properties") {
		this->AddChildNode(new PropertiesNode(this), eChild);
	}
	else if (tagName == "ellipse") {
		this->AddChildNode(new EllipseNode(this), eChild);
	}
	else if (tagName == "point") {
		this->AddChildNode(new PointNode(this), eChild);
	}
	else if (tagName == "polygon") {
		this->AddChildNode(new PolygoneNode(this), eChild);
	}
	else if (tagName == "polyline") {
		this->AddChildNode(new PolylineNode(this), eChild);
	}
}