#ifndef ORGANISM_H
#define ORGANISM_H

class City;

class Organism
{	

protected:
	int _x;
	int _y;
	City* _city;
	int moves[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	

public:
	bool hasMoved;
	int moveCount;
	Organism( City* city, int x, int y);
	virtual ~Organism();

	virtual void move();
	virtual bool spawn() = 0;


};

#endif
