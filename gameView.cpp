#include"Maze.h"
#include<ctime>
#include<conio.h>

/* Priority: Core
   Designer: Xiang Haoyang
   Responsible person:
   Function: Core game function, which needs to integrate and call other functions, such as map printing function, victory determination, character movement function, interaction function, game state function
    First call the initialization function initGame(), then enter the game main loop while(1), call the printMapX() function to draw the game map,
    Detect keyboard input
    If the input is a movement key, distinguish ADSW direction keys
        Use movePlayer() function to determine whether movement is possible
        If possible, move the character and update the coordinates
        If an item is picked up, update the item status
    If the input is a number key, such as 1, 2, 3 keys
        Call the item use function, update the character status, and trigger the corresponding effect
        Item status changes
    Then call the IsWin() function to implement victory detection
    If the game is won
        Core: Simultaneously use the playerOperate() function to detect keyboard keys, if the spacebar is clicked, call the pause interface, and implement game pause by calling the pauseView() function
        Non-core: Call the settingView() function to display settings
    Finally call the resultView() function to display the victory interface

    Reference logic: Clear screen, receive keyboard messages, countdown
    Return value: None
*/


void gameView()
{
    const int targetFps = 60;
    const int frameDelay = 1000 / targetFps;
    clock_t startClock = clock();
    curTime = 0;

    const int TOP_HEIGHT = 100;
    const int TIME_X = 20, TIME_Y = 20;
    const int TIME_WIDTH = 160, TIME_HEIGHT = 60;
    const int PROP_X = 880 - 320 - 20;
    const int PROP_Y = 5;

    // 预加载四个道具图片
        // 手电筒
    IMAGE flash;
    loadimage(&flash, _T("resource\\image\\flash.jpg"), 60, 60);
    // 炸弹
    IMAGE bomb;
    loadimage(&bomb, _T("resource\\image\\bomb.jpg"), 60, 60);
    // 视野药水
    IMAGE viewmedicine;
    loadimage(&viewmedicine, _T("resource\\image\\viewmedicine.png"), 60, 60);
    // 沙漏
    IMAGE sandglass;
    loadimage(&sandglass, _T("resource\\image\\sandglass.jpg"), 60, 60);


    // 根据难度确定地图尺寸
    int mapSize = 15;
    if (level == 1) mapSize = 30;
    int gridSize = (640 - TOP_HEIGHT) / mapSize;
    int mapStartX = (880 - mapSize * gridSize) / 2;
    int mapStartY = TOP_HEIGHT;

    initgraph(880, 640); // 已在 main 中打开，但保留无妨

    ExMessage msg; // 局部消息变量

    while (1) {
        clock_t frameStart = clock();

        BeginBatchDraw();

        // 清屏为浅灰色
        setfillcolor(RGB(240, 240, 240));
        solidrectangle(0, 0, 880, 640);

        // 绘制地图
        printMap0(mapStartX, mapStartY, gridSize);

        // 顶部信息栏
        wchar_t timeText[50];
        swprintf_s(timeText, L"剩余：%ds", timeLeft);
        setfillcolor(RGB(180, 70, 60));
        solidrectangle(TIME_X, TIME_Y, TIME_X + TIME_WIDTH, TIME_Y + TIME_HEIGHT);
        settextcolor(BLACK);
        setbkmode(TRANSPARENT);
        settextstyle(30, 0, _T("微软雅黑"));
        int textWidth = textwidth(timeText);
        int textHeight = textheight(timeText);
        int tx = TIME_X + (TIME_WIDTH - textWidth) / 2;
        int ty = TIME_Y + (TIME_HEIGHT - textHeight) / 2;
        outtextxy(tx, ty, timeText);

        // 道具栏背景
        setfillcolor(RGB(200, 200, 200));
        solidrectangle(PROP_X, PROP_Y, PROP_X + 320, PROP_Y + 80);

        //画出道具图片
        putimage(PROP_X + 10, PROP_Y + 10, &flash);     
        putimage(PROP_X + 90, PROP_Y + 10, &bomb);
        putimage(PROP_X + 170, PROP_Y + 10, &viewmedicine);
        putimage(PROP_X + 250, PROP_Y + 10, &sandglass);


        // 显示数量
        wchar_t prop1[10], prop2[10], prop3[10], prop4[10];
        swprintf_s(prop1, L"x%d", flashNum);
        swprintf_s(prop2, L"x%d", bombNum);
        swprintf_s(prop3, L"x%d", viewmedicineNum);
        swprintf_s(prop4, L"x%d", sandglassNum);
        settextcolor(RED);
        outtextxy(PROP_X + 30, PROP_Y + 75, prop1);
        outtextxy(PROP_X + 110, PROP_Y + 75, prop2);
        outtextxy(PROP_X + 190, PROP_Y + 75, prop3);
        outtextxy(PROP_X + 270, PROP_Y + 75, prop4);

        EndBatchDraw();

        // 玩家操作
        if (peekmessage(&msg, EM_KEY)) {
            playerOperate(msg, &startClock);
        }

        // 视野药水计时
        if (player.viewMedicineStatus > 0) {
            player.viewMedicineStatus--;
            if (player.viewMedicineStatus == 0)
                player.viewMode = preViewmode;
        }

        // 更新时间
        clock_t currentClock = clock();
        int nowCurTime = (currentClock - startClock) / CLOCKS_PER_SEC;
        if (nowCurTime > curTime) {
            curTime = nowCurTime;
            timeLeft = curModetime - curTime;
        }

        // 胜负判断
        if (isLose()) {
            cleardevice();
            resultView(false);
        }
        else if (isWin(player)) {
            cleardevice();
            resultView(true);
        }

        // 帧率控制
        clock_t frameEnd = clock();
        int elapsed = frameEnd - frameStart;
        if (elapsed < frameDelay) {
            Sleep(frameDelay - elapsed);
        }
    }
}