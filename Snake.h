#include <iostream>
#include <conio.h>
using namespace std;

class Snake
{
public:

	char c,w,a,s,d;
	int snake_size, dir_x, dir_y; 
	int coord_x[15], coord_y[15];

	Snake(int snakesize, int head_coord_x, int head_coord_y, int coord1_x, int coord1_y, int coord2_x, int coord2_y, int dir_X, int dir_Y, 
			char body_c, char W, char A, char S, char D)
	{
		snake_size = snakesize;			dir_x = dir_X;					dir_y = dir_Y;	c = body_c;
		coord_x[0] = head_coord_x;		coord_y[0] = head_coord_y;
		coord_x[1] = coord1_x;			coord_y[1] = coord1_y;
		coord_x[2] = coord2_x;			coord_y[2] = coord2_y;
		w = W;			a = A;			s = S;		 d = D;

		for (int i = 3; i < 15; i++) { coord_x[i] = 0; coord_y[i] = 0; }
	}

	void Next_Step (int w_, int h_)
{

	for (int i = snake_size-1; i >= 1; i--)
		{
			coord_x[i] = coord_x[i-1];
			coord_y[i] = coord_y[i-1];
		}
	coord_x[0]+=dir_x;		coord_y[0]-=dir_y;

	Check_Out (w_, h_);
}

	void Snake_On_Field (Game_Field &field_tmp)
	{
		if ((dir_x == 1)&&(dir_y == 0))  field_tmp.GameField[coord_x[0]][coord_y[0]] = '>';
		if ((dir_x == -1)&&(dir_y == 0)) field_tmp.GameField[coord_x[0]][coord_y[0]] = '<';
		if ((dir_x == 0)&&(dir_y == 1))  field_tmp.GameField[coord_x[0]][coord_y[0]] = '^';
		if ((dir_x == 0)&&(dir_y ==-1))  field_tmp.GameField[coord_x[0]][coord_y[0]] = 'v';
		
		for (int i = 1; i < snake_size; i++)
			{
				if (coord_x[i] && coord_y[i] != 0)
				field_tmp.GameField[coord_x[i]][coord_y[i]] = c;
			}
	}

	void Check_Out (int w, int h)
	{
		if (coord_x[0] == w) coord_x[0] = 1;
		if (coord_x[0] == 0) coord_x[0] = w-1;
		if (coord_y[0] == h) coord_y[0] = 1;
		if (coord_y[0] == 0) coord_y[0] = h-1;
	}

	void Clear_Coord (Game_Field &field_tmp)
{
	 
	  for (int i = 0; i < snake_size; ++i)
		 field_tmp.GameField[coord_x[i]][coord_y[i]] = ' ';
}

	void Change_Dir (char C)
	{
		 if (C == w) if (dir_x != 0 && dir_y != -1) { dir_x = 0;dir_y = 1; } 
         if (C == a) if (dir_x != 1 && dir_y != 0) { dir_x = -1; dir_y = 0;} 
         if (C == s) if (dir_x != 0 && dir_y != 1){ dir_x = 0; dir_y = -1; } 
         if (C == d) if (dir_x != -1 && dir_y != 0){ dir_x = 1; dir_y = 0; }       
	}

	bool Game_Over (Game_Field &field_tmp)
	{
     for (int i = 1; i < snake_size; ++i)
      if (coord_x[0] == coord_x[i] && coord_y[0] == coord_y[i]) 
	  { field_tmp.GameField[coord_x[i]][coord_y[i]] = 'X'; return true;}
      
		  return false;
	}

	void Count_Snake ()
	{
		snake_size++;
	}

};