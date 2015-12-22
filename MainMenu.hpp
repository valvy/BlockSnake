#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP
#include "Scene.hpp"
#include "AssetManager.hpp"
#include <memory>
class MainMenu : public Scene{
private:
    std::shared_ptr<AssetManager> assetManager;

    int backgroundProgramRef;
 //   GLint mv_
public:
    MainMenu();
protected:
    virtual void update(float) override;
    virtual void draw(float) override;
    virtual void keyDown(unsigned short) override;
    virtual void onSceneClose() override;
    
    
};

#endif