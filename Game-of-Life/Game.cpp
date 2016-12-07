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
	print();


	//one turn
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {
			city->getOrganism(row, col)->move();
		}
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
			Organism* space = city->getOrganism(row, col);

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