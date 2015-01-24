#ifndef GAMECOPY_H
#define GAMECOPY_H

#include <SFML/Graphics.hpp>

class SceneManager;

class GameCopy
{
    //Constants
    const int PLAYER_SPEED = 100.0f;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    GameCopy();
    ~GameCopy();
    void Run();

private:
    void ProcessEvents();
    void Update(sf::Time delta);
    void Render();
    void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow m_Window;
    SceneManager* m_SceneManager;
};

#endif // GAME_H