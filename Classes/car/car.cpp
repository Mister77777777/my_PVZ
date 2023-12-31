#include"HelloWorldScene.h"
USING_NS_CC;
car::car(Sprite* outside_sprite,int outside_line)
{
	Sprite::onEnter();
	sprite = outside_sprite;
	line = outside_line;
	this->scheduleUpdate();
}
void car::update(float dt)
{
	std::vector<zombie*>::iterator it;   	/*ָ��ʬ����ĵ�����*/
	int size = 0;  /*���ڵõ���vector������*/
	switch (line) /*������ֵ����������ָ���Ӧvector�Ŀ�ͷλ��*/
	{
	case 1:
		it = line_1.begin();
		size = line_1.size();
		break;
	case 2:
		it = line_2.begin();
		size = line_2.size();
		break;
	case 3:
		it = line_3.begin();
		size = line_3.size();
		break;
	case 4:
		it = line_4.begin();
		size = line_4.size();
		break;
	case 5:
		it = line_5.begin();
		size = line_5.size();
		break;
	}
	if (!(is_on))       /*δ����С��ʱ�ж���ǰ�潩ʬ��λ���Ƿ񵽴�����λ��*/
	{
		if(size!=0)   /*���ȵ��н�ʬ*/
		{
			if ((*it)->position.x <= CAR_POSITION+20)
			{
				move();
				is_on = 1;
			}
		}
	}
	else
	{
		position = sprite->getPosition();   /*��õ�ǰС��������*/
		if (size != 0) 
		{
			if ((*it)->position.x - position.x < 80)     /*�ж�ʱ��ʬ�϶���С���ұߣ����þ���ֵ*/
			{
				(*it)->blood = -1;
			}
		}
	}
	if (position.x == START_POSITION)  /*�ƶ����յ�λ���˾����ٵ�*/
		die();
}
void car::move()
{
	auto moveby = MoveBy::create(4, Vec2(START_POSITION, 0));
	sprite->runAction(moveby);
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect("Music/car.mp3", false, 1.0f, 1.0f, 1.0f);
}
void car::die()
{
	unscheduleUpdate();    /*�رն�ʱ��*/
	sprite->getParent()->removeChild(sprite);
	delete all_car[line - 1];
}
car::~car()
{
	all_car[line - 1] = NULL;
	Sprite::onExit();
}