#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#pragma once
#include "Scene.hpp"
#include <memory>
#include <thread>
class Application{
private:
    std::unique_ptr<Scene> currentScene;
    float timeLastFrame;
    std::unique_ptr<std::thread> mainThread;
    bool shouldStop;
    unsigned short width, height;
public:
    Application(unsigned short,unsigned short);
    void gameLoop();
    void drawLoop();
    void keyDown(unsigned short);
    void onClose();
    
    
};



#endif