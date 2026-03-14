#include"Maze.h"
void settingView()//无参数直接调用
{
    /* Priority: Extension
         Designer: Xie Xinyu
         Responsible person:
         Function: Game extension function
         First load and place the background image, then print the initial default interface, then enter the main loop while(1),
         Receive mouse information:
         If it's the scroll wheel, determine whether the value is within the limited area, if so, modify the volume
         If it's a click, detect the click area
             If it's the sound effect toggle key, change the sound effect on/off state
             If it's the return to menu key, call menuView()
         Return value: None

 */

    TCHAR s[10];
    TCHAR s1[10];
    IMAGE img_ib;//定义背景图
    loadimage(&img_ib, L"resource\\image\\settingViewback.jpg", 880, 640);
    putimage(0, 0, &img_ib);//放置背景图880x640
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);

    while (1) {

        setfillcolor(WHITE);
        solidroundrect(340, 100, 550, 180,10,10);
        solidroundrect(340, 180, 550, 260,10,10);
        solidroundrect(340, 520, 550, 600,10,10);
        outtextxy(350, 130, L"音量大小");
        _stprintf_s(s, _T("%d"), nowSound);
        outtextxy(480, 130, s);
        outtextxy(350, 210, L"音效开关: ");
        if (music) {
            _stprintf_s(s1, _T("%s"), L"开");
            outtextxy(480, 210, s1);
        }
        else {
            _stprintf_s(s1, _T("%s"), L"关");
            outtextxy(480, 210, s1);
        }
        outtextxy(380, 540, L"返回菜单");
        

        ExMessage msg3;

        while (1) {
            getmessage(&msg3, EX_MOUSE);//接收鼠标信息
            if (msg3.message == WM_MOUSEWHEEL) {

                nowSound += (msg3.wheel / 120) * 5;//每划一下，增加或减少5格音量
                if (nowSound > 100)nowSound = 100;
                else if (nowSound < 0)nowSound = 0;
                solidrectangle(340, 100, 550, 180);
                _stprintf_s(s, _T("%d"), nowSound);
                outtextxy(350, 130, L"音量大小：");
                outtextxy(480, 130, s);
            }
            if (msg3.message == WM_LBUTTONDOWN) {

                if (msg3.x > 340 && msg3.x < 550 && msg3.y>180 && msg3.y < 260)
                {
                    music = !music;//设置音效
                    if (music == true) {
                        _stprintf_s(s1, _T("%s"), L"开");
                        solidrectangle(340, 180, 550, 260);
                        outtextxy(350, 210, L"音效开关: ");
                        outtextxy(480, 210, s1);
                    }
                    else {
                        _stprintf_s(s1, _T("%s"), L"关");
                        solidrectangle(340, 180, 550, 260);
                        outtextxy(350, 210, L"音效开关: ");
                        outtextxy(480, 210, s1);
                    }
                }

                if (msg3.x > 340 && msg3.x < 550 && msg3.y>520 && msg3.y < 600)
                    menuView();//打开菜单界面
            }
        }
    }
}