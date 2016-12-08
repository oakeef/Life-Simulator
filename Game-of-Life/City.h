#ifndef CITY_H
#define CITY_H

class Organism;

class City {	

public:
	City(int width, int height);
	~City();

	Organism* getOrganism( int x, int y );
	void setOrganism( Organism* organism, int x, int y );

	void day();
	bool inBounds( int x, int y);


private:
	int _width;
	int _height;
	Organism** grid;
};

#endif

