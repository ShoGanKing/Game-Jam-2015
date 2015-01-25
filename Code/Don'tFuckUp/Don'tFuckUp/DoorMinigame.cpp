#include "DoorMinigame.h"
#include <sstream>
#include <random>

using namespace std;

DoorMinigame::DoorMinigame() : m_Window(sf::VideoMode(1600, 900),
    "SFML Application"),
    m_Texture(),
    m_Player(),
    m_Font(),
    m_Text(),
    m_Text_A(),
    m_Text_W(),
    m_Text_D(),
    m_TimerText(),
    m_IsMovingDown(false),
    m_IsMovingUp(false),
    m_IsMovingLeft(false),
    m_IsMovingRight(false),
    m_IsGameOver(false),
    m_RandomNumber(0),
    m_Max(0),
    m_Timer(240)
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
    m_Text.setPosition(250, 300);

    m_Text_A.setString("A");
    m_Text_A.setFont(m_Font);
    m_Text_A.setCharacterSize(300);
    m_Text_A.setPosition(100, 0);

    m_Text_W.setString("W");
    m_Text_W.setFont(m_Font);
    m_Text_W.setCharacterSize(300);
    m_Text_W.setPosition(650, 0);

    m_Text_D.setString("D");
    m_Text_D.setFont(m_Font);
    m_Text_D.setCharacterSize(300);
    m_Text_D.setPosition(1300, 0);

    m_TimerText.setFont(m_Font);
    m_TimerText.setCharacterSize(300);
    m_TimerText.setPosition(0, 590);

    m_Max = MAX1;
} // end of Game()

void DoorMinigame::Run()
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

void DoorMinigame::ProcessEvents() // Input()
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

void DoorMinigame::Update(sf::Time aDelta)
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

    if (m_Timer != 0 && m_IsGameOver == false)
    {
        m_Timer--;

        if (m_Timer == 0)
        {
            m_Text.setString("You lose");
            m_Text_W.setString(" ");
            m_Text_A.setString(" ");
            m_Text_D.setString(" ");
        }
    }

    stringstream tt;

    tt << (m_Timer + 59) / 60;

    string std = tt.str();

    m_TimerText.setString(std);

    m_Player.move(movement * aDelta.asSeconds());
} // end of Update(sf::Time aDelta)

void DoorMinigame::Render() // Draw()
{
    if (m_RandomNumber == RIGHTDOOR)
    {
        m_Text.setString("You win");
        m_Text_W.setString(" ");
        m_Text_A.setString(" ");
        m_Text_D.setString(" ");
        m_IsGameOver = true;
    }
    else if (m_RandomNumber == FAILDOOR)
    {
        m_Text.setString("You lose");
        m_Text_W.setString(" ");
        m_Text_A.setString(" ");
        m_Text_D.setString(" ");
        m_IsGameOver = true;
    }
    else if (m_RandomNumber == BRICKDOOR)
    {
        m_Text.setString("Try again quick!!");
    }

    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.draw(m_Text);
    m_Window.draw(m_Text_A);
    m_Window.draw(m_Text_W);
    m_Window.draw(m_Text_D);
    m_Window.draw(m_TimerText);
    m_Window.display();
} // end of Render()

void DoorMinigame::HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)
{
    if (m_IsGameOver == false)
    {
        if (aKey == sf::Keyboard::W && m_KeyNotActive != KEY_W)
        {
            m_RandomNumber = random(MIN, m_Max);
            m_KeyNotActive = KEY_W;
            m_Max = MAX2;
            m_Text_W.setString(" ");
        }
        else if (aKey == sf::Keyboard::S)
        {

        }
        else if (aKey == sf::Keyboard::A && m_KeyNotActive != KEY_A)
        {
            m_RandomNumber = random(MIN, m_Max);
            m_KeyNotActive = KEY_A;
            m_Max = MAX2;
            m_Text_A.setString(" ");
        }
        else if (aKey == sf::Keyboard::D && m_KeyNotActive != KEY_D)
        {
            m_RandomNumber = random(MIN, m_Max);
            m_KeyNotActive = KEY_D;
            m_Max = MAX2;
            m_Text_D.setString(" ");
        }
    }
} // end of HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)

int DoorMinigame::random(int min, int max)
{
    static bool initialized = false;
    if (!initialized)
    {
        std::srand(std::time(0));
        initialized = true;
    }

    return rand() % (max - min + 1) + min;
}