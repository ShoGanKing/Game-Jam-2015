#include "Game - Copy.h"
#include "SceneManager.h"
#include "Scene.h"
#include "StaticObject.h"
#include "ActiveGameObject.h"

GameCopy::GameCopy() : m_Window(sf::VideoMode(1600, 900), "SFML Application"),
    m_SceneManager(nullptr)
{
    m_SceneManager = new SceneManager(&m_Window);


    Scene* Scene1 = new Scene(m_SceneManager);
    ActiveGameObject* SGO1 = new ActiveGameObject(Scene1, MyVec2(100.0f,100.0f));
    Scene1->AddGameObject(SGO1);
    Scene1->SetIsActive(true);

    m_SceneManager->Push(Scene1);

    m_SceneManager->Load();


} // end of Game()

GameCopy::~GameCopy()
{
    delete m_SceneManager;
    m_SceneManager = nullptr;
}

void GameCopy::Run()
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

void GameCopy::ProcessEvents() // Input()
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

void GameCopy::Update(sf::Time aDelta)
{
    m_SceneManager->Update(aDelta);
} // end of Update(sf::Time aDelta)

void GameCopy::Render() // Draw()
{
    m_Window.clear();

    m_SceneManager->Draw();

    m_Window.display();
} // end of Render()

void GameCopy::HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)
{
    if (aKey == sf::Keyboard::W)
    {
        if (aIsPressed)
        {

        }
        else
        {

        }
    }
    else if (aKey == sf::Keyboard::S)
    {
        if (aIsPressed)
        {

        }
        else
        {

        }
    }
    else if (aKey == sf::Keyboard::A)
    {
        if (aIsPressed)
        {

        }
        else
        {

        }
    }
    else if (aKey == sf::Keyboard::D)
    {
        if (aIsPressed)
        {

        }
        else
        {

        }
    }
} // end of HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)