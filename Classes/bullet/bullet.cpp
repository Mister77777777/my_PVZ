#include"HelloWorldScene.h"
USING_NS_CC;
bullet::bullet(Sprite* outside_sprite)
{
	Sprite::onEnter();
	sprite = outside_sprite;
	position = sprite->getPosition();
	bullet::get_line();
	bullet::move();
	scheduleUpdate();
}
bullet::~bullet()
{
	Sprite::onExit();
}
void bullet::update(float dt)
{
	position = sprite->getPosition();
	bullet::is_zombie();
}
void bullet::hit_music()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect("Music/bullet_hit.mp3", false, 1.0f, 1.0f, 1.0f);
}

void bullet::hit_Buckethead_music()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->playEffect("Music/shieldhit.mp3", false, 1.0f, 1.0f, 1.0f);
}
void bullet::get_line()
{
	int i =static_cast<int>((570 - position.y+13) / 100);
	/*��13����Ϊ�ӵ���λ�û�ȳ�ʼλ�ø�13���������ܺ��㶹���ֵ���ˮƽ*/
	line = i;
}
/*����ӵ����ڵ���*/
void bullet::is_zombie()
{
	std::vector<zombie*>::iterator it;  /*�õ�����������Ӧ��vector�����еĽ�ʬ���꣬��С��һ����Χ���ж�Ϊ����Ŀ��*/
	switch (line)
	{
	case 1:
		for (it = line_1.begin(); it < line_1.end(); it++)
		{
			if (position.x - (*it)->position.x < 20&& position.x - (*it)->position.x > 0)
			{
				if ((*it)->type == 2)
					hit_Buckethead_music();
				else
					hit_music();
				(*it)->blood -= attack;
				(sprite->getParent())->removeChild(sprite);      /*���ӵ��Ƴ�*/
				unscheduleUpdate();
				break;
			}
		}
		break;
	case 2:
		for (it = line_2.begin(); it < line_2.end(); it++)
		{
			if (position.x - (*it)->position.x < 20 && position.x - (*it)->position.x > 0)
			{
				if ((*it)->type == 2)
					hit_Buckethead_music();
				else
					hit_music();
				(*it)->blood -= attack;
				(sprite->getParent())->removeChild(sprite);      /*���ӵ��Ƴ�*/
				unscheduleUpdate();
				break;
			}
		}
		break;
	case 3:
		for (it = line_3.begin(); it < line_3.end(); it++)
		{
			if (position.x - (*it)->position.x < 20 && position.x - (*it)->position.x > 0)
			{
				if ((*it)->type == 2)
					hit_Buckethead_music();
				else
					hit_music();
				(*it)->blood -= attack;
				(sprite->getParent())->removeChild(sprite);      /*���ӵ��Ƴ�*/
				unscheduleUpdate();
				break;
			}
		}
		break;
	case 4:
		for (it = line_4.begin(); it < line_4.end(); it++)
		{
			if (position.x - (*it)->position.x < 20 && position.x - (*it)->position.x > 0)
			{
				if ((*it)->type == 2)
					hit_Buckethead_music();
				else
					hit_music();
				(*it)->blood -= attack;
				(sprite->getParent())->removeChild(sprite);      /*���ӵ��Ƴ�*/
				unscheduleUpdate();
				break;
			}
		}
		break;
	case 5:
		for (it = line_5.begin(); it < line_5.end(); it++)
		{
			if (position.x - (*it)->position.x < 20 && position.x - (*it)->position.x > 0)
			{
				if ((*it)->type == 2)
					hit_Buckethead_music();
				else
					hit_music();
				(*it)->blood -= attack;
				(sprite->getParent())->removeChild(sprite);      /*���ӵ��Ƴ�*/
				unscheduleUpdate();
				break;
			}
		}
		break;
	}
}
/*�ж��Ƿ���ײ����ʬ*/
void bullet::move()
{
	auto moveby = MoveBy::create(4, Vec2(START_POSITION, 0));
	sprite->runAction(moveby);
}
/*�����ƶ�*/