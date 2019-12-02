#include "AssetManager.hpp"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

sf::Texture* AssetManager::GetTexture(const std::string& filename)
{
    auto it = m_textures.find(filename);
    if(it != m_textures.end()){
        return &(it->second);
    }
    sf::Texture& newTexture = m_textures[filename];
    newTexture.loadFromFile(filename);

    return &newTexture;
}

sf::SoundBuffer* AssetManager::GetSound(const std::string& filename)
{
    auto it = m_sounds.find(filename);
    if(it != m_sounds.end()){
        return &(it->second);
    }

    sf::SoundBuffer& newSound = m_sounds[filename];
    newSound.loadFromFile(filename);

    return &newSound;
}

sf::Font* AssetManager::GetFont(const std::string& filename)
{
    auto it = m_fonts.find(filename);
    if(it != m_fonts.end()){
        return &(it->second);
    }

    sf::Font& newFont = m_fonts[filename];
    newFont.loadFromFile(filename);

    return &newFont;
}