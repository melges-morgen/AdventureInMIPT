//
// Created by melge on 24.04.2016.
//

#ifndef MYGAME_GAMESETTINGS_H
#define MYGAME_GAMESETTINGS_H

#include "exceptions/InitializationError.h"
#include "base/CCUserDefault.h"

class GameSettings
{
public:
    static GameSettings *getInstance();

    inline bool isFullScreen()
    {
        return userDefault_->getBoolForKey("fullScreen");
    }

    inline void setFullScreen(bool fullScreen)
    {
        userDefault_->setBoolForKey("fullScreen", fullScreen);
    }

private:
    GameSettings();
    GameSettings(const GameSettings&);
    GameSettings& operator=(GameSettings&);

    static GameSettings *instance_;

    cocos2d::UserDefault *userDefault_;
};


#endif //MYGAME_GAMESETTINGS_H
