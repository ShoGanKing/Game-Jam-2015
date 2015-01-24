#include "StaticObject.h"
#include "GameObject.h"
#include "MyVec2.h"
#include "Scene.h"

StaticObject::StaticObject(sf::RenderWindow* aWindow) : GameObject(MyVec2(100.0f, 100.0f), "Static")
{
    m_Scene = nullptr;
    m_Window = aWindow;
    m_Active = true;
}

StaticObject::StaticObject(Scene* aScene, MyVec2 aPos, float aAngle) : GameObject(aPos, "Static", aAngle)
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
    if (!m_Texture.loadFromFile("../Assets/Images/Missing.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture.loadFromFile("../Assets/Images/Missing.png");
    }

    m_Sprite.setTexture(m_Texture);

    m_Sprite.setPosition(100.0,100.0);

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