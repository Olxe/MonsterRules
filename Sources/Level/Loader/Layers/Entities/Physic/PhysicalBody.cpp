#include "PhysicalBody.h"

PhysicalBody::PhysicalBody(sf::Vector2f position, float rotation, b2BodyType bodyType, bool rotationFixed, void* userData)
	: m_b2Body(nullptr)
	, SCALE(30.f)
{
	this->Create(position, rotation, bodyType, rotationFixed, userData);
}

PhysicalBody::~PhysicalBody()
{
	clearBody();
}

void PhysicalBody::onUpdate()
{
	m_transform = sf::Transform().rotate(this->getRotation(), this->getPosition());
	for (auto& it : m_shapes) {
		it->setPosition(this->getPosition());
	}
}

void PhysicalBody::onDebugDraw(sf::RenderWindow& window)
{
	if (m_b2Body) {
		for (auto& it : m_shapes) {
			window.draw(*it, m_transform);
		}
	}
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
}

bool PhysicalBody::AddFixtureRectangle(sf::Vector2f offset, sf::Vector2f size, float rotation, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	offset += size / 2.f;

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
	rect->setRotation(rotation);
	rect->setFillColor(sf::Color(sf::Color::Transparent));
	if(!isSensor)
		rect->setOutlineColor(sf::Color::Red);
	else
		rect->setOutlineColor(sf::Color::Blue);
	rect->setOutlineThickness(1);
	
	m_shapes.push_back(std::unique_ptr<debug::Shape>(new debug::Shape(std::move(rect), offset)));
	m_shapes.back()->setPosition(this->getPosition());

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

	std::unique_ptr<sf::VertexArray> line(new sf::VertexArray(sf::Lines, 2));
	(*line)[0].position = p1 + offset;
	(*line)[1].position = p2 + offset;
	(*line)[0].color = sf::Color::Red;
	(*line)[1].color = sf::Color::Red;

	m_shapes.push_back(std::unique_ptr<debug::Line>(new debug::Line(std::move(line))));
	m_shapes.back()->setPosition(this->getPosition());

	return true;
}

bool PhysicalBody::AddFixtureCircle(sf::Vector2f offset, float radius, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	offset += sf::Vector2f(radius, radius);

	b2CircleShape shape;
	shape.m_radius = radius / SCALE;
	shape.m_p.Set(offset.x / SCALE, offset.y / SCALE);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);

	std::unique_ptr<sf::CircleShape> circle(new sf::CircleShape());
	circle->setRadius(radius);
	circle->setOrigin(sf::Vector2f(radius, radius));
	circle->setFillColor(sf::Color(sf::Color::Transparent));
	if (!isSensor)
		circle->setOutlineColor(sf::Color::Red);
	else
		circle->setOutlineColor(sf::Color::Blue);
	circle->setOutlineThickness(1);

	m_shapes.push_back(std::unique_ptr<debug::Shape>(new debug::Shape(std::move(circle), offset)));
	m_shapes.back()->setPosition(this->getPosition());

	return true;
}

bool PhysicalBody::AddFixturePolygon(sf::Vector2f offset, std::vector<sf::Vector2f> points, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	b2Vec2* vertices = new b2Vec2[points.size()];
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

	std::unique_ptr<sf::ConvexShape> polygon(new sf::ConvexShape());
	polygon->setPointCount(points.size());
	for (size_t i = 0; i < points.size(); i++) {
		polygon->setPoint(i, points[i]);
	}
	polygon->setFillColor(sf::Color(sf::Color::Transparent));
	if (!isSensor)
		polygon->setOutlineColor(sf::Color::Red);
	else
		polygon->setOutlineColor(sf::Color::Blue);
	polygon->setOutlineThickness(1);

	m_shapes.push_back(std::unique_ptr<debug::Shape>(new debug::Shape(std::move(polygon), offset)));
	m_shapes.back()->setPosition(this->getPosition());

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

	return sf::Vector2f();
}

float PhysicalBody::getRotation() const
{
	if (m_b2Body) {
		return m_b2Body->GetAngle() * 180.f / b2_pi;
	}

	return 0.f;
}

