#include"Maze.h"
#include<iostream>
#include<graphics.h>
#include <mmsystem.h>       // 音乐播放
#pragma comment(lib,"winmm.lib")
using namespace std;
void resultView(bool success)
{
    /* Settlement Interface
Designer: HawkPP
Responsible person:
Parameters: success or failure
No return value;
Function:
    When the player wins or fails, display the settlement interface, showing the player's completion time and other information;
    Display options:
        1. Restart Game
        2. Return to Menu;
*/
    if (success)
    {
        //显示胜利界面
        initgraph(880, 640);
        IMAGE img_win;
        loadimage(&img_win, L"resource\\image\\win2.jpg");
        putimage(0, 0, &img_win);
        setlinecolor(BLACK);
        setfillcolor(YELLOW);
        solidroundrect(320, 320, 550, 400, 20, 20);
        setbkmode(TRANSPARENT);
        settextcolor(BLACK);
        settextstyle(30, 0, L"黑体");
        wchar_t buf[100];
        swprintf_s(buf, L"通过耗时：%d秒", curTime);
        outtextxy(340, 340, buf);
        setlinecolor(BLACK);
        setfillcolor(YELLOW);
        solidroundrect(200, 470, 400, 550, 20, 20);
        settextcolor(BLACK);
        outtextxy(240, 490, L"返回首页");
        setlinecolor(BLACK);
        setfillcolor(YELLOW);
        solidroundrect(500, 470, 700, 550, 20, 20);
        settextcolor(BLACK);
        outtextxy(540, 490, L"再来一局");
        mciSendString(L"close winsound", NULL, 0, NULL);
        const wchar_t* soundPath1 = L"resource\\audio\\win_music.mp3";
        // 打开音效文件，指定别名为 winsound
        wchar_t openCmd[256];
        swprintf_s(openCmd, L"open \"%s\" alias winsound", soundPath1);
        mciSendString(openCmd, NULL, 0, NULL);
        wchar_t volCmd[256];
        swprintf_s(volCmd, L"setaudio winsound volume to %d", nowSound);
        mciSendString(volCmd, NULL, 0, NULL);

        // 播放一次（无 repeat）
        if (music) {
            mciSendString(L"play winsound", NULL, 0, NULL);
        }
        while (true)
        {
            peekmessage(&msg, EM_MOUSE);
            if (msg.message == WM_LBUTTONDOWN)
            {
                if (msg.x >= 200 && msg.x <= 400 && msg.y >= 470 && msg.y <= 550)
                {
                    //返回首页                            
                    menuView();
                }
                else if (msg.x >= 500 && msg.x <= 700 && msg.y >= 470 && msg.y <= 550)
                {        //再来一局
                    initGame(level);
                    gameView();
                }
            }
        }

    }
    else
    {
        //显示失败界面
        IMAGE img_lose;
        loadimage(&img_lose, L"resource\\image\\lose2.jpg");
        putimage(0, 0, &img_lose);
        setlinecolor(BLACK);
        setfillcolor(BLACK);
        solidroundrect(200, 470, 400, 550, 20, 20);
        settextcolor(BLACK);
        setbkmode(TRANSPARENT);
        settextstyle(30, 20, L"黑体");
        outtextxy(360, 290, L"GAME OVER!");
        settextstyle(30, 0, L"黑体");
        outtextxy(335, 350, L"你的时间已经用完！");
        settextcolor(RED);
        outtextxy(240, 490, L"返回首页");
        setlinecolor(BLACK);
        setfillcolor(BLACK);
        fillroundrect(500, 470, 700, 550, 20, 20);
        settextcolor(RED);
        outtextxy(540, 490, L"再来一局");
        mciSendString(L"close losesound", NULL, 0, NULL);
        const wchar_t* soundPath = L"resource\\audio\\lose_music.mp3";
        // 打开音效文件，指定别名为 losesound
        wchar_t openCmd[256];
        swprintf_s(openCmd, L"open \"%s\" alias losesound", soundPath);
        mciSendString(openCmd, NULL, 0, NULL);
        wchar_t volCmd[256];
        swprintf_s(volCmd, L"setaudio winsound volume to %d", nowSound);
        mciSendString(volCmd, NULL, 0, NULL);
        // 播放一次（无 repeat）
        if (music) {
            mciSendString(L"play losesound", NULL, 0, NULL);
        }
        while (true)
        {
            peekmessage(&msg, EM_MOUSE);
            if (msg.message == WM_LBUTTONDOWN)
            {
                if (msg.x >= 200 && msg.x <= 400 && msg.y >= 470 && msg.y <= 550)
                {
                    //返回首页
                    cout << 1 << endl;
                    menuView();
                }
                else if (msg.x >= 500 && msg.x <= 700 && msg.y >= 470 && msg.y <= 550)
                {        //再来一局
                    initGame(level);
                    gameView();
                }
            }
        }


    }

}