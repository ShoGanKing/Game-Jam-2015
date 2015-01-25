#ifndef DDRCLONE_H
#define DDRCLONE_H

#include"Scene.h"
#include<vector>

class ActiveGameObject;
class StaticObject;
class ButtonObject;

class TimingGameDDR : public Scene
{
public:
    TimingGameDDR(SceneManager* aManager);
    ~TimingGameDDR();

    void SetIsActive(bool aActive);

    virtual bool Load();
    virtual void Update(sf::Time aDelta);
    virtual void Draw();


    virtual void HandleInputEvent(Input_Events aEvent);

protected:

    void HitPlayer();
    void HitEnemy();

    void Reset();

    void LoadAssets();

    unsigned short m_Misses;
    unsigned short m_Hits;

    StaticObject* m_Background;

    std::vector<ButtonObject*> m_TargetArea;

    std::vector<ButtonObject*> m_TargetKeys;

};

#endif