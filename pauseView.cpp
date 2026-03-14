#include"Maze.h"

/* Pause Interface
Designer: HawkPP
Responsible person:
No parameters, no return value;
Function:
    When the player presses the pause button, pause the game and display the pause interface:
        1. Return to Game
        2. Restart Game
        3. Return to Menu
*/
//插入暂停界面背景图
void pauseView()
{
    // 用纯色背景代替图片
    setfillcolor(RGB(200, 200, 200));
    solidrectangle(0, 0, 880, 640);

    settextcolor(BLACK);
    settextstyle(100, 0, _T("黑体"));
    setbkmode(TRANSPARENT);
    outtextxy(330, 50, _T("暂停"));

    // 按钮区域
    int btnLeft = 360, btnRight = 500;
    int btnY1 = 200, btnY2 = 250;
    int btnY3 = 300, btnY4 = 350;
    int btnY5 = 400, btnY6 = 450;

    settextstyle(30, 0, _T("黑体"));
    setfillcolor(LIGHTGRAY);
    solidroundrect(btnLeft, btnY1, btnRight, btnY2, 20, 20);
    outtextxy(370, 210, _T("继续游戏"));

    solidroundrect(btnLeft, btnY3, btnRight, btnY4, 20, 20);
    outtextxy(370, 310, _T("返回首页"));

    solidroundrect(btnLeft, btnY5, btnRight, btnY6, 20, 20);
    outtextxy(370, 410, _T("重新开始"));


    ExMessage msg;
    while (true) {
        peekmessage(&msg, EM_MOUSE);
        if (msg.message == WM_LBUTTONDOWN) {
            if (msg.x >= btnLeft && msg.x <= btnRight && msg.y >= btnY1 && msg.y <= btnY2) {
                return; // 继续游戏
            }
            else if (msg.x >= btnLeft && msg.x <= btnRight && msg.y >= btnY3 && msg.y <= btnY4) {
                menuView();
                return;
            }
            else if (msg.x >= btnLeft && msg.x <= btnRight && msg.y >= btnY5 && msg.y <= btnY6) {
                initGame(level);
                gameView();
                return;
            }
        }
    }
}