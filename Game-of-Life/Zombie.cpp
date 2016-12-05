#include "Zombie.h"

Zombie::Zombie(City* city, int x, int y) 
:Organism(city, x, y){}
Zombie::~Zombie() {

}

void Zombie::move() {}
void Zombie::spawn() {}