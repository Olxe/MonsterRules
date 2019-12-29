#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

namespace entities
{
	class Animation
	{
	public:
		Animation(std::string name, const sf::Texture* texture, std::vector<sf::Vector2i> framesPos, sf::Vector2i frameSize, float frameDuration);
		~Animation();

		const std::string& Name() const { return m_name; }
		const sf::Texture* Texture() const { return m_texture; }
		const float& FrameDuration() const { return m_frameDuration; }
		const size_t Size() const { return m_frame.size(); }
		const sf::IntRect& Frame(size_t id) const { return m_frame[id]; }

	private:
		std::string m_name;
		const sf::Texture* m_texture;
		float m_frameDuration;
		std::vector<sf::IntRect> m_frame;
	};
}

