#include "Zombie.h"
#include "City.h"
#include "Human.h"
#include "GameSpecs.hpp"
#include <algorithm>
#include <ctime>

Zombie::Zombie(City* city, int x, int y) 
:Organism(city, x, y){
	daysUntilStarve = ZOMBIE_STARVE;
}
Zombie::~Zombie() {

}

void Zombie::move() {

	daysUntilStarve -= 1;

	if (daysUntilStarve <= 0) {
		backToLife();
	}
	else {

		//shuffle moves array
		srand(time(NULL));
		std::random_shuffle(std::begin(shuffledZombieMoves), std::end(shuffledZombieMoves));

		for (int i = 0; i < (sizeof(shuffledZombieMoves) / sizeof(shuffledZombieMoves[0])); i++) {
			int newX = _x + shuffledZombieMoves[i][0];
			int newY = _y + shuffledZombieMoves[i][1];
			if (_city->inBounds(newX, newY)) {
				if (dynamic_cast<Human*>(_city->getOrganism(newX, newY))) {

					_city->setOrganism(nullptr, _x, _y); //previous position is now NULL

					_x = newX;
					_y = newY;

					delete _city->getOrganism(newX, newY);

					_city->setOrganism(this, _x, _y);
					hasMoved = true;
					moveCount += 1;
					daysUntilStarve = ZOMBIE_STARVE;
					break;

				}//end if
			}//end if
		}//end for
		if (!hasMoved) {
			Organism::move();
		}
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

	Organism* human = new Human(_city, _x, _y);
	_city->setOrganism(human, _x, _y);
	
	

}