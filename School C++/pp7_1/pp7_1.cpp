//Program that playes paper, rock,  scissor game with eather two players
//or a player agent the computer
//Programing Project 7.1
//Adam Holt
//last edited 5-25-01

#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

enum game{N,P=1,R,S};
enum playertype{H=1,C};

game getplayer();
playertype getplayertype();
game getplayer(int);
game converttoprs(char);
game converttoprs(int);
game getcomputer();
void showwinner(game,game,char *);
bool isvalid(game);


void main()
{
	playertype player2;
	char anothergame='Y';

	player2=getplayertype();
	do
	{
		if(player2==H)
		{
			showwinner(getplayer(2),getplayer(1),"Player2");
		}
		else
		{
			showwinner(getcomputer(),getplayer(),"Computer");
		}
		cout<<"Another Game(Y,N)?"<<endl;
		anothergame=getch();
		anothergame=toupper(anothergame);
	}while(anothergame=='Y');
}


playertype getplayertype()
{
	char playtype;
	playertype toreturn=C;
	cout<<"Welcome the Paper, Rock, Scissors Game."<<endl
		<<"Please Select Secont Player."<<endl
		<<"H-Human"<<endl
		<<"C-Computer"<<endl
		<<"----------"<<endl;
	playtype=char(getch());
	playtype=toupper(playtype);
	playtype=='H'?toreturn=H:toreturn=C;
	return toreturn;
}


game getplayer()
{
	char prs;
	game choice;
	do
	{
		cout<<"Enter Your Choice"<<endl
			<<"P-Paper"<<endl
			<<"R-Rock"<<endl
			<<"S-Scissors"<<endl
			<<"----------"<<endl;
		prs=char(getch());
		choice=converttoprs(prs);
	}while(choice==N);
	
	
	return choice;

}

game getplayer(int player)
{
	char prs;
	game choice;
	do
	{
		cout<<"Player "<<player
			<<" Enter Your Choice"<<endl
			<<"P-Paper"<<endl
			<<"R-Rock"<<endl
			<<"S-Scissors"<<endl
			<<"----------"<<endl;
		prs=char(getch());
		choice=converttoprs(prs);
	}while(choice==N);
	
	
	return choice;

}


game converttoprs(char prs)
{
	game toreturn;
	prs=toupper(prs);

	switch(prs)
	{
	case 'P':
		toreturn=P;
		break;
	case 'R':
		toreturn=R;
		break;
	case 'S':
		toreturn=S;
		break;
	default:
		toreturn=N;
		break;
	}
	return toreturn;
}
game converttoprs(int prs)
{
	game toreturn;
	prs=toupper(prs);

	switch(prs)
	{
	case P:
		toreturn=P;
		break;
	case R:
		toreturn=R;
		break;
	case S:
		toreturn=S;
		break;
	default:
		toreturn=N;
		break;
	}
	return toreturn;
}

game getcomputer()
{
	game cchoice;
	//srand(time(NULL));
	cchoice=converttoprs((rand()%S)+1);
	if(!isvalid(cchoice))
	{
		exit(1);
	}
	return(cchoice);
}

void showwinner(game player2,game player1,char * player)
{
	if(player1==player2)
	{
		cout<<"Nobody wins"<<endl;
	}
	else if(player1==P&&player2==R)
	{
		cout<<"Player1 Wins"<<endl
			<<"Paper covers rock"<<endl;
	}
	else if(player1==R&&player2==S)
	{
		cout<<"Player1 Wins"<<endl
			<<"Rock breaks scissors"<<endl;
	}
	else if(player1==S&&player2==P)
	{
		cout<<"Player1 Wins"<<endl
			<<"Scissors cut paper"<<endl;
	}
	else if(player2==P&&player1==R)
	{
		cout<<player<<" Wins"<<endl
			<<"Paper covers rock"<<endl;
	}
	else if(player2==R&&player1==S)
	{
		cout<<player<<" Wins"<<endl
			<<"Rock breaks scissors"<<endl;
	}
	else if(player2==S&&player1==P)
	{
		cout<<player<<" Wins"<<endl
			<<"Scissors cut paper"<<endl;
	}
	else
	{
		cout<<"An error has accourd"<<endl;
	}
}

bool isvalid(game choice)
{
	return((choice==P)||(choice==R)||(choice==S));
}