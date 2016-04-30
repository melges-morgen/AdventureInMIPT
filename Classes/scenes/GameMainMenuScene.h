//
// Created by melges on 30.04.16.
//

#ifndef MYGAME_GAMEMAINMENUSCENE_H
#define MYGAME_GAMEMAINMENUSCENE_H


#include <ui/CocosGUI.h>
#include <2d/CCLayer.h>
#include <base/CCDirector.h>
#include <2d/CCMenu.h>
#include <GameSettings.h>

class GameMainMenuScene : cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    GameMainMenuScene();
    virtual ~GameMainMenuScene();

    CREATE_FUNC(GameMainMenuScene);

    virtual bool init();

    void switchToMainMenu();

    void switchToSettingsMenu();

private:
    cocos2d::Director *director_;
    GameSettings *gameSettings_;
    cocos2d::Menu *menu_;
};


#endif //MYGAME_GAMEMAINMENUSCENE_H
