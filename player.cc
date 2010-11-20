 //Author: Nathan Newman
//Date: 6/4/2010
//CSE 230, Raffi Khatchadourian
//Final Project, Board Game Simulation

#include "player.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

#include <ctime>
using namespace std;
//see declaration for descriptions of specific definitions

//-------------------------------------------------------
//Player Class Defintions
//-------------------------------------------------------
Player::Player()
{
    char name[11];
    current_space = 0;
}
int Player::roll()
{
	int die_1, die_2;
	die_1 = (rand() % 6) + 1;
	die_2 = (rand() % 6) + 1;
	return (die_1 + die_2);
}
void Player::display_player()
{
     cout << "Player's Name: " << name << endl;
     cout << "Player's Current Space: " << current_space;     
}
void Player::display_name()
{
	cout << name;
}
void Player::advance(int number_of_spaces_to_move)
{
	current_space = current_space + number_of_spaces_to_move;
}
void Player::move_to(int space_to_move_to)
{
	current_space = space_to_move_to;
}
void Player::read_name()
{
	cin >> name;
}
int Player::return_current_space()
{
	return current_space;
}
