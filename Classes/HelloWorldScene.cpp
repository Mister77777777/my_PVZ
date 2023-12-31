/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

Scene* PVZ::createScene()
{
    return PVZ::create();
}
// on "init" you need to initialize your instance
bool PVZ::init()
{
	if (!Scene::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize(); /*��ȡ���ڴ�С*/
	loadResource();             /*�������г�Ա*/
	get_progress();
	return true;
}
void PVZ::get_progress()
{
	level_1_ready = UserDefault::getInstance()->getBoolForKey("level_1_ready",0);
	level_2_ready = UserDefault::getInstance()->getBoolForKey("level_2_ready", 0);
}
void PVZ::loadResource()
{
	addBackground();
	addstartButton();
	addexitButton();
	addmusic();
}
void PVZ::addBackground()
{
	auto Surface = Sprite::create("pictures/icon/Surface.png");          /*����ͼƬ����*/
	Surface->setPosition(Vec2(450, 300));
	addChild(Surface, 0);      /*�������²�*/
}
void PVZ::addmusic()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("Music/start.ogg", true);
}

/*��ʼ��ť��غ���*/
void PVZ::addstartButton()     /*��ӿ�ʼ��ť*/
{
	startButton = Sprite::create("pictures/icon/begin.png");
	startButton->setPosition(Vec2(600,450));
	addChild(startButton, 1);
	init_startButton_event();
}
void PVZ::init_startButton_event()         /*������ʼ��ť������*/
{
	auto startListener = EventListenerTouchOneByOne::create();
	startListener->onTouchBegan = CC_CALLBACK_2(PVZ::touch_startButton_began, this);
	startListener->onTouchEnded = CC_CALLBACK_2(PVZ::touch_startButton_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(startListener, startButton);
}
bool PVZ::touch_startButton_began(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		log("began");
		sprite->setTexture("pictures/icon/begin_select.png"); /*��ͼƬ��Ϊѡ��״̬*/
		return true;
	}
	return false;
}
bool PVZ::touch_startButton_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		stopmusic();
		auto scene = select::createScene();     /*������һ�س���*/
		Director::getInstance()->replaceScene(scene);
		return true;
	}
	sprite->setTexture("pictures/icon/begin.png"); /*��ͼƬ��Ϊδѡ��״̬*/
	return false;
}


/*�˳���ť��غ���*/
void PVZ::addexitButton()      /*����˳���ť*/
{
	exitButton = Sprite::create("pictures/icon/exit.png");
	exitButton->setPosition(Vec2(850,570));
	addChild(exitButton, 1);
	init_exitButton_event();
}
void PVZ::init_exitButton_event()      /*�����˳�������*/
{
	auto exitListener = EventListenerTouchOneByOne::create();
	exitListener->onTouchBegan = CC_CALLBACK_2(PVZ::touch_exitButton_began, this);
	exitListener->onTouchEnded = CC_CALLBACK_2(PVZ::touch_exitButton_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(exitListener, exitButton);
}
bool PVZ::touch_exitButton_began(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		log("exit-began-true");
		sprite->setTexture("pictures/icon/exit_select.png"); /*��ͼƬ��Ϊѡ��״̬*/
		return true;
	}
	log("exit-began-false");
	return false;
}
bool PVZ::touch_exitButton_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		sprite->setTexture("pictures/icon/exit.png"); /*��ͼƬ��Ϊδѡ��״̬*/
		Director::getInstance()->end();      /*�˳�*/
		return true;
	}
	sprite->setTexture("pictures/icon/exit.png"); /*��ͼƬ��Ϊδѡ��״̬*/
	return false;
}
void PVZ::stopmusic()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->stopBackgroundMusic();
}

/*
������뾫��󶨲ο�����
https://blog.csdn.net/arv002/article/details/132108748?spm=1001.2014.3001.5501
*/