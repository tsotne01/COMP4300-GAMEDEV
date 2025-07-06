
#include <iostream>
#include <memory>

class Vec2
{
public:
    float x = 0.0f;
    float y = 0.0f;
    Vec2() {}
    Vec2(float xin, float yin) : x(xin), y(yin) {}

    Vec2 add(const Vec2 &rhs)
    {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 subtract(const Vec2 &rhs)
    {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    Vec2 normalize()
    {
        float magnitude = (y * y) * (x * x);
        return Vec2(x / magnitude, y / magnitude);
    }
};

class CTransofrm
{
    Vec2 m_pos;

public:
    void setPosition(Vec2 pos)
    {
        m_pos = pos;
    }
    void printPostition()
    {
        std::cout << m_pos.x << "  " << m_pos.y << std::endl;
    }
};

class Entity
{
private:
    int m_id;
    std::string m_tag;

public:
    std::shared_ptr<CTransofrm> m_ctransform;
    Entity(std::string tag, int id) : m_tag(tag), m_id(id) {}
};


int main()
{
    Entity e("player", 0);

    e.m_ctransform = std::make_shared<CTransofrm>();
    e.m_ctransform->setPosition(Vec2(2, 3));
    e.m_ctransform->printPostition();

    return 0;
}