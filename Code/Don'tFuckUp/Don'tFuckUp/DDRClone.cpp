#include"DDRClone.h"
#include"GameObject.h"
#include"ActiveGameObject.h"
#include"StaticObject.h"
#include"ButtonObject.h"

TimingGameDDR::TimingGameDDR(SceneManager* aManager) : Scene(aManager)
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
    m_Background = new StaticObject( this, 255, 255, 255 );
    m_Background->Load();


    //Static Objects Here


    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Load();
        }
    }


    //Keys Here
    m_TargetKeys.push_back(new ButtonObject(Key_Down_W, this, MyVec2(100.0f, 100.0f)));
    m_TargetKeys.push_back(new ButtonObject(Key_Down_A, this, MyVec2(250.0f, 100.0f)));
    m_TargetKeys.push_back(new ButtonObject(Key_Down_S, this, MyVec2(400.0f, 100.0f)));
    m_TargetKeys.push_back(new ButtonObject(Key_Down_D, this, MyVec2(550.0f, 100.0f)));

    if (!m_TargetKeys.empty())
    {
        for (int i = 0; i < m_TargetKeys.size(); i++)
        {
            m_TargetKeys[i]->Load();
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
        }
    }

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
        }
    }

    if (!m_TargetArea.empty())
    {
        for (int i = 0; i < m_TargetArea.size(); i++)
        {
            m_TargetArea[i]->Update(aDelta);
        }
    }
}

void TimingGameDDR::Draw()
{
    if (!m_Objects.empty())
    {
        for (int i = 0; i < m_Objects.size(); i++)
        {
            m_Objects[i]->Draw();
        }
    }

    if (!m_TargetKeys.empty())
    {
        for (int i = 0; i < m_TargetKeys.size(); i++)
        {
            m_TargetKeys[i]->Draw();
        }
    }

    if (!m_TargetArea.empty())
    {
        for (int i = 0; i < m_TargetArea.size(); i++)
        {
            m_TargetArea[i]->Draw();
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
            }
            else if (m_TargetKeys[i]->MyType() + 8 == aEvent) //the + 8 reffers to the up version of each button
            {
                m_TargetKeys[i]->PressButton(false);
            }
        }
    }

}