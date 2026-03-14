#include"Maze.h"
#include<ctime>
void pauseGame(clock_t* pStartClock)
{
	/* Time Pause Function
Designer: Wang Yujie
Responsible person:
Function: The countdown stops when paused, and continues after exiting pause
Parameter: Initial time
Return value: None
*/
	clock_t pauseStart = clock();  // 暂停开始的时钟计数
	pauseView();                    // 显示暂停界面，阻塞直到继续
	clock_t pauseEnd = clock();     // 暂停结束的时钟计数
	*pStartClock += (pauseEnd - pauseStart);  // 补偿暂停时间
}