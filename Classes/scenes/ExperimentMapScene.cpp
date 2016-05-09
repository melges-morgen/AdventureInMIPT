//
// Created by melges on 09.05.16.
//

#include <2d/CCTMXTiledMap.h>
#include <2d/CCTMXLayer.h>
#include <2d/CCSprite.h>
#include <base/CCDirector.h>
#include <base/CCEventListenerKeyboard.h>
#include <base/CCEventDispatcher.h>
#include <base/CCEventListenerMouse.h>
#include <utils.h>
#include "ExperimentMapScene.h"

USING_NS_CC;

Scene *ExperimentMapScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ExperimentMapScene::create();
    scene->addChild(layer);

    return scene;
}

ExperimentMapScene::ExperimentMapScene() : director_(Director::getInstance())
{
}

ExperimentMapScene::~ExperimentMapScene()
{

}

bool ExperimentMapScene::init()
{
    if(!Layer::init())
        return false;

    auto map = TMXTiledMap::create("maps/experiment_map.tmx");
    addChild(map, 0, 0);
    map->setPosition(0, 0);

    auto instrumentalObjects = map->getObjectGroup("InstrumentalObjects");
    auto spawnPoint = instrumentalObjects->getObject("SpawnPoint");

    auto hero = Sprite::create("sprites/people/princess_one.png");

    addChild(hero);
    hero->setPosition(utils::getCenterScreenCoordinates());
//            spawnPoint["x"].asFloat(),
//            spawnPoint["y"].asFloat()
//    );


    auto eventListener = EventListenerMouse::create();

    eventListener->onMouseDown = [=](EventMouse* event)
    {
        Vec2 mouseClickLocation = event->getLocation();
        map->setPosition(utils::normalizeMouseEventLocation(mouseClickLocation));
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, map);

    return true;
}







