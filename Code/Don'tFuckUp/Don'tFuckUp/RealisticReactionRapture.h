#ifndef REALISTICREACTIONRAPTURE_H
#define REALISTICREACTIONRAPTURE_H

#include "Scene.h"
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class RealisticReactionRapture
{
    enum Keys
    {
        PRESS_W = 1,
        PRESS_A,
        PRESS_S,
        PRESS_D,
    };

    //Constants
    const int PLAYER_SPEED = 100.0f;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    RealisticReactionRapture();
    void Run();

private:
    void ProcessEvents();
    void Update(sf::Time delta);
    void Render();
    void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    int Random(int min, int max);

private:
    sf::RenderWindow m_Window;
    sf::Texture m_Texture;
    sf::Sprite m_Player;
    sf::Font m_Font;
    sf::Text m_Text;
    sf::Text m_TimerText;
    sf::Text m_RandomText;

    // Member Variables
    bool m_IsMovingUp;
    bool m_IsMovingDown;
    bool m_IsMovingLeft;
    bool m_IsMovingRight;
    bool m_HasWon;
    unsigned short m_Timer;
    unsigned short m_Random;
    unsigned short m_RandomTime;
};

#endif // GAME_H