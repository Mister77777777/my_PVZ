#include "HelloWorldScene.h"
USING_NS_CC;
plant::plant(Sprite*outside_sprite)
{
	Sprite::onEnter();
	sprite = outside_sprite;
	position = sprite->getPosition();
	row = static_cast<int>((position.x -125 ) / 85);  /*�̶�λ�÷���ȡֵ�̶ܹ������迼����������*/
	line = static_cast<int>((470 - position.y) / 100);
	plant_init();
	this->scheduleUpdate();
}
plant::~plant()
{
	board[line][row] = NULL;
	Sprite::onExit();
}
void plant::update(float dt)
{
	switch (line)      /*���������õ���Ӧ���ϵĽ�ʬ����*/
	{
	case 0:
		size = line_1.size();
		break;
	case 1:
		size = line_2.size();
		break;
	case 2:
		size = line_3.size();
		break;
	case 3:
		size = line_4.size();
		break;
	case 4:
		size = line_5.size();
		break;
	}
	if(size!=0)       /*��һ����*/
		interval--;
	if (interval == 0)
	{
		shoot();
		interval = BULLET_SHOOT;
	}
	if (blood <= 0)
	{
		die();
	}
}
void plant::plant_init()
{
	loadResource();          /*������Դ*/
	wait();
}
void plant::die()
{
	unscheduleUpdate();    /*�رն�ʱ��*/
	sprite->getParent()->removeChild(sprite);
	delete board[line][row];
}
void plant ::loadResource()
{
	init_animate();
	init_sound();
}
void plant::wait()
{
	is_wait = true;
	sprite->stopAllActions();
	sprite->runAction(RepeatForever::create(
		Animate::create(Animation::createWithSpriteFrames(waitFrames, 1.0 / 15))));;
}
void plant::init_sound()
{}
void plant::init_animate()
{
	init_wait_animate();
}
void plant::init_wait_animate()
{
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/1.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/2.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/3.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/4.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/5.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/6.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/7.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/8.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/9.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/10.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/11.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/12.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/bullet_shooter/13.png", Rect(0, 0, 75, 75)));
}
void plant::shoot()
{
	auto bullet_sprite = Sprite::create("pictures/bullet/pea.png");
	(sprite->getParent())->addChild(bullet_sprite, 3);  /*��sprite�л�ȡ�丸ĸ�����ӵ���ӵ�����Ů��*/
	bullet_sprite->setPosition(Vec2(position.x+20,position.y+13));
	bullet* pea = new bullet(bullet_sprite);
	all_bullet.push_back(pea);
}

/*����Ϊֲ�����ĺ��������㶹����Ϊ����*/

sunflower::sunflower(Sprite* outside_sprite) :plant(outside_sprite)
{
	plant_init();
	/*���û���ĺ��ι��캯��������ʾ����*/
}
void sunflower::update(float dt)
{
	create_interval--;
	if (create_interval == 0)
	{
		create_sun();
		create_interval = SUNFLOWER_CREATE;
	}
	if (blood <= 0)
	{
		die();
	}
}
void sunflower::loadResource()
{
	this->init_animate();
}
void sunflower::wait()
{
	sprite->stopAllActions();
	sprite->runAction(RepeatForever::create(
		Animate::create(Animation::createWithSpriteFrames(waitFrames, 1.0 / 15))));;
}
void sunflower::plant_init()
{
	this->loadResource();          /*������Դ*/
	this->wait();
}
void sunflower::init_animate()
{
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/1.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/2.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/3.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/4.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/5.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/6.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/7.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/8.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/9.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/10.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/11.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/12.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/13.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/14.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/15.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/16.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/17.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/sunflower/18.png", Rect(0, 0, 75, 75)));
}
void sunflower::create_sun()
{
	auto s = Sprite::create("pictures/sun.png");
	sun* a = new sun(s);
	
	all_sun.push_back(a);
	sprite->getParent()->addChild(s, 3);
	s->setPosition(position.x,position.y);     /*�����տ�λ��Ϊ��׼*/
	a->create();
}
/*k����Ϊ���տ�����д����*/

