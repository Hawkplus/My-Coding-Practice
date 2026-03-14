#include"Maze.h"
bool isWin(Player& player)
{
    /* Priority: Core
   Designer: Wang Yujie
   Responsible person:
   Function: Determine whether the game has been won.
    Determine if the player has reached the end point (coinciding with the end point coordinates).
    Specific logic:
        1. Check if the player's coordinates (x, y) are equal to the global end point coordinates (finalx, finaly).
        2. If so, call resultView(true) to display the victory interface and return true indicating victory.
        3. Otherwise, return false.
    Reference logic: Called every frame in the game main loop, passing in the player's current coordinates.
    Return value: bool - true indicates victory, false indicates not yet won
  Parameters:
    Player object
*/
    if (player.x == finalx && player.y == finaly) {
        //记录通关耗时
        return true;
    }
    return false;
}