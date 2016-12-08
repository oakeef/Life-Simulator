#include "Organism.h"
#include "City.h"

Organism::Organism(City* city, int x, int y) {
	_city = city;
	_x = x;
	_y = y;
}

Organism::~Organism() {

}

void Organism::move() {

	for (int i = 0; i < (sizeof(moves)/sizeof(moves[0])); i++) {
		int newX = _x + moves[i][0];
		int newY = _y + moves[i][1];
		if (_city->inBounds(newX, newY)) {
			if (_city->getOrganism(newX, newY) == nullptr) {

				_city->setOrganism(nullptr, _x, _y); //previous position is now NULL

				_x = newX;
				_y = newY;

				_city->setOrganism(this, _x, _y);
				hasMoved = true;
				moveCount += 1;
				break;
			}//end if
		}//end if
		
	}//end for

}