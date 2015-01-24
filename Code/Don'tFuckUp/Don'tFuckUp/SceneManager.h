#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

enum Input_Events;

class Scene;

class SceneManager
{
public:
    SceneManager(sf::RenderWindow* aWindow);
    ~SceneManager();

    void Push(Scene* aScene);
    void Pop(unsigned short aNumPops = 1);

    bool Load();
    void Update(sf::Time aDelta);
    void Draw();

    sf::RenderWindow* MyWindow();

    void HandleInputEvent(Input_Events aEvent);

private:
    unsigned short m_ActiveSceneIndex;

    sf::RenderWindow* m_Window;

    std::vector<Scene*> m_SceneList;

};

#endif