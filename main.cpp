#include "Game.h"

int main()
{
	int Number;
	srand(time(NULL)); //time seed null for random 
	cout << "Enter number of cards you want to play with: ";
	cin >> Number;
	Game m(Number);
	m.Run();

	return false;
}