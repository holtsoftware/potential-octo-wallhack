#include "stdafx.h"
#include "m2dclass.h"


int main()
{
	Maze2d maze;
	maze.setmaze("maze1.maz");
	maze.moveright();

	maze.movedown();
	maze.movedown();
	maze.movedown();
	maze.moveright();
	maze.moveright();
	maze.moveup();
	maze.moveup();
	maze.moveup(); 
	maze.moveright();
	maze.moveright();
	maze.movedown();
	//maze.gotoend();
	maze.display();
	return 0;
}

