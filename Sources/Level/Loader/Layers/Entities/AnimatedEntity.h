#pragma once

#include <functional>

#include "Animation.h"

namespace entities
{
	class AnimatedEntity
	{
	public:
		AnimatedEntity(sf::Sprite* sprite = nullptr);
		~AnimatedEntity();

		void setSprite(sf::Sprite* sprite);
		void setCallBack(std::function<void(const std::string & name, const std::string & type)> callBack) { m_callBack = callBack; }
		const std::string& getType() const { return m_type; }
		bool Add(std::string name, const sf::Texture* texture, sf::Vector2i frameSize, float frameTime, std::vector<sf::Vector2i> framePos);
		bool Start(const std::string& name, bool looped = true, const std::string& type = "");
		bool Update(const float& deltaTime);

	private:
		sf::Sprite* m_sprite;
		std::vector<std::unique_ptr<Animation>> m_animations;
		Animation* m_currentAnimation;
		float m_currentTime;
		size_t m_currentFrame;
		bool isLooped;
		std::string m_type;
		std::function<void(const std::string & name, const std::string & type)> m_callBack;
	};
}

