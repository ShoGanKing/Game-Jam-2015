#include"SceneManager.h"
#include"Scene.h"

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

}

void SceneManager::Pop()
{

}