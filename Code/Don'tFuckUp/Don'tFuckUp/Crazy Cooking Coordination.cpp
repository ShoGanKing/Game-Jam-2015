#include "Crazy Cooking Coordination.h"
#include <sstream>

using namespace std;
//
//Crazy
//Cooking
//Coodination
//Game
//
Coordination::Coordination() : m_Window(sf::VideoMode(1600, 900),
    "SFML Application"),
    m_Texture(),
    m_Player(),
    m_Font(),
    m_Text(),
    m_TimerText(),
    m_Button1(),
    m_IsMovingDown(false),
    m_IsMovingUp(false),
    m_IsMovingLeft(false),
    m_IsMovingRight(false),
    m_Timer(240),
    m_RandomNum1(0),
    m_RandomNum2(0),
    m_Points1(0),
    m_Points2(0)
{
    if (!m_Texture.loadFromFile("../../../Assets/Models/Vivi.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
    }

    if (!m_Font.loadFromFile("../../../Assets/Arial.ttf"))
    {

    }

    m_Player.setTexture(m_Texture);
    m_Player.setPosition(100.0f, 100.0f);

    m_Text.setFont(m_Font);
    m_Text.setCharacterSize(300);
    m_Text.setPosition(250, 200);

    m_TimerText.setFont(m_Font);
    m_TimerText.setCharacterSize(300);
    m_TimerText.setPosition(0, 590);

    m_Button1.setFont(m_Font);
    m_Button1.setCharacterSize(150);

    m_Button2.setFont(m_Font);
    m_Button2.setCharacterSize(150);
    m_Button2.setPosition(800, 0);

    m_RandomNum1 = random(1, 4);
    m_RandomNum2 = random(5, 8);

} // end of Game()

void Coordination::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (m_Window.isOpen())
    {
        ProcessEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            ProcessEvents();
            Update(TIME_PER_FRAME);
        }
        Render();
    }
} // end of Run()

void Coordination::ProcessEvents() // Input()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            HandlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            HandlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            m_Window.close();
            break;

        }

    }
} // end of ProcessEvents()

void Coordination::Update(sf::Time aDelta)
{
    //WASD buttons
    if (m_RandomNum1 == PRESS_W)
    {
        m_Button1.setString("Press W");
    }
    else if (m_RandomNum1 == PRESS_A)
    {
        m_Button1.setString("Press A");
    }
    else if (m_RandomNum1 == PRESS_S)
    {
        m_Button1.setString("Press S");
    }
    else if (m_RandomNum1 == PRESS_D)
    {
        m_Button1.setString("Press D");
    }
    //Arrow buttons
    if (m_RandomNum2 == PRESSUP)
    {
        m_Button2.setString("Press Up");
    }
    else if (m_RandomNum2 == PRESSLEFT)
    {
        m_Button2.setString("Press Left");
    }
    else if (m_RandomNum2 == PRESSDOWN)
    {
        m_Button2.setString("Press Down");
    }
    else if (m_RandomNum2 == PRESSRIGHT)
    {
        m_Button2.setString("Press Right");
    }

    sf::Vector2f movement(0.0f, 0.0f);
    if (m_IsMovingUp)
    {
        movement.y -= PLAYER_SPEED; // Inverted y axis for SFML...
    }
    if (m_IsMovingDown)
    {
        movement.y += PLAYER_SPEED;
    }
    if (m_IsMovingLeft)
    {
        movement.x -= PLAYER_SPEED;
    }
    if (m_IsMovingRight)
    {
        movement.x += PLAYER_SPEED;
    }

    if (m_Timer != 0)
    {
        m_Timer--;

        if (m_Points1 >= 4 && m_Points2 >= 4)
        {
            m_Text.setString("You win");
        }
        else if (m_Timer == 0)
        {
            m_Text.setString("You lose");
        }
    }

    stringstream tt;

    tt << m_Timer;

    string std = tt.str();

    m_TimerText.setString(std);

    m_Player.move(movement * aDelta.asSeconds());
} // end of Update(sf::Time aDelta)

void Coordination::Render() // Draw()
{
    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.draw(m_Text);
    m_Window.draw(m_TimerText);
    m_Window.draw(m_Button1);
    m_Window.draw(m_Button2);
    m_Window.display();
} // end of Render()

void Coordination::HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)
{
    //WASD keys
    if (aKey == sf::Keyboard::W && aIsPressed == true)
    {
        if (m_RandomNum1 == PRESS_W)
        {
            m_Points1++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum1 = random(1, 4);
    }
    else if (aKey == sf::Keyboard::S && aIsPressed == true)
    {
        if (m_RandomNum1 == PRESS_S)
        {
            m_Points1++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum1 = random(1, 4);
    }
    else if (aKey == sf::Keyboard::A && aIsPressed == true)
    {
        if (m_RandomNum1 == PRESS_A)
        {
            m_Points1++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum1 = random(1, 4);
    }
    else if (aKey == sf::Keyboard::D && aIsPressed == true)
    {
        if (m_RandomNum1 == PRESS_D)
        {
            m_Points1++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum1 = random(1, 4);
    }
    //Arrow keys
    else if (aKey == sf::Keyboard::Up && aIsPressed == true)
    {
        if (m_RandomNum2 == PRESSUP)
        {
            m_Points2++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum2 = random(5, 8);
    }
    else if (aKey == sf::Keyboard::Down && aIsPressed == true)
    {
        if (m_RandomNum2 == PRESSDOWN)
        {
            m_Points2++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum2 = random(5, 8);
    }
    else if (aKey == sf::Keyboard::Left && aIsPressed == true)
    {
        if (m_RandomNum2 == PRESSLEFT)
        {
            m_Points2++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum2 = random(5, 8);
    }
    else if (aKey == sf::Keyboard::Right && aIsPressed == true)
    {
        if (m_RandomNum2 == PRESSRIGHT)
        {
            m_Points2++;
        }
        else
        {
            m_Text.setString("You lose");
        }
        m_RandomNum2 = random(5, 8);
    }
} // end of HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)

int Coordination::random(int min, int max)
{
    static bool initialized = false;
    if (!initialized)
    {
        std::srand(std::time(0));
        initialized = true;
    }

    return rand() % (max - min + 1) + min;
}// end of random(int min, int max)