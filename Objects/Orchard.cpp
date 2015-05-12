/*
 * Orchard.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Orchard.h"
#include "../Exceptions/OrchardExceptions.h"
#include "../Exceptions/AVLExceptions.h"

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

int Orchard::getMaxSize() {
	return maxSize;
}

void Orchard::AddPlant(int i, int j, Plant* plant) {
	if (!legalInput(i, j)) {
		throw InvalidInput();
	}
	if (GetPlant(i, j)) {  //checking to see if we have already planted in i, j
		throw InvalidInput();
	}
	PairID key;
	key.msi = i;
	key.lsi = j;
	Plants.Insert(key, plant);
	// changed msi lsi to public.
}

void Orchard::AddFruit(int i, int j, Fruit* fruit) {
	if (!fruit) {
		throw InvalidInput();
	}
	if (!legalInput(i, j)) {
		throw InvalidInput();
	}
	//we need to add to both DS's
	try {
		Fruits.getByKey(fruit->getID());
		Plant* temp = GetPlant(i, j);
		temp->AddFruit(fruit);
		Fruits.Insert(fruit->getID(), fruit);
	} catch (KeyAlreadyExist& e) {
		throw Failure();
	}
}

Plant* Orchard::GetPlant(int i, int j) {
	if (!legalInput(i, j)) {
		throw InvalidInput();
	}
	return Plants.getByKey(PairID(i, j));
}

Fruit* Orchard::GetFruit(int fruitID) {
	if (!legalFruitID(fruitID)) {
		throw InvalidInput();
	}
	//goes to second DS sorted by FRUITID's and searches for Fruit ID;
	return Fruits.getByKey(fruitID);
}

Fruit* Orchard::GetBestFruit(int i, int j, int *fruitID) {
	//goes to DS and gets Fruit with lowest ripe rating, min is 1.
	if (!legalFruitID(*fruitID)) {
		throw InvalidInput();
	}
//TODO
}

void* Orchard::GetAllFruitsByRate(int i, int j, int **fruits,
		int *numOfFruits) {
	return NULL;
}

void UpdateRottenFruits(int rottenBase, int rottenFactor) {
	//take care of this last
	return;
}

//TODO this function should return an int(flag), otherwise how will we know if there was a FAILURE
void Orchard::RateFruit(int id, int ripeness) {
	if (!legalFruitID(id)) {
		//throw InvalidInput;
		return;
	}

}

void Orchard::RemovePlant(int i, int j) {
	if (!legalInput(i, j)) {
		return;
	}
	Plant* temp = GetPlant(i, j);
	if (!temp) {
		return;
	}
	//Plants.RemoveNode(temp);
	//TODO need to decide how to delete and add. Two seperte calls to two diff DS's? Or on call that calls the other.
	delete temp;
}
void Orchard::RemoveFruit(int fruitID) {
	if (!legalFruitID(fruitID)) {
		return;
	}
	Fruit* temp = GetFruit(fruitID);
	if (!temp) {
		return;
	}
	//Fruits.RemoveNode(temp);
	delete temp;
}

bool Orchard::legalInput(int i, int j) {
	int fieldSize = getMaxSize();
	if (i < 0 || j < 0 || i > fieldSize || j > fieldSize) {
		return false;
	}
	return true;
}

bool Orchard::legalFruitID(int fruitID) {
	int fieldSize = getMaxSize();
	if (fruitID < 0 || fruitID >= fieldSize) {
		return false;
		//we should throw some type of error or flag here.
	}
	return true;
}

