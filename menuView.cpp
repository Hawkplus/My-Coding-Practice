#include"Maze.h"
#include<easyx.h>
#include<conio.h>
void menuView()
{
    /* Menu Interface
 * Priority: Core
 * Designer: Zhang Kaixuan
   Function:
      Display the menu interface:
      Start Game: After clicking, enter the difficulty selection interface: call levelSelectView() -> select difficulty -> initialize game: call initGame -> call gameView
      Game Instructions: call instructionView()
      Historical Highest Records:
      Game Settings: call settingView()
      Team Introduction: call teamView()
      Exit Game
      Return value: void
      No parameters
 */
    initgraph(880, 640);
    setbkmode(TRANSPARENT);
    IMAGE img;
    loadimage(&img, L"resource\\image\\true.jpg", 880, 640);
    putimage(0, 0, &img);
    wchar_t menu_texts[6][20] = {
    L"开始游戏",
    L"游戏说明",
    L"游戏设置",
    L"团队介绍",
    L"退出游戏"
    };
    //菜单按钮坐标
    int menu_bottonpow[5][4] = {
    {300, 210, 580, 250},
    {300, 260, 580, 300},
    {300, 310, 580, 350},
    {300, 360, 580, 400},
    {300, 410, 580, 450}
    };

    while (1) {

        BeginBatchDraw();
        // 绘制标题
        settextcolor(BLACK);
        settextstyle(50, 0, L"黑体");
        outtextxy(300, 50, L"迷宫大冒险");

        // 绘制菜单按钮
        settextstyle(30, 0, L"黑体");
        setfillcolor(YELLOW);
        int wspace = 0;
        int hspace = 0;
        for (int i = 0; i < 5; i++) {
            int left = menu_bottonpow[i][0];
            int top = menu_bottonpow[i][1];
            int right = menu_bottonpow[i][2];
            int bottom = menu_bottonpow[i][3];
            solidroundrect(left, top, right, bottom,10,10);
            wspace = (right - left - textwidth(menu_texts[i])) / 2;
            hspace = (bottom - top - textheight(menu_texts[i])) / 2;
            outtextxy(left + wspace, top + hspace, menu_texts[i]);
        }
        EndBatchDraw();


        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                for (int i = 0; i < 5; i++) {
                    int left = menu_bottonpow[i][0];
                    int top = menu_bottonpow[i][1];
                    int right = menu_bottonpow[i][2];
                    int bottom = menu_bottonpow[i][3];

                    if (msg.x >= left && msg.x <= right &&
                        msg.y >= top && msg.y <= bottom) {
                        switch (i) {
                        case 0:cleardevice(); levelSelectView(); break;
                        case 1:  cleardevice(); instructionView(); break;
                        case 2: cleardevice(); settingView(); break;
                        case 3: cleardevice(); teamView(); break;
                        case 4: closegraph(); exit(0); break;
                        }
                    }
                }
            }
        }
    }
    _getch();
}