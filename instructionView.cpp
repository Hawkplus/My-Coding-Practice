#include"Maze.h"
void instructionView()
{
    /* Game Introduction Function
   Designer: Xie Xinyu
   Responsible person:
   Function: Introduce game gameplay and通关 rules
  */
    IMAGE img_ib;//定义背景图
    loadimage(&img_ib, L"resource\\image\\instructionViewback.jpg", 880, 640);
    putimage(0, 0, &img_ib);
    settextcolor(BLACK);
    settextstyle(30, 0, L"宋体");
    setbkmode(TRANSPARENT);

    //setfillcolor(LIGHTGRAY);
    //solidroundrect(20, 20, 860, 500,10,10);
    outtextxy(30, 30, L"操作方式：WASD");//介绍的内容"
    outtextxy(30, 70, L"道具作用：手电筒：困难模式可拾取，拓展玩家正");
    outtextxy(30, 110, L"       前方视野范围为包括角色行在内的前方视野，永久生效");
    outtextxy(30, 150, L"         炸弹：全模式可拾取，炸毁角色周围指定范围（1格）\n");
    outtextxy(30, 190, L"       的任意墙壁，仅可使用 1 次，用于快速开辟道路，若");
    outtextxy(30, 230, L"        周围为空地或边界墙则无效果");
    outtextxy(30, 270, L"         视野药水：困难模式下可用，扩大视野为全局范");
    outtextxy(30, 310, L"        围（限时10s）");
    outtextxy(30, 350, L"         沙漏：所有模式下可用，加时1min");//介绍的内容
    outtextxy(30, 390, L"通关规则：规定时间内到达目的地即为游戏胜利");
    outtextxy(30, 430, L"难度区别：地图大小与时间限制不同");
    outtextxy(30, 470, L"");

    settextstyle(16, 0, L"宋体");
    setfillcolor(WHITE);
    solidroundrect(340, 520, 500, 600,10,10);
    outtextxy(380, 555, L"返回菜单");//绘制按钮


    ExMessage msg1;
    while (1) {
        getmessage(&msg1, EM_MOUSE);//接收鼠标信息
        if (msg1.message == WM_LBUTTONDOWN) {
            if (msg1.x > 340 && msg1.x < 500 && msg1.y>520 && msg1.y < 600)
                menuView();//打开菜单界面
        }
    }
}