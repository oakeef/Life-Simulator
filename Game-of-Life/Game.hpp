#ifndef  GAME_H
#define GAME_H

class City;

class Game {

public:
	Game();
	void run();
	void print();
	int countHumans();
	int countZombies();
	void resetMoves();
	void moveOrganisms();
	void spawnOrganisms();
	bool extinctionEvent(int human, int zombies);

private:
	City* city;

};

#endif // ! DISPLAY_H
