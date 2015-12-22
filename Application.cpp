#include "Application.hpp"
#include "SnakeScene.hpp"
#include "MainMenu.hpp"
#include <ctime>
#include "Renderer.hpp"
#include <iostream>

Application::Application(unsigned short width, unsigned short height){
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glFrontFace(GL_CW);
    this->width =width;
    this->height = height;
    this->currentScene = std::unique_ptr<Scene>(new MainMenu());
    this->timeLastFrame = 0;
     std::cout << glGetString(GL_VERSION) << "\n";
}

void Application::gameLoop(){
    clock_t timer;
    timer = clock();
    this->currentScene->update(this->timeLastFrame);
    this->timeLastFrame = 0.001f * (clock() - timer);
    
}

void Application::drawLoop(){
    //Do game logic first
    this->gameLoop();
    
    //Give a common background to start with
    static const GLfloat background[] = { 0.0f, 0.25f, 0.0f, 1.0f };
    static const GLfloat depth = 1.0f;
    glViewport(0, 0, this->width, this->height);
    glClearBufferfv(GL_COLOR, 0, background);
    glClearBufferfv(GL_DEPTH, 0, &depth);
    
    GLenum errors = GL_NO_ERROR;
    while((errors = glGetError()) != GL_NO_ERROR){
        switch(errors){
            case GL_INVALID_ENUM:
                std::cout << "? \n";
                break;
            case GL_INVALID_VALUE:
                std::cout << "found invalid value \n";
                break;
            case GL_INVALID_OPERATION:
                std::cout << "found invalid operation \n";
                break;
            case GL_OUT_OF_MEMORY:
                std::cout << "Opengl experienced an out of memory exception \n";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                std::cout << "Invalid framebuffer operation \n";
                break;
            default:
                std::cout << "Found an error \n";
                break;
        }
        
    }
    
    float aspect = 1 * this->width / this->height;
    this->currentScene->draw(aspect);
}

void Application::keyDown(unsigned short keycode){
    //just give the keys back without doing anything
    this->currentScene->keyDown(keycode);
}


Application::~Application(){
    this->currentScene->onSceneClose();//Destroy all the stuff in the scene
    this->currentScene.reset();
    std::cout << "closing \n";
   
}