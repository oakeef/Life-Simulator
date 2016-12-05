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


private:
	int _width;
	int _height;
	Organism** grid;
};

#endif

