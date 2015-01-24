
class Scene
{
public:
    Scene();
    ~Scene();


    bool IsActive(){ return m_Active; }

private:
    bool m_Active;


};