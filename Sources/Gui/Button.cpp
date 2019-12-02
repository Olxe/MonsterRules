#include "Button.hpp"

namespace gui
{
	Button::Button(const sf::Texture* texture, const sf::Vector2f& position, const std::string& label)
		: Widget()
		, m_label(label, *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 48, sf::Text::Bold, sf::Color::White, position)
		, m_pressed(false)
	{
		m_body.setSize((sf::Vector2f)texture->getSize());
		m_body.setTexture(texture);
		m_body.setOrigin(m_body.getSize() / 2.f);
		this->setPosition(position);
	}

	Button::~Button()
	{
	}

	void Button::setPosition(const sf::Vector2f& position)
	{
		Widget::setPosition(position);
		m_label.setPosition(position);
	}

	void Button::onMouseMoved(float x, float y)
	{
	}

	void Button::onMouseButtonPressed(float x, float y)
	{
	}

	void Button::onMouseButtonReleased(float x, float y)
	{
		this->MouseButtonReleasedCallback();
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_body, states);
		target.draw(m_label, states);
	}
	void Button::press()
	{
	}
	void Button::release()
	{
	}
}