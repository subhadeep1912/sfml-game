#include "include/RotateWithMouse.h"

float RotateWithMouse(sf::Vector2f pos,sf::Vector2i mousePos)
{

    float a = pos.x - mousePos.x;
    float b = pos.y - mousePos.y;

    float rotation = atan2(b, a) * 180 / PI;
    return rotation;
}