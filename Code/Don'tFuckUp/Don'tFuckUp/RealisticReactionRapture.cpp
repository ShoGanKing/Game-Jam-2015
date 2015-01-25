#include "RealisticReactionRapture.h"
#include <sstream>

using namespace std;

RealisticReactionRapture::RealisticReactionRapture() : m_Window(sf::VideoMode(1600, 900),
    "SFML Application"),
    m_Texture(),
    m_Player(),
    m_Font(),
    m_Text(),
    m_TimerText(),
    m_RandomText(),
    m_IsMovingDown(false),
    m_IsMovingUp(false),
    m_IsMovingLeft(false),
    m_IsMovingRight(false),
    m_HasWon(false),
    m_Timer(240),
    m_Random(0),
    m_RandomTime(0)
{
    if (!m_Texture.loadFromFile("../../../Assets/Models/Vivi.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
    }

    if (!m_Font.loadFromFile("../../../Assets/Arial.ttf"))
    {

    }

    m_Text.setFont(m_Font); // win/lose
    m_Text.setCharacterSize(300);
    m_Text.setPosition(250, 200);

    m_TimerText.setFont(m_Font);
    m_TimerText.setCharacterSize(200);
    m_TimerText.setPosition(0, 590);

    m_RandomText.setFont(m_Font);
    m_RandomText.setCharacterSize(300);
    m_RandomText.setPosition(700, 0);

    m_Random = Random(PRESS_W, PRESS_D);
    m_RandomTime = Random(0, 210);

    m_Player.setTexture(m_Texture);
    m_Player.setPosition(100.0f, 100.0f);
} // end of Game()

void RealisticReactionRapture::Run()
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

void RealisticReactionRapture::ProcessEvents() // Input()
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

void RealisticReactionRapture::Update(sf::Time aDelta)
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

    if (m_Timer >= m_RandomTime && m_Timer < m_RandomTime + 30)
    {
        switch (m_Random)
        {
        case PRESS_W:
            m_RandomText.setString("W");
            break;
        case PRESS_A:
            m_RandomText.setString("A");
            break;
        case PRESS_S:
            m_RandomText.setString("S");
            break;
        case PRESS_D:
            m_RandomText.setString("D");
            break;
        default:
            break;
        }
    }
    else
    {
        m_RandomText.setString(" ");
    }

    if (m_Timer != 0 && m_HasWon == false)
    {
        m_Timer--;

        if (m_Timer == 0)
        {
            m_Text.setString("You lose");
        }
    }

    stringstream tt;

    tt << (m_Timer + 59) / 60;

    string std = tt.str();

    m_TimerText.setString(std);

    m_Player.move(movement * aDelta.asSeconds());
} // end of Update(sf::Time aDelta)

void RealisticReactionRapture::Render() // Draw()
{
    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.draw(m_Text);
    m_Window.draw(m_TimerText);
    m_Window.draw(m_RandomText);
    m_Window.display();
} // end of Render()

void RealisticReactionRapture::HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)
{
    if (m_Timer >= m_RandomTime && m_Timer < m_RandomTime + 30)
    {
        if (aKey == sf::Keyboard::W && m_HasWon == false)
        {
            if (m_Random == PRESS_W)
            {
                m_Text.setString("You win");
                m_HasWon = true;
            }
            else
            {
                m_Text.setString("You lose");
            }
        }
        else if (aKey == sf::Keyboard::S && m_HasWon == false)
        {
            if (m_Random == PRESS_S)
            {
                m_Text.setString("You win");
                m_HasWon = true;
            }
            else
            {
                m_Text.setString("You lose");
            }
        }
        else if (aKey == sf::Keyboard::A && m_HasWon == false)
        {
            if (m_Random == PRESS_A)
            {
                m_Text.setString("You win");
                m_HasWon = true;
            }
            else
            {
                m_Text.setString("You lose");
            }
        }
        else if (aKey == sf::Keyboard::D && m_HasWon == false)
        {
            if (m_Random == PRESS_D)
            {
                m_Text.setString("You win");
                m_HasWon = true;
            }
            else
            {
                m_Text.setString("You lose");
            }
        }
    }
} // end of HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)

int RealisticReactionRapture::Random(int min, int max)
{
    static bool initialized = false;
    if (!initialized)
    {
        std::srand(std::time(0));
        initialized = true;
    }

    return rand() % (max - min + 1) + min;
}// end of random(int min, int max)