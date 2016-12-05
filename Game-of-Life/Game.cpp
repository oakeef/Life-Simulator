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

}

void Game::print() {
	for (int row = 0; row < GRIDSIZE; row++) {
		std::cout << "|";
		for (int col = 0; col < GRIDSIZE; col++) {
			Organism* space = city->getOrganism(row, col);
			if (space) {
				if (dynamic_cast<Zombie*>(space)) {
					std::cout << ZOMBIE_CH;
				}
				else if (dynamic_cast<Human*>(space)) {
					std::cout << HUMAN_CH;
				}
				else {
					std::cout << "?";
				}

			}
			else {
				std::cout << SPACE_CH;
			}
			std::cout << "|";
		}
		std::cout << std::endl;
	}
}