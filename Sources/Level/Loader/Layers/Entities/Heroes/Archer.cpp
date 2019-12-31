#include "Archer.h"

namespace entities
{
	Archer::Archer(Builder::SceneObject* obj)
		: Hero(obj)
	{		
		sf::Vector2i frameSize = sf::Vector2i((int)obj->GetTile()->GetWidth(), (int)obj->GetTile()->GetHeight());
		m_animations.setSprite(this);

		m_animations.Add("WALK_BACK", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 12), sf::Vector2i(1, 12), sf::Vector2i(2, 12), sf::Vector2i(3, 12) });
		m_animations.Add("WALK_FRONT", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 13), sf::Vector2i(1, 13), sf::Vector2i(2, 13), sf::Vector2i(3, 13) });
		m_animations.Add("WALK_LEFT", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 14), sf::Vector2i(1, 14), sf::Vector2i(2, 14), sf::Vector2i(3, 14) });
		m_animations.Add("WALK_RIGHT", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 15), sf::Vector2i(1, 15), sf::Vector2i(2, 15), sf::Vector2i(3, 15) });

		m_animations.Add("IDLE_BACK", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 4), sf::Vector2i(1, 4), sf::Vector2i(2, 4), sf::Vector2i(3, 4) });
		m_animations.Add("IDLE_FRONT", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 5), sf::Vector2i(1, 5), sf::Vector2i(2, 5), sf::Vector2i(3, 5) });
		m_animations.Add("IDLE_LEFT", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 6), sf::Vector2i(1, 6), sf::Vector2i(2, 6), sf::Vector2i(3, 6) });
		m_animations.Add("IDLE_RIGHT", this->getTexture(), frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 7), sf::Vector2i(1, 7), sf::Vector2i(2, 7), sf::Vector2i(3, 7) });

		m_animations.Add("ATTACK_BACK", this->getTexture(), frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 8), sf::Vector2i(1, 8), sf::Vector2i(2, 8), sf::Vector2i(3, 8) });
		m_animations.Add("ATTACK_FRONT", this->getTexture(), frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 9), sf::Vector2i(1, 9), sf::Vector2i(2, 9), sf::Vector2i(3, 9) });
		m_animations.Add("ATTACK_LEFT", this->getTexture(), frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 10), sf::Vector2i(1, 10), sf::Vector2i(2, 10), sf::Vector2i(3, 10) });
		m_animations.Add("ATTACK_RIGHT", this->getTexture(), frameSize, 0.09f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 11), sf::Vector2i(1, 11), sf::Vector2i(2, 11), sf::Vector2i(3, 11) });

		m_animations.Add("HURT_BACK", this->getTexture(), frameSize, 0.3f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 3) });
		m_animations.Add("HURT_FRONT", this->getTexture(), frameSize, 0.3f, std::vector<sf::Vector2i>{ sf::Vector2i(1, 3) });
		m_animations.Add("HURT_LEFT", this->getTexture(), frameSize, 0.3f, std::vector<sf::Vector2i>{ sf::Vector2i(2, 3) });
		m_animations.Add("HURT_RIGHT", this->getTexture(), frameSize, 0.3f, std::vector<sf::Vector2i>{sf::Vector2i(3, 3) });

		m_animations.Add("DEAD_BACK", this->getTexture(), frameSize, 0.1f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0) });
		m_animations.Add("DEAD_FRONT", this->getTexture(), frameSize, 0.1f, std::vector<sf::Vector2i>{ sf::Vector2i(3, 0), sf::Vector2i(0, 1), sf::Vector2i(1, 1) });
		m_animations.Add("DEAD_LEFT", this->getTexture(), frameSize, 0.1f, std::vector<sf::Vector2i>{ sf::Vector2i(2, 1), sf::Vector2i(3, 1), sf::Vector2i(0, 2) });
		m_animations.Add("DEAD_RIGHT", this->getTexture(), frameSize, 0.1f, std::vector<sf::Vector2i>{sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(3, 2) });

		m_animations.Start("IDLE_FRONT");
	}

	Archer::~Archer()
	{
	}
}