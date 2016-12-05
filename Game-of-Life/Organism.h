#ifndef ORGANISM_H
#define ORGANISM_H

class City;

class Organism
{
protected:
	int _x;
	int _y;
	City* _city;

	enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
	Organism( City* city, int x, int y);
	virtual ~Organism();

	virtual void move() = 0;
	virtual void spawn() = 0;

};

#endif
