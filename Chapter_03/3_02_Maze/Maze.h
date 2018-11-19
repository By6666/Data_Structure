#ifndef _MAZE
#define _MAZE

#include "Stack.h"

struct Pos                //λ������ṹ��
{
	int x, y;
};

#define UP      maze[current.x-1][current.y]
#define DOUWN   maze[current.x+1][current.y]
#define LEFT    maze[current.x][current.y-1]
#define RIGHT   maze[current.x][current.y+1]
const int ExitX = 8;		//������ڵ�X�����ڵ�8��
const int ExitY = 10;		//������ڵ�Y�����ڵ�10��

int maze[10][12] = { 1,1,1,1,1,1,1,1,1,1,1,1,		//�����Թ�����
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


