#include "HelloWorldScene.h"
USING_NS_CC;
void card::card_init()
{
	Sprite::onEnter();
	init_listener();
	sprite->setPosition(Vec2(170,550));
	cost = 100;
	this->scheduleUpdate();
}
void card::update(float dt)
{	
	if (total < cost)   /*������ⲻ��������ɶ�����������*/
		;
}
void card::init_listener()
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�����ǵ��״̬ʱ�ļ�����*/
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(card::touch_began, this);
	cardListener->onTouchEnded = CC_CALLBACK_2(card::touch_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
bool card::touch_began(Touch *t,Event *e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto now = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (now->getBoundingBox().containsPoint(pt))
	{
		is_select = 1;     /*���Ϊ���״̬��ִ����һ��������������*/
		return true;
	}
	return false;
}
bool card::touch_end(Touch*t,Event*e)
{
	Vec2 pt = t->getLocation();
	auto now = static_cast<Sprite*>(e->getCurrentTarget());
	if (now->getBoundingBox().containsPoint(pt))
	{
		if (total >= cost)
		{
			sprite->setTexture("pictures/card/bullet_shooter_select.png");
			init_listener_select();
			return true;
		}
	}
	return false;
}
void card::add_plant(double x,double y)
{
	int row = static_cast<int>((x - 75) / 85);
	int line = static_cast<int>((520 - y) / 100);
	/*���ǵ��������㲻�����������룬�ȼ���50�ڽ�������*/
	auto s = Sprite::create("pictures/plant/bullet_shooter/1.png");
	sprite->getParent()->addChild(s, 2);
	s->setPosition(row * 85 + 125, 470 - line  * 100);
	plant* shooter = new plant(s);
	board[line][row] = shooter;
}
void card::plant_music()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect("Music/plant.mp3", false, 1.0f, 1.0f, 1.0f);
}
bool card::move(Touch*t,Event*e)
{
	return true;
}
bool card::is_in_board(Vec2 pt)
{
	/*���ǵ�ִ��ѭ�����߽������жϲ������д������������Ч�ʣ�ֱ��ʹ���ж�*/
	/*��Ϊû�������������Զ��ȼ���5�ٽ����ж�*/
	if (fabs(pt.x - BLOCK_1) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1)< 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_2) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_3) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_4) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_5) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_6) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_7) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_8) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_9) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1) < 20)
			return true;
		if (fabs(pt.y - LINE_2) < 20)
			return true;
		if (fabs(pt.y - LINE_3) < 20)
			return true;
		if (fabs(pt.y - LINE_4) < 20)
			return true;
		if (fabs(pt.y - LINE_5) < 20)
			return true;
		else
			return false;
	}
	return false;
}
bool card::is_empty(Vec2 pt)
{
	int row, line;
	/*��Ϊû���������룬�����ȼ���50�ڽ��м���*/
	row = static_cast<int>((fabs(pt.x - 125+50)) / 85);
	line = static_cast<int>((fabs(470+50 - pt.y)) / 100);
	if (row >= 0 && row < 9)
		if (line >= 0 && line < 5)
			if (board[line][row] == NULL)
				return true;
	return false;
}
void card::init_listener_select() 
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�������״̬ʱ�ļ�����*/
	_eventDispatcher->removeEventListenersForTarget(sprite);
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(card::touch_began_select, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
bool card::touch_began_select(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto now = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (total >= cost)
	{
		if (is_in_board(pt))
		{
			if (is_empty(pt))  /*���з���ֲ�����*/
			{
				total -= cost;
				add_plant(pt.x, pt.y);
				plant_music();
				is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
				is_used = 1;
				sprite->setTexture("pictures/card/bullets_shooter.png");
				init_listener();               /*�л�Ϊ��һ��������*/
				return true;
			}
		}
	}
	is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
	is_used = 1;
	sprite->setTexture("pictures/card/bullets_shooter.png");
	init_listener();               /*�л�Ϊ��һ��������*/
	return false;
}
card::~card()
{
	this->unscheduleUpdate();
	Sprite::onExit();
}


/*����Ϊ��Ƭ�������к���ʵ��*/
void sunflower_card::card_init()
{
	Sprite::onEnter();
	init_listener();
	sprite->setPosition(Vec2(240, 550));
	cost = 50;
}
void sunflower_card::init_listener()
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�����ǵ��״̬ʱ�ļ�����*/
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(sunflower_card::touch_began, this);
	cardListener->onTouchEnded = CC_CALLBACK_2(sunflower_card::touch_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
void sunflower_card::init_listener_select()
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�������״̬ʱ�ļ�����*/
	_eventDispatcher->removeEventListenersForTarget(sprite);
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(sunflower_card::touch_began_select, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
void sunflower_card::add_plant(double x, double y)
{
	int row = static_cast<int>((x - 75) / 85);
	int line = static_cast<int>((520 - y) / 100);
	/*���ǵ��������㲻�����������룬�ȼ���50�ڽ�������*/
	auto s = Sprite::create("pictures/plant/sunflower/1.png");
	sprite->getParent()->addChild(s, 2);
	s->setPosition(row * 85 + 125, 470 - line * 100);
	sunflower* a = new sunflower(s);
	board[line][row] = a;
}
bool sunflower_card::touch_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto now = static_cast<Sprite*>(e->getCurrentTarget());
	if (now->getBoundingBox().containsPoint(pt))
	{
		if (total >= cost)
		{
			sprite->setTexture("pictures/card/sunflower_select.png");
			init_listener_select();
			return true;
		}
	}
	return false;
}
bool sunflower_card::touch_began_select(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto now = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (total >= cost)
	{
		if (is_in_board(pt))
		{
			if (is_empty(pt))  /*���з���ֲ�����*/
			{
				total -= cost;
				add_plant(pt.x, pt.y);
				plant_music();
				is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
				is_used = 1;
				sprite->setTexture("pictures/card/sunflower.png");
				init_listener();               /*�л�Ϊ��һ��������*/
				return true;
			}
		}
	}
	is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
	is_used = 1;
	sprite->setTexture("pictures/card/sunflower.png");
	init_listener();               /*�л�Ϊ��һ��������*/
	return false;
}
/*����Ϊ���տ���Ƭ�ຯ��ʵ��*/
void nut_card::card_init()
{
	Sprite::onEnter();
	init_listener();
	sprite->setPosition(Vec2(310, 550));
	cost = 50;
}
void nut_card::init_listener()
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�����ǵ��״̬ʱ�ļ�����*/
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(nut_card::touch_began, this);
	cardListener->onTouchEnded = CC_CALLBACK_2(nut_card::touch_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
void nut_card::init_listener_select()
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�������״̬ʱ�ļ�����*/
	_eventDispatcher->removeEventListenersForTarget(sprite);
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(nut_card::touch_began_select, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
bool nut_card::touch_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto now = static_cast<Sprite*>(e->getCurrentTarget());
	if (now->getBoundingBox().containsPoint(pt))
	{
		if (total >= cost)
		{
			sprite->setTexture("pictures/card/nut_select.png");
			init_listener_select();
			return true;
		}
	}
	return false;
}
bool nut_card::touch_began_select(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto now = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (total >= cost)
	{
		if (is_in_board(pt))
		{
			if (is_empty(pt))  /*���з���ֲ�����*/
			{
				total -= cost;
				add_plant(pt.x, pt.y);
				plant_music();
				is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
				is_used = 1;
				sprite->setTexture("pictures/card/nut.png");
				init_listener();               /*�л�Ϊ��һ��������*/
				return true;
			}
		}
	}
	is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
	is_used = 1;
	sprite->setTexture("pictures/card/nut.png");
	init_listener();               /*�л�Ϊ��һ��������*/
	return false;
}
void nut_card :: add_plant(double x, double y)
{
	int row = static_cast<int>((x - 75) / 85);
	int line = static_cast<int>((520 - y) / 100);
	/*���ǵ��������㲻�����������룬�ȼ���50�ڽ�������*/
	auto s = Sprite::create("pictures/plant/nut/1.png");
	sprite->getParent()->addChild(s, 2);
	s->setPosition(row * 85 + 125, 470 - line * 100);
	nut* a = new nut(s);
	board[line][row] = a;
}

/*����Ϊ���ǽ��Ƭ��ʵ��*/
void potato_mine_card::card_init()
{
	Sprite::onEnter();
	init_listener();
	sprite->setPosition(Vec2(380, 550));
	cost = 25;
}
void potato_mine_card::init_listener()
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�����ǵ��״̬ʱ�ļ�����*/
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(potato_mine_card::touch_began, this);
	cardListener->onTouchEnded = CC_CALLBACK_2(potato_mine_card::touch_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
void potato_mine_card::init_listener_select()
{
	_eventDispatcher->removeEventListenersForTarget(sprite);  /*��ΪҪ�������ã�����Ƚ�������sprite�ϵļ������Ƴ�*/
	/*�������״̬ʱ�ļ�����*/
	_eventDispatcher->removeEventListenersForTarget(sprite);
	auto cardListener = EventListenerTouchOneByOne::create();
	cardListener->onTouchBegan = CC_CALLBACK_2(potato_mine_card::touch_began_select, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cardListener, sprite);
}
bool potato_mine_card::touch_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto now = static_cast<Sprite*>(e->getCurrentTarget());
	if (now->getBoundingBox().containsPoint(pt))
	{
		if (total >= cost)
		{
			sprite->setTexture("pictures/card/potato_mine_select.png");
			init_listener_select();
			return true;
		}
	}
	return false;
}
bool potato_mine_card::touch_began_select(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto now = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (total >= cost)
	{
		if (is_in_board(pt))
		{
			if (is_empty(pt))  /*���з���ֲ�����*/
			{
				total -= cost;
				add_plant(pt.x, pt.y);
				plant_music();
				is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
				is_used = 1;
				sprite->setTexture("pictures/card/potato_mine.png");
				init_listener();               /*�л�Ϊ��һ��������*/
				return true;
			}
		}
	}
	is_select = 0;     /*���Ϊ�ǵ��״̬��ִ����һ��������������*/
	is_used = 1;
	sprite->setTexture("pictures/card/potato_mine.png");
	init_listener();               /*�л�Ϊ��һ��������*/
	return false;
}
void potato_mine_card::add_plant(double x, double y)
{
	int row = static_cast<int>((x - 75) / 85);
	int line = static_cast<int>((520 - y) / 100);
	/*���ǵ��������㲻�����������룬�ȼ���50�ڽ�������*/
	auto s = Sprite::create("pictures/plant/potato_mine/1.png");
	sprite->getParent()->addChild(s, 2);
	s->setPosition(row * 85 + 125, 470 - line * 100);
	potato_mine* a = new potato_mine(s);
	board[line][row] = a;
}