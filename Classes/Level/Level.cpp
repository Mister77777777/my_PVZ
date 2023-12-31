#include"HelloWorldScene.h"
USING_NS_CC;
Level::~Level()
{
	this->off_zombie_schedule();
	this->off_plant_schedule();
	this->off_bullet_schedule();
	this->off_sun();
	this->off_car();
	this->removeAllChildren();
	this->unscheduleUpdate();
	line_1.clear();
	line_2.clear();
	line_3.clear();
	line_4.clear();
	line_5.clear();
	all_bullet.clear();
	all_sun.clear();
	total = 0;

}
void Level::off_car()
{
	for (int i=0; i<5; i++)
	{
		if (all_car[i] != NULL)
		{
			delete all_car[i];
		}
	}
}
void Level::off_sun()
{
	std::vector<sun*>::iterator it;
	for (it = all_sun.begin(); it != all_sun.end(); it++)
	{
		(*it)->unscheduleUpdate();
		delete (*it);
	}
}
void Level::off_zombie_schedule()
{
	std::vector<zombie*>::iterator it;
	for (it = line_1.begin(); it != line_1.end(); it++)   /*�ر����еĶ�ʱ������ɾ������õ��ڴ�*/
	{
		(*it)->unscheduleUpdate();
		delete (*it);
	}
	for (it = line_2.begin(); it != line_2.end(); it++)   /*�ر����еĶ�ʱ������ɾ������õ��ڴ�*/
	{
		(*it)->unscheduleUpdate();
		delete (*it);
	}
	for (it = line_3.begin(); it != line_3.end(); it++)   /*�ر����еĶ�ʱ������ɾ������õ��ڴ�*/
	{
		(*it)->unscheduleUpdate();
		delete (*it);
	}
	for (it = line_4.begin(); it != line_4.end(); it++)   /*�ر����еĶ�ʱ������ɾ������õ��ڴ�*/
	{
		(*it)->unscheduleUpdate();
		delete (*it);
	}
	for (it = line_5.begin(); it != line_5.end(); it++)   /*�ر����еĶ�ʱ������ɾ������õ��ڴ�*/
	{
		(*it)->unscheduleUpdate();
		delete (*it);
	}
}
void Level::off_bullet_schedule()
{
	std::vector<bullet*>::iterator it = all_bullet.begin();
	for (; it != all_bullet.end(); it++)
	{
		(*it)->unscheduleUpdate();
		delete* it;
	}
}
void Level::off_plant_schedule()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j]!=NULL)
			{
				delete board[i][j];
			}
		}
	}
}

