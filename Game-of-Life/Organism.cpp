#include "Organism.h"
#include "City.h"

Organism::Organism(City* city, int x, int y) {
	_city = city;
	_x = x;
	_y = y;
}

Organism::~Organism() {

}

void Organism::move() {
	if (_city->getOrganism( (_x + 1) , _y ) == nullptr) {

		
	}
	else if (_city->getOrganism( (_x - 1), _y ) == nullptr) {
	
		
	}
	else if (_city->getOrganism(_x, ( _y + 1 ) ) == nullptr) {
	
		
	}
	else if (_city->getOrganism(_x, ( _y - 1 ) ) == nullptr) {
	
		
	}
}