//Author: Nathan Newman
//Date: 6/4/2010
//CSE 230, Raffi Khatchadourian
//Final Project, Board Game Simulation


//-------------------------------------------------------
//Card and Deck_Of_Cards Class Declaration
//-------------------------------------------------------
#ifndef _Card_
#define _Card_

using namespace std;

class Card
{
	private:
		char card_descrip[21]; //used to store the description of the card
		int card_movement; //the actual movement the card describes
	public:
		Card(); //constructor, card_descrip = "", card_movement = 0
		void display_descrip(); //displays the card's description
		int return_movement(); //returns the specified action of the card
		void read_descrip(char cstr1[]); //stores a description 
		void read_movement(int n); //stores an action
};
#endif

#ifndef _Deck_Of_Cards_
#define _Deck_Of_Cards_
class Deck_Of_Cards
{
	private:
		int current_card_index; //keeps track of the current index in the deck
		int number_of_cards; //holds how many cards there are (needed for modulus)
		Card current_card; //could be called 'top_card' as it is the top card of the deck
		Card deck[10]; //holds the various card objects
	public:
		Deck_Of_Cards(); //constrcutor, stores card descriptions and actions, hard-coded into definition
		int draw_a_card(); //stores the index of the top card then advances the index into the deck, and returns top index
		void display_card(int card_number); //displays whatever card's index is given it
		int return_card_action(int card_number); //returns the action of whatever card's index is given it
};
#include "card_deck.cc"
#endif
