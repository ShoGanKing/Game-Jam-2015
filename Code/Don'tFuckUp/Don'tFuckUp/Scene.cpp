#include "Scene.h"
#include "GameObject.h"


Scene::Scene(sf::RenderWindow* aWindow)
{
    m_Window = aWindow;
    m_Active = true;
}
Scene::~Scene()
{

}

void Scene::AddGameObject(GameObject* aObject)
{
    m_Objects.push_back(aObject);
}

void Scene::RemoveGameObjectType(std::string aType)
{

}

void Scene::RemoveGameObjectAtIndex(unsigned int aIndex)
{

}

bool Scene::Load()
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Load();
        }
    }
    return true;
}

void Scene::Update()
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Update(0.0);
        }
    }
}

void Scene::Draw()
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Draw();
        }
    }

}

void Scene::SetIsActive(bool aActive)
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->SetIsActive(aActive);
        }
    }

}