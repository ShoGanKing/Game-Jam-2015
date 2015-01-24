#include "DoorMinigame.h"
#include <random>

DoorMinigame::DoorMinigame() : m_Window(sf::VideoMode(1600, 900),
    "SFML Application"),
    m_Texture(),
    m_Player(),
    m_Font(),
    m_Text(),
    m_IsMovingDown(false),
    m_IsMovingUp(false),
    m_IsMovingLeft(false),
    m_IsMovingRight(false),
    m_RandomNumber(0)
{

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

    m_Player.move(movement * aDelta.asSeconds());
} // end of Update(sf::Time aDelta)

void DoorMinigame::Render() // Draw()
{
    if (m_RandomNumber == RIGHTDOOR)
    {
        m_Text.setString("You win");
    }
    else if (m_RandomNumber == WRONGDOOR1 || m_RandomNumber == WRONGDOOR2)
    {
        m_Text.setString("You lose");
    }
    m_Text.setFont(m_Font);
    m_Text.setCharacterSize(300);
    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.draw(m_Text);
    m_Window.display();
} // end of Render()

void DoorMinigame::HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)
{
    if (aKey == sf::Keyboard::W)
    {
        m_IsMovingUp = aIsPressed;
        m_RandomNumber = random(1, 3);
    }
    else if (aKey == sf::Keyboard::S)
    {
        m_IsMovingDown = aIsPressed;
    }
    else if (aKey == sf::Keyboard::A)
    {
        m_IsMovingLeft = aIsPressed;
        m_RandomNumber = random(1, 3);
    }
    else if (aKey == sf::Keyboard::D)
    {
        m_IsMovingRight = aIsPressed;
        m_RandomNumber = random(1, 3);
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