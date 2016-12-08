#include "Human.h"
#include "City.h"

Human::Human(City* city, int x, int y) 
:Organism(city, x, y) {}
Human::~Human() {

}

bool Human::spawn() {
	
	for (int i = 0; i < (sizeof(moves) / sizeof(moves[0])); i++) {
		int newX = _x + moves[i][0];
		int newY = _y + moves[i][1];
		if (_city->inBounds(newX, newY)) {
			if (_city->getOrganism(newX, newY) == nullptr) {

				Organism* org = new Human(_city, newX, newY);

				_city->setOrganism(org, newX, newY);
				return true;
				}//end if
			}//end if
		}//end for
	return false;
}