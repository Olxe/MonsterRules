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

bool PhysicalBody::AddFixtureEdge(sf::Vector2f p1, sf::Vector2f p2, float density, bool isSensor)
{
	return false;
}

/*bool PhysicalBody::AddFixturePolygon(sf::Vector2f offset, const std::vector<Point>& points, float density, bool isSensor)
{
	return false;
}*/

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

