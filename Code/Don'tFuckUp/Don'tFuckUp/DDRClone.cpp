#include"DDRClone.h"
#include"GameObject.h"
#include"ActiveGameObject.h"
#include"StaticObject.h"
#include"ButtonObject.h"
#include"BIRDS.h"


TimingGameDDR::TimingGameDDR(SceneManager* aManager) : Scene(aManager),
    m_Misses(0),
    m_Hits(0)
{
    Load();
}

TimingGameDDR::~TimingGameDDR()
{
    if (!m_TargetKeys.empty())
    {
        for (int i = m_TargetKeys.size() - 1; i >= 0; i--)
        {
            delete m_TargetKeys[i];
            m_TargetKeys.pop_back();
        }
    }

    if (!m_TargetArea.empty())
    {
        for (int i = m_TargetArea.size() - 1; i >= 0; i--)
        {
            delete m_TargetArea[i];
            m_TargetArea.pop_back();
        }
    }
}

void TimingGameDDR::SetIsActive(bool aActive)
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->SetIsActive(aActive);
        }
    }


    if (!m_TargetKeys.empty())
    {
        for (int i = 0; i < m_TargetKeys.size(); i++)
        {
            m_TargetKeys[i]->SetIsActive(aActive);
        }
    }

    if (!m_TargetArea.empty())
    {
        for (int i = 0; i < m_TargetArea.size(); i++)
        {
            m_TargetArea[i]->SetIsActive(aActive);
        }
    }
}

bool TimingGameDDR::Load()
{
    m_Background = new StaticObject( this, 255,255,255 );

    m_Background->Load();

    m_Background->MyTexture()->loadFromFile("../../../Assets/Backgrounds/Images/GrassAndSky.png");


    m_Objects.push_back(new BirdObject(this, MyVec2(1200.0f, 150.0f)));

    //Static Objects Here

    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Load();
        }
    }


    LoadAssets();

    return true;
}

void TimingGameDDR::Update(sf::Time aDelta)
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Update(aDelta);
        }
    }

    if (!m_TargetKeys.empty())
    {
        for (int i = 0; i < m_TargetKeys.size(); i++)
        {
            m_TargetKeys[i]->Update(aDelta);
            if (m_TargetKeys[i]->GetPosition().Y() < -100.0f)
            {
                m_TargetKeys[i]->SetPosition(MyVec2(m_TargetKeys[i]->GetPosition().X(), 1000.0f));
                HitPlayer();
            }
        }
    }

    if (!m_TargetArea.empty())
    {
        for (int i = 0; i < m_TargetArea.size(); i++)
        {
            m_TargetArea[i]->Update(aDelta);
        }
    }


    if (m_Misses >= 10)
    {
        Reset();
        m_Misses = 0;
        m_Hits = 0;
    }

    if (m_Hits >= 10)
    {
        Reset();
        m_Misses = 0;
        m_Hits = 0;
    }

}

void TimingGameDDR::Draw()
{
    m_Background->Draw();

    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Draw();
        }
    }

    if (!m_TargetArea.empty())
    {
        for (int i = 0; i < m_TargetArea.size(); i++)
        {
            m_TargetArea[i]->Draw();
        }
    }

    if (!m_TargetKeys.empty())
    {
        for (int i = 0; i < m_TargetKeys.size(); i++)
        {
            m_TargetKeys[i]->Draw();
        }
    }

}

void TimingGameDDR::HandleInputEvent(Input_Events aEvent)
{
    if (!m_TargetKeys.empty())
    {
        for (int i = 0; i < m_TargetKeys.size(); i++)
        {
            if (m_TargetKeys[i]->MyType() == aEvent)
            {
                m_TargetKeys[i]->PressButton(true);

                if (m_TargetKeys[i]->GetPosition().Y() > m_TargetArea[i]->GetPosition().Y() - 75.0f && m_TargetKeys[i]->GetPosition().Y() < m_TargetArea[i]->GetPosition().Y() + 75.0f)
                {
                    m_TargetKeys[i]->SetPosition(MyVec2(m_TargetKeys[i]->GetPosition().X(), 1000.0f));
                    HitEnemy();
                }
                else
                {
                    HitPlayer();
                }
            }
            else if (m_TargetKeys[i]->MyType() + 8 == aEvent) //the + 8 reffers to the up version of each button
            {
                m_TargetKeys[i]->PressButton(false);
            }
        }
    }

}

void TimingGameDDR::Reset()
{
    if (!m_TargetKeys.empty())
    {
        for (int i = m_TargetKeys.size() - 1; i >= 0; i--)
        {
            delete m_TargetKeys[i];
            m_TargetKeys.pop_back();
        }
    }

    if (!m_TargetArea.empty())
    {
        for (int i = m_TargetArea.size() - 1; i >= 0; i--)
        {
            delete m_TargetArea[i];
            m_TargetArea.pop_back();
        }
    }

    LoadAssets();
}

void TimingGameDDR::HitPlayer()
{
    m_Misses++;
}

void TimingGameDDR::HitEnemy()
{
    m_Hits++;
}

void TimingGameDDR::LoadAssets()
{
    //Keys Here
    m_TargetKeys.push_back(new ButtonObject(Key_Down_A, this, MyVec2(116.0f, 950.0f)));
    m_TargetKeys.push_back(new ButtonObject(Key_Down_W, this, MyVec2(266.0f, 1050.0f)));
    m_TargetKeys.push_back(new ButtonObject(Key_Down_S, this, MyVec2(416.0f, 1150.0f)));
    m_TargetKeys.push_back(new ButtonObject(Key_Down_D, this, MyVec2(566.0f, 850.0f)));

    m_TargetKeys[0]->MySprite()->setColor(sf::Color(255, 128, 128));
    m_TargetKeys[1]->MySprite()->setColor(sf::Color(128, 255, 128));
    m_TargetKeys[2]->MySprite()->setColor(sf::Color(128, 128, 255));
    m_TargetKeys[3]->MySprite()->setColor(sf::Color(255, 255, 128));


    m_TargetKeys[0]->SetVelocity(MyVec2(0.0f, -289.0f));
    m_TargetKeys[1]->SetVelocity(MyVec2(0.0f, -301.0f));
    m_TargetKeys[2]->SetVelocity(MyVec2(0.0f, -323.0f));
    m_TargetKeys[3]->SetVelocity(MyVec2(0.0f, -369.0f));

    if (!m_TargetKeys.empty())
    {
        for (int i = 0; i < m_TargetKeys.size(); i++)
        {
            m_TargetKeys[i]->Load();
            m_TargetKeys[i]->SetIsActive(true);
        }
    }


    //Grey Boxes Here
    m_TargetArea.push_back(new ButtonObject(Input_Event_Count, this, MyVec2(100.0f, 300.0f)));
    m_TargetArea.push_back(new ButtonObject(Input_Event_Count, this, MyVec2(250.0f, 300.0f)));
    m_TargetArea.push_back(new ButtonObject(Input_Event_Count, this, MyVec2(400.0f, 300.0f)));
    m_TargetArea.push_back(new ButtonObject(Input_Event_Count, this, MyVec2(550.0f, 300.0f)));

    if (!m_TargetArea.empty())
    {
        for (int i = 0; i < m_TargetArea.size(); i++)
        {
            m_TargetArea[i]->Load();
            m_TargetArea[i]->SetIsActive(true);
        }
    }

}