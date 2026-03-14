#include"Maze.h"
int timer1 = 30;
int timer2 = 60;
int map[2][50][50];      //有三个关卡，每个关卡的大小不同，0表示空地，1表示墙壁，2表示玩家,3表示手电筒，4表示炸弹，5表示视野药水，6表示沙漏

//简单模式为15*15，困难模式为30*30，地狱模式为50*50，简单困难模式多余部分为-1，不打印

bool music = true;			//音乐是否开启
int nowSound = 100;		//音量大小
int finalx, finaly;		//终点坐标
int beginx, beginy;		//起点坐标
int level = 0;               //当前关卡，取值为0，1，分别对应简单模式、困难模式
int timeLeft = 0;             //剩余时间，单位为秒，剩余时间=总时间-已经过的时间
int curTime = 0;            //当前已经过的时间，单位为秒
int curModetime = 0;			//当前模式总时间
int flashNum =0;			//手电筒数量
int bombNum = 0;			//炸弹数量
int viewmedicineNum = 0;		//视野药水数量
int sandglassNum = 0;			//沙漏数量
int preViewmode = 0;			//
struct Player player;		//玩家	
ExMessage msg;