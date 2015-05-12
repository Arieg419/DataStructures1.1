/*
 * Fruit.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Fruit.h"
#include "../Exceptions/OrchardExceptions.h"


Fruit::Fruit(int fruidID, int ripeRate) {
	//if (fruidID<=0 || ripeRate<=0) throw InvalidInput;
	this->id = fruidID;
	this->ripeRate = ripeRate;
}

Fruit::~Fruit() {

}

int Fruit::getID() {
	return this->id;
}

int Fruit::getRipeRate() {
	return this->ripeRate;
}

void Fruit::setRipeRate(int ripeRate) {
	this->ripeRate = ripeRate;
}