Scene* Level::createScene()  
{
	return Level::create();
}
bool Level::init()
{
	if (!Scene::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize(); /*��ȡ���ڴ�С*/
	loadResoure();
	this->scheduleUpdate();
	return true;
}
void Level::loadResoure()
{
	addbackground();
	addshop();
	addcard();
	addloadingBar();
	addexitButton();
	/*	addstopButton();*/
	addlabel();
	addshovel();
	addmusic();
}
void Level::addbackground()
{
	auto background = Sprite::create("pictures/icon/level_1.jpg");          /*����ͼƬ����*/
	background->setPosition(Vec2(530, 295));
	addChild(background, 0);      /*�������²�*/
}
void Level::addlabel()
{
	sun_total = Label::createWithTTF(StringUtils::format("%d",total), "fonts/arial.ttf",20);
	sun_total->setTextColor(Color4B::BLACK);
	sun_total->setPosition(113, 515);
	this->addChild(sun_total, 5);
}
void Level::addshop()
{
	auto shop = Sprite::create("pictures/icon/shop.png");                  /*�̵�ͼƬ*/
	shop->setPosition(Vec2(300, 550));
	addChild(shop, 1);
}
void Level::addcard()
{
	bullet_shooter_card.sprite = Sprite::create("pictures/card/bullets_shooter.png");
	addChild(bullet_shooter_card.sprite, 2);
	bullet_shooter_card.card_init();
	/*�㶹���ֿ�Ƭ���*/

	Sunflower_Card.sprite = Sprite::create("pictures/card/sunflower.png");
	addChild(Sunflower_Card.sprite, 2);
	Sunflower_Card.card_init();
	/*���տ���Ƭ���*/


	Nut_Card.sprite = Sprite::create("pictures/card/nut.png");
	addChild(Nut_Card.sprite, 2);
	Nut_Card.card_init();
	/*���ǽ��Ƭ���*/

	Potato_Mine_Card.sprite = Sprite::create("pictures/card/potato_mine.png");
	addChild(Potato_Mine_Card.sprite, 2);
	Potato_Mine_Card.card_init();
	/*�����׿�Ƭ���*/
}
void Level::addcar()
{
	for (int i = 0; i < 5; i++)
	{
		auto sprite = Sprite::create("pictures/car.png");
		this->addChild(sprite, 3);
		sprite->setPosition(Vec2(CAR_POSITION, 470 - 100 * i));
		car *a=new car(sprite, i + 1);
		all_car[i] = a;     /*�洢�����鵱��*/
	}
}
void Level::addloadingBar()
{
	auto Bar = Sprite::create("pictures/icon/loadingBar.png");   /*������*/
	Bar->setPosition(Vec2(820, 10));
	this->addChild(Bar, 3);


	auto head = Sprite::create("pictures/icon/time.png");    /*��ʾʱ���õ�С��ʬͷ*/
	head->setPosition(Vec2(880, 10));
	this->addChild(head, 5);

	auto moveBy = MoveBy::create(time/60, Vec2(-120, 0));   
	/*��Ϊ��ʼ��ʱִ�ж����������������ֱ��ʹ����ʱ��/60(����ĵ�λ���룬ͷ�ļ���time�ĵ�λ��֡)���ƶ�*/
	head->runAction(moveBy);

	auto flag = Sprite::create("pictures/icon/flag.png");    /*��ʾ�����õ�����*/
	flag->setPosition(Vec2(760, 15));
	this->addChild(flag, 4);

}
void Level::addmusic()
{
	/*���ñ�������*/
	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("Music/gaming.mp3", true);  /*����Ϊtrue���ظ�����*/
}


void Level::addshovel()
{
	shovel = Sprite::create("pictures/icon/shovel.png");
	this->addChild(shovel, 4);
	shovel->setPosition(Vec2(500, 550));
	init_shovel();
}
void Level::init_shovel()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Level::touch_shovel_began, this);
	listener->onTouchEnded = CC_CALLBACK_2(Level::touch_shovel_end, this);
	listener->onTouchMoved = [&](Touch* t, Event* e)
	{
		Vec2 pt = t->getLocation();  /*�õ���ǰ����*/
		shovel->setPosition(pt);
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, shovel);
}
bool Level::touch_shovel_began(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		return true;
	}
	return false;
}
bool Level::is_in_board(Vec2 pt)
{
	/*���ǵ�ִ��ѭ�����߽������жϲ������д������������Ч�ʣ�ֱ��ʹ���ж�*/
	if (fabs(pt.x - BLOCK_1) < 20)        /*��⵱ǰ���Ӵ��Ƿ���Է���*/
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_2) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_3) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_4) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_5) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_6) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_7) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_8) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	if (fabs(pt.x - BLOCK_9) < 20)
	{
		if (fabs(pt.y - LINE_1 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_2 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_3 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_4 < 20))
			return true;
		else
			return false;
		if (fabs(pt.y - LINE_5 < 20))
			return true;
		else
			return false;
	}
	return false;
}
bool Level::is_empty(Vec2 pt)
{
	/*�жϸ�λ���Ƿ���ֲ��*/
	int row, line;
	row = static_cast<int>((pt.x - 125+50) / 85);  /*Ϊ��ʵ���������룬����һ����ʮ*/
	line = static_cast<int>((fabs(600 - pt.y)) / 100) - 1;
	if (row >= 0 && row < 9)
		if (line >= 0 && line < 5)
			if (board[line][row] == NULL)
				return true;
	return false;
}
bool Level::touch_shovel_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		if (is_in_board(pt))
		{
			if (!(is_empty(pt)))
			{
				int row = static_cast<int>((fabs(pt.x - 75)) / 85);
				int line = static_cast<int>((fabs(650 - pt.y)) / 100) - 1;
				board[line][row]->blood = 0;
			}
		}
		shovel->setPosition(Vec2(500, 550));
		return true;
	}
	return false;
}

