#include "GuiLayout.hpp"

namespace gui
{
	GuiLayout::GuiLayout(sf::RenderWindow& window)
		: m_window(window)
	{
	}

	GuiLayout::~GuiLayout()
	{
	}

	void GuiLayout::AddWidget(std::unique_ptr<gui::Widget> widget)
	{
		m_widgets.push_back(std::move(widget));
	}

	void GuiLayout::onEvent(sf::Event& event)
	{
		switch (event.type){
		case sf::Event::MouseMoved:{
			sf::Vector2f mousePosition = m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
			this->onMouseMoved(mousePosition.x, mousePosition.y);
			break;
		}

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left){
				sf::Vector2f mousePosition = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				this->onMouseButtonPressed(mousePosition.x, mousePosition.y);
			}
			break;

		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left){
				sf::Vector2f mousePosition = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				this->onMouseButtonReleased(mousePosition.x, mousePosition.y);
			}
			break;

		case sf::Event::MouseWheelMoved:
			this->onMouseWheelMoved(event.mouseWheel.delta);
			break;

		case sf::Event::KeyPressed:
			this->onKeyPressed(event.key);
			break;

		case sf::Event::KeyReleased:
			this->onKeyReleased(event.key);
			break;

		case sf::Event::TextEntered:
			this->onTextEntered(event.text.unicode);
			break;

		default:
			break;
		}
	}

	void GuiLayout::onMouseButtonReleased(float x, float y)
	{
		if (gui::Widget* fw = focus(sf::Vector2f(x, y))) {
			fw->onMouseButtonReleased(x, y);
		}
	}

	void GuiLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& it : m_widgets) {
			target.draw(*it, states);
		}
	}

	gui::Widget* GuiLayout::focus(const sf::Vector2f& mousePosition)
	{
		for (auto& it : m_widgets) {
			if (it->GlobalBounds().contains(mousePosition)) {
				return it.get();
			}
		}

		return nullptr;
	}
}