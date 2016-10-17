#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Game_Field.h"
#include "Snake.h"
using namespace std;

#define CLS system ("cls")
#define VERSION ("1.1") 
#define AUTHOR ("Kucher Vitaliy")
#define ROB_WIN   cout << endl << pl1 << " win!" << endl << endl; system ("pause"); 
#define POUL_WIN  cout << endl << pl2 << " win!" << endl << endl; system ("pause"); 

const int W = 28, H = 15, SleepTime = 130;
int w = 0, time_ = 59;


int Time_Out ()
{
	w+=100;

	if (w == 600)
		{
			time_--;
			w = 0;
		}

	cout <<"\t timer: ["<< time_ << ']'<< endl;

	return time_ + 1;
}

void Game2 (string pl1, string pl2)
{

	int go = 0;
	Game_Field game_field(W,H);
	Snake Poul(3, 8, 10, 8, 9, 8, 8, 0, -1, '@', 'w', 'a', 's', 'd'); // ((snakesize,head_coord_x,head_coord_y,coord1_x,coord1_y,coord2_x,coord2_y,dir_X,dir_Y,body_s,w,a,s,d))
	Snake Rob(3, 18, 7, 18, 8, 18, 9, 0, 1, '$', '8', '4', '5', '6'); // ((snakesize,head_coord_x,head_coord_y,coord1_x,coord1_y,coord2_x,coord2_y,dir_X,dir_Y,body_s,w,a,s,d))

	

	while (5)
	{
		Poul.Snake_On_Field(game_field);
		Rob.Snake_On_Field(game_field);

		if (_kbhit())
		{
			char c = _getch();
			Poul.Change_Dir (c);
			Rob.Change_Dir (c);
		}		

		if (!game_field.Food_Check())
			 go+=game_field.Set_Food();

		if (Rob.coord_x[0] == game_field.food_x && Rob.coord_y[0] == game_field.food_y)
		{
			Rob.Count_Snake();
			game_field.food_x = -1;		game_field.food_y = -1;
		}

		if (Poul.coord_x[0] == game_field.food_x && Poul.coord_y[0] == game_field.food_y)
		{
			game_field.food_x = -1;		game_field.food_y = -1;
		}

		for (int i = 0; i < Rob.snake_size; i++)
		{
			if ((Poul.coord_x[0] == Rob.coord_x[i]) && (Poul.coord_y[0] == Rob.coord_y[i]))
			{
				POUL_WIN
				exit(0);
			}
		}

		if (Rob.Game_Over(game_field))
		{
			game_field.Output_Field();
			POUL_WIN
		}

		game_field.Output_Field();

		Poul.Clear_Coord(game_field);
		Rob.Clear_Coord	(game_field);
		Poul.Next_Step(W,H);
		Rob.Next_Step(W,H);

		if (Rob.snake_size - 3 != 4)
			cout << "Åäà: [" << Rob.snake_size - 3 << "/4] ";
		else { ROB_WIN }

		if (!Time_Out()) { ROB_WIN }

		Sleep (SleepTime);

	}
}

string Set_Login1 ()
{
	string log;
	cout << "Enter first player name:" << endl << "\t\t $$$>  ";
	cin >> log;
	return log;
}

string Set_Login2 ()
{
	string log;
	cout << "Enter second player name:" << endl << "\t\t @@@>  ";
	cin >> log;
	return log;
}

void How_To_Play ()
{
	CLS;
	cout << "Rules" << endl;
	cout << "At first, You should type first and second player`s names"<< endl << "(without spaces)" << endl;
	cout << "After it, game will be start, and task first player $$$> "<< endl << "is eat 5 apples, " << endl;
	cout << "And @@@> task is catch first player"<< endl;

	cout << "Press any key to continue...";
	_getch();

	string pl_1, pl_2;
	CLS; pl_1 = Set_Login1(); CLS; pl_2 = Set_Login2(); Game2 (pl_1, pl_2);
	
}

void About ()
{
	CLS;
	cout << "About..." << endl<< endl;
	cout << "\tName: Double Snake" << endl;	
	cout << "\tVersion: " << VERSION << endl;
	cout << "\tAuthor: " << AUTHOR << endl << endl;

	cout << "Press any key to begin";
	_getch();

	string pl_1, pl_2;
	CLS; pl_1 = Set_Login1(); CLS; pl_2 = Set_Login2(); Game2 (pl_1, pl_2);
}


int main ()
{
	setlocale( LC_ALL,"Russian" );
	char c;
	string pl_1, pl_2;
	system ("color 9");
	cout << "Menu:\n \t1.Play\n \t2.How to play\n \t3.About...\n \t4.Quit\n\nPress any key... "; 
	c = _getch();

	switch (c)
	{
	case '1': CLS; pl_1 = Set_Login1(); CLS; pl_2 = Set_Login2(); Game2 (pl_1, pl_2); break;
	case '2': How_To_Play(); break;
	case '3': About(); break;
	case '4': exit(0); break;
	default: cout << endl << "Invalid choise" << endl; break;
	}

	system ("pause");
	system ("pause");
	return 0;

}
