#ifndef HUMAN_H
#define HUMAN_H

#include "Organism.h"

class Human : public Organism
{
public:
	Human( City *city, int x, int y );
	~Human();

	bool spawn();
};

#endif
