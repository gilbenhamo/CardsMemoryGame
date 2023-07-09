#ifndef GAME
#define GAME
#include "Pile.h"

class Game
{
private:
	Pile Pack;
	int Pairs;
	int Choose(); //private function
public:
	Game(int = 20);
	void Run();
};

#endif // !GAME
