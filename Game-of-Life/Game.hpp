#ifndef  GAME_H
#define GAME_H

class City;

class Game {

public:
	Game();
	void run();
	void print();

private:
	City* city;

};

#endif // ! DISPLAY_H
