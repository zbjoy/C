#ifndef __MAINSCENE_H__
#define __MAINSCENE_H__

#include <iostream>
#include <graphics.h>

#ifndef MAINSCENESIZE
#define MAINSCENESIZE

#define MAINSCENE_HEIGHT 600
#define MAINSCENE_WEIGHT 400

#define MAINBUTTON_LEFT_PLAY 155
#define MAINBUTTON_TOP_PLAY 360
#define MAINBUTTON_RIGHT_PLAY 240
#define MAINBUTTON_BOTTOM_PLAY 400

#define MAINBUTTON_LEFT_EXIT 155
#define MAINBUTTON_TOP_EXIT 480
#define MAINBUTTON_RIGHT_EXIT 240
#define MAINBUTTON_BOTTOM_EXIT 520

#endif

void InitMainScene(IMAGE MainImage);

int MainMouseContral(MOUSEMSG& msg);

#endif