
#include <iostream>

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

    void subtract(const Vec2 &rhs)
    {
        x = x - rhs.x;
        y = y - rhs.y;
    }

    Vec2 normalize()
    {
        float magnitude = (y * y) * (x * x);
        return Vec2(x / magnitude, y / magnitude);
    }
};

int main(int argc, char *argv[])
{
    Vec2 v1(150.0, 233.0);
    Vec2 v2(100.0, 200.0);

    Vec2 v3 = v1.add(v2);

    std::cout << v3.x << std::endl;

    v3.subtract(v2);

    std::cout << v3.x << std::endl;

    std::cout << v2.x << std::endl;

    v2.subtract(v1);
    std::cout << v2.x << std::endl;
    Vec2 N = v3.normalize();

    std::cout << N.x << "  " << N.y << std::endl;
    return 0;
}