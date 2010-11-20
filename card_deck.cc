//Author: Nathan Newman
//Date: 6/4/2010
//CSE 230, Raffi Khatchadourian
//Final Project, Board Game Simulation

#include "card_deck.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

#include <ctime>
using namespace std;

//-------------------------------------------------------
//Card and Deck_Of_Cards Class Definitions
//-------------------------------------------------------
Card::Card()
{
	char card_descrip[21];
    	card_movement = 0;
}
void Card::display_descrip()
{
	cout << card_descrip << endl;
}
int Card::return_movement()
{
	return card_movement;
}
void Card::read_descrip(char cstr1[])
{
    //card_descrip = cstr1;
    strcpy(card_descrip, cstr1);
}
void Card::read_movement(int n)
{
	card_movement = n;
}
Deck_Of_Cards::Deck_Of_Cards()
{
	deck[0].read_descrip("Go back 9 spaces.");
	deck[0].read_movement(-9);
	deck[1].read_descrip("Go to the beginning.");
	deck[1].read_movement(0);
	deck[2].read_descrip("Go back 3 spaces.");
	deck[2].read_movement(-3);
	deck[3].read_descrip("Go back 8 spaces.");
	deck[3].read_movement(-8);
	deck[4].read_descrip("Go forward 2 spaces.");
	deck[4].read_movement(2);
	deck[5].read_descrip("Go forward 1 space.");
	deck[5].read_movement(1);
	deck[6].read_descrip("Go forward 3 spaces.");
	deck[6].read_movement(3);
	deck[7].read_descrip("Go to the beginnning.");
	deck[7].read_movement(0);
	deck[8].read_descrip("Go forward 2 spaces.");
	deck[8].read_movement(2);
	deck[9].read_descrip("Go forward 6 spaces.");
	deck[9].read_movement(6);
	current_card_index = 0;
	number_of_cards = 10;
	current_card = deck[current_card_index];
	
}
int Deck_Of_Cards::draw_a_card()
{
	int temp = current_card_index;
	current_card_index++;
	current_card_index = current_card_index % number_of_cards;
	return temp;
}
void Deck_Of_Cards::display_card(int card_number)
{
	deck[card_number].display_descrip();
}
int Deck_Of_Cards::return_card_action(int card_number)
{
	int x = deck[card_number].return_movement();
	return x;
}
