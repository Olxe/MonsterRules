#include "Animation.h"

namespace entities
{
	Animation::Animation(std::string name, const sf::Texture* texture, std::vector<sf::Vector2i> framesPos, sf::Vector2i frameSize, float frameDuration)
		: m_name(name)
		, m_texture(texture)
		, m_frameDuration(frameDuration)
	{
		for (auto pos : framesPos) {
			m_frame.push_back(sf::IntRect(sf::Vector2i(pos.x*frameSize.x, pos.y*frameSize.y), frameSize));
		}
	}

	Animation::~Animation()
	{
	}
}