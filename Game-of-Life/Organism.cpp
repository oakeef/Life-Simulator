#include "Organism.h"
#include "City.h"
#include <algorithm>
#include <ctime>

Organism::Organism(City* city, int x, int y) {
	_city = city;
	_x = x;
	_y = y;
}

Organism::~Organism() {

}

void Organism::move() {

	//shuffle moves array
	srand(time(NULL));
	std::random_shuffle(std::begin(shuffledMoves), std::end(shuffledMoves));

	for (int i = 0; i < (sizeof(shuffledMoves)/sizeof(shuffledMoves[0])); i++) {
		int newX = _x + shuffledMoves[i][0];
		int newY = _y + shuffledMoves[i][1];
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