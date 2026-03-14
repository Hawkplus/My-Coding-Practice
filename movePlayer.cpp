#include "Maze.h"

void movePlayer(Player & player)
{

    /* Priority: Core
Designer: Xiang Haoyang
Responsible person:
Function: Move according to player direction, detect boundaries and walls, pick up items
*/
        int newX = player.x;
        int newY = player.y;
        int nowRows = 0, nowCols = 0;

        switch (player.dir) {
        case 0: newY--; break; // 上
        case 1: newY++; break; // 下
        case 2: newX--; break; // 左
        case 3: newX++; break; // 右
        }

        switch (level) {
        case 0: nowRows = 15; nowCols = 15; break;
        case 1: nowRows = 30; nowCols = 30; break;
        case 2: nowRows = 50; nowCols = 50; break;
        }

        // 边界检测
        if (newX < 0 || newX >= nowCols || newY < 0 || newY >= nowRows) return;
        // 墙壁检测
        if (map[level][newY][newX] == 1) return;

        // 拾取道具
        switch (map[level][newY][newX]) {
        case 3: // 手电筒
            player.flashlight = true;
            flashNum++;
            map[level][newY][newX] = 0;
            break;
        case 4: // 炸弹
            player.bomb = true;
            bombNum++;
            map[level][newY][newX] = 0;
            break;
        case 5: // 视野药水
            player.viewMedicine = true;
            viewmedicineNum++;
            map[level][newY][newX] = 0;
            break;
        case 6: // 沙漏
            player.sandGlass = true;
            sandglassNum++;
            map[level][newY][newX] = 0;
            break;
        default: break;
        }

        // 移动玩家
        map[level][player.y][player.x] = 0;
        player.x = newX;
        player.y = newY;
        map[level][player.y][player.x] = 2;
    }