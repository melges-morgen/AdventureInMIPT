//
// Created by melges on 30.04.16.
//

#include <2d/CCTransition.h>
#include "GameMainMenuScene.h"
#include "ExperimentMapScene.h"

USING_NS_CC;

Scene *GameMainMenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameMainMenuScene::create();
    scene->addChild(layer);

    return scene;
}

GameMainMenuScene::GameMainMenuScene() :
        director_(Director::getInstance()),
        gameSettings_(GameSettings::getInstance()),
        menu_(nullptr)
{
    if(director_ == nullptr)
        throw std::runtime_error("Can't get game director instance");
}

bool GameMainMenuScene::init()
{
    if(!Layer::init())
        return false;

    switchToMainMenu();

    return true;
}

void GameMainMenuScene::switchToMainMenu()
{
    if(menu_ != nullptr)
        this->removeChild(menu_);

    Vector<MenuItem*> menuItems;
    auto continueGameItem = MenuItemFont::create("Продолжить", [&] (Ref *pSender) {});
    auto newGameItem = MenuItemFont::create("Новая игра", [&] (Ref *pSender)
    {
        director_->replaceScene(TransitionFade::create(0.5, ExperimentMapScene::createScene()));
    });
    auto settingsItem = MenuItemFont::create("Настройки", [&] (Ref *pSender) { switchToSettingsMenu(); });
    auto exitGameItem = MenuItemFont::create("Выход", [&] (Ref *pSender) { director_->end(); });
    menuItems.pushBack(continueGameItem);
    menuItems.pushBack(newGameItem);
    menuItems.pushBack(settingsItem);
    menuItems.pushBack(exitGameItem);

    continueGameItem->setEnabled(false);

    menu_ = Menu::createWithArray(menuItems);
    menu_->alignItemsVertically();

    this->addChild(menu_, 1);
}

void GameMainMenuScene::switchToSettingsMenu()
{
    if(menu_ != nullptr)
        this->removeChild(menu_);

    Vector<MenuItem*> menuItems;
    auto fullScreenItemOn = MenuItemFont::create("Полноэкрыннй режим");
    auto fullScreenItemOff = MenuItemFont::create("Оконный режим");
    auto fullScreenItem = MenuItemToggle::create();
    fullScreenItem->addSubItem(fullScreenItemOff);
    fullScreenItem->addSubItem(fullScreenItemOn);

    if(gameSettings_->isFullScreen())
        fullScreenItem->setSelectedIndex(1);
    else
        fullScreenItem->setSelectedIndex(0);
    
    fullScreenItem->setCallback([this, fullScreenItem, fullScreenItemOn] (Ref *pSender)
    {
        gameSettings_->setFullScreen(fullScreenItem->getSelectedItem() == fullScreenItemOn);
            
    });

    auto settingsItem = MenuItemFont::create("Назад", [&] (Ref *pSender) { switchToMainMenu(); });
    menuItems.pushBack(settingsItem);
    menuItems.pushBack(fullScreenItem);

    menu_ = Menu::createWithArray(menuItems);
    menu_->alignItemsVertically();

    this->addChild(menu_, 1);
}

GameMainMenuScene::~GameMainMenuScene()
{

}













