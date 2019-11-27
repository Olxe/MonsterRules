#ifndef __SETTINGS__
#define __SETTINGS__

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../Tools/ToolsFunction.h"
#include "../../Tools/SettingsParser.h"

namespace Window
{
	struct SRenderWindow
	{
		sf::VideoMode videoMode = sf::VideoMode(1920, 1080, 32);
		std::string title = "MonsterRules";
		sf::Uint32 style = sf::Style::Close;
		sf::ContextSettings contextSettings;
		unsigned int fps = 60;
		bool verticalSync = false;
	};

	class Settings
	{
	public:
		Settings(const std::string& settingsFile);
		Settings();
		~Settings();

	public:
		void SetSettings(const std::string& settingsFile);
		void SetRenderWindowSettings(const std::string& windowFile);
		void SetInputSettings(const std::string& inputFile);

		const SRenderWindow& GetRenderWindowSettings() const { return m_sRenderWindow; }

	private:
		SRenderWindow m_sRenderWindow;

	};
}

#endif