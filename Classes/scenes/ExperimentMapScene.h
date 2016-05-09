//
// Created by melges on 09.05.16.
//

#ifndef MYGAME_EXPERIMENTMAPSCENE_H
#define MYGAME_EXPERIMENTMAPSCENE_H


#include <2d/CCLayer.h>
#include <2d/CCScene.h>

class ExperimentMapScene : cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    ExperimentMapScene();
    virtual ~ExperimentMapScene();

    CREATE_FUNC(ExperimentMapScene);

    virtual bool init();

private:
    cocos2d::Director *director_;
};


#endif //MYGAME_EXPERIMENTMAPSCENE_H
