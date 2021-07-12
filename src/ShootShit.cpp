#include "include/ShootShit.h"

#define RADIUS 1
#define SPEED 0.1f

sf::Vector2f ShootShit(sf::RenderWindow* window, sf::CircleShape *circ, sf::Vector2i mousePos)
{
    
    float magnitude = sqrt(((mousePos.x - circ->getPosition().x)*(mousePos.x - circ->getPosition().x)) + ((mousePos.y - circ->getPosition().y)*(mousePos.y - circ->getPosition().y)));
    sf::Vector2f offset((mousePos.x - circ->getPosition().x)/magnitude, (mousePos.y - circ->getPosition().y)/magnitude);
    return offset;

}