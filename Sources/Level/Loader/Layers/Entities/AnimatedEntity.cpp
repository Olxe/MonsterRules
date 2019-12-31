#include "AnimatedEntity.h"

namespace entities
{
	AnimatedEntity::AnimatedEntity(sf::Sprite* sprite)
		: m_sprite(sprite)
		, m_currentAnimation(nullptr)
		, m_currentTime(0.f)
		, m_currentFrame(0)
		, isLooped(false)
		, isActived(false)
	{
	}

	AnimatedEntity::~AnimatedEntity()
	{
	}

	void AnimatedEntity::setSprite(sf::Sprite* sprite)
	{
		m_sprite = sprite;
	}

	void AnimatedEntity::Add(std::string name, const sf::Texture* texture, sf::Vector2i frameSize, float frameTime, std::vector<sf::Vector2i> framePos)
	{
		m_animations.push_back(std::make_unique<Animation>(name, texture, framePos, frameSize, frameTime));
	}

	bool AnimatedEntity::Start(const std::string& name, const std::string& type, bool looped, bool reseted)
	{
		for (auto& animation : m_animations) {
			if (animation->Name() == name) {
				if (!m_currentAnimation || m_currentAnimation->Name() != name) {
					m_currentAnimation = animation.get();

					if (m_sprite && m_currentAnimation && m_currentAnimation->Size() > 0) {
						isLooped = looped;
						m_type = type;
						m_sprite->setTexture(*m_currentAnimation->Texture());

						if (reseted) {
							this->Stop();
						}
						m_sprite->setTextureRect(m_currentAnimation->Frame(m_currentFrame - 1));
					
						this->Start();

						return true;
					}
				}
			}
		}

		return false;
	}

	void AnimatedEntity::Update(const float& deltaTime)
	{
		if (m_currentAnimation && isActived) {
			m_currentTime += deltaTime;

			while (m_currentTime >= m_currentAnimation->FrameDuration()) {
				m_currentTime -= m_currentAnimation->FrameDuration();

				if (m_currentFrame >= m_currentAnimation->Size()) {
					this->m_callBack(m_currentAnimation->Name(), m_type);
					if (isLooped) {
						m_currentFrame = 0;
					}
					else {
						isActived = false;
					}
				}

				if (isActived && m_sprite) {
					m_currentFrame++;
					m_sprite->setTextureRect(m_currentAnimation->Frame(m_currentFrame - 1));
				}
			}
		}
	}

	void AnimatedEntity::Stop()
	{
		m_currentFrame = 1;
		m_currentTime = 0;
		isActived = false;
	}

	void AnimatedEntity::Start()
	{
		isActived = true;
	}
}