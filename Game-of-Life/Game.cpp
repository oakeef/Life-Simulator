#include "Game.hpp";
#include "GameSpecs.hpp";
#include "City.h";
#include "Zombie.h"
#include "Human.h"

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <string>

Game::Game() {
	city = new City(GRIDSIZE, GRIDSIZE);

}

//runs the game
void Game::run() {
	std::chrono::milliseconds interval(PAUSE_MILLISECONDS);

	int humans;
	int zombies;
	int iterations;
	
	for(int i=0;i<ITERATIONS;i++){
		iterations = i;
		humans = countHumans();
		zombies = countZombies();
		system("cls");

		if (extinctionEvent(humans, zombies)) {
			std::cout << "------------ZOMBIES VS HUMANS------------" << std::endl;
			std::cout << std::endl;
			print();
			std::cout << std::endl;
			std::cout << "There was an extinction event :(" << std::endl;
			std::cout << "Iterations: " << i + 1 << std::endl;
			std::cout << "Humans: " << humans << std::endl;
			std::cout << "Zombies: " << zombies << std::endl;
			break;
		}
		
		moveOrganisms();
		spawnOrganisms();
		resetMoves();
		
		std::cout << "------------ZOMBIES VS HUMANS------------" << std::endl;
		std::cout << std::endl;
		print();
		std::cout << std::endl;
		std::cout << "Iterations: " << i+1 << std::endl;
		std::cout << "Humans: " << humans << std::endl;
		std::cout << "Zombies: " << zombies << std::endl;
		std::this_thread::sleep_for(interval);
	}
}
//prints out the game board
void Game::print() {

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int row = 0; row < GRIDSIZE; row++) {

		//cout a | char to greate one side of grid
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << "|";

		for (int col = 0; col < GRIDSIZE; col++) {

			//checks if each "space" in the grid is a Zombie or Human
			//Create Orangism pointer called space that gets the Organism at the current x,y location
			Organism* space = city->getOrganism(col, row);

			//iff the space is not null do this stuff
			if (space) {

				//if the space can be cast to a Zombie then print out the Zombie Char
				if (dynamic_cast<Zombie*>(space)) {
					SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << ZOMBIE_CH;
				}//end if

				//else if the space can be cast as a Human then print out the Human Char
				else if (dynamic_cast<Human*>(space)) {
					SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					std::cout << HUMAN_CH;
				}//end else if
				
				//in the weird circumstance where it isn't either than it becomes MISSINGNO
				else {
					std::cout << "?";
				}//end else

			}//end if

			//if the space is a null space then the Space Char is printed out
			else {
				SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				std::cout << SPACE_CH;
			}//end else

			//and finally another | to finish off the grid
			SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			std::cout << "|";

		}//end for

		//endline
		std::cout << std::endl;
	}
}

//checks for extinction event
bool Game::extinctionEvent(int humans, int zombies) {
	if (humans == 0 && zombies == 0) {
		return true;
	}
	else if (humans == 0 || zombies == 0) {
		return true;
	}
	return false;
}

//counts humans on board
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

//counts zombies on board
int Game::countZombies() {
	int zombies = 0;
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {
			if (dynamic_cast<Zombie*>(city->getOrganism(col, row))) {
				zombies += 1;
			}//end if
		}//end for
	}//end for
	return zombies;
}

//resets moves of organisms
void Game::resetMoves() {
	//loop through city grid
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {

			//check if the organism in not null
			if (city->getOrganism(col, row)) {
				//if it is not null then reset it's hasMoved to false
				city->getOrganism(col, row)->hasMoved = false;
			}//end if
		}//end for
	}//end for
}

//moves organisms
void Game::moveOrganisms() {

	//loop through city grid
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {

			//check if the organism is not null
			if (city->getOrganism(col, row)) {
				//check if the organism has moved
				if (!city->getOrganism(col, row)->hasMoved) {
					//if it hasn't moved than make it move
					city->getOrganism(col, row)->move();
				}//end if
			}//end if
		}//end for
	}//end for
}

//spawns organisms
void Game::spawnOrganisms() {

	//loop through city grid
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {

			//create a variable that stores the current Organism*
			Organism* currentOrg = city->getOrganism(col, row);

			//check if the organism is not null
			if (currentOrg) {
				//check if it is Human
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