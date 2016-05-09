//
// Created by melges on 10.05.16.
//

#ifndef MYGAME_UTILS_H
#define MYGAME_UTILS_H

#include <math/Vec2.h>
#include <base/CCDirector.h>

namespace utils
{
    inline cocos2d::Vec2 normalizeMouseEventLocation(cocos2d::Vec2 &location)
    {
        return cocos2d::Vec2(location.x, cocos2d::Director::getInstance()->getVisibleSize().height - location.y);
    }

    inline cocos2d::Vec2 getCenterScreenCoordinates()
    {
        return cocos2d::Vec2(
                cocos2d::Director::getInstance()->getWinSize().width / 2,
                cocos2d::Director::getInstance()->getWinSize().height / 2
        );
    }
}

#endif //MYGAME_UTILS_H
