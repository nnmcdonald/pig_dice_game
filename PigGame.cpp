//This program runs a game of pig between a human player and the computer.
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int playerScore = 0;
int compScore = 0;
int playerTotal = 0;
int compTotal = 0;
int diceRoll;
char rollAgain;

int main()
{
	srand(time(NULL));
	//checks to see if either player has enough points to win and continues the game if not.
	while (playerTotal < 100 && compTotal < 100)
	{
		diceRoll = 0;
		//runs the players turn
		while (diceRoll != 1)
		{
			cout << "Your score is: " << playerTotal << endl;
			cout << "Computer Score: " << compTotal << endl;
			diceRoll = rand() % 6 + 1;
			if (diceRoll == 1)
			{
				cout << "You rolled a 1, end of turn, no points awarded." << endl;
				cout << "Computer's turn..." << endl;
				playerScore = 0;
			}
			else
			{
				playerScore = playerScore + diceRoll;
				cout << "You rolled a " << diceRoll << ". You've earned " << playerScore << " points." << endl;
				cout << "Would you like to roll again? enter r to roll again or h to hold. Or enter q to quit." << endl;
				cin >> rollAgain;
				if (rollAgain == 'h')
				{
					playerTotal = playerTotal + playerScore;
					playerScore = 0;
					diceRoll = 1;
				}
				else if (rollAgain == 'q')
					return 0;
			}
		}
		diceRoll = 0;
		//runs the computers turn
		while (diceRoll != 1 && playerTotal < 100)
		{
			diceRoll = rand() % 6 + 1;
			if (diceRoll == 1)
				compScore = 0;
			else
			{
				compScore = compScore + diceRoll;
				//ends the computer's turn if its score is 20 or greater
				if (compScore > 19)
				{
					compTotal = compTotal + compScore;
					compScore = 0;
					diceRoll = 1;
				}
			}
		}
	}
	//Checks for a player win or player loss
	if (playerTotal >= 100)
	{
		cout << "You win!" << endl;
		cout << "Your score is: " << playerTotal << endl;
		cout << "Computer score: " << compTotal << endl;
	}
	else if (compTotal >= 100)
	{
		cout << "You lost" << endl;
		cout << "Your score is: " << playerTotal << endl;
		cout << "Computer score: " << compTotal << endl;
	}
	system("pause");
	return 0;
}

