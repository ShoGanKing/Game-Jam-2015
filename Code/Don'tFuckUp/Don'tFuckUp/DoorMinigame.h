#ifndef DOORMINIGAME_H
#define DOORMINIGAME_H

#include <SFML/Graphics.hpp>

class DoorMinigame
{
    enum
    {
        RIGHTDOOR = 1, //The only right door the player can pick
        WRONGDOOR1,    //Both of the wrong doors the player can pick
        WRONGDOOR2     //^^
    };

    //Constants
    const int PLAYER_SPEED = 100.0f;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:
    DoorMinigame();
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


    // Member Variables
    bool m_IsMovingUp;
    bool m_IsMovingDown;
    bool m_IsMovingLeft;
    bool m_IsMovingRight;
    int m_RandomNumber;
};

#endif // DOORMINIGAME_H