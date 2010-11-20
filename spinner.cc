//Author: Nathan Newman
//Date: 6/4/2010
//CSE 230, Raffi Khatchadourian
//Final Project, Board Game Simulation

#include "spinner.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

#include <ctime>
using namespace std; 


//-------------------------------------------------------
//Spin_Tile and Spinner Class Definitions
//-------------------------------------------------------
Spin_Tile::Spin_Tile()
{
	char tile_descrip[21];
    	tile_movement = 0;
}
void Spin_Tile::display_descrip()
{
	cout << tile_descrip << endl;
}
int Spin_Tile::return_movement()
{
	return tile_movement;
}
void Spin_Tile::read_descrip(char cstr1[])
{
    //tile_descrip = cstr1;
    strcpy(tile_descrip, cstr1);
}
void Spin_Tile::read_movement(int n)
{
	tile_movement = n;
}
Spinner::Spinner()
{
	spinner[0].read_descrip("Back 9");
	spinner[0].read_movement(-9);
	spinner[1].read_descrip("Go to Beginning");
	spinner[1].read_movement(0);
	spinner[2].read_descrip("Back 8");
	spinner[2].read_movement(-8);
	spinner[3].read_descrip("Back 7");
	spinner[3].read_movement(-7);
	spinner[4].read_descrip("Forward 1");
	spinner[4].read_movement(1);
	spinner[5].read_descrip("Back 4");
	spinner[5].read_movement(4);
	spinner[6].read_descrip("Forward 2");
	spinner[6].read_movement(2);
	spinner[7].read_descrip("Back 6");
	spinner[7].read_movement(-6);
	current_tile_index = 0;
	number_of_tiles = 8;
	current_tile = spinner[current_tile_index];
}
int Spinner::spin()
{
	int random = (rand() % 8);
	return random;
}
void Spinner::display_tile(int tile_number)
{
	spinner[tile_number].display_descrip();
}
int Spinner::return_tile_action(int tile_number)
{
	int x = spinner[tile_number].return_movement();
	return x;
}
