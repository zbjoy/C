#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include <iostream>
#include <graphics.h>

#include "move.h"

#ifndef PLAYSCENE_SIZE
#define PLAYSCENE_SIZE

#define INTERVAL 50 //间隔
#define CHESS_GRID_SIZE 70  //格子宽度
#define ROW 10
#define COL 9
#define SIZE 60
#define BUTTON_SIZE 20
#define PLAYSCENEBUTTON_LEFT_EXIT 650
#define PLAYSCENEBUTTON_RIGHT_EXIT 750
#define PLAYSCENEBUTTON_TOP_EXIT 300
#define PLAYSCENEBUTTON_BOTTOM_EXIT 360

#endif

void GameDraw();

int PlayMouseContral(MOUSEMSG& msg, int ChessMap[][COL]);

int PlayScene(MOUSEMSG& msg, int ChessMap[][COL]);

void CheckChess(int ChessMap[][COL]);

void ChessMove(MOUSEMSG& msg, int ChessMap[][COL], int j, int i);

int ChessWin(int ChessMap[][COL]);

#endif