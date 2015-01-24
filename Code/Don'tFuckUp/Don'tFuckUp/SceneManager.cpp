#include"SceneManager.h"

#include"Scene.h"

#include <SFML/Graphics.hpp>

SceneManager::SceneManager() :
    m_ActiveSceneIndex(0)
{
   
}

SceneManager::~SceneManager()
{

    for (int i = m_SceneList.size() - 1; i >= 0; i--)
    {
        delete m_SceneList[i];
        m_SceneList.pop_back();
    }

}

void SceneManager::Push()
{
    m_SceneList.push_back(new Scene());
}

void SceneManager::Pop()
{

}

sf::RenderWindow* SceneManager::MyWindow()
{
    return m_Window;
}