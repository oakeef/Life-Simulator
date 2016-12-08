#ifndef  GAME_H
#define GAME_H

class City;

class Game {

public:
	Game();
	void run();
	void print();
	int countHumans();
	void resetMoves();
	void moveOrganisms();
	void spawnOrganisms();

private:
	City* city;

};

#endif // ! DISPLAY_H
