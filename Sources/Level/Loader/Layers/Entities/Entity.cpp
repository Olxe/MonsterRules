#include "Entity.hpp"

namespace entities
{
	Entity::Entity(Builder::SceneObject* obj)
		: m_id(0)
	{	
		sf::Texture* texture = AssetManager::Instance()->GetTexture(obj->GetTile()->GetSource());
		texture->setSmooth(true);
		this->setTexture(*texture);
		this->setTextureRect(sf::IntRect(0, 0, (int)obj->GetTile()->GetWidth(), (int)obj->GetTile()->GetHeight()));

		this->setup(sf::Vector2f(obj->GetX(), obj->GetY()), sf::Vector2f(obj->GetTile()->GetWidth(), obj->GetTile()->GetHeight()), obj->GetRotation());

		m_type = obj->GetTile()->GetType();
		m_id = obj->getUniqueId();
		m_name = obj->GetName();
	}

	Entity::Entity(Builder::ObjectTemplate* obj)
	{
		//m_id = obj->getUniqueId();
		m_name = obj->GetName();
	}

	Entity::~Entity()
	{
	}

	void Entity::onDraw(sf::RenderWindow& window) const
	{
		window.draw(*this);
	}

	void Entity::setup(sf::Vector2f position, sf::Vector2f size, float rotation)
	{
		this->setOrigin(size / 2.f);
		this->setPosition(position);
		this->setRotation(rotation);
		this->move(this->transformOffsetPoint(sf::Vector2f(this->getOrigin().x, -this->getOrigin().y), this->getRotation()));

		this->setPosition(std::floor(this->getPosition().x), std::floor(this->getPosition().y));
	}

	sf::Vector2f Entity::transformOffsetPoint(sf::Vector2f offset, float rotation)
	{
		sf::Transform transform;
		transform.rotate(rotation);
		sf::Vector2f offsetTransformed = transform.transformPoint(offset);
		return offsetTransformed;
	}
}