#include"Maze.h"
void teamView()
{
    /* Team Introduction Function
Priority: Non-core
Designer: Xie Xinyu
Responsible person
Function: Introduce team members and the parts each person is responsible for
*/
    IMAGE img_t;//定义背景图
    loadimage(&img_t, L"resource\\image\\teamViewback.jpg", 880, 640);
    putimage(0, 0, &img_t);
    settextcolor(BLACK);
    settextstyle(30, 0, L"宋体");
    setbkmode(TRANSPARENT);

    //setfillcolor(LIGHTGRAY);
    //solidroundrect(20, 20, 860, 500,10,10);
    outtextxy(30, 30, L"Team Division Introduction:");
    outtextxy(30, 70, L"Wang Jiayang  playerOperate  useFlashlight");
    outtextxy(30, 110, L"Huang Zhaopeng  resultView  pauseView");
    outtextxy(30, 150, L"Zhou Xingyu  useBomb      useViewmedicine");
    outtextxy(30, 190, L"Wang Yujie  isLose  isWin");
    outtextxy(30, 230, L"Zhang Kaixuan  menuView  levelSelectView");
    outtextxy(30, 270, L"Xie Xinyu  instructionView  settingView  teamView");
    outtextxy(30, 310, L"Xiang Haoyang  gameView  movePlayer  useSandglass");
    outtextxy(30, 350, L"Zhang Jingyao  initGame  printMap");
    outtextxy(30, 390, L"Special Thanks: Senior AC  for helping find bugs and perfecting the code (Thank you for your help!!)");//Introduction content
    outtextxy(30, 430, L"The completion of the project is inseparable from everyone's efforts!");
    settextstyle(16, 0, L"Songti");
    setfillcolor(WHITE);
    solidroundrect(340, 520, 500, 600, 10, 10);
    outtextxy(390, 555, L"Return to Menu");//Draw button

    ExMessage msg2;
    while (1) {
        getmessage(&msg2, EM_MOUSE);//接收鼠标信息
        if (msg2.message == WM_LBUTTONDOWN) {
            if (msg2.x > 340 && msg2.x < 500 && msg2.y>520 && msg2.y < 600)
                menuView();//打开菜单界面
        }
    }
}