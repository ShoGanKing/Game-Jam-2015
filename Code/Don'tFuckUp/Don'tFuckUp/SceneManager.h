#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

class Scene;

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void Push();
    void Pop(unsigned short aNumPops = 1);

    sf::RenderWindow* MyWindow();

private:
    unsigned short m_ActiveSceneIndex;

    sf::RenderWindow* m_Window;

    std::vector<Scene*> m_SceneList;

};

#endif