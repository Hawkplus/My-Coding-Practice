#include"Maze.h"
#include<ctime>
void playerOperate(ExMessage& msg, clock_t* pStartClock)
{
	/* User Operation Function
	Priority: Non-core
	Responsible person: Wang Jiayang
	Function:
		Place in GameView(), manipulate within the drawing
		Determine through easyx key messages:
		wasd changes player direction and calls movePlayer()
		Press keyboard keys 1, 2, 3, 4 to use items
		Press spacebar to display pause interface
	Reference logic: Receive keyboard information
	Return value: None
*/
	if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 49) {
		if (player.flashlight) {
			useFlashlight();
		}			//按下1使用手电筒
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 50) {
		if (player.bomb) {
			useBomb();
		}					//按下2使用炸弹
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 51) {
		if (player.viewMedicine) {
			useViewmedicine();
		}			//按下3使用视野药水
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 52) {
		if (player.sandGlass) {
			useSandglass();
		}			//按下4使用沙漏
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 32) {
		pauseGame(pStartClock);				//按下空格使用暂停
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 87) {
		player.dir = 0;					//按下w将方向改为向上
		movePlayer(player);
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 65) {
		player.dir = 2;					//按下a将方向改为向左
		movePlayer(player);
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 83) {
		player.dir = 1;					//按下s将方向改成向下
		movePlayer(player);
	}
	else if (msg.message == WM_KEYDOWN &&
		msg.vkcode == 68) {
		player.dir = 3;					//按下d将方向改成向右
		movePlayer(player);
	}
}