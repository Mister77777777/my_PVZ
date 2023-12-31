#pragma once
#include"cocos2d.h"
USING_NS_CC;
class plant :public Sprite
{
    double attack = 100;     /*���ι������˺�ֵ*/
    int interval =4   *60;    /*ʹ��֡��ʱ�������60Ϊ��λ��*/
    int size;            /*���ڼ�¼��ǰ���ϵĽ�ʬ���������Ϊ0�򲻷����ӵ�*/
    bool is_attack;
    bool is_wait;
    bool is_die;
    Vector<SpriteFrame*> waitFrames;
public:
    int line;            /*��Ӧ����*/
    int row;             /*��Ӧ����*/
    Vec2 position;
    Sprite* sprite;     /*��Ӧ����*/
    double blood = 500;   /*��ǰѪ��*/
    plant(Sprite* outside_sprite);
    ~plant();
    virtual void update(float dt);
    virtual void plant_init();
    void shoot();
    void die();
    virtual void wait();
    virtual void loadResource();
    virtual void init_animate();
    virtual void init_wait_animate();
    virtual void init_sound();
};
/*����Ϊֲ��������*/



class sunflower :public plant
{
    int create_interval = 15 * 60;   /*���������ʱ����*/
    void create_sun();
    void plant_init();
    Vector<SpriteFrame*> waitFrames;
public:
    sunflower(Sprite* outside_sprite);
    void wait();
    void loadResource();
    void init_animate();
    void update(float dt);
};


/*����Ϊ���տ��࣬�̳�ֲ����������ٴ�����*/
class nut :public plant
{
    void plant_init();
    Vector<SpriteFrame*> waitFrames;
public:
    nut(Sprite* outside_sprite);
    void wait();
    void loadResource();
    void init_animate();
    void update(float dt);
};


/*����Ϊ���ǽ�࣬�̳�ֲ����������ٴ�����*/
class potato_mine :public plant
{
    bool is_ready = 0;
    int start_interval = 5 * 60;
    void plant_init();
    void play_music();     /*���ű�ը����*/
    Vector<SpriteFrame*> waitFrames;
    Vector<SpriteFrame*> readyFrames;
public:
    potato_mine(Sprite* outside_sprite);
    void ready();
    void wait();
    void loadResource();
    void init_animate();
    void update(float dt);
};

/*����Ϊ��������*/