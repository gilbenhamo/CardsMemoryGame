#include "Card.h"
#ifndef PILE
#define PILE

class Pile
{
private:
	Card *pack;
	int Psize;
public:
	Pile() :pack(NULL), Psize(0) {};
	Pile(int);
	~Pile();
	Card& ReturnIndex(int)const;
	void Print()const;
	void FillPack();
	void Shuffle();
	void TurnDown();
	void Flip(int);
	int getSize()const { return Psize; }
};
#endif // !PILE