void Level::addexitButton()      /*����˳���ť*/
{
	exitButton = Sprite::create("pictures/icon/exit.png");
	exitButton->setPosition(Vec2(800, 550));
	addChild(exitButton, 1);
	init_exitButton_event();
}
void Level::init_exitButton_event()      /*�����˳�������*/
{
	auto exitListener = EventListenerTouchOneByOne::create();
	exitListener->onTouchBegan = CC_CALLBACK_2(Level::touch_exitButton_began, this);
	exitListener->onTouchEnded = CC_CALLBACK_2(Level::touch_exitButton_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(exitListener, exitButton);
}
bool Level::touch_exitButton_began(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		sprite->setTexture("pictures/icon/exit_select.png"); /*��ͼƬ��Ϊѡ��״̬*/
		return true;
	}
	return false;
}
bool Level::touch_exitButton_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		sprite->setTexture("pictures/icon/exit.png"); /*��ͼƬ��Ϊδѡ��״̬*/
		back_to_select();
		return true;
	}
	sprite->setTexture("pictures/icon/exit.png"); /*��ͼƬ��Ϊδѡ��״̬*/
	return false;
}

void Level::addstopButton()      /*����˳���ť*/
{
	stopButton = Sprite::create("pictures/icon/stop.png");
	stopButton->setPosition(Vec2(700, 550));
	addChild(stopButton, 1);
	init_stopButton_event();
}
void Level::init_stopButton_event()      /*�����˳�������*/
{
	auto stopListener = EventListenerTouchOneByOne::create();
	stopListener->onTouchBegan = CC_CALLBACK_2(Level::touch_stopButton_began, this);
	stopListener->onTouchEnded = CC_CALLBACK_2(Level::touch_stopButton_end, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(stopListener, stopButton);
}
bool Level::touch_stopButton_began(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();      /*�õ���ǰ����*/
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());       /*ȡ�õ�ǰ����Ķ���*/
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		sprite->setTexture("pictures/icon/stop_select.png"); /*��ͼƬ��Ϊѡ��״̬*/
		return true;
	}
	return false;
}
bool Level::touch_stopButton_end(Touch* t, Event* e)
{
	Vec2 pt = t->getLocation();
	auto sprite = static_cast<Sprite*>(e->getCurrentTarget());
	if (sprite->getBoundingBox().containsPoint(pt))
	{
		sprite->setTexture("pictures/icon/stop.png"); /*��ͼƬ��Ϊδѡ��״̬*/
		stop();
		return true;
	}
	sprite->setTexture("pictures/icon/stop.png"); /*��ͼƬ��Ϊδѡ��״̬*/
	return false;
}
/*�ɵ��������Ӧ��������*/

