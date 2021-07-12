#include "include/PlayerMovement.h"

static std::vector<sf::CircleShape> circs;

int count = 0;
void mainMovement(sf::RenderWindow *window, const float WIDTH, const float HEIGHT, const float SPEED, sf::RectangleShape *rectShape)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    sf::Vector2f pos = rectShape->getPosition();

    

    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        else if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            
            // circs.push_back(ShootShit(window, rectShape, mousePos));
            sf::CircleShape circ(10.0f);
            circ.setFillColor(sf::Color(sf::Color::Cyan));
            circ.setPosition((sf::Vector2f) pos);
            circs.push_back(circ);
            
            std::cout<<"YOO"<<std::endl;
        }
    }

    

    float rotation = RotateWithMouse(pos, mousePos);

    rectShape->setRotation(rotation);
    // std::cout <<(mousePos.x + mousePos.y)*(360)/(WIDTH + HEIGHT)<<std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    {
        
        rectShape->move(sf::Vector2f(SPEED, 0));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    {
        
        rectShape->setPosition(pos.x-SPEED, pos.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    {
        
        rectShape->setPosition(pos.x, pos.y-SPEED);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        
        rectShape->setPosition(pos.x, pos.y+SPEED);
    }
   
    window->clear();
    for (int i=0;i<circs.size();i++)
    {
        circs[i].move(ShootShit(window, &circs[i], mousePos));
        window->draw(circs[i]);
        
    }
    window->draw(*rectShape);
    window->display();
}
