#include "Mash.h"
#include <sstream>
#include <random>

using namespace std;

Mash::Mash() : m_Window(sf::VideoMode(1600, 900),
    "SFML Application"),
    m_Texture(),
    m_Player(),
    m_IsMovingDown(false),
    m_IsMovingUp(false),
    m_IsMovingLeft(false),
    m_IsMovingRight(false),
    m_IsDown(false),
    m_numMash(0),
    m_timer(240),
    m_Timer(),
    m_WinLose(),
    m_Font(),
    m_Mash()
{
    if (!m_Texture.loadFromFile("../../../Assets/Models/Vivi.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
    }

    //gets the font for the text
    if (!m_Font.loadFromFile("../../../Assets/Arial.ttf"));
    {

    }

    //setting up the mash counter to count your mashes
    m_Mash.setFont(m_Font);
    m_Mash.setCharacterSize(500);
    m_Mash.setPosition(-100, -100);

    //setting up the win/lose message
    m_WinLose.setFont(m_Font);
    m_WinLose.setCharacterSize(500);
    m_WinLose.setPosition(0, 300);

    //setting up the time counter
    m_Timer.setFont(m_Font);
    m_Timer.setCharacterSize(500);
    m_Timer.setPosition(100, 200);

    m_Player.setTexture(m_Texture);
    m_Player.setPosition(100.0f, 100.0f);
} // end of Game()

void Mash::Run()
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

void Mash::ProcessEvents() // Input()
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

void Mash::Update(sf::Time aDelta)
{
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

    //this is all for the countdown for timer then it checks if you hit the amount of mashes to display if you won or lost.
    if (m_timer != 0)
    {
        m_timer--;

        if (m_timer == 0)
        {
            if (m_numMash != 100)
            {
                m_WinLose.setString("You Lose!");
            }

            else
            {
                m_WinLose.setString("You Win!");
            }
        }
    }

    //converts int to string
    stringstream ss;
    stringstream tt;

    tt << m_timer;

    string std = tt.str();

    m_Timer.setString(std);

    ss << m_numMash;

    string str = ss.str();

    m_Mash.setString(str);

    m_Player.move(movement * aDelta.asSeconds());
} // end of Update(sf::Time aDelta)

void Mash::Render() // Draw()
{
    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.draw(m_Mash);
    m_Window.draw(m_Timer);
    m_Window.draw(m_WinLose);
    m_Window.display();
} // end of Render()

void Mash::HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)
{     
    if (aIsPressed == false)
    {
        m_IsDown = false;
    }
    if (aKey == sf::Keyboard::W && aIsPressed == true && m_IsDown == false)
    {
        m_IsDown = true;
        m_IsMovingUp = aIsPressed;
        //incrementing the mashes
        m_numMash++;
    }
   
    else if (aKey == sf::Keyboard::S && aIsPressed == true && m_IsDown == false)
    {
        m_IsDown = true;
        m_IsMovingDown = aIsPressed;
        //incrementing the mashes
        m_numMash++;
    }
    else if (aKey == sf::Keyboard::A && aIsPressed == true && m_IsDown == false)
    {
        m_IsDown = true;
        m_IsMovingLeft = aIsPressed;
        //incrementing the mashes
        m_numMash++;
    }
    else if (aKey == sf::Keyboard::D && aIsPressed == true && m_IsDown == false)
    {
        m_IsDown = true;
        m_IsMovingRight = aIsPressed;
        //incrementing the mashes
        m_numMash++;
    }
}

