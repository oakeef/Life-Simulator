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
	void spawn();

private:
	void backToLife();
};

#endif
