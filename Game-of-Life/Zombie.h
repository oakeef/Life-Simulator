#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Organism.h"

class Zombie : public Organism
{
public:
	Zombie();
	Zombie( City *city, int x, int y );
	~Zombie();

	void move();
	bool spawn();

private:
	int hasEaten;
	int zombieMoves[8][2] = { {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1} };
	void backToLife();
};

#endif
