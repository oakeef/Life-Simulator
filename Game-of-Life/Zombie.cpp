#include "Zombie.h"
#include "City.h"
#include "Human.h"

Zombie::Zombie(City* city, int x, int y) 
:Organism(city, x, y){}
Zombie::~Zombie() {

}

void Zombie::move() {

	for (int i = 0; i < (sizeof(zombieMoves) / sizeof(zombieMoves[0])); i++) {
		int newX = _x + zombieMoves[i][0];
		int newY = _y + zombieMoves[i][1];
		if (_city->inBounds(newX, newY)) {
			if (dynamic_cast<Human*>(_city->getOrganism(newX, newY))) {

				_city->setOrganism(nullptr, _x, _y); //previous position is now NULL

				_x = newX;
				_y = newY;

				delete _city->getOrganism(newX, newY);

				_city->setOrganism(this, _x, _y);
				hasMoved = true;
				break;	

			}//end if
		}//end if
	}//end for
	if (!hasMoved) {
		Organism::move();
	}
}
bool Zombie::spawn() {

	for (int i = 0; i < (sizeof(zombieMoves) / sizeof(zombieMoves[0])); i++) {
		int newX = _x + zombieMoves[i][0];
		int newY = _y + zombieMoves[i][1];
		if (_city->inBounds(newX, newY)) {
			if (dynamic_cast<Human*>(_city->getOrganism(newX, newY))) {

				Organism* org = new Zombie(_city, newX, newY);

				delete _city->getOrganism(newX, newY);

				_city->setOrganism(org, newX, newY);
				return true;

			}//end if
		}//end if
	}//end for
	return false;
}

void Zombie::backToLife() {

	Organism* org = new Human(_city, _x, _y);

	delete _city->getOrganism(_x, _y);

	_city->setOrganism(org, _x, _y);

}