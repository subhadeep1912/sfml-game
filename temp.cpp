#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    std::vector<sf::RectangleShape> rects;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed &&
                     event.mouseButton.button == sf::Mouse::Left) {
                sf::RectangleShape rect(sf::Vector2f(20, 20));
                rect.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
                rect.setFillColor(sf::Color::Green);
                rects.push_back(rect);
                std::cout<<"CLICKED"<<std::endl;
            }   
        }
        if(!rects.empty())
        {
            for (int i=0;i<rects.size();i++)
            {
                rects[i].move(0.05f, 0);
           
            }
            // rects[0].move(0.05f, 0);
        }

        window.clear();
        for (auto r : rects)
        {
            r.move(0.5f, 0);
            window.draw(r);
        }
        window.display();
    }
}