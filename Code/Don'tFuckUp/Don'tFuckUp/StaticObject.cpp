#include "StaticObject.h"
#include "MyVec2.h"
#include "Scene.h"

StaticObject::StaticObject(sf::RenderWindow* aWindow) : GameObject(MyVec2(100.0f, 100.0f), "Static")
{
    m_Scene = nullptr;
    m_Window = aWindow;
    m_Active = true;

    m_Sprite.setPosition(100.0, 100.0);
}

StaticObject::StaticObject(Scene* aScene, int aColour1, int aColour2, int aColour3, MyVec2 aPos, float aAngle) : GameObject(aPos, "Static", aAngle)
{
    m_Scene = aScene;

    m_Window = m_Scene->GetWindow();

    m_Sprite.setRotation(m_Angle);
    m_Sprite.setPosition(m_Position.X(), m_Position.Y());

    m_Sprite.setColor(sf::Color(aColour1, aColour2, aColour3));

}
StaticObject::~StaticObject()
{

}

bool StaticObject::Load()
{
    if (!m_Texture.loadFromFile("../../../Assets/Models/Vivi.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
    }

    m_Sprite.setTexture(m_Texture);

    return true;
}

void StaticObject::Update(sf::Time aDelta)
{

}

void StaticObject::Draw()
{
    if (m_Active)
    {
        m_Window->draw(m_Sprite);
    }
}