nut::nut(Sprite* outside_sprite) :plant(outside_sprite)
{
	plant_init();
	/*���û���ĺ��ι��캯��������ʾ����*/
}
void nut::plant_init()
{
	blood = 10000;                 /*��Ѫ���θ�*/
	this->loadResource();          /*������Դ*/
	this->wait();
}
void nut::loadResource()
{
	this->init_animate();
}
void nut::init_animate()
{
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/1.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/2.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/3.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/4.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/5.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/6.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/7.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/nut/8.png", Rect(0, 0, 75, 75)));
}
void nut::wait()
{
	sprite->stopAllActions();
	sprite->runAction(RepeatForever::create(
		Animate::create(Animation::createWithSpriteFrames(waitFrames, 1.0 / 15))));;
}
void nut::update(float dt)
{
	if (blood <= 0)
	{
		die();
	}
}


/*����Ϊ�������д����*/

potato_mine::potato_mine(Sprite* outside_sprite) :plant(outside_sprite)
{
	plant_init();
	/*���û���ĺ��ι��캯��������ʾ����*/
}
void potato_mine::plant_init()
{
	blood = 10000;
	sprite->stopAllActions();
	this->loadResource();
}
void potato_mine::update(float dt)
{
	if(start_interval!=0)     /*����ʱ��*/
		start_interval--;
	else                     /*������ʼ���ǰ����ʬ*/
	{
		if (!(is_ready))       /*û�л���ɶ�������������*/
		{
			ready();
			is_ready = 1;
		}
		std::vector<zombie*>::iterator it;
		switch (line)
		{
		case 0:
			for (it = line_1.begin(); it < line_1.end(); it++)
			{
				if ((*it)->position.x - position.x < 40&&(*it)->position.x-position.x>=0)
				{
					(*it)->blood = -1;
					this->die(); /*������*/
					play_music();
				}
			}
			break;
		case 1:
			for (it = line_2.begin(); it < line_2.end(); it++)
			{
				if ((*it)->position.x - position.x < 40&&(*it)->position.x - position.x >= 0)
				{
					(*it)->blood = -1;
					this->die(); /*������*/
					play_music();
				}
			}
			break;
		case 2:
			for (it = line_3.begin(); it < line_3.end(); it++)
			{
				if ((*it)->position.x - position.x < 40 && (*it)->position.x - position.x >= 0)
				{
					(*it)->blood = -1;
					this->die(); /*������*/
					play_music();
				}
			}
			break;
		case 3:
			for (it = line_4.begin(); it < line_4.end(); it++)
			{
				if ((*it)->position.x - position.x < 40 && (*it)->position.x - position.x >= 0)
				{
					(*it)->blood = -1;
					this->die(); /*������*/
					play_music();
				}
			}
			break;
		case 4:
			for (it = line_5.begin(); it < line_5.end(); it++)
			{
				if ((*it)->position.x - position.x < 40 && (*it)->position.x - position.x >= 0)
				{
					(*it)->blood = -1;
					this->die(); /*������*/
					play_music();
				}
			}
			break;
		}
	}
	if (blood < 0)
		die();
}
void potato_mine::ready()
{
	sprite->stopAllActions();
	sprite->runAction(RepeatForever::create(
		Animate::create(Animation::createWithSpriteFrames(waitFrames, 1.0 / 15))));;
}
void potato_mine::wait()
{
	sprite->setTexture("pictures/plant/potato_mine/wait.png");
}
void potato_mine::play_music()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect("Music/potato_mine.mp3", false);
}
void potato_mine::loadResource()
{
	init_animate();
}
void potato_mine::init_animate()
{
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/1.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/2.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/3.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/4.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/5.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/6.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/7.png", Rect(0, 0, 75, 75)));
	waitFrames.pushBack(SpriteFrame::create("pictures/plant/potato_mine/8.png", Rect(0, 0, 75, 75)));
}
/*����Ϊ����������д����*/