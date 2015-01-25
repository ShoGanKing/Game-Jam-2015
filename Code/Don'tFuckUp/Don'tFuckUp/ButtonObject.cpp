#include "ActiveGameObject.h"
#include "MyVec2.h"
#include "Scene.h"
#include "ButtonObject.h"

ButtonObject::ButtonObject(Input_Events aType, Scene* aScene, MyVec2 aPos, float aAngle, MyVec2 aVelocity) : ActiveGameObject(aScene, aPos, aAngle)
{
    m_Scene = aScene;

    m_Type = aType;
    m_IsPressed = false;

    m_Velocity = aVelocity;

    m_Window = m_Scene->GetWindow();

    m_Sprite.setRotation(m_Angle);
    m_Sprite.setPosition(m_Position.X(), m_Position.Y());
    m_PressedSprite.setRotation(m_Angle);
    m_PressedSprite.setPosition(m_Position.X(), m_Position.Y());

}
ButtonObject::~ButtonObject()
{

}

bool ButtonObject::Load()
{
    switch (m_Type)
    {
    case Key_Down_W:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPromptW.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptWPressed.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);

        break;
    case Key_Down_A:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPromptA.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptAPressed.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    case Key_Down_S:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPromptS.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptSPressed.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    case Key_Down_D:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPromptD.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptDPressed.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    case Key_Down_Up_Arrow:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPrompt.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptA.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    case Key_Down_Left_Arrow:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPrompt.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptA.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    case Key_Down_Down_Arrow:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPrompt.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptA.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    case Key_Down_Right_Arrow:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPrompt.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptA.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    case Input_Event_Count:
        if (!m_Texture.loadFromFile("../../../Assets/Models/GreySpaceForButton.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/GreySpaceForButton.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    default:
        if (!m_Texture.loadFromFile("../../../Assets/Models/ButtonPrompt.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_Texture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_Sprite.setTexture(m_Texture);

        if (!m_PressedTexture.loadFromFile("../../../Assets/Models/ButtonPromptA.png")) // ./ current directory, ../ back one
        {
            // Handle Loading Error
            m_PressedTexture.loadFromFile("../../../Assets/Models/Missing.png");
        }

        m_PressedSprite.setTexture(m_PressedTexture);
        break;
    }

    return true;
}

void ButtonObject::Update(sf::Time aDelta)
{
    MyVec2 translation(0.0f, 0.0f);
    translation.AddToMe(m_Velocity);
    translation.MultiplyMeBy(aDelta.asSeconds());

    m_Position.AddToMe(translation);
}

void ButtonObject::Draw()
{
    if (m_Active)
    {
        if (m_IsPressed)
        {
            m_Window->draw(m_PressedSprite);
        }
        else
        {
            m_Window->draw(m_Sprite);
        }
    }
}

void ButtonObject::SetPosition(MyVec2 aPosition)
{
    m_Position = aPosition;
    m_Sprite.setPosition(aPosition.X(), aPosition.Y());
    m_PressedSprite.setPosition(aPosition.X(), aPosition.Y());
}

void ButtonObject::PressButton(bool aDown)
{
    m_IsPressed = aDown;
}

Input_Events ButtonObject::MyType()
{
    return m_Type;
}

MyVec2 ButtonObject::GetVelocity()
{
    return m_Velocity;
}

void ButtonObject::SetVelocity(MyVec2 aVelocity)
{
    m_Velocity = aVelocity;
}