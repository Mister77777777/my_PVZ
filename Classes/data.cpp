#include<vector>
#include"HelloWorldScene.h"
plant* board[5][9];
std::vector<zombie*>line_1;
std::vector<zombie*>line_2;
std::vector<zombie*>line_3;
std::vector<zombie*>line_4;
std::vector<zombie*>line_5;
std::vector<bullet*>all_bullet;   /*�������ڴ洢���е��ӵ��������ͷ��ڴ�͹رն�ʱ��*/
std::vector<sun*>all_sun;
car* all_car[5];
int total = 0;    /*Ϊ����ÿ�������඼���Է������֣�ʹ��ȫ�ֱ���*/
bool level_1_ready = 0;
bool level_2_ready = 0;
/*�ؿ�������*/