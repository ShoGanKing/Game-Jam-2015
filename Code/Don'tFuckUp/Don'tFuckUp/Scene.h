#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>

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
    Scene(sf::RenderWindow* aWindow);
    ~Scene();  

    bool IsActive(){ return m_Active; }
    void SetIsActive(bool aActive);

    void AddGameObject(GameObject* aObject);
    void RemoveGameObjectType(std::string aType);
    void RemoveGameObjectAtIndex(unsigned int aIndex);

    virtual bool Load();
    virtual void Update();
    virtual void Draw();


private:
    bool m_Active;

    sf::RenderWindow* m_Window;

    std::vector<GameObject*> m_Objects;

};


#endif