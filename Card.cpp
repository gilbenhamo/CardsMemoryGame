#include "Card.h"

Card::Card(bool _state, char _tav):tav(_tav),state(_state)
{} //Ctor, defalut and parametric

void Card::ChangeState() //change card state
{
	state = !state;
}

bool Card::CmpTav(const Card& other)const // cmp if two cards has the same char
{
	if (tav == other.tav)
		return true;
	return false;
}

void Card::Print()const // print card pattern
{
	if (state == false)
		cout << "[  ?  ] ";
	else
		cout << "[  " << tav << "  ] ";
}

void Card::ChangeTav(char T) //change the char in the card by index
{
	tav = T;
}