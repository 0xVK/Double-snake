#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;

class Game_Field
{
public:	
	char GameField[50][50];
	int Width, Heigth, food_x, food_y;

	Game_Field(int Width_, int Heigth_)
	{
		Width = Width_;		Heigth = Heigth_;
		food_x = -1;	food_y = -1;

		for (int i = 0; i <= Heigth_; i++)
			for (int j = 0; j <= Width_; j++)
				GameField[j][i] = ' ';
	}

	void Output_Field ()
	{
		system ("cls");
		for (int h = 0; h <= Heigth; h++)
			{
				for (int w = 0; w <= Width; w++)
					{
						if ((w == 0) || (h == 0) || (w == Width) || (h == Heigth)) cout << '#';
						else cout << GameField[w][h];
					}	cout << endl;
			} cout << endl;
	}

	bool Food_Check ()
	{
		if (food_x == -1 && food_y == -1)
			return false;
		return true;
	}

	int Set_Food()

	{
     srand(time(NULL));

     for (int i = 1; i <= 9; ++i)
     {
         int x,y;
		 char c = ' ';
		 x = 1 + rand() % (Width - 1);;               //         min + rand() % (max - min);
		 y = 1 + rand() % (Heigth - 1);
         
		 if (GameField[x][y] == c)
			 {
				 food_x = x;
				 food_y = y;
				 GameField[food_x][food_y] = '+';
				 return 1;
			 }
     }
    
	}
};