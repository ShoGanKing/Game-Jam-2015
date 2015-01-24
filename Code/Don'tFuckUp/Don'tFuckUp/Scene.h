#ifndef SCENE_H
#define SCENE_H

#include <vector>

class GameObject;

enum SceneType
{
    Scene_MainMenu = 0,
    Scene_PauseMenu,
    Scene_FailMenu,
    Scene_BetweenMenu,
    Scene_MiniGame,
    Scene_Type_Count
};


class Scene
{
public:
    Scene();
    ~Scene();
    

    bool IsActive(){ return m_Active; }

private:
    bool m_Active;



    std::vector<GameObject*> m_Objects;

};


#endif