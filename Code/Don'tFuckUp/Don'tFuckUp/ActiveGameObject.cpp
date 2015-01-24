#include"ActiveGameObject.h"
#include "MyVec2.h"
#include "Scene.h"

ActiveGameObject::ActiveGameObject(Scene* aScene, MyVec2 aPos, float aAngle, MyVec2 aVelocity) : GameObject(MyVec2(100.0f, 100.0f), "Active")
{
    m_Scene = aScene;

    m_Window = m_Scene->GetWindow();

    m_Sprite.setRotation(m_Angle);
    m_Sprite.setPosition(m_Position.X(), m_Position.Y());

}
ActiveGameObject::~ActiveGameObject()
{

}

bool ActiveGameObject::Load()
{
    if (!m_Texture.loadFromFile("../../../Assets/Models/Vivi.png")) // ./ current directory, ../ back one
    {
        // Handle Loading Error
        m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
    }

    m_Sprite.setTexture(m_Texture);

    return true;
}

void ActiveGameObject::Update(sf::Time aDelta)
{
    MyVec2 translation(0.0f,0.0f);
    translation.AddToMe(m_Velocity);
    translation.MultiplyMeBy(aDelta.asSeconds());

    m_Position.AddToMe(translation);
}

void ActiveGameObject::Draw()
{
    if (m_Active)
    {
        m_Window->draw(m_Sprite);
    }
}