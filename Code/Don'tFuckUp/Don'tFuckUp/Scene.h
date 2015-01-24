#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>

class SceneManager;

enum Input_Events
{
    Key_Down_W = 0,
    Key_Down_A,
    Key_Down_S,
    Key_Down_D,
    Key_Down_Up_Arrow,
    Key_Down_Left_Arrow,
    Key_Down_Down_Arrow,
    Key_Down_Right_Arrow,
    Key_Up_W,
    Key_Up_A,
    Key_Up_S,
    Key_Up_D,
    Key_Up_Up_Arrow,
    Key_Up_Left_Arrow,
    Key_Up_Down_Arrow,
    Key_Up_Right_Arrow,
    Input_Event_Count
};



class GameObject;


class Scene
{
public:
    Scene(SceneManager* aManager);
    ~Scene();  

    bool IsActive(){ return m_Active; }
    void SetIsActive(bool aActive);

    void AddGameObject(GameObject* aObject);
    void RemoveGameObjectType(std::string aType);
    void RemoveGameObjectAtIndex(unsigned int aIndex);

    sf::RenderWindow* GetWindow();

    SceneManager* GetSceneManager();

    virtual bool Load();
    virtual void Update(sf::Time aDelta);
    virtual void Draw();

    virtual void HandleInputEvent(Input_Events aEvent);

protected:
    bool m_Active;

    SceneManager* m_Manager;

    sf::RenderWindow* m_Window;

    std::vector<GameObject*> m_Objects;

};


#endif