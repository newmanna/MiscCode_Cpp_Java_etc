//Author: Nathan Newman
//Date: 6/4/2010
//CSE 230, Raffi Khatchadourian
//Final Project, Board Game Simulation
#ifndef _Player_
#define _Player_

using namespace std;
//-------------------------------------------------------
//Player Class Declaration
//-------------------------------------------------------
class Player
{
	private:
		char name[11]; //cstring designated to store the player's name
		int current_space; //used to keep track of the player's current space on the game board
	public:
		Player(); //constructor, name = "", and current_space = 0
		int roll(); //generates a random dice roll that is the sum of a roll of two six sided die
		void display_player(); //displays the player's name and current_space
		void display_name(); //displays only the player's name
		void advance(int number_of_spaces_to_move); //advances (or retreats) a player's position
		void move_to(int space_to_move_to); //instantly moves a player to specific position on the game board
		void read_name(); //reads in a player's name
		int return_current_space(); //returns the player's current space
};
#include "player.cc"
#endif

