#include"Maze.h"
bool isLose()
{
    /* Priority: Core
   Designer: Wang Yujie
   Responsible person:
   Function: Determine whether the game has failed.
    Determine if the player has failed based on the current game state, currently implementing timeout determination.
    Specific logic:
        1. Check if the remaining time timeLeft is less than or equal to 0.
        2. If so, call resultView(false) to display the failure interface and return true indicating failure.
        3. Otherwise, return false and the game continues.
    Reference logic: Called every frame in the game main loop, passing in the player's current coordinates for future expansion (such as traps, monsters, etc.).
    Return value: bool - true indicates failure, false indicates the game continues
    No parameters
*/

    //检查时间是否耗尽
    if (timeLeft <= 0) {
        //显示失败界面（超时）
        return true;//游戏失败
    }
    //可扩充其他失败条件
    return false;
}