#include "Button.hpp"

namespace gui
{
	Button::Button(const sf::Texture* texture, const sf::Vector2f& position, const std::string& label, std::function<void(void)> callback)
		: Widget()
		, m_pressed(false)
	{
		m_body.setSize((sf::Vector2f)texture->getSize());
		m_body.setTexture(texture);
		m_body.setOrigin(m_body.getSize() / 2.f);
		m_body.setPosition(position);

		m_label.setString(label);
		m_label.setFont(*AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"));
		m_label.setCharacterSize(48);
		m_label.setStyle(sf::Text::Bold);
		m_label.setFillColor(sf::Color::White);

		sf::FloatRect r = m_label.getLocalBounds();
		m_label.setOrigin(r.left + std::round(r.width / 2.f), r.top + std::round(r.height / 2.f));
		m_label.setPosition(m_body.getPosition());

		this->setCallback(callback);
	}

	Button::~Button()
	{
	}

	void Button::onStateChanged(State state)
	{
	}

	void Button::onMouseMoved(float x, float y)
	{
	}

	void Button::onMouseButtonPressed(int x, int y)
	{
	}

	void Button::onMouseButtonReleased(int x, int y)
	{
		if (m_body.getGlobalBounds().contains((float)x, (float)y)) {
			this->TriggerCallback();
		}
	}

	void Button::onKeyPressed(const sf::Event::KeyEvent& key)
	{
	}

	void Button::onKeyReleased(const sf::Event::KeyEvent& key)
	{
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
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