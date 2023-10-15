#include "MainScene.h"

void InitMainScene(IMAGE MainImage)
{

}

int MainMouseContral(MOUSEMSG& msg)
{
	int Select = -1;

	while (MouseHit)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (msg.x > MAINBUTTON_LEFT_PLAY && msg.x < MAINBUTTON_RIGHT_PLAY
				&& msg.y > MAINBUTTON_TOP_PLAY && msg.y < MAINBUTTON_BOTTOM_PLAY)
			{
				//std::cout << "hhh" << std::endl;
				Select = 1;
				return Select;
			}
			else if (msg.x > MAINBUTTON_LEFT_EXIT && msg.x < MAINBUTTON_RIGHT_EXIT
				&& msg.y > MAINBUTTON_TOP_EXIT && msg.y < MAINBUTTON_BOTTOM_EXIT)
			{
				Select = 0;
				return Select;
			}
			break;
		default:
			break;
		}
	}


}