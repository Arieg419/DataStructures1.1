/*
 * Insect.cpp
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#include "Insect.h"

Insect::Insect(int rottenBase, int rottenFactor) {
	this->rottenBase = rottenBase;
	this->rottenFactor = rottenFactor;
}

Insect::~Insect() { }

void Insect::attack(Fruit* fruit){
	if (!fruit) return;
	if (fruit->getID() % rottenBase == 0)
		fruit->setRipeRate(fruit->getRipeRate()*rottenFactor);
}
