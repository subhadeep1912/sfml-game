#include "include/PlayerMovement.h"
#include <iostream>
#include <thread>
#include <X11/Xlib.h>
#include "include/imgui.h"


void printStuff(sf::RenderWindow *window, const float WIDTH, const float HEIGHT)
{
    sf::Vector2i mousePos =  sf::Mouse::getPosition(*window);
    while (window->isOpen())
    {
        std::cout<<mousePos.x + ","<<mousePos.y<<std::endl;
    }
    
}


int main()
{
    XInitThreads();
    const float WIDTH = 800;
    const float HEIGHT = 600;
    const float SPEED = 0.05f;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game Window");
    pthread_t threads[2];
    
    
    sf::RectangleShape rectShape(sf::Vector2f(30.0f, 10.0f));

    
    rectShape.setFillColor(sf::Color(sf::Color::Cyan));
    // std::thread th(printStuff, &window, WIDTH, HEIGHT);
    // ImGui::Text("Hello, world %d", 123);
    
    while (window.isOpen())
    {
        
        
        mainMovement(&window, WIDTH, HEIGHT, SPEED, &rectShape);
            
        // std::cout<<"YOO->"<<rectShape.getPosition().x<<rectShape.getPosition().y<<std::endl;
        // th2.detach();
        
        
        std::cout<<std::thread::hardware_concurrency()<<std::endl;
        
    }
    // th.detach();


    

    return 0;
}