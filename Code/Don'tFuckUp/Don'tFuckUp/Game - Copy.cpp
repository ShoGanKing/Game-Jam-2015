#include "Game - Copy.h"
#include "SceneManager.h"
#include "Scene.h"
#include "StaticObject.h"

GameCopy::GameCopy() : m_Window(sf::VideoMode(1600, 900), "SFML Application"),
    m_SceneManager(nullptr)
{
    m_SceneManager = new SceneManager();


    Scene* Scene1 = new Scene(&m_Window);
    StaticObject* SGO1 = new StaticObject(Scene1, 255,0,0,MyVec2(00.0,100.0));
    Scene1->AddGameObject(SGO1);

    Scene* Scene2 = new Scene(&m_Window);
    StaticObject* SGO2 = new StaticObject(Scene1, 255, 255, 0, MyVec2(100.0, 00.0));
    Scene2->AddGameObject(SGO2);

    Scene* Scene3 = new Scene(&m_Window);
    StaticObject* SGO3 = new StaticObject(Scene1, 0, 255, 0, MyVec2(00.0, 400.0));
    Scene3->AddGameObject(SGO3);

    Scene* Scene4 = new Scene(&m_Window);
    StaticObject* SGO4 = new StaticObject(Scene1, 255, 0, 255, MyVec2(400.0, 400.0));
    Scene4->AddGameObject(SGO4);

    Scene* Scene5 = new Scene(&m_Window);
    StaticObject* SGO5 = new StaticObject(Scene1, 255, 255, 255, MyVec2(300.0, 200.0));
    Scene5->AddGameObject(SGO5);

    Scene* Scene6 = new Scene(&m_Window);
    StaticObject* SGO6 = new StaticObject(Scene1, 0, 255, 255, MyVec2(200.0, 200.0));
    Scene6->AddGameObject(SGO6);
    Scene6->SetIsActive(true);

    m_SceneManager->Push(Scene1);
    m_SceneManager->Push(Scene2);
    m_SceneManager->Push(Scene3);
    m_SceneManager->Push(Scene4);
    m_SceneManager->Push(Scene5);
    m_SceneManager->Push(Scene6);

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
            m_SceneManager->Pop();
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

} // end of HandlePlayerInput(sf::Keyboard::Key aKey, bool aIsPressed)