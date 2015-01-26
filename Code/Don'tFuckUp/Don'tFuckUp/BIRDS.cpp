#include"BIRDS.h"

#include "ActiveGameObject.h"
#include "MyVec2.h"
#include "Scene.h"
#include "ButtonObject.h"

BirdObject::BirdObject(Scene* aScene, MyVec2 aPos, float aAngle, MyVec2 aVelocity) : ActiveGameObject(aScene, aPos, aAngle)
{
    m_Scene = aScene;

    m_Frame = 0;

    m_Time = m_Time.Zero;

    m_Velocity = aVelocity;

    m_Window = m_Scene->GetWindow();

    m_Sprite.setRotation(m_Angle);
    m_Sprite.setPosition(m_Position.X(), m_Position.Y());
}
BirdObject::~BirdObject()
{

}

bool BirdObject::Load()
{
    if (!m_Texture.loadFromFile("../../../Assets/Models/Bird1.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
    }

    m_Sprite.setTexture(m_Texture);



    if (!m_Texture2.loadFromFile("../../../Assets/Models/Bird2.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture2.loadFromFile("../../../Assets/Models/Missing.png");
    }

    if (!m_Texture3.loadFromFile("../../../Assets/Models/Bird3.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture3.loadFromFile("../../../Assets/Models/Missing.png");
    }

    if (!m_Texture4.loadFromFile("../../../Assets/Models/Bird4.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture4.loadFromFile("../../../Assets/Models/Missing.png");
    }


    return true;
}

void BirdObject::Update(sf::Time aDelta)
{
    MyVec2 translation(0.0f, 0.0f);
    translation.AddToMe(m_Velocity);
    translation.MultiplyMeBy(aDelta.asSeconds());
    m_Position.AddToMe(translation);
    SetPosition(m_Position);

    m_Time += aDelta;

    if (m_Time.asSeconds() >= 0.2f)
    {
        m_Frame++;

        if (m_Frame >= 4)
        {
            m_Frame = 0;
        }

        m_Time = m_Time.Zero;
    }


}

void BirdObject::Draw()
{
    if (m_Active)
    {

        switch (m_Frame)
        {
        case 0:
            m_Sprite.setTexture(m_Texture);
            break;
        case 1:
            m_Sprite.setTexture(m_Texture2);
            break;
        case 2:
            m_Sprite.setTexture(m_Texture3);
            break;
        case 3:
            m_Sprite.setTexture(m_Texture4);
            break;
        }
       
        m_Window->draw(m_Sprite);
        
    }
}

void BirdObject::SetPosition(MyVec2 aPosition)
{
    m_Position = aPosition;
    m_Sprite.setPosition(aPosition.X(), aPosition.Y());
    m_PressedSprite.setPosition(aPosition.X(), aPosition.Y());
}

MyVec2 BirdObject::GetVelocity()
{
    return m_Velocity;
}

void BirdObject::SetVelocity(MyVec2 aVelocity)
{
    m_Velocity = aVelocity;
}