#include <ap/apmatrix.h>
#include <ap/apstring.h>
#include <fstream.h>
#include <iostream.h>

struct PAS{//PAS stands for pasition cordinats x and y (x,y)
	int x;
	int y;
};

class Maze2d{
public:
	Maze2d();//sets all private variables to 0
	void setmaze(const apstring &);//sets the maze matrix to file on hard drive
	void computerfinish();//hase the computer finish the maze
	bool moveright();//moves the pasition in the maze right one if posiable
	bool moveleft();//moves the pasition in the maze left one if posiable
	bool moveup();//moves the pasition in the maze up one if posiable
	bool movedown();//moves the pasition in the maze down one if posiable
	void reset();//resets the pasition back to starting pasition
	void display(ostream &);//displayes the maze into ostream operator
	void display();//displayes the maze to defalt operator "cout"
private:
	void computerfinish(char);//hase the computer finish the maze
	bool mover();//returns true if and only if the user can move right
	bool movel();//returns true if and only if the user can move left
	bool moveu();//returns true if and only if the user can move up
	bool moved();//returns true if and only if the user can move down
	void find(char,PAS &);//return the pasition of the char
	apmatrix<char> maze;//creats the maze matrix
	PAS mazesize;//creats a variable mazesize that holds the maze's size
	PAS pasition;//the curent pasition of the user/computer
	PAS start;//the starting pasition 
	PAS end;//the ending pasition
};

#include "m2dclass.cpp"