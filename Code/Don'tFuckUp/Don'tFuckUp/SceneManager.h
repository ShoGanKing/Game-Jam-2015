#ifndef SCENE_H
#define SCENE_H
#include <vector>


class Scene;

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void Push();
    void Pop();


private:
    unsigned short m_ActiveSceneIndex;

    std::vector<Scene*> m_SceneList;

};

#endif