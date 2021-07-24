#include "Drawer.h"


void Drawer::drawRec(float x, float y, float width , float height)
{
    sf::RectangleShape rectangle(sf::Vector2f(width , height));
    rectangle.setOrigin(width/2, 0);
    rectangle.setFillColor(sf::Color(255, 255, 255));
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(sf::Color(0, 0, 0));
    rectangle.move(x, y);

    renderTexture.draw(rectangle);
    renderTexture.display();
}

void Drawer::drawLine(float x, float y, float length, float thickness, float angle)
{

    sf::RectangleShape line(sf::Vector2f(length, thickness));

    line.setFillColor(sf::Color(0, 0, 0));
    line.rotate(angle);
    line.move(x, y);

    renderTexture.draw(line);
    renderTexture.display();
}

void Drawer::drawSquare(float x, float y, float width, float height)
{
    sf::ConvexShape convex;
    convex.setPointCount(4);

    convex.setPoint(0, sf::Vector2f(width/2, 0));
    convex.setPoint(1, sf::Vector2f(width, height/2));
    convex.setPoint(2, sf::Vector2f(width/2, height));
    convex.setPoint(3, sf::Vector2f(0, height/2));
    convex.setFillColor(sf::Color::White);
    convex.setOutlineThickness(1);
    convex.setOutlineColor(sf::Color::Black);
    convex.move(x - width/2, y);
    renderTexture.draw(convex);
    renderTexture.display();
}

void Drawer::saveToDisk(const char* path)
{
    renderTexture.getTexture().copyToImage().saveToFile(path);

}

void Drawer::drawShape(float x, float y)
{
    x -= 50;
    sf::CircleShape ellipse(25);
    ellipse.scale(2, 1);
    ellipse.move(x, y);
    ellipse.setFillColor(sf::Color::White);
    ellipse.setOutlineThickness(1);
    ellipse.setOutlineColor(sf::Color::Black);

    renderTexture.draw(ellipse);
    renderTexture.display();
}

Drawer::Drawer() {

    if (!renderTexture.create(2000, 2000))//1920 1080
    {
        // error...
    }
    renderTexture.clear(sf::Color(255, 255, 255));
}
