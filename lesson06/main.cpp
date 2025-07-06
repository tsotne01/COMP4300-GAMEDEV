#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <algorithm>

class CTransform
{

public:
    CTransform() {}
};

class CShape
{
    float radius;
    float width;
    float height;
    bool filled;
    std::string color;
    int sides;

public:
    CShape() {}
    CShape(float rin, int sides, float win, float hin, std::string cin, bool fin) : radius(rin), width(win), height(hin), color(cin), filled(fin)
    {
    }
};

class Entity
{

public:
    CShape m_shape;
    Entity() {}
};
typedef std::vector<std::shared_ptr<Entity>> EntitiesVector;

class EntityManager
{
    EntitiesVector m_entities;
    EntitiesVector m_toAdd;
    EntitiesVector m_toRemove;

    std::map<std::string, EntitiesVector> m_str_to_entities;
    int m_count = 0;

public:
    void addEntity(std::shared_ptr<Entity> e)
    {
        m_toAdd.push_back(e);
    }

    void update()
    {
        for (auto e : m_toAdd)
        {
            m_entities.push_back(e);
        }
        m_toAdd.clear();
        for (auto e : m_toRemove)
        {
            m_entities.erase(remove(m_entities.begin(), m_entities.end(), e), m_entities.end());
        }
        m_toRemove.clear();
    }
    void removeEntity(std::shared_ptr<Entity> e)
    {
        m_toRemove.push_back(e);
    }
    EntitiesVector getEntities()
    {
        return m_entities;
    }
};

int main()
{
    EntityManager em;
    std::shared_ptr<Entity> myEntity1 = std::make_shared<Entity>();
    std::shared_ptr<Entity> myEntity2 = std::make_shared<Entity>();
    std::shared_ptr<Entity> myEntity3 = std::make_shared<Entity>();

    em.addEntity(myEntity1);
    em.addEntity(myEntity2);
    em.addEntity(myEntity3);
    em.update();

    auto en = em.getEntities();

    for (auto e : en)
    {
        std::cout << e << std::endl;
    }
    em.removeEntity(myEntity2);
    std::cout << "After Removing" << std::endl;
    em.update();

    en = em.getEntities();

    for (auto e : en)
    {
        std::cout << e << std::endl;
    }

    return 0;
}