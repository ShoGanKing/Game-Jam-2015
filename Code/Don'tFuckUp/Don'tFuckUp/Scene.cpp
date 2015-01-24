#include "Scene.h"
#include "GameObject.h"
#include "SceneManager.h"

Scene::Scene(SceneManager* aManager)
{
    m_Manager = aManager;
    m_Window = m_Manager->MyWindow();
    m_Active = true;
}
Scene::~Scene()
{
    if (!m_Objects.empty())
    {
        for (int i = m_Objects.size() - 1; i >= 0; i--)
        {
            delete m_Objects[i];
            m_Objects.pop_back();
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

void Scene::AddGameObject(GameObject* aObject)
{
    m_Objects.push_back(aObject);
}

void Scene::RemoveGameObjectType(std::string aType)
{
    if (!m_Objects.empty())
    {
        for (int i = m_Objects.size() - 1; i >= 0; i--)
        {
            if (m_Objects[i]->GetType() == aType)
            {
                delete m_Objects[i];
                m_Objects.erase(m_Objects.begin() + i);
            }
        }
    }
}

void Scene::RemoveGameObjectAtIndex(unsigned int aIndex)
{
    if (!m_Objects.empty())
    {
        if (m_Objects.size() > aIndex)
        {
            delete m_Objects[aIndex];
            m_Objects.erase(m_Objects.begin() + aIndex);
        }
    }
}

sf::RenderWindow* Scene::GetWindow()
{
    return m_Window;
}

SceneManager* Scene::GetSceneManager()
{
    return m_Manager;
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

void Scene::Update(sf::Time aDelta)
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Update(aDelta);
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

void Scene::HandleInputEvent(Input_Events aEvent)
{
    if (IsActive())
    {
        switch (aEvent)
        {
        case Key_Down_A:
            if (!m_Objects.empty())
            {
                for (int i = 0; i < m_Objects.size(); i++)
                {
                    m_Objects[i]->SetPosition(MyVec2(0.0f,100.0f));
                }
            }
            break;
        case Key_Down_D:
            if (!m_Objects.empty())
            {
                for (int i = 0; i < m_Objects.size(); i++)
                {
                    m_Objects[i]->SetPosition(MyVec2(200.0f, 100.0f));
                }
            }
            break;
        default:
            if (!m_Objects.empty())
            {
                for (int i = 0; i < m_Objects.size(); i++)
                {
                    m_Objects[i]->SetPosition(MyVec2(100.0f, 100.0f));
                }
            }
            break;
        }
    }
}