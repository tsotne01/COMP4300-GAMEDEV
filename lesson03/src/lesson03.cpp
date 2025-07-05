
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Initialized");

    sf::CircleShape circle(50);
    float circleX = 100.0f;
    float circleY = 100.0f;

    circle.setFillColor(sf::Color::Green);
    circle.setPosition(circleX, circleY);

    float circleSpeed = 0.1f;

    float speedX = 0.1f;
    float speedY = 0.1f;

    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;

    float circleHeight = circle.getLocalBounds().height;
    float circleWidth = circle.getLocalBounds().width;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type ==
                sf::Event::Closed)
                window.close();

        circleX += speedX;
        circleY += speedY;
        circle.setPosition(circleX, circleY);
        float circlePositionX = circle.getPosition().x;
        float circlePostitionY = circle.getPosition().y;
        if (windowWidth <= circlePositionX + circleWidth + 1)
        {
            speedX = -speedX;
        };
        if (windowHeight <= circlePostitionY + circleHeight + 1)
        {
            speedY = -speedY;
        };
        if (1 >= circlePostitionY)
        {
            speedY = -1 * speedY;
        };
        if (1 >= circlePositionX)
        {
            speedX = -1 * speedX;
        };
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}