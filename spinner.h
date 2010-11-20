//Author: Nathan Newman
//Date: 6/4/2010
//CSE 230, Raffi Khatchadourian
//Final Project, Board Game Simulation

//-------------------------------------------------------
//Spin_Tile and Spinner Class Declaration
//-------------------------------------------------------
#ifndef _Spin_Tile_
#define _Spin_Tile_

class Spin_Tile
{
	private:
		char tile_descrip[21]; //used to store the description of the tile
		int tile_movement; ////the actual movement the tile describes
	public:
		Spin_Tile(); //constructor, tile_descrip = "", tile_movement = 0
		void display_descrip();//displays the tile's description
		int return_movement();//returns the specified action of the tile
		void read_descrip(char cstr1[]); //stores a description 
		void read_movement(int n); //stores an action
};
#endif

#ifndef _Spinner_
#define _Spinner_
class Spinner
{
	private:
		int current_tile_index; //keeps track of the current index in the spinner
		int number_of_tiles; //keeps track of how many tiles the spinner has, used for modulus
		Spin_Tile current_tile; //current tile the spinner has landed on
		Spin_Tile spinner[8]; //holds the various Spin_Tile objects
	public:
		Spinner(); //constrcutor, stores tile descriptions and actions, hard-coded into definition
		int spin(); //generates a random number between 0 and number_of_tiles-1 in order to determine what tile the spinner lands on
		void display_tile(int tile_number); //displays whatever tile's index is given to it
		int return_tile_action(int tile_number); //returns the action of whatever tile's index is given it
};
#include "spinner.cc"
#endif
