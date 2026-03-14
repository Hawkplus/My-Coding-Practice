#ifndef MAZE_H
#define MAZE_H
#include<graphics.h>
#include<conio.h>
#include<ctime>
// Global variables:

extern int timer1;   //简单模式总时间，单位为秒
extern int timer2;   //困难模式总时间，单位为秒

extern int map[2][50][50];      //有三个关卡，每个关卡的大小不同，0表示空地，1表示墙壁，2表示玩家,3表示手电筒，4表示炸弹，5表示视野药水

//简单模式为15*15，困难模式为30*30，地狱模式为50*50，简单困难模式多余部分为-1，不打印

extern bool music;			//音乐是否开启
extern int nowSound;		//音量大小
extern int finalx, finaly;		//终点坐标
extern int beginx, beginy;		//起点坐标
extern int level;               //当前关卡，取值为0，1，2，分别对应简单模式、困难模式和地狱模式
extern int timeLeft;             //剩余时间，单位为秒，剩余时间=总时间-已经过的时间
extern int curTime;              //当前已经过的时间，单位为秒
extern int curModetime;				//当前模式总时间
extern int flashNum;			//手电筒数量
extern int bombNum ;			//炸弹数量
extern int viewmedicineNum ;	//视野药水数量
extern int sandglassNum;		//沙漏数量
extern int preViewmode;			//视野药水之前的视野情况
struct Player
{
	int x, y;                 //玩家当前所在位置的坐标
	bool flashlight;           //玩家是否拥有手电筒，0表示没有，1表示有
	bool bomb;                 //玩家是否拥有炸弹，0表示没有，1表示有
	bool viewMedicine;         //玩家是否拥有视野药剂，0表示没有，1表示有
	bool sandGlass;				//玩家是否拥有沙漏，0表示没有，1表示有
	int viewMode;             //玩家的视野模式，0表示普通视野，1表示手电筒视野，2表示全局视野
	int viewRange;             //玩家的视野范围，单位为格子数(如3*3或5*5)
	int viewFront;             //玩家的视野范围前方的格子数(3或4，)
	int dir;				  //表示玩家方向，0上 1下 2左 3右
	int viewMedicineStatus;   // 视野药水状态剩余时间
};
extern struct Player player;//创建玩家对象

extern ExMessage msg;


/* Menu Interface
* Priority: Non-core
Responsible person: Zhang Kaixuan
No parameters, no return value;
Function:
Display the menu interface:
Start Game / Game Instructions / Game Settings / Team Introduction / Exit Game
*/
void menuView(); 

/* Difficulty Selection Interface
	No parameters, no return value;
	Function:
		Display the difficulty selection interface:
			Easy Mode / Hard Mode / Hell Mode
*/
void levelSelectView();

/* Game Instructions Interface
	No parameters, no return value;
	Function:
		Display the game instructions interface, introducing the game's gameplay, rules, items, etc.;
*/
void instructionView();

/* Game Settings Interface
	No parameters, no return value;
	Function:
		Display the game settings interface, allowing players to adjust game volume, background music, and other options;
*/
void settingView();

/* Game Interface
	No parameters, no return value;
	Function:
		Print map, player position, item bar, remaining time, elapsed time and other information;
		Enter main loop, player moves, determine if forward movement is possible, update player position, determine victory or defeat, update remaining time and other information;
		Display pause button, allow players to pause the game, restart the game, or return to the menu interface;
*/
void gameView();

/* Settlement Interface
	Parameters: success or failure
	No return value;
	Function:
		When the player wins or fails, display the settlement interface, showing the player's completion time and other information;
		Display options:
			1. Restart Game
			2. Return to Menu;
*/
void resultView(bool success);

/* Pause Interface
	No parameters, no return value;
	Function:
		When the player presses the pause button, pause the game and display the pause interface:
			1. Return to Game
			2. Restart Game
			3. Return to Menu
			4. Settings
*/
void pauseView();

/* Team Introduction Interface
	No parameters, no return value;
	Function:
		Display the team introduction interface, introducing the game's development team members, the functions each person is responsible for, and other information;
*/
void teamView();
//---------------------------------view--------------------------------





//-------------------------------service--------------------------------

// Initialization function
	/* Initialization Function

	Function:
		According to the current level, call printMap() to initialize the map, player position, item positions, remaining time, elapsed time, and other information;
	Parameters:
		Pass in level, indicating the current level, with values 0, 1, 2 corresponding to Easy Mode, Hard Mode, and Hell Mode respectively;
	Return value:
		No return value;
	*/
void initGame(int level);

/* Map Printing Function
	Parameters:
		No parameters;
	Return value:
		No return value;
	Function:
		Three in total, one for each mode, call the corresponding map printing function according to the current level;
		Print map information based on the current level, including player position, item positions, remaining time, elapsed time, etc.;
		Determine which grids can be seen by the player based on the player's view mode and view range, and print the corresponding information;
*/
void printMap0(int startX, int startY, int gridSize);


/* Movement Function
	Parameters:
		Pass in dir, indicating the player's movement direction, with values 0, 1, 2, 3 corresponding to up, down, left, and right respectively;
	Return value:
		Bool type, indicating whether the movement was successful, true means success, false means failure (such as hitting a wall or out of bounds);
	Function:
		Calculate the player's new position based on the movement direction, and determine whether it is possible to move to that position;
		If movement is possible, update the player's position and return true;
		If movement is not possible, keep the player's position unchanged and return false;
		Obtain player input through easyx, mark dir with the corresponding value, and call this function to achieve player movement;
*/
void movePlayer(Player& player);

/* Failure Function
	Parameters:
		Player structure;
	Function:
		Call this function from the start of the game to record elapsed time and remaining time;
		Calculate elapsed time based on current level and update remaining time;
		If remaining time is less than or equal to 0, the game ends and the player fails;
		If the player reaches the end point, the game ends and the player wins;
	Return value:
		Bool type, true indicates the game is over, false indicates the game continues;
*/
bool isLose();

/* Victory Function
	Parameters:
		Player structure;
	Function:
		When the player moves, determine if the space ahead of the player is the end point; if so, victory;
		If the player wins, display the victory interface and record the completion time of the current level;
		If the player fails, display the failure interface and allow the player to restart the game or return to the menu interface;
	Return value:
		Bool type, true indicates the player wins, false indicates the player has not won;
*/
bool isWin(Player& player);

/* User Operation Function
	No parameters, no return value;
	Function:
		Place in GameView(), manipulate within the drawing
		Determine through easyx key messages:
			wasd calls movePlayer()
			Other keys use items
*/
void playerOperate(ExMessage& msg, clock_t* pStartClock);

/* Flashlight Use Function
	No parameters, no return value
	Function:
		Called through playerOperate(), flashlight becomes 1, the forward field of view changes, viewMode changes
*/
void useFlashlight();

/* Bomb Use Function
	No parameters, no return value
	Function:
		Called through playerOperate(), bomb becomes 0, the wall ahead is blasted open, with explosion effects
*/
void useBomb();

/* Vision Potion Use Function
	No parameters, no return value
	Function:
		Called through playerOperate(), viewRange becomes global range, viewMedicine becomes 0
*/
void useViewmedicine();

/* Hourglass Use Function
	No parameters, no return value
	Function:
		Called through playerOperate(), extends time by one minute
*/
void useSandglass();

/* Time Pause Function
	Function: The countdown stops when paused, and continues after exiting pause
	Parameter: Initial time
	Return value: None
*/
void pauseGame(clock_t* pStartClock);

#endif //MAZE