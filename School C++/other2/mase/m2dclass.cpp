Maze2d::Maze2d()
{
	end.x=0;end.y=0;
	mazesize.x=0;mazesize.y=0;
	pasition.x=0;pasition.y=0;
	start.x=0;start.y=0;
	maze.resize(0,0);
}

void Maze2d::find(char tofind,PAS &Pasition)
{
	for(int i=0;i<mazesize.x;i++)
	{
		for(int x=0;x<mazesize.y;x++)
		{
			if(maze[i][x]==tofind)
			{
				Pasition.x=i;
				Pasition.y=x;
			}
		}
	}
}

void Maze2d::setmaze(const apstring &filename)
{
	ifstream file(filename.c_str());
	file>>mazesize.x>>mazesize.y;
	maze.resize(mazesize.x,mazesize.y);
	for(int i=0;i<mazesize.x;i++)
	{
		for(int x=0;x<mazesize.y;x++)
		{
			file>>maze[i][x];
		}
	}
	find('0',pasition);
	start=pasition;
	find('e',end);
}
bool Maze2d::mover()
{
	if(pasition.y+1<mazesize.y)
		return(maze[pasition.x][pasition.y+1]!='#');
	else
		return false;
}

bool Maze2d::movel()
{
	if(pasition.y-1>=0)
		return(maze[pasition.x][pasition.y-1]!='#');
	else
		return false;
}

bool Maze2d::moveu()
{
	if(pasition.x-1>=0)
		return(maze[pasition.x-1][pasition.y]!='#');
	else
		return false;
}

bool Maze2d::moved()
{
	if(pasition.x+1<mazesize.x)
		return(maze[pasition.x+1][pasition.y]!='#');
	else
		return false;
}

bool Maze2d::moveright()
{
	if(mover())
	{
		maze[pasition.x][pasition.y]='.';
		maze[pasition.x][++pasition.y]='0';
		return true;
	}
	else
		return false;
}

bool Maze2d::moveleft()
{
	if(movel())
	{
		maze[pasition.x][pasition.y]='.';
		maze[pasition.x][--pasition.y]='0';
		return true;
	}
	else 
		return false;
}

bool Maze2d::moveup()
{
	if(moveu())
	{
		maze[pasition.x][pasition.y]='.';
		maze[--pasition.x][pasition.y]='0';
		return true;
	}
	else
		return false;
}

bool Maze2d::movedown()
{
	if(moved())
	{
		maze[pasition.x][pasition.y]='.';
		maze[++pasition.x][pasition.y]='0';
		return true;
	}
	else
		return false;
}

void delay(const apmatrix<char> &maze)
{
	for(int x=0;x<maze.
	cout<<endl;
	for(long t=0;t<88888888;t++);//delayes the computer
}
void Maze2d::computerfinish()
{
	if(mover())
	{
		maze[pasition.x][pasition.y]='.';
		maze[pasition.x][++pasition.y]='0';
		delay(maze);
		computerfinish('r');
		maze[pasition.x][pasition.y]='.';
		maze[pasition.x][--pasition.y]='0';
	}
	if(movel())
	{
		maze[pasition.x][pasition.y]='.';
		maze[pasition.x][--pasition.y]='0';
		delay(maze);
		computerfinish('l');
		maze[pasition.x][pasition.y]='.';
		maze[pasition.x][++pasition.y]='0';
	}
	if(moveu())
	{
		maze[pasition.x][pasition.y]='.';
		maze[--pasition.x][pasition.y]='0';
		delay(maze);
		computerfinish('u');
		maze[pasition.x][pasition.y]='.';
		maze[++pasition.x][pasition.y]='0';
	}
	if(moved())
	{
		maze[pasition.x][pasition.y]='.';
		maze[++pasition.x][pasition.y]='0';
		delay(maze);
		computerfinish('d');
		maze[pasition.x][pasition.y]='.';
		maze[--pasition.x][pasition.y]='0';
	}
}
void Maze2d::computerfinish(char dir='s')
{
		
	if(dir=='r')
	{
		if(mover())
		{
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][++pasition.y]='0';
			delay(maze);
			computerfinish('r');
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][--pasition.y]='0';
		}
		if(moveu())
		{
			maze[pasition.x][pasition.y]='.';
			maze[--pasition.x][pasition.y]='0';
			delay(maze);
			computerfinish('u');
			maze[pasition.x][pasition.y]='.';
			maze[++pasition.x][pasition.y]='0';
		}
		if(moved())
		{
			maze[pasition.x][pasition.y]='.';
			maze[++pasition.x][pasition.y]='0';
			delay(maze);
			computerfinish('d');
			maze[pasition.x][pasition.y]='.';
			maze[--pasition.x][pasition.y]='0';
		}
	}
	if(dir=='l')
	{
		if(movel())
		{
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][--pasition.y]='0';
			delay(maze);
			computerfinish('l');
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][++pasition.y]='0';
		}
		if(moveu())
		{
			maze[pasition.x][pasition.y]='.';
			maze[--pasition.x][pasition.y]='0';
			delay(maze);
			computerfinish('u');
			maze[pasition.x][pasition.y]='.';
			maze[++pasition.x][pasition.y]='0';
		}
		if(moved())
		{
			maze[pasition.x][pasition.y]='.';
			maze[++pasition.x][pasition.y]='0';
			delay(maze);
			computerfinish('d');
			maze[pasition.x][pasition.y]='.';
			maze[--pasition.x][pasition.y]='0';
		}
	}
	if(dir=='u')
	{
		if(moveu())
		{
			maze[pasition.x][pasition.y]='.';
			maze[--pasition.x][pasition.y]='0';
			delay(maze);
			computerfinish('u');
			maze[pasition.x][pasition.y]='.';
			maze[++pasition.x][pasition.y]='0';
		}
		if(mover())
		{
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][++pasition.y]='0';
			delay(maze);
			computerfinish('r');
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][--pasition.y]='0';
		}
		if(movel())
		{
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][--pasition.y]='0';
			delay(maze);
			computerfinish('l');
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][++pasition.y]='0';
		}
	}
	if(dir=='d')
	{
		if(moved())
		{
			maze[pasition.x][pasition.y]='.';
			maze[++pasition.x][pasition.y]='0';
			delay(maze);
			computerfinish('d');
			maze[pasition.x][pasition.y]='.';
			maze[--pasition.x][pasition.y]='0';
		}
		if(mover())
		{
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][++pasition.y]='0';
			delay(maze);
			computerfinish('r');
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][--pasition.y]='0';
		}
		if(movel())
		{
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][--pasition.y]='0';
			delay(maze);
			computerfinish('l');
			maze[pasition.x][pasition.y]='.';
			maze[pasition.x][++pasition.y]='0';
		}
	}
}

void Maze2d::display(ostream &output)
{
	charspaced(output,maze);
}
void Maze2d::display()
{
	charspaced(cout,maze);
}

ostream &operator<<(ostream &output,apmatrix<char> &maze)
{
	charspaced(output,maze);
	return output;
}


void Maze2d::reset()
{
	maze[start.x][start.y]='0';
	maze[pasition.x][pasition.y]='.';
	pasition=start;
}