void Level::add_zombie(double line)
{
	auto sprite = Sprite::create("pictures/zombie/normal/move/1.png");
	this->addChild(sprite, 3);
	sprite->setPosition(Vec2(START_POSITION, line));
	zombie* normal = new zombie(sprite, line);
	int i = static_cast<int>((600-line)/100);
	switch (i)
	{
	case 1:
		line_1.push_back(normal);
		break;
	case 2:
		line_2.push_back(normal);
		break;
	case 3:
		line_3.push_back(normal);
		break;
	case 4:
		line_4.push_back(normal);
		break;
	case 5:
		line_5.push_back(normal);
		break;
	}
}
void Level::add_Buckethead_zombie(double line)
{
	auto sprite = Sprite::create("pictures/zombie/Buckethead/move/1.png");
	this->addChild(sprite, 3);
	sprite->setPosition(Vec2(START_POSITION, line));
	Buckethead_zombie* normal = new Buckethead_zombie(sprite, line);
	int i = static_cast<int>((600 - line) / 100);
	switch (i)
	{
	case 1:
		line_1.push_back(normal);
		break;
	case 2:
		line_2.push_back(normal);
		break;
	case 3:
		line_3.push_back(normal);
		break;
	case 4:
		line_4.push_back(normal);
		break;
	case 5:
		line_5.push_back(normal);
		break;
	}
}
void Level::add_Flag_zombie(double line)
{
	auto sprite = Sprite::create("pictures/zombie/Flag/move/1.png");
	this->addChild(sprite, 3);
	sprite->setPosition(Vec2(START_POSITION, line));
	flag_zombie* normal = new flag_zombie(sprite, line);
	int i = static_cast<int>((600 - line) / 100);
	switch (i)
	{
	case 1:
		line_1.push_back(normal);
		break;
	case 2:
		line_2.push_back(normal);
		break;
	case 3:
		line_3.push_back(normal);
		break;
	case 4:
		line_4.push_back(normal);
		break;
	case 5:
		line_5.push_back(normal);
		break;
	}
}
void Level::add_plant(double row, double line)
{
	auto sprite = Sprite::create("pictures/plant/bullet_shooter/1.png");
	addChild(sprite, 2);
	sprite->setPosition(row, line);
	plant* shooter = new plant(sprite);
	/*Ϊ��ʵ���������룬����һ����ʮ*/
	board[static_cast<int>(static_cast<int>((600 - line) / 100) - 1)][static_cast<int>((row - 125+50) / 85)] = shooter;
}
void Level::add_sunflower(double x,double y)
{
	int row = static_cast<int>((x - 75) / 85);
	int line = static_cast<int>((520 - y) / 100);
	auto sprite = Sprite::create("pictures/plant/sunflower/1.png");
	addChild(sprite, 2);
	sprite->setPosition(row * 85 + 125, 470 - line * 100);
	sunflower* a = new sunflower(sprite);
	board[line][row] = a;
}
void Level::add_nut(double x, double y)
{
	int row = static_cast<int>((x - 75) / 85);
	int line = static_cast<int>((520 - y) / 100);
	auto sprite = Sprite::create("pictures/plant/nut/1.png");
	addChild(sprite, 2);
	sprite->setPosition(row * 85 + 125, 470 - line * 100);
	nut* a = new nut(sprite);
	board[line][row] = a;
}
void Level::add_potato(double x, double y)
{
	int row = static_cast<int>((x - 75) / 85);
	int line = static_cast<int>((520 - y) / 100);
	auto sprite = Sprite::create("pictures/plant/potato_mine/1.png");
	addChild(sprite, 2);
	sprite->setPosition(row * 85 + 125, 470 - line * 100);
	potato_mine* a = new potato_mine(sprite);
	board[line][row] = a;
}

/*����Ϊ���Թ���*/

void Level::addsun()
{
	auto s = Sprite::create("pictures/sun.png");
	sun* a = new sun(s);
	all_sun.push_back(a);
	addChild(s, 5);
	int x = 70 + rand() % 735;   /*�������ɺ�λ����[70,805)*/
	s->setPosition(x, SUN_START);
	a->fall();   /*ִ�е���*/
}
void Level::addzombie()
{
	int line = rand() % 5+1;   /*����������Ϊ[1,5]*/
	add_zombie(static_cast<double>(570-line*100));          /*���������Ƕ������ȶ���������һ����ʬ*/
}



void Level::update(float dt)
{
	sun_total->setString(StringUtils::format("%d", total));   /*ˢ��̫������*/
	gaming();       /*������Ϸ*/
}




