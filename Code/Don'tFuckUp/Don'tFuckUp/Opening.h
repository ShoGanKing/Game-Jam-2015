#ifndef OPENING_H
#define OPENING_H

#include"Scene.h"
#include<vector>

class ActiveGameObject;
class StaticObject;
class ButtonObject;

class Opening : public Scene
{
public:
    Opening(SceneManager* aManager);
    ~Opening();

    void SetIsActive(bool aActive);

    virtual bool Load();
    virtual void Update(sf::Time aDelta);
    virtual void Draw();

    virtual void HandleInputEvent(Input_Events aEvent);

protected:

    StaticObject* m_Background;

};

#endif