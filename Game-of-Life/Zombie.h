#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Organism.h"

class Zombie : public Organism
{
public:
	int hasEaten;
	int daysUntilStarve;

	Zombie();
	Zombie( City *city, int x, int y );
	~Zombie();

	void move();
	bool spawn();
	void backToLife();

private:
	int zombieMoves[8][2] = { {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1} };
	int shuffledZombieMoves[8][2] = { { -1,-1 },{ 0,-1 },{ 1,-1 },{ -1,0 },{ 1,0 },{ -1,1 },{ 0,1 },{ 1,1 } };
	
};

#endif
