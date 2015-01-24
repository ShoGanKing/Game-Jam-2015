#include "Game.h"

Game::Game() : m_Window(sf::VideoMode(640, 480),
    "SFML Application"),
    m_Texture(),
    m_Player(),
    m_IsMovingDown(false),
    m_IsMovingUp(false),
    m_IsMovingLeft(false),
    m_IsMovingRight(false)
{
    if (!m_Texture.loadFromFile("../Assets/Images/Vivi.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
    }


    m_Player.setTexture(m_Texture);
    m_Player.setPosition(100.0f, 100.0f);
} // end of Game()

void Game::Run()
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

void Game::ProcessEvents() // Input()
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

void Game::Update(sf::Time aDelta)
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

void Game::Render() // Draw()
{
    m_Window.clear();
    m_Window.draw(m_Player);
    m_Window.display();
} // end of Render()

void Game::HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)
{
    if (aKey == sf::Keyboard::W)
    {
        m_IsMovingUp = aIsPressed;
    }
    else if (aKey == sf::Keyboard::S)
    {
        m_IsMovingDown = aIsPressed;
    }
    else if (aKey == sf::Keyboard::A)
    {
        m_IsMovingLeft = aIsPressed;
    }
    else if (aKey == sf::Keyboard::D)
    {
        m_IsMovingRight = aIsPressed;
    }
} // end of HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)