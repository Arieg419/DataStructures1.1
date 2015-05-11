/*
 * Orchard.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Orchard.h"

Orchard::Orchard() {
	maxSize = 0;
}

Orchard::~Orchard() {
	// TODO Auto-generated destructor stub
}

void Orchard::setMaxSize(int N) {
	if (N >= 0)
		maxSize = N;
}

void Orchard::AddPlant(int i, int j, Plant* plant) {

}

void Orchard::AddFruit(int i, int j, Fruit* fruit){

}

Plant* Orchard::GetPlant(int i, int j) {
	return NULL;
}
Plant* Orchard::GetFruit(int fruitID) {
	return NULL;
}

void Orchard::RemovePlant(int i, int j){

}
void Orchard::RemoveFruit(int fruitID){

}
