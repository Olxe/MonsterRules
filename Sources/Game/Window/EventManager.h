#ifndef __EVENTMANAGER__
#define __EVENTMANAGER__

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <map>
#include <iostream>

namespace Window
{
	class EventManager
	{
	public:
		EventManager();
		~EventManager();

	public:
		void Update(sf::RenderWindow* window);
		sf::Event* GetEvent(sf::Event::EventType eventType);
		bool IsEventTriggered(sf::Event::EventType eventType);

	private:
		std::map< sf::Event::EventType, sf::Event > m_event;

	};
}

#endif