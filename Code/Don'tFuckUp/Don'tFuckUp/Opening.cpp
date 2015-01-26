#include"Opening.h"
#include"GameObject.h"
#include"ActiveGameObject.h"
#include"StaticObject.h"
#include"ButtonObject.h"
#include"BIRDS.h"


Opening::Opening(SceneManager* aManager) : Scene(aManager)
{
    Load();
}

Opening::~Opening()
{

}

void Opening::SetIsActive(bool aActive)
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->SetIsActive(aActive);
        }
    }
}

bool Opening::Load()
{
    m_Background = new StaticObject(this, 255, 255, 255);

    m_Background->Load();

    m_Background->MyTexture()->loadFromFile("../../../Assets/Backgrounds/Images/GrassAndSky.png");


    m_Objects.push_back(new BirdObject(this, MyVec2(-800.0f, 50.0f), 0.0f, MyVec2(200.0f,0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-200.0f, 150.0f), 0.0f, MyVec2(190.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-600.0f, 100.0f), 0.0f, MyVec2(180.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-450.0f, 180.0f), 0.0f, MyVec2(210.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-750.0f, 75.0f), 0.0f, MyVec2(220.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-1800.0f, 50.0f), 0.0f, MyVec2(200.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-1200.0f, 150.0f), 0.0f, MyVec2(190.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-1600.0f, 100.0f), 0.0f, MyVec2(180.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-1450.0f, 180.0f), 0.0f, MyVec2(210.0f, 0.0f)));
    m_Objects.push_back(new BirdObject(this, MyVec2(-1750.0f, 75.0f), 0.0f, MyVec2(220.0f, 0.0f)));



    //Static Objects Here

    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Load();
        }
    }



    return true;
}

void Opening::Update(sf::Time aDelta)
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Update(aDelta);

            if (m_Objects[i]->GetPosition().X() > 1800.0f)
            {
                m_Objects[i]->SetPosition(MyVec2(-200.0f, m_Objects[i]->GetPosition().Y()));
            }
        }
    }
}

void Opening::Draw()
{
    m_Background->Draw();

    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Draw();
        }
    }
}

void Opening::HandleInputEvent(Input_Events aEvent)
{

}