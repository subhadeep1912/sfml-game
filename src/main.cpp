#include "include/PlayerMovement.h"
#include <iostream>
#include <thread>
#include <X11/Xlib.h>
#include "include/imgui.h"
#include "include/imgui-SFML.h"


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

    
    
    sf::RectangleShape rectShape(sf::Vector2f(30.0f, 10.0f));

    
    rectShape.setFillColor(sf::Color(sf::Color::Cyan));
    // std::thread th(printStuff, &window, WIDTH, HEIGHT);
    // ImGui::Text("Hello, world %d", 123);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        
        
        mainMovement(&window, WIDTH, HEIGHT, SPEED, &rectShape);
        
        ImGui::SFML::Update(window, deltaClock.restart());
        // std::cout<<"YOO->"<<rectShape.getPosition().x<<rectShape.getPosition().y<<std::endl;
        // th2.detach();
        ImGui::Begin("YOOO");
        ImGui::Button("BRUHH", ImVec2(200, 200));
        ImGui::End();
        
        // std::cout<<std::thread::hardware_concurrency()<<std::endl;
        ImGui::SFML::Render(window);
        
    }
    // th.detach();

    ImGui::SFML::Shutdown();
    

    return 0;
}