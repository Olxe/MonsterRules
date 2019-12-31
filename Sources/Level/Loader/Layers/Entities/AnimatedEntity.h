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
		void Add(std::string name, const sf::Texture* texture, sf::Vector2i frameSize, float frameTime, std::vector<sf::Vector2i> framePos);
		bool Start(const std::string& name, const std::string& type = "DEFAULT", bool looped = true, bool reseted = true);
		void Update(const float& deltaTime);
		
		void setCallBack(std::function<void(const std::string & name, const std::string & type)> callBack) { m_callBack = callBack; }
		const std::string& getType() const { return m_type; }
		void Stop();
		void Start();
		bool Actived() const { return isActived; }
		bool Looped() const { return isLooped; }

	private:
		sf::Sprite* m_sprite;
		std::vector<std::unique_ptr<Animation>> m_animations;
		Animation* m_currentAnimation;
		float m_currentTime;
		size_t m_currentFrame;
		std::string m_type;
		std::function<void(const std::string & name, const std::string & type)> m_callBack;

		bool isLooped;
		bool isActived;
	};
}

