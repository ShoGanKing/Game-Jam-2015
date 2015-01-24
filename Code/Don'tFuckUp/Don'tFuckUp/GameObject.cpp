#include "GameObject.h"

GameObject::GameObject(MyVec2 aPos, std::string aType, float aAngle)
{
    m_Position = aPos;
    m_Angle = aAngle;
    m_Active = false;
}


GameObject::~GameObject()
{

}

bool GameObject::IsActive()
{ 
    return m_Active; 
}

void GameObject::SetIsActive(bool aActive)
{
    m_Active = aActive;
}

std::string GameObject::GetType()
{
    return m_Type;
}

MyVec2 GameObject::GetPosition()
{
    return m_Position;
}

void GameObject::SetPosition(MyVec2 aPosition)
{
    m_Position = aPosition;
}

float GameObject::GetAngle()
{
    return m_Angle;
}

void GameObject::SetAngle(float aAngle)
{
    m_Angle = aAngle;
}