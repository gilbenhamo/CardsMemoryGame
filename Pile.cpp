#include "Pile.h"
#include <time.h>

Pile::Pile(int size):Psize(size) // parametric ctor
{
	if (Psize < 4 || Psize > 52)  // the lowest option for memory game is 4, at least two pairs
		Psize = 20;
	if (Psize % 2 == 1) // check if the size is odd number
		Psize--;

	pack = new Card[Psize];
	FillPack();
	Shuffle();
}

Pile::~Pile()
{
	delete[] pack;
} // release allocate memory

Card& Pile::ReturnIndex(int index)const // return card obj by index
{
	if (index<0 || index>=Psize) // array borders
	{
		cout << "Invalid index! Game over";
		exit(1);
	}
	return pack[index];
}

void Pile::Print()const
{
	int row = 1;
	cout << "\t   1\t   2\t   3\t   4\t   5\n" << row++ << '\t';
	for (int i = 0; i < Psize; i++)
	{
		pack[i].Print();
		if ((i + 1) % 5 == 0 && i!=Psize-1) // print it like a table
		{
			cout << endl << row++ << '\t';
		}
	}
	cout << endl;

} //print the pile

void Pile::FillPack() // fill pile with Letters A-Z
{
	char tav = 'A';
	for (int i = 0; i < Psize; i += 2) // make pairs of each letter
	{
		pack[i].ChangeTav(tav);
		pack[i + 1].ChangeTav(tav);
		tav++;
	}
}

void Pile::Shuffle()
{
	int index;
	Card temp;
	for (int i = 0; i < Psize; i++)   // for for Shuffle the pile by random indexes
	{
		index = (rand() % (Psize - 1)) + 0;
		temp = pack[i];
		pack[i] = ReturnIndex(index);
		pack[index] = temp;
	}
	system("cls");
	cout << "Get ready you have 30 seconds to memorize :\n"; // 30 sec delay to allow the player to memorize cards
	Print();
	int sec=30; 
	clock_t start_time = clock(); 
	clock_t end_time = sec * 1000 + start_time; 
	while (clock() != end_time);
	system("cls");
	TurnDown(); //flip down all cards !
	
}

void Pile::Flip(int index)
{
	pack[index].ChangeState(); // flip card by index
}

void Pile::TurnDown()
{
	for (int i = 0; i < Psize; i++) //  Turn down all cards in pile.(change the state to 0)
		 pack[i].TurnDown();
}

