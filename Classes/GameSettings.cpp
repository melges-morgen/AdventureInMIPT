//
// Created by melge on 24.04.2016.
//

#include "GameSettings.h"

GameSettings* GameSettings::instance_ = 0;

GameSettings::GameSettings()
{
    userDefault_ = cocos2d::UserDefault::getInstance();
    if(userDefault_ != nullptr)
        instance_ = this;
}


GameSettings *GameSettings::getInstance()
{
    if(instance_ == nullptr)
        instance_ = new GameSettings();

    return instance_;
}

