#ifndef __ASSETMANAGER__
#define __ASSETMANAGER__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Tools/Singleton.hpp"

class AssetManager: public Singleton<AssetManager>
{
	friend class Singleton< AssetManager >;

private:
    AssetManager();
    ~AssetManager();

public:
    sf::Texture* GetTexture(const std::string& filename);
    sf::SoundBuffer* GetSound(const std::string& filename);
    sf::Font* GetFont(const std::string& filename);

private:
    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::SoundBuffer> m_sounds;
    std::map<std::string, sf::Font> m_fonts;
};

#endif