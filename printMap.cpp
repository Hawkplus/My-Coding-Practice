#include"Maze.h"
#include<conio.h>
/* Map Printing Function
    Designer: Zhang Jingyao
    Responsible person:
    Parameters:
        No parameters;
    Return value:
        No return value;
    Function:
        Three in total, one for each mode, call the corresponding map printing function according to the current level;
        Print map information based on the current level, including player position, item positions, remaining time, elapsed time, etc.;
        Determine which grids can be seen by the player based on the player's view mode and view range, and print the corresponding information;
   */



// 判断格子是否可见
static bool isVisible(int row, int col) {
    int px = player.x, py = player.y;
    int dx = abs(col - px), dy = abs(row - py);

    if (player.viewMode == 2) // 全局视野（药水）
        return true;

    if (player.viewMode == 1) { // 手电筒视野
        switch (player.dir) {
        case 0: // 向上
            return (row <= py && row >= py - player.viewFront && abs(col - px) <= 4);
        case 1: // 向下
            return (row >= py && row <= py + player.viewFront && abs(col - px) <= 4);
        case 2: // 向左
            return (col <= px && col >= px - player.viewFront && abs(row - py) <= 4);
        case 3: // 向右
            return (col >= px && col <= px + player.viewFront && abs(row - py) <= 4);
        default: return false;
        }
    }

    // 普通视野：5x5正方形
    return (dx <= 3 && dy <= 3);
}

void printMap0(int startX, int startY, int gridSize)
{   
    int mapSize = 0;
    if (level == 0) mapSize = 15;
    else if (level == 1) mapSize = 30;

    // 加载墙和迷雾图片
    IMAGE wallimg, fogimg;
    loadimage(&wallimg, _T("resource\\image\\wall.jpg"), gridSize, gridSize);
    loadimage(&fogimg, _T("resource\\image\\fog.jpg"), mapSize * gridSize, mapSize * gridSize);

    // 放置迷雾背景（覆盖整个地图区域）
    putimage(startX, startY, &fogimg);

    // 遍历每个格子，如果可见则绘制墙或空地底色（浅灰），并绘制特殊元素（玩家、终点、道具）
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            int x = startX + j * gridSize;
            int y = startY + i * gridSize;

            if (level == 1) {
                if (!isVisible(i, j)) {
                    // 不可见：保持迷雾（已经绘制了fogimg，所以这里什么都不做）
                    continue;
                }
            }

            int cell = map[level][i][j];

            // 如果是墙壁，绘制墙图片（会覆盖迷雾）
            if (cell == 1) {
                putimage(x, y, &wallimg);
            }
            else {
                // 空地或道具：绘制浅灰色底色（以便显示道具文字或玩家圆）
                setfillcolor(RGB(200, 200, 200));
                solidrectangle(x, y, x + gridSize, y + gridSize);
            }

            // 绘制特殊标记（覆盖在底色上）
            if (cell == 2) { // 玩家
                IMAGE player1, player2;
                loadimage(&player2, _T("resource\\image\\player2.png"),gridSize,gridSize);
                loadimage(&player1, _T("resource\\image\\player1.jpg"),gridSize,gridSize);
                putimage(x, y, &player2,NOTSRCERASE);
                putimage(x, y, &player1,SRCINVERT);
            }
            else if (i == finaly && j == finalx) { // 终点
                IMAGE exit1,exit2;
                loadimage(&exit2, _T("resource\\image\\exit2.png"),gridSize,gridSize);
                loadimage(&exit1, _T("resource\\image\\exit1.jpg"), gridSize, gridSize);
                putimage(x, y, &exit2,NOTSRCERASE);
                putimage(x, y, &exit1,SRCINVERT);
            }
            else if (cell == 3) { // 手电筒
                IMAGE f;
                loadimage(&f, _T("resource\\image\\flash.jpg"), gridSize, gridSize);
                putimage(x, y, &f);
            }
            else if (cell == 4) { // 炸弹
                IMAGE b;
                loadimage(&b, _T("resource\\image\\bomb.jpg"), gridSize, gridSize);
                putimage(x, y, &b);
            }
            else if (cell == 5) { // 视野药水
                IMAGE v;
                loadimage(&v, _T("resource\\image\\viewmedicine.png"), gridSize, gridSize);
                putimage(x, y, &v);
            }
            else if (cell == 6) { // 沙漏
                IMAGE s;
                loadimage(&s, _T("resource\\image\\sandglass.jpg"), gridSize, gridSize);
                putimage(x, y, &s);
            }
        }
    }
}