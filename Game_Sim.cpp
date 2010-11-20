//Author: Nathan Newman
//Date: 6/4/2010
//CSE 230, Raffi Khatchadourian
//Final Project, Board Game Simulation
#include "player.h"
#include "card_deck.h"
#include "spinner.h" 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
//see read_me_nathan_newman.txt for game description and instructions
//all necessary information will be given in read_me in order to prevent
//cluttering the main body with comments.  Thanks
int main()
{
	srand ((unsigned) time(0));//needed for random number generator
	cout << "-----------------------------------------------------\n"
		<<"\t\t\tWelcome To THE GAME!!!!\n"
		<<"-----------------------------------------------------\n"
		<< endl;
	cout << "Please enter the number of players: ";
	int numbPlayers;
	cin >> numbPlayers;
	Player *playPtr = new Player[numbPlayers];
	int *winners = new int[numbPlayers];
	for (int i = 0; i < numbPlayers; i++)
	{
		cout << "Please enter a name for Player (max of 10 letters) " << i+1 << ": ";
		playPtr[i].read_name();
	}
      
	Deck_Of_Cards newDeck;
	Spinner newSpin;
    
	cout << "Now let's randomly select someone to start this game up!\n";
	int current_player = rand() % numbPlayers;
	cout << "Alright it looks like ";
	playPtr[current_player].display_name();
	cout << " gets to go first!\nSo let's get this party started!\n\n";
	
	//int activePlayers = numbPlayers;
	int recent_winner = 0;

	while (recent_winner < numbPlayers)
	{
        int current_space = playPtr[current_player].return_current_space();
		if (current_space < 90)
		{
			cout << "Ok, ";
			playPtr[current_player].display_name();
			cout << ", let's give those dice a roll...\n";
			int dice_roll = playPtr[current_player].roll();
			cout << "You rolled a " << dice_roll << ".\n";
			playPtr[current_player].advance(dice_roll);
			current_space = playPtr[current_player].return_current_space();
		
			if (current_space == 10)
			{
				cout << "Alright it looks like you get to draw a card, so let's see what it says...\n";
				int current_card = newDeck.draw_a_card();
				newDeck.display_card(current_card);
				int move = newDeck.return_card_action(current_card);
				if (move == 0)
				{
					cout << "Oh shoot!  You have to go back to the beginning...thats too bad\n";
					playPtr[current_player].move_to(move);
				}
				else if (move < 0)
				{
					cout << "Uh oh!  You have to take a few steps back.\nWell its not like it's the end of the world, right?\n";
					playPtr[current_player].advance(move);
				}
				else //move > 0
				{
					cout << "Woohoo!  Looks like you get a push in the right direction!\n";
					playPtr[current_player].advance(move);
				}
			}
			else if (current_space == 30)
			{
				cout << "WOW!  Thats quite a jump ahead!\nTry not to rub it in to the other players.\n";
				playPtr[current_player].move_to(70);
			}
			else if (current_space == 40)
			{
				cout << "Alright it's time to SPIN THE WHEEL!!!\n'"
					<< "So give her a spin and let's see what happens.\n";
				int current_tile = newSpin.spin();
				newSpin.display_tile(current_tile);
				int move = newSpin.return_tile_action(current_tile);
				if (move == 0)
				{
					cout << "Oh shoot!  You have to go back to the beginning...thats too bad\n";
					playPtr[current_player].move_to(move);
				}
				else if (move < 0)
				{
					cout << "Uh oh!  You have to take a few steps back.\nWell its not like it's the end of the world, right?\n";
					playPtr[current_player].advance(move);
				}
				else //move > 0
				{
					cout << "Woohoo!  Looks like you get a push in the right direction!\n";
					playPtr[current_player].advance(move);
				}
			}	
			else if (current_space == 60)
			{
				cout << "Alright it looks like you get to draw a card, so let's see what it says...\n";
				int current_card = newDeck.draw_a_card();
				newDeck.display_card(current_card);
				int move = newDeck.return_card_action(current_card);
				if (move == 0)
				{
					cout << "Oh shoot!  You have to go back to the beginning...thats too bad\n";
					playPtr[current_player].move_to(move);
				}
				else if (move < 0)
				{
					cout << "Uh oh!  You have to take a few steps back.\nWell its not like it's the end of the world, right?\n";
					playPtr[current_player].advance(move);
				}
				else //move > 0
				{
					cout << "Woohoo!  Looks like you get a push in the right direction!\n";
					playPtr[current_player].advance(move);
				}
			}
			else if (current_space == 70)
			{
				cout << "Alright it's time to SPIN THE WHEEL!!!\n"
					<< "So give her a spin and let's see what happens.\n";
				int current_tile = newSpin.spin();
				newSpin.display_tile(current_tile);
				int move = newSpin.return_tile_action(current_tile);
				if (move == 0)
				{
					cout << "Oh shoot!  You have to go back to the beginning...thats too bad\n";
					playPtr[current_player].move_to(move);
				}
				else if (move < 0)
				{
					cout << "Uh oh!  You have to take a few steps back.\nWell its not like it's the end of the world, right?\n";
					playPtr[current_player].advance(move);
				}
				else //move > 0
				{
					cout << "Woohoo!  Looks like you get a push in the right direction!\n";
					playPtr[current_player].advance(move);
				}
			}
			else if (current_space == 80)
			{
				cout << "Well this is different.\n"
					<< "You get to choose whether you spin the wheel or draw a card.\n"
					<< "So which will it be: spin (enter 1) or draw (enter 2)? ";
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					cout << "Alright it's time to SPIN THE WHEEL!!!\n"
						<< "So give her a spin and let's see what happens.\n";
					int current_tile = newSpin.spin();
					newSpin.display_tile(current_tile);
					int move = newSpin.return_tile_action(current_tile);
					if (move == 0)
					{
						cout << "Oh shoot!  You have to go back to the beginning...thats too bad\n";
						playPtr[current_player].move_to(move);
					}
					else if (move < 0)
					{
						cout << "Uh oh!  You have to take a few steps back.\nWell its not like it's the end of the world, right?\n";
						playPtr[current_player].advance(move);
					}
					else //move > 0
					{
						cout << "Woohoo!  Looks like you get a push in the right direction!\n";
						playPtr[current_player].advance(move);
					}					
				}
				else ///choice == 2
				{
					cout << "Alright it looks like you get to draw a card, so let's see what it says...\n";
					int current_card = newDeck.draw_a_card();
					newDeck.display_card(current_card);
					int move = newDeck.return_card_action(current_card);
					if (move == 0)
					{
						cout << "Oh shoot!  You have to go back to the beginning...thats too bad\n";
						playPtr[current_player].move_to(move);
					}
					else if (move < 0)
					{
						cout << "Uh oh!  You have to take a few steps back.\nWell its not like it's the end of the world, right?\n";
						playPtr[current_player].advance(move);
					}
					else //move > 0
					{
						cout << "Woohoo!  Looks like you get a push in the right direction!\n";
						playPtr[current_player].advance(move);
					}				
				}
			}
			else if (current_space >= 90)
			{
				playPtr[current_player].move_to(90);
				cout << "Congratulations ";
				playPtr[current_player].display_name();
				cout << "!\n"
					<< "You made it to the end!\n\n";
				winners[recent_winner] = current_player;
				recent_winner++;
			}
		cout << "\nEnd of Turn: So let's see how you did...\n";
		playPtr[current_player].display_player();
		cout << endl << endl;
		}

		current_player++;
		current_player = current_player % numbPlayers;
	}

	cout << "...And the winners are: \n";
	cout << "********************\n";
	for (int i = 0; i < numbPlayers; i++)
	{
		int temp = winners[i];
		cout << i+1 << ". ";
		playPtr[temp].display_name();
		cout << endl;
	}
	cout << "CONGRATULATIONS ";
	int temp = winners[0];
	playPtr[temp].display_name();
	cout << "!!!  \nYou have won and therefore earned yourself the title:\n"
		<< "'Champion of THE GAME'\n";

	delete [] playPtr;
	delete [] winners;

	system("PAUSE");
	return EXIT_SUCCESS;
}
