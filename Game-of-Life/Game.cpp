#include "Game.hpp";
#include "GameSpecs.hpp";
#include "City.h";
#include <iostream>
#include "Zombie.h"
#include "Human.h"

Game::Game() {
	city = new City(GRIDSIZE, GRIDSIZE);

}

void Game::run() {

	int humans = 1;
	

	for(int i=0;i<10;i++){
		humans = countHumans();
		moveOrganisms();
		spawnOrganisms();
		resetMoves();
		std::cout << humans << std::endl;
	}
		print();

}

void Game::print() {

	for (int row = 0; row < GRIDSIZE; row++) {

		//cout a | char to greate one side of grid
		std::cout << "|";

		for (int col = 0; col < GRIDSIZE; col++) {

			//checks if each "space" in the grid is a Zombie or Human
			//Create Orangism pointer called space that gets the Organism at the current x,y location
			Organism* space = city->getOrganism(col, row);

			//iff the space is not null do this stuff
			if (space) {

				//if the space can be cast to a Zombie then print out the Zombie Char
				if (dynamic_cast<Zombie*>(space)) {
					std::cout << ZOMBIE_CH;
				}//end if

				//else if the space can be cast as a Human then print out the Human Char
				else if (dynamic_cast<Human*>(space)) {
					std::cout << HUMAN_CH;
				}//end else if
				
				//in the weird circumstance where it isn't either than it becomes MISSINGNO
				else {
					std::cout << "?";
				}//end else

			}//end if

			//if the space is a null space then the Space Char is printed out
			else {
				std::cout << SPACE_CH;
			}//end else

			//and finally another | to finish off the grid
			std::cout << "|";

		}//end for

		//endline
		std::cout << std::endl;
	}
}

int Game::countHumans() {
	int humans = 0;
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {
			if (dynamic_cast<Human*>(city->getOrganism(col, row))) {
				humans += 1;
			}//end if
		}//end for
	}//end for
	return humans;
}

void Game::resetMoves() {
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {
			if (city->getOrganism(col, row)) {
				city->getOrganism(col, row)->hasMoved = false;
			}//end if
		}//end for
	}//end for
}

void Game::moveOrganisms() {
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {
			if (city->getOrganism(col, row)) {
				if (!city->getOrganism(col, row)->hasMoved) {
					city->getOrganism(col, row)->move();
					
				}//end if
			}//end if
		}//end for
	}//end for
}

void Game::spawnOrganisms() {
	//loop through city grid
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {
			//create a variable that stores the current Organism*
			Organism* currentOrg = city->getOrganism(col, row);
			//if the organism is not null
			if (currentOrg) {
				//if it is Human
				if (dynamic_cast<Human*>(currentOrg)) {
					//if it is Human and it's move count is 3
					if (currentOrg->moveCount == 3) {
						//run the spawn()
						currentOrg->spawn();
						//reset moveCount to 0;
						currentOrg->moveCount = 0;
					}//end if
				}//end if
				//else if it is a Zombie
				else if (dynamic_cast<Zombie*>(currentOrg)) {
					//and the Zombie moveCount is 8
					if (currentOrg->moveCount == 8) {
						//Zombie spawn()
						if (currentOrg->spawn()) {
							currentOrg->moveCount = 0;
						}//end if
					}//end if
				}//end if
			}//end if
		}//end for
	}//end for
}