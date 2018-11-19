#ifndef _MAZE
#define _MAZE

#include "Stack.h"

struct Pos                //位置坐标结构体
{
	int x, y;
};

#define UP      maze[current.x-1][current.y]
#define DOUWN   maze[current.x+1][current.y]
#define LEFT    maze[current.x][current.y-1]
#define RIGHT   maze[current.x][current.y+1]
const int ExitX = 8;		//定义出口的X坐标在第8行
const int ExitY = 10;		//定义出口的Y坐标在第10列

int maze[10][12] = { 1,1,1,1,1,1,1,1,1,1,1,1,		//声明迷宫数组
					 1,0,0,0,1,1,1,1,1,1,1,1,
					 1,1,1,0,1,1,0,0,0,0,1,1,
					 1,1,1,0,1,1,0,1,1,0,1,1,
					 1,1,1,0,0,0,0,1,1,0,1,1,
					 1,1,1,0,1,1,0,1,1,0,1,1,
					 1,1,1,0,1,1,0,1,1,0,1,1,
					 1,1,1,1,1,1,0,1,1,0,1,1,
					 1,1,0,0,0,0,0,0,1,0,0,1,
					 1,1,1,1,1,1,1,1,1,1,1,1 };



#endif // !_MAZE


