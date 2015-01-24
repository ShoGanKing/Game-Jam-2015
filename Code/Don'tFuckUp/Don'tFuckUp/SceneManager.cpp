#include"SceneManager.h"

#include"Scene.h"

#include <SFML/Graphics.hpp>

SceneManager::SceneManager() :
    m_ActiveSceneIndex(0)
{
   
}

SceneManager::~SceneManager()
{
    if (!m_SceneList.empty())
    for (int i = m_SceneList.size() - 1; i >= 0; i--)
    {
        delete m_SceneList[i];
        m_SceneList.pop_back();
    }
}

void SceneManager::Push(Scene* aScene)
{
    if (!m_SceneList.empty())
    {
        m_SceneList.back()->SetIsActive(false);
    }

    m_SceneList.push_back(aScene);
}

void SceneManager::Pop(unsigned short aNumPops)
{
    if (!m_SceneList.empty())
    {
        if (m_SceneList.size() > aNumPops)
        {
            for (int i = 0; i < aNumPops; i++)
            {
                delete m_SceneList.back();
                m_SceneList.pop_back();
            }
            m_SceneList.back()->SetIsActive(true);
        }
        else
        {
            for (int i = m_SceneList.size() - 1; i >= 0; i--)
            {
                delete m_SceneList[i];
                m_SceneList.pop_back();
            }
        }

    }
}

bool SceneManager::Load()
{
    if (!m_SceneList.empty())
    {
        for (int i = 0; i < m_SceneList.size(); i++)
        {
            m_SceneList[i]->Load();
        }
    }
    return true;
}

void SceneManager::Update(sf::Time aDelta)
{
    if (!m_SceneList.empty())
    {
        for (int i = 0; i < m_SceneList.size(); i++)
        {
            m_SceneList[i]->Update(aDelta);
        }
    }
}

void SceneManager::Draw()
{
    if (!m_SceneList.empty())
    {
        for (int i = 0; i < m_SceneList.size(); i++)
        {
            m_SceneList[i]->Draw();
        }
    }
}

sf::RenderWindow* SceneManager::MyWindow()
{
    return m_Window;
}