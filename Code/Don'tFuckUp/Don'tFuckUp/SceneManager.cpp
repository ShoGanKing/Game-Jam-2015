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
    m_SceneList.push_back(new Scene(m_Window));
}

void SceneManager::Pop(unsigned short aNumPops)
{
    for (int i = 0; i < aNumPops; i++)
    {
        delete m_SceneList.back();
        m_SceneList.pop_back();
    }
}

sf::RenderWindow* SceneManager::MyWindow()
{
    return m_Window;
}