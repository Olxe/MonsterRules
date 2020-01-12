#include "CEntity.hpp"

namespace entities
{
	CEntity::CEntity(Builder::SceneObject* obj)
		: m_id(0)
	{	
		sf::Texture* texture = AssetManager::Instance()->GetTexture(obj->GetTile()->getSource());
		texture->setSmooth(true);
		this->setTexture(*texture);
		this->setTextureRect(sf::IntRect(0, 0, (int)obj->GetTile()->getSize().x, (int)obj->GetTile()->getSize().y));

		this->setup(obj->getPosition(), obj->GetTile()->getSize(), obj->getRotation());

		m_type = obj->GetTile()->getType();
		m_name = obj->getName();
	}

	CEntity::CEntity(Builder::ObjectTemplate* obj)
	{
		m_name = obj->getName();
	}

	CEntity::~CEntity()
	{
	}

	void CEntity::onDraw(sf::RenderWindow& window) const
	{
		window.draw(*this);
	}

	void CEntity::setup(sf::Vector2f position, sf::Vector2f size, float rotation)
	{
		this->setOrigin(size / 2.f);
		this->setPosition(position);
		this->setRotation(rotation);
		this->move(this->transformOffsetPoint(sf::Vector2f(this->getOrigin().x, -this->getOrigin().y), this->getRotation()));

		this->setPosition(std::floor(this->getPosition().x), std::floor(this->getPosition().y));
	}

	sf::Vector2f CEntity::transformOffsetPoint(sf::Vector2f offset, float rotation)
	{
		sf::Transform transform;
		transform.rotate(rotation);
		sf::Vector2f offsetTransformed = transform.transformPoint(offset);
		return offsetTransformed;
	}
}