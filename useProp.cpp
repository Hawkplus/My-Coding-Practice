#include"Maze.h"

/* Priority: Non-core
  Designer: Zhou Xingyu
  Responsible person: Zhou Xingyu
  Function: Bomb use function, called when the player uses a bomb. First check if there is a bomb. If not, return. If yes, set the player's up, down, left, and right to empty spaces. Set bomb ownership to false.
  No parameters. No return value.
*/
void useBomb()
{
    if (!player.bomb || bombNum <= 0) return;

    int sz;
    if (level == 0) sz = 15;
    else if (level == 1) sz = 30;
    else sz = 50;

    int x = player.x, y = player.y;

    if (y > 0 && map[level][y - 1][x] == 1) map[level][y - 1][x] = 0;   // 上
    if (y < sz - 1 && map[level][y + 1][x] == 1) map[level][y + 1][x] = 0; // 下
    if (x > 0 && map[level][y][x - 1] == 1) map[level][y][x - 1] = 0;   // 左
    if (x < sz - 1 && map[level][y][x + 1] == 1) map[level][y][x + 1] = 0; // 右

    player.bomb = false;
    bombNum--;
}

/* Flashlight Use Function
Priority: Non-core
Responsible person: Wang Jiayang
Function:
    Called through playerOperate(), after calling flashlight becomes false, forward field of view changes to 12, viewMode changes to flashlight view
Reference logic: Modify global variables
Return value: None
*/
void useFlashlight()
{
    if (!player.flashlight || flashNum <= 0) return;
    player.viewMode = 1;           // 手电筒视野
    player.viewFront = 6;         // 前方视野范围
    player.flashlight = false;
    flashNum--;
}

// Hourglass Use Function

    /* Priority: Non-core
       Designer: Xiang Haoyang
       Responsible person:
       Function: After use, extend total time by one minute
     */
void useSandglass()
{
    if (!player.sandGlass || sandglassNum <= 0) return;
    curModetime += 40;
    timeLeft += 40;
    player.sandGlass = false;
    sandglassNum--;
}

/* Vision Potion Use Function
Priority: Non-core
Designer: Zhou Xingyu
Responsible person
Function: Use vision potion, vision becomes global, with countdown
No parameters, no return value
*/
void useViewmedicine()
{
    preViewmode = player.viewMode;
    if (!player.viewMedicine || viewmedicineNum <= 0) return;
    player.viewMedicineStatus =150; // 10秒（假设60fps）
    player.viewMode = 2;              // 全局视野
    player.viewMedicine = false;
    viewmedicineNum--;
}