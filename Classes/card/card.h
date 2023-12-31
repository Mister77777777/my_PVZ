#pragma once
class card :public Sprite
{
protected:
    bool is_select = 0;  /*���ڼ�¼�Ƿ񱻵����*/
    bool is_used = 0;    /*���ڼ�¼�Ƿ�ɹ����ù�ֲ��*/
    int cost;
public:
    Sprite* sprite;
    Sprite* tmp;
    ~card();
    void update(float dt);
    virtual void card_init();
    void plant_music();
    void init_listener();
    void set_picture();
    bool touch_began(Touch* t, Event* e);
    bool move(Touch* t, Event* e);
    bool is_empty(Vec2 pt);                  /*�ж��Ƿ�������ֲ��*/
    bool is_in_board(Vec2 pt);               /*�ж��Ƿ����ڸ��ӵ���*/

    /*���ּ������漰���Կ�Ƭͼ���ĸı䣬Ҫ������д*/
    virtual bool touch_end(Touch* t, Event* e);
    void init_listener_select();
    bool touch_began_select(Touch* t, Event* e);
    virtual void add_plant(double row,double line);
};
/*��Ƭ���࣬���㶹����Ϊԭ��*/
class sunflower_card :public card
{
    void init_listener();
    void init_listener_select();
    bool touch_end(Touch* t, Event* e);
    bool touch_began_select(Touch* t, Event* e);
    void add_plant(double row, double line);
public:
    void card_init();
};
class nut_card :public card
{
    void init_listener();
    void init_listener_select();
    bool touch_end(Touch* t, Event* e);
    bool touch_began_select(Touch* t, Event* e);
    void add_plant(double row, double line);
public:
    void card_init();
};
class potato_mine_card :public card
{
    void init_listener();
    void init_listener_select();
    bool touch_end(Touch* t, Event* e);
    bool touch_began_select(Touch* t, Event* e);
    void add_plant(double roe, double line);
public:
    void card_init();
};