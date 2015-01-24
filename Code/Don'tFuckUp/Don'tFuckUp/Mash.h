#ifndef MASH_H
#define MASH_H

#include "Scene.h"
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class Mash
{
    //Constants
    const int PLAYER_SPEED = 100.0f;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    Mash();
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
    sf::Font m_Font;
    sf::Text m_Mash;
    sf::Text m_Timer;
    sf::Text m_WinLose;

    // Member Variables
    bool m_IsMovingUp;
    bool m_IsMovingDown;
    bool m_IsMovingLeft;
    bool m_IsMovingRight;

    int m_numMash;
    int m_timer;

};

#endif // GAME_H