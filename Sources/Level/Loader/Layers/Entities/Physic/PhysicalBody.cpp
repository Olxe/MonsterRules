#include "PhysicalBody.h"

PhysicalBody::PhysicalBody(sf::Vector2f position, float rotation, b2BodyType bodyType, bool rotationFixed, void* userData)
	: m_b2Body(nullptr)
	, SCALE(30.f)
	, PhysicDebug(30.f)
{
	this->Create(position, rotation, bodyType, rotationFixed, userData);
}

PhysicalBody::~PhysicalBody()
{
	clearBody();
}

void PhysicalBody::Create(sf::Vector2f position, float rotation, b2BodyType bodyType, bool rotationFixed, void* userData)
{
	clearBody();

	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	bodyDef.angle = rotation / 180.f * b2_pi;
	bodyDef.type = bodyType;

	m_b2Body = Box2DWorld::Instance()->getWorld()->CreateBody(&bodyDef);
	m_b2Body->SetFixedRotation(rotationFixed);
	m_b2Body->SetUserData(userData);

	this->setBody(m_b2Body);
}

bool PhysicalBody::AddFixtureRectangle(sf::Vector2f offset, sf::Vector2f size, float rotation, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	b2PolygonShape shape;
	shape.SetAsBox(size.x / 2.0f / SCALE, size.y / 2.0f / SCALE, b2Vec2(offset.x / SCALE, offset.y / SCALE), rotation / 180.f * b2_pi);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);

	std::unique_ptr<sf::RectangleShape> rect(new sf::RectangleShape());
	rect->setSize(size);
	rect->setOrigin(size / 2.f);
	rect->setPosition(sf::Vector2f(m_b2Body->GetPosition().x * SCALE + offset.x, m_b2Body->GetPosition().y * SCALE + offset.y));
	rect->setRotation(rotation);
	rect->setFillColor(sf::Color(sf::Color::Transparent));
	if(!isSensor)
		rect->setOutlineColor(sf::Color::Red);
	else
		rect->setOutlineColor(sf::Color::Blue);
	rect->setOutlineThickness(1);
	
	this->addRect(std::move(rect), offset);

	return true;
}

bool PhysicalBody::AddFixtureEdge(sf::Vector2f offset, sf::Vector2f p1, sf::Vector2f p2, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	b2EdgeShape shape;
	shape.Set(b2Vec2((p1.x + offset.x) / SCALE, (p1.y + offset.y) / SCALE), b2Vec2((p2.x + offset.x) / SCALE, (p2.y + offset.y) / SCALE));

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);

	/*std::unique_ptr<sf::ConvexShape> debugShape(new sf::ConvexShape());
	debugShape->setPointCount(3);
	debugShape->setPoint(0, p1);
	debugShape->setPoint(1, p2);
	debugShape->setPoint(2, p1);
	debugShape->setPosition(sf::Vector2f(m_b2Body->GetPosition().x * SCALE + offset.x, m_b2Body->GetPosition().y * SCALE + offset.y));
	debugShape->setFillColor(sf::Color(sf::Color::Transparent));
	if (!isSensor)
		debugShape->setOutlineColor(sf::Color::Red);
	else
		debugShape->setOutlineColor(sf::Color::Blue);
	debugShape->setOutlineThickness(1);

	this->addRect(std::move(debugShape), offset);*/

	std::unique_ptr<sf::RectangleShape> rect(new sf::RectangleShape());
	rect->setSize(sf::Vector2f(p2.x - p1.x, 0));
	//rect->setOrigin(rect->getSize() / 2.f);
	rect->setPosition(sf::Vector2f(m_b2Body->GetPosition().x * SCALE + offset.x, m_b2Body->GetPosition().y * SCALE + offset.y));
	sf::Vector2f direction = p2 - p1;
	float rotation = std::atan2f(direction.y, direction.x) * 180.f / b2_pi;
	rect->setRotation(rotation);
	rect->setFillColor(sf::Color(sf::Color::Transparent));
	if (!isSensor)
		rect->setOutlineColor(sf::Color::Red);
	else
		rect->setOutlineColor(sf::Color::Blue);
	rect->setOutlineThickness(1);

	this->addRect(std::move(rect), offset);

	return true;
}

bool PhysicalBody::AddFixtureCircle(sf::Vector2f offset, float radius, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	b2CircleShape shape;
	shape.m_radius = radius / SCALE;
	shape.m_p.Set(offset.x / SCALE, offset.y / SCALE);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);

	std::unique_ptr<sf::CircleShape> rect(new sf::CircleShape());
	rect->setRadius(radius);
	rect->setOrigin(sf::Vector2f(radius, radius));
	rect->setPosition(sf::Vector2f(m_b2Body->GetPosition().x * SCALE + offset.x, m_b2Body->GetPosition().y * SCALE + offset.y));
	rect->setFillColor(sf::Color(sf::Color::Transparent));
	if (!isSensor)
		rect->setOutlineColor(sf::Color::Red);
	else
		rect->setOutlineColor(sf::Color::Blue);
	rect->setOutlineThickness(1);

	this->addRect(std::move(rect), offset);

	return true;
}

bool PhysicalBody::AddFixturePolygon(sf::Vector2f offset, std::vector<sf::Vector2f> points, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	b2Vec2* vertices = new b2Vec2[points.size()];//delete ?
	for (size_t i = 0; i < points.size(); i++) {
		vertices[i].Set((points[i].x + offset.x) / SCALE, (points[i].y + offset.y) / SCALE);
	}

	b2PolygonShape shape;
	shape.Set(vertices, (int32)points.size());

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);

	std::unique_ptr<sf::ConvexShape> debugShape(new sf::ConvexShape());
	debugShape->setPointCount(points.size());
	for (size_t i = 0; i < points.size(); i++) {
		debugShape->setPoint(i, points[i]);
	}
	debugShape->setPosition(sf::Vector2f(m_b2Body->GetPosition().x * SCALE + offset.x, m_b2Body->GetPosition().y * SCALE + offset.y));
	debugShape->setFillColor(sf::Color(sf::Color::Transparent));
	if (!isSensor)
		debugShape->setOutlineColor(sf::Color::Red);
	else
		debugShape->setOutlineColor(sf::Color::Blue);
	debugShape->setOutlineThickness(1);

	this->addRect(std::move(debugShape), offset);

	return true;
}

void PhysicalBody::clearBody()
{
	if (m_b2Body) {
		m_b2Body->SetUserData(nullptr);
		m_b2Body->GetWorld()->DestroyBody(m_b2Body);
		m_b2Body = nullptr;
	}
}

sf::Vector2f PhysicalBody::getPosition() const
{
	if (m_b2Body) {
		return sf::Vector2f(m_b2Body->GetPosition().x * SCALE, m_b2Body->GetPosition().y * SCALE);
	}

	return sf::Vector2f(0.f, 0.f);
}

float PhysicalBody::getRotation() const
{
	if (m_b2Body) {
		return m_b2Body->GetAngle() * 180.f / b2_pi;
	}

	return 0.f;
}

