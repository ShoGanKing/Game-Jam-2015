#ifndef CRAZYCOOKINGCOORDINATION_H
#define CRAZYCOOKINGCOORDINATION_H

#include "Scene.h"
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class Coordination
{
    enum
    {
        PRESS_W = 1,
        PRESS_A,
        PRESS_S,
        PRESS_D,
        PRESSUP,
        PRESSLEFT,
        PRESSDOWN,
        PRESSRIGHT
    };
    //Constants
    const int PLAYER_SPEED = 100.0f;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    Coordination();
    void Run();

private:
    void ProcessEvents();
    void Update(sf::Time delta);
    void Render();
    void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    int random(int min, int max);

private:
    sf::RenderWindow m_Window;
    sf::Texture m_Texture;
    sf::Sprite m_Player;
    sf::Font m_Font;
    sf::Text m_Text;
    sf::Text m_TimerText;
    sf::Text m_Button1;
    sf::Text m_Button2;
    sf::Text m_PointsText;

    // Member Variables
    bool m_IsMovingUp;
    bool m_IsMovingDown;
    bool m_IsMovingLeft;
    bool m_IsMovingRight;
    int m_Timer;
    unsigned short m_RandomNum1;
    unsigned short m_RandomNum2;
    unsigned short m_Points1;
    unsigned short m_Points2;
    bool m_IsGameOver;
};

#endif