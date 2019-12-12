#include "Entity.hpp"

namespace entities
{
	Entity::Entity(Builder::Object* obj, int id)
		: m_id(id)
	{
		this->setSize(sf::Vector2f(obj->GetWidth(), obj->GetHeight()));
		this->setOrigin(this->getSize() / 2.f);
		this->setPosition(sf::Vector2f(obj->GetX(), obj->GetY()));
		this->setRotation(obj->GetRotation());
		this->move(this->transformOffsetPoint(sf::Vector2f(this->getOrigin().x, -this->getOrigin().y), this->getRotation()));
		m_name = obj->GetName();

		if (Builder::SceneObject* sceneObj = dynamic_cast<Builder::SceneObject*>(obj)) {
			if (Builder::Tile* tile = sceneObj->GetTile()) {
				this->setTexture(AssetManager::Instance()->GetTexture(tile->GetSource()));
				m_type = tile->GetType();
			}
		}
	}

	Entity::~Entity()
	{
	}

	void Entity::onUpdate(const float& deltaTime)
	{
	}

	void Entity::onDraw(sf::RenderWindow& window)
	{
		window.draw(*this);
	}

	sf::Vector2f Entity::transformOffsetPoint(sf::Vector2f offset, float rotation)
	{
		sf::Transform transform;
		transform.rotate(rotation);
		sf::Vector2f offsetTransformed = transform.transformPoint(offset);

		return offsetTransformed;
	}
	
}