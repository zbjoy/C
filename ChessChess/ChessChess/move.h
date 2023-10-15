#ifndef __MOVE_H__
#define __MOVE_H__

#include <iostream>

#ifndef PLAYSCENE_SIZE
#define PLAYSCENE_SIZE

#define INTERVAL 50 //���
#define CHESS_GRID_SIZE 70  //���ӿ��
#define ROW 10
#define COL 9
#define SIZE 60
#define BUTTON_SIZE 20
#define PLAYSCENEBUTTON_LEFT_EXIT 650
#define PLAYSCENEBUTTON_RIGHT_EXIT 750
#define PLAYSCENEBUTTON_TOP_EXIT 300
#define PLAYSCENEBUTTON_BOTTOM_EXIT 360

#endif

bool RedBin_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool BlackBin_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool BlackChe_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool RedChe_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool RedMa_Move(int x, int y, const int ChessMap[][COL], int j, int i);

bool BlackMa_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool RedPao_Move(int x, int y, const int ChessMap[][COL], int j, int i);

bool BlackPao_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool RedXiang_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool BlackXiang_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool RedShi_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool BlackShi_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool Shuai_Move(int x, int y, const int ChessMap[][COL], int i, int j);

bool Jiang_Move(int x, int y, const int ChessMap[][COL], int i, int j);

#endif