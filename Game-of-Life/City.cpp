#include "City.h"
#include "Zombie.h"
#include "Human.h"
#include "GameSpecs.hpp"
#include <stdlib.h>;

City::City(int width, int height) {
	_width = width;
	_height = height;
	int gridLength = width * height;

	grid = new Organism*[gridLength];
	for (int i = 0; i < (gridLength); i++) {
		grid[i] = 0;
	}

	int placedZombies = 0;
	int placedHumans = 0;

	while (placedZombies < ZOMBIE_STARTCOUNT) {
		//create random cooridantes
		int randomX = (rand() % _width);
		int randomY = (rand() % _height);

		//since i'm using a 1d array this finds the relative position from the dual cooridnates
		int position = randomX + (randomY * GRIDSIZE);

		//if the grid at the position is a 0 then add a zombie there
		if (grid[position] == 0) {
			grid[position] = new Zombie(this, randomX, randomY); 
			placedZombies += 1;
		}//end if
		
	}//end while

	while (placedHumans < HUMAN_STARTCOUNT) {
		int randomX = (rand() % _width);
		int randomY = (rand() % _height);
		int position = randomX + (randomY * GRIDSIZE);

		if (grid[position] == 0) {
			grid[position] = new Human(this, randomX, randomY);
			placedHumans += 1;
		}//end if
	}
	
}//end constructor

Organism* City::getOrganism(int x, int y) {
	int position = x + (y * GRIDSIZE);
	return grid[position];
}