void Level::back_to_select()
{
	stop_music();
	auto scene = select::createScene();
	Director::getInstance()->replaceScene(scene);
}
void Level::play_first_music()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect("Music/zombie_comming.mp3", false);   /*���β���*/
}
void Level::game_fail()
{
	stop();
	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("Music/losemusic.mp3", false);  
	/*ʧ�����ֲ���*/

	auto sprite = Sprite::create("pictures/icon/fail.png");
	this->addChild(sprite, 5);
	sprite->setPosition(Vec2(400, 350));
	auto label=Label::createWithTTF("PRESS TO BACK THE MENU", "fonts/Marker Felt.ttf", 50);
	label->setTextColor(Color4B::BLACK);
	label->setPosition(400, 100);
	this->addChild(label, 5);
	/*ʧ��ͼ�괴��*/

	auto listener = EventListenerTouchOneByOne::create(); 
	/*����������*/
	listener->onTouchBegan = [&](Touch* t, Event* e)    /*��������˳�*/
	{
		back_to_select();
		return true; 
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,label);
}
bool Level::judge_fail()
{
	/*��Ϊû�а����ٶȸ���Ľ�ʬ������ÿһ��vector�ĵ�һ��Ԫ��һ����λ����ǰ�Ľ�ʬ��ֻ����0λ�õĽ�ʬλ�ü���*/
	std::vector<zombie*>::iterator it;
	it = line_1.begin();
	if (line_1.size()!=0)
	{
		if ((*it)->position.x <= END_POSITION)
			return true;
	}
	it = line_2.begin();
	if (line_2.size() != 0)
	{
		if ((*it)->position.x <= END_POSITION)
			return true;
	}
	it = line_3.begin();
	if (line_3.size() != 0)
	{
		if ((*it)->position.x <= END_POSITION)
			return true;
	}
	it = line_4.begin();
	if (line_4.size() != 0)
	{
		if ((*it)->position.x <= END_POSITION)
			return true;
	}
	it = line_5.begin();
	if (line_5.size() != 0)
	{
		if ((*it)->position.x <= END_POSITION)
			return true;
	}
	return false;
}
void Level::game_win()
{
	set_level_ready();
	if (!(is_win_play))
	{
		auto audio = SimpleAudioEngine::getInstance();   /*ʤ�����ֲ���*/
		audio->stopAllEffects();
		audio->playEffect("Music/winmusic.mp3", false);
		is_win_play = 1;

		auto label = Label::createWithTTF("You Win!!!", "fonts/Marker Felt.ttf", 80); 
		label->setTextColor(Color4B::BLACK);
		label->setPosition(400, 300);
		this->addChild(label, 5);
		auto label2 = Label::createWithTTF("You have a new plant in next level", "fonts/Marker Felt.ttf", 60);
		label2->setTextColor(Color4B::BLACK);
		label2->setPosition(400, 100);
		this->addChild(label2, 5);
		/*��ʤͼ�괴��*/
	}
	else if (win_time != 0)     /*��¼����ʱ�䣬�����������л���ѡ�ؽ���*/
		win_time--;
	else
		back_to_select();
}
void Level::gaming()
{
	if (judge_fail())    /*�ж��Ƿ������Ϸ*/
		game_fail();
	sun_interval--;
	if (ready_interval > 0)
		ready_interval--;
	if (ready_interval == 0)    /*׼��ʱ�����ʱ��������*/
	{
		play_first_music();
		ready_interval--;
	}
	if (sun_interval == 0)   /*�����Բ�������*/
	{
		sun_interval = SUN_CREAT;   /*����һ������*/
		addsun(); 
	}
	if(time!=0)
	{
		if(ready_interval<0)          /*׼��ʱ���ſ�ʼ�������ͷŽ�ʬ*/
			zombie_interval--;          /*�ڵ������ʱ���ǰ�Ų�����ʬ*/
		time--;              /*�ڵ������ʱ���ǰÿ��update������ʱ��*/
	}
	if (zombie_interval == 0&&time!=0)  /*û��һ�󲨽�ʬǰ�����Բ�����ʬ*/
	{
		int num = rand() % 101;    /*ȡֵΪ[0,100]*/
		if (num > per)              /*����һ��һ�γ��������ĸ��� ��Ȼ����̫���˶�ˢ2����������*/
			num = 1;
		else
			num = 2;
		addzombie();               /*�������ɵĽ�ʬ�Ƕ��ٸ�����Ҫ����һ����ʬ*/
		if(num==1)
			zombie_interval = ZOMBIE_CREATE;  /*����һ������*/
		else
			zombie_interval = 1*60;  
		/*�����ɼ����Ϊ1�룬��ʵ�ֵ������ɵļ������Ȼ���һֱˢ����2��ֻ��˵��������*/
	}
	if (time == 0)
		flush();            /*�����ε���ʱ�ų�һ�󲨽�ʬ*/
	if (time == 0 
		&& is_flush==1
		&& line_1.size() == 0
		&& line_2.size() == 0
		&& line_3.size() == 0
		&& line_4.size() == 0
		&& line_5.size() == 0) /*�����һ��ִ��֮����ҵ�ǰ��ʬ��ɱ����ж�Ϊ��Ϸʤ��*/
		game_win();
}
void Level::flush()
{

	if (flush_time != 0)
	{
		if (flush_time % 100 == 0)
		{
			int tmp_line = rand() % 5 + 1; /*�����������������ʬ*/
			switch (tmp_line)
			{
			case 1:
				if (flush_time == 2000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_1);
				}
				if (num_1 <= 6)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_1++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_1);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_1);
				}
				break;
			case 2:
				if (flush_time == 2000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_2);
				}
				if (num_2 <= 6)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_2++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_2);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_2);
				}
				break;
			case 3:
				if (flush_time == 2000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_3);
				}
				if (num_3 <= 6)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_3++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_3);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_3);
				}
				break;
			case 4:
				if (flush_time == 2000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_4);
				}
				if (num_4 <= 6)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_4++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_4);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_4);
				}
				break;
			case 5:
				if (flush_time == 2000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_5);
				}
				if (num_5 <= 6)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_5++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_5);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_5);
				}
				break;
			}
		}
		flush_time--;
	}
	else
		is_flush = 1;    /*����Ϊ����ȫ�ͷŸò���*/
}
void Level::stop()
{
	stop_plant();
	stop_zombie();
	stop_music();
	this->unscheduleUpdate();   /*�Ѷ�ʱ�����˷�ֹ�����������*/
}
void Level::stop_plant()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != NULL)
			{
				board[i][j]->sprite->stopAllActions();
				board[i][j]->unscheduleUpdate();   /*�Ѷ�ʱ�����ˣ���ֹ���������ӵ�*/
			}
		}
	}
}
void Level::stop_bullet()
{
	std::vector<bullet*>::iterator it = all_bullet.begin();
	for (; it != all_bullet.end(); it++)
	{
		(*it)->unscheduleUpdate();
		(*it)->sprite->stopAllActions();
	}
}
void Level::stop_zombie()
{
	std::vector<zombie*>::iterator it;
	for (it = line_1.begin(); it != line_1.end(); it++)   
	{
		(*it)->unscheduleUpdate();
		(*it)->sprite->stopAllActions();
	}
	for (it = line_2.begin(); it != line_2.end(); it++)  
	{
		(*it)->unscheduleUpdate();
		(*it)->sprite->stopAllActions();
	}
	for (it = line_3.begin(); it != line_3.end(); it++)   
	{
		(*it)->unscheduleUpdate();
		(*it)->sprite->stopAllActions();
	}
	for (it = line_4.begin(); it != line_4.end(); it++)  
	{
		(*it)->unscheduleUpdate();
		(*it)->sprite->stopAllActions();
	}
	for (it = line_5.begin(); it != line_5.end(); it++)  
	{
		(*it)->unscheduleUpdate();
		(*it)->sprite->stopAllActions();
	}
}
void Level::stop_sun()
{
	std::vector<sun*>::iterator it;
	for (it = all_sun.begin(); it != all_sun.end(); it++)
	{
		(*it)->unscheduleUpdate();
		(*it)->sprite->stopAllActions();
	}
}
void Level::stop_music()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->stopAllEffects();
}
/*����Ϊ�ؿ��������ú���*/


