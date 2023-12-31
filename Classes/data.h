#pragma once
#include<vector>
#define LINE_1 500
#define LINE_2 400
#define LINE_3 300
#define LINE_4 200
#define LINE_5 100
/*以上为行数对应的高度(从上到下）*/
#define END_POSITION 0
#define BLOCK_1 120
#define BLOCK_2 220
#define BLOCK_3 320
#define BLOCK_4 420
#define BLOCK_5 520
#define BLOCK_6 620
#define BLOCK_7 720
#define BLOCK_8 820
#define BLOCK_9 920
#define BLOCK_10 1020
#define START_POSITION 1120
/*以上为从左到右格子数对应的位置*/
class zombie;
int board[5][9];
std::vector<zombie*>line_1;