#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
    //Constants
    const int PLAYER_SPEED = 100.0f;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    Game();
    void Run();

private:
    void ProcessEvents();
    void Update(sf::Time delta);
    void Render();
    void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow m_Window;
    sf::Texture m_Texture;
    sf::Sprite m_Player;

    // Member Variables
    bool m_IsMovingUp;
    bool m_IsMovingDown;
    bool m_IsMovingLeft;
    bool m_IsMovingRight;

};

#endif // GAME_H