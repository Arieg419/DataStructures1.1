/*
 * Fruit.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Fruit.h"

Fruit::Fruit(int fruidID) {
	this->id = fruidID;
	this->ripeRate = 0;
}

Fruit::Fruit(int fruidID, int ripeRate) {
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
