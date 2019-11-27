#include "Settings.h"

namespace Window
{
	Settings::Settings(const std::string& settingsFile)
	{
		this->SetSettings(settingsFile);
	}

	Settings::Settings()
	{
	}

	Settings::~Settings()
	{
	}

	void Settings::SetSettings(const std::string& settingsFile)
	{
		this->SetRenderWindowSettings(settingsFile);
		this->SetInputSettings(settingsFile);
	}

	void Settings::SetRenderWindowSettings(const std::string& windowFile)
	{
		SettingsParser settingsParser;
		if (settingsParser.loadFromFile(windowFile)) {
			settingsParser.get("width", m_sRenderWindow.videoMode.width);
			settingsParser.get("height", m_sRenderWindow.videoMode.height);
			settingsParser.get("bitsPerPixel", m_sRenderWindow.videoMode.bitsPerPixel);
			settingsParser.get("title", m_sRenderWindow.title);
			settingsParser.get("style", m_sRenderWindow.style);
			settingsParser.get("antialiasingLevel", m_sRenderWindow.contextSettings.antialiasingLevel);
			settingsParser.get("fps", m_sRenderWindow.fps);
			settingsParser.get("verticalSync", m_sRenderWindow.verticalSync);
		}
		else {
			Out("Error : ", "Settings file not found.");
		}
	}

	void Settings::SetInputSettings(const std::string& inputFile)
	{

	}
}