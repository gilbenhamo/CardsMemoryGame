#define CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef CARD
#define CARD

class Card
{
private:
	char tav;
	bool state;
public:
	Card(bool=1 ,char='?');
	void ChangeState();
	bool CmpTav(const Card& other)const;
	void Print()const;
	void ChangeTav(char);
	char getTav()const { return tav; }
	bool getState()const { return state; }
	void TurnDown() { state = 0; }
};
#endif // !CARD

