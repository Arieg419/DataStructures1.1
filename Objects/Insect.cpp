/*
 * Insect.cpp
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#include "Insect.h"
#include "../Exceptions/OrchardExceptions.h"

Insect::Insect(int rottenBase, int rottenFactor) {
	if (rottenBase<1 || rottenFactor<1)
		throw InvalidInput();
	this->rottenBase = rottenBase;
	this->rottenFactor = rottenFactor;
}

Insect::~Insect() { }

bool Insect::ShouldAttack(Fruit* fruit){
	if (fruit->getID() % rottenBase == 0)
		return true;
	return false;
}

void Insect::Attack(Fruit* fruit){
	if (!fruit) throw InvalidInput();
	if (ShouldAttack(fruit))
		fruit->setRipeRate(fruit->getRipeRate()*rottenFactor);

}
