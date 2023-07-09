#include "Game.h"

Game::Game(int num):Pairs(0),Pack(num)  // Ctor, parametric and defalut
{
	
}

int Game::Choose() // private function to let the player choose row and col each time
{
	int row, col;
	bool STflag;
	do
	{
		STflag = false;
		cout << "Row: ";
		cin >> row;
		if (row <=0 || row >((Pack.getSize() / 5)+1)) // check the row borders and exit if the player cross them
		{
			cout << "Invalid row!! Game ended!";
			exit(1);
		}
		cout << "Col: ";
		cin >> col;
		if (col <= 0 || col>5)  // check the col borders and exit if the player cross them
		{
			cout << "Invalid col!! Game ended!";
			exit(1);
		}
		if ((5 * row - (5 - col + 1)) >= Pack.getSize()) // check that the input index is not bigger than the pile size
		{
			cout << "Invalid Index! Game over";
			exit(1);
		}
		if (Pack.ReturnIndex(5 * row - (5 - col + 1)).getState() == true) //cehck the state of the card to determine if he is shown or not, to not flip it down again
		{
			cout << "You enterd index of already shown card, try again!\n";
			STflag = true;
		}
	} while (STflag == true);
	Pack.Flip(5 * row - (5 - col + 1)); // find the slot by row and col, and flip the card
	Pack.Print();
	return (5 * row - (5 - col + 1)); // the formula represent the index location in array
}

void Game::Run()
{
	int one, two;
	bool option; // for checking if the player still want to play
	do 
	{
		system("cls");
		cout << "Memory game:\n";
		Pack.Print();
		cout << "Enter the first card by entering row and col numbers:\n";
		one = Choose();
		cout << "Enter the second card by entering row and col numbers:\n";
		two = Choose();
		if (Pack.ReturnIndex(one).getTav() == Pack.ReturnIndex(two).getTav()) // cmp the char sign in each card
		{
			Pairs++; // if match inc the pairs counter
			if (Pairs == Pack.getSize() / 2) //check if the player revealse all cards
			{
				cout << "Game over, YOU WON!!! Congratiolations\n";
				exit(1);
			}
			cout << "Match!!! do yo want to continue ? 1-yes, 0-no\n";
			cin >> option;
		}
		else
		{
			Pack.Flip(one);  // if the player was wrong turn down the cards
			Pack.Flip(two);
			cout << "No match, do yo want to continue ? 1-yes, 0-no\n";
			cin >> option;
		}

	} while (option == true);
	cout << "Game over, Better luck next time ;) !\n"; //the player chose to exit the game before finish. suitable messege
}