#include"HelloWorldScene.h"
USING_NS_CC;
sun::sun(Sprite*outside_sprite)
{
	Sprite::onEnter();
	sprite=outside_sprite;
	sun_init();
}
sun::~sun()
{
	Sprite::onExit();
}
void sun::sun_init()
{
	init_listener();
	this->scheduleUpdate();
}
void sun::update(float dt)
{
	Vec2 pt=sprite->getPosition();
	if (pt == Vec2(105, 545)&&is_move==1)    
		/*Ϊ�˷�ֹ˵��Ȼ����ʱ����(105,545)λ�þͱ������ʹ��is_move���ж��Ƿ񱻵��*/
	{
		sprite->getParent()->removeChild(sprite);
		total += 50;
		this->unscheduleUpdate();
	}
}
void sun::init_listener()
{
	auto sunListener = EventListenerTouchOneByOne::create();
	sunListener->onTouchBegan = CC_CALLBACK_2(sun::touch_began, this);
	sunListener->onTouchEnded = CC_CALLBACK_2(sun::touch_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(sunListener, sprite);
}
bool sun::touch_began(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto now = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (now->getBoundingBox().containsPoint(pt))
	{
		return true;
	}
	return false;
}
bool sun::touch_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto now = static_cast<Sprite*>(e->getCurrentTarget());
	if (now->getBoundingBox().containsPoint(pt))
	{
		play_music();
		this->move();
		return true;
	}
	return false;
}
void sun::play_music()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect("Music/sun.mp3", false);
}
void sun::move()
{
	auto moveto = MoveTo::create(0.5,Vec2(105,545));
	sprite->stopAllActions();
	sprite->runAction(moveto);
	is_move = 1;
}
void sun::create()
{
	/*ִ�����ⱻ����ʱ����������*/
	auto up = MoveBy::create(2, Vec2(5, 50));
	auto down = MoveBy::create(2, Vec2(5, -75));
	auto seq = Sequence::create(up,down, nullptr);
	sprite->runAction(seq);
}
void sun::fall()
{
	int distance = 200 + rand() % 400;    /*��������λ����[200,600)*/
	auto moveto = MoveTo::create(30, Vec2(sprite->getPosition().x, -distance));
	sprite->runAction(moveto);
}