Scene* Level_1::createScene()
{
	return Level_1::create();
}
void Level_1::addcard()
{
	per = 30;
	flush_time = 1000;
	Buckethead_num = 0;
	bullet_shooter_card.sprite = Sprite::create("pictures/card/bullets_shooter.png");
	addChild(bullet_shooter_card.sprite, 2);
	bullet_shooter_card.card_init();
	/*�㶹���ֿ�Ƭ���*/

	Sunflower_Card.sprite = Sprite::create("pictures/card/sunflower.png");
	addChild(Sunflower_Card.sprite, 2);
	Sunflower_Card.card_init();
	/*���տ���Ƭ���*/
	addcar();
}
void Level_1::flush()
{
	if (flush_time != 0)
	{
		if (flush_time % 100 == 0)
		{
			int tmp_line = rand() % 5 + 1; /*�����������������ʬ*/
			switch (tmp_line)
			{
			case 1:
				if (flush_time == 1000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_1);
				}
				if (num_1 <= 2)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_1++;
					add_zombie(LINE_1);
				}
				break;
			case 2:
				if (flush_time == 1000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_2);
				}
				if (num_2 <= 2)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_2++;
					add_zombie(LINE_2);
				}
				break;
			case 3:
				if (flush_time == 1000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_3);
				}
				if (num_3 <= 2)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_3++;
					add_zombie(LINE_3);
				}
				break;
			case 4:
				if (flush_time == 1000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_4);
				}
				if (num_4 <= 2)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_4++;
					add_zombie(LINE_4);
				}
				break;
			case 5:
				if (flush_time == 1000)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_5);
				}
				if (num_5 <= 2)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_5++;
					add_zombie(LINE_5);
				}
				break;
			}
		}
		flush_time--;
	}
	else
		is_flush = 1;    /*����Ϊ����ȫ�ͷŸò���*/
}
void Level_1::set_level_ready()
{
	level_1_ready = 1;
    UserDefault::getInstance()->setBoolForKey("level_1_ready", 1);
}
/*����Ϊ�ؿ�һ����д����ʵ��*/
Scene* Level_2::createScene()
{
	return Level_2::create();
}
void Level_2::addcard()
{
	per = 50;
	flush_time = 1500;
	Buckethead_num = 5;
	bullet_shooter_card.sprite = Sprite::create("pictures/card/bullets_shooter.png");
	addChild(bullet_shooter_card.sprite, 2);
	bullet_shooter_card.card_init();
	/*�㶹���ֿ�Ƭ���*/

	Sunflower_Card.sprite = Sprite::create("pictures/card/sunflower.png");
	addChild(Sunflower_Card.sprite, 2);
	Sunflower_Card.card_init();
	/*���տ���Ƭ���*/


	Nut_Card.sprite = Sprite::create("pictures/card/nut.png");
	addChild(Nut_Card.sprite, 2);
	Nut_Card.card_init();
	/*���ǽ��Ƭ���*/
	addcar();
}
void Level_2::flush()
{
	if (flush_time != 0)
	{
		if (flush_time % 100 == 0)
		{
			int tmp_line = rand() % 5 + 1; /*�����������������ʬ*/
			switch (tmp_line)
			{
			case 1:
				if (flush_time == 1500)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_1);
				}
				if (num_1 <= 4)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_1++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_1);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_1);
				}
				break;
			case 2:
				if (flush_time == 1500)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_2);
				}
				if (num_2 <= 4)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_2++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_2);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_2);
				}
				break;
			case 3:
				if (flush_time == 1500)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_3);
				}
				if (num_3 <= 4)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_3++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_3);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_3);
				}
				break;
			case 4:
				if (flush_time == 1500)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_4);
				}
				if (num_4 <= 4)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_4++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_4);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_4);
				}
				break;
			case 5:
				if (flush_time == 1500)   /*�������Ľ�ʬ*/
				{
					add_Flag_zombie(LINE_5);
				}
				if (num_5 <= 4)
				{                 /*��ÿһ�з��䵽�Ľ�ʬ������ƽ��һ��*/
					num_5++;
					if (Buckethead_num != 0)     /*�����ͨ��ʬ*/
					{
						add_Buckethead_zombie(LINE_5);
						Buckethead_num--;
					}
					else
						add_zombie(LINE_5);
				}
				break;
			}
		}
		flush_time--;
	}
	else
		is_flush = 1;    /*����Ϊ����ȫ�ͷŸò���*/
}
void Level_2::set_level_ready()
{
	level_2_ready = 1;
	UserDefault::getInstance()->setBoolForKey("level_2_ready", 1);
}
/*����Ϊ�ؿ�������д����ʵ��*/