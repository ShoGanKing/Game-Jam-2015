#ifndef DOORMINIGAME_H
#define DOORMINIGAME_H

#include <SFML/Graphics.hpp>

class DoorMinigame
{
    enum Door
    {
        RIGHTDOOR = 1, //Player wins
        FAILDOOR,    //Player loses
        BRICKDOOR     //Player get 2nd chance
    };

    enum MinMax
    {
        MIN = 1,
        MAX2,
        MAX1
    };

    enum Keys
    {
        KEY_A = 1,
        KEY_W,
        KEY_D
    };

    //Constants
    const int PLAYER_SPEED = 100.0f;

    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    DoorMinigame();
    void Run();

    int random(int min, int max);
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
    sf::Text m_Text;
    sf::Text m_Text_A;
    sf::Text m_Text_W;
    sf::Text m_Text_D;
    sf::Text m_TimerText;

    // Member Variables
    bool m_IsMovingUp;
    bool m_IsMovingDown;
    bool m_IsMovingLeft;
    bool m_IsMovingRight;
    int m_RandomNumber;
    bool m_IsGameOver;
    unsigned short m_KeyNotActive;
    unsigned short m_Max;
    unsigned short m_Timer;
};

#endif // DOORMINIGAME_H