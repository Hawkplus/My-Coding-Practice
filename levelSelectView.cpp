#include"Maze.h"
#include<graphics.h>
void levelSelectView()
{
    /* Difficulty Selection Interface
     Priority: Non-core
     Designer: Zhang Kaixuan
     Function:
         Display the difficulty selection interface:
         Easy Mode / Hard Mode / Hell Mode / Return to Menu
         Provide difficulty selection buttons, the player clicks the button to get the corresponding level, then calls initView for initialization
     Parameters: void
     Return value: void
 */
    initgraph(880, 640);
    cleardevice();
    setbkmode(TRANSPARENT);
    IMAGE img;
    loadimage(&img, L"resource\\image\\true1.jpg", 880, 640);
    putimage(0, 0, &img);
    while (1) {

        BeginBatchDraw();
        setbkmode(TRANSPARENT);

        // 绘制标题
        settextcolor(BLACK);
        settextstyle(40, 0, L"黑体");
        outtextxy(350, 50, L"选择难度");

        int level_pow[3][4] = {
            {300, 210, 580, 250}, // 简单
            {300, 260, 580, 300}, // 困难
            {300, 370, 580, 410}  // 回到主页
        };
        wchar_t level_texts[4][20] =
        {
            L"简单",
            L"困难",
            L"回到主页"
        };
        settextstyle(30, 0, L"黑体");
        setfillcolor(YELLOW);
        int wspace = 0;
        int hspace = 0;


        for (int i = 0; i < 3; i++) {
            int left = level_pow[i][0];
            int top = level_pow[i][1];
            int right = level_pow[i][2];
            int bottom = level_pow[i][3];
            solidroundrect(left, top, right, bottom,10,10);
            wspace = (right - left - textwidth(level_texts[i])) / 2;
            hspace = (bottom - top - textheight(level_texts[i])) / 2;
            outtextxy(left + wspace, top + hspace, level_texts[i]);
        }

        EndBatchDraw();


        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                for (int i = 0; i < 3; i++) {
                    int left = level_pow[i][0];
                    int top = level_pow[i][1];
                    int right = level_pow[i][2];
                    int bottom = level_pow[i][3];
                    if (msg.x >= left && msg.x <= right &&
                        msg.y >= top && msg.y <= bottom) {
                        if (i == 2)
                        {
                            cleardevice();
                            menuView(); // 返回主菜单前清空
                        }
                        else {
                            if (i == 0) {
                                level = i;
                                cleardevice();
                                initGame(level);
                                gameView();
                            }
                            if (i == 1) {
                                level = i;
                                cleardevice();
                                initGame(level);
                                gameView();
                            }
                        };
                    }
                }
            }
        }
    }
}