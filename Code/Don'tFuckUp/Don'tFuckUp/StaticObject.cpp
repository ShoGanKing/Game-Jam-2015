#include "StaticObject.h"
#include "GameObject.h"
#include "MyVec2.h"
#include "Scene.h"

StaticObject::StaticObject(Scene* aScene, MyVec2 aPos, float aAngle) : GameObject(aPos, aAngle)
{
    m_Scene = aScene;

    m_Sprite.setRotation(m_Angle);
    m_Sprite.setPosition(m_Position.X(), m_Position.Y());
}
StaticObject::~StaticObject()
{

}

bool StaticObject::Load()
{
    if (!m_Texture.loadFromFile("../Assets/Images/Vivi.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture.loadFromFile("../Assets/Images/Missing.png");
    }

    m_Sprite.setTexture(m_Texture);

    return true;
}

void StaticObject::Update(double aDelta)
{

}

void StaticObject::Draw()
{
    if (m_Active)
    {
        m_Window->draw(m_Sprite);
    }
}