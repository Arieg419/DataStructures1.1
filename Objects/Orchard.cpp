/*
 * Orchard.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Orchard.h"
#include "../Exceptions/OrchardExceptions.h"
#include "../Exceptions/AVLExceptions.h"
#include "../Objects/Plant.h"

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
	if (DoesExist(i, j)) {
		throw PlantAlreadyExist();
	} else {
		PairID key;
		key.msi = i;
		key.lsi = j;
		Plants.Insert(key, plant);
	}
}

void Orchard::AddFruit(int i, int j, Fruit* fruit) {
	if (!fruit) {
		throw InvalidInput();
	}
	if (!legalInput(i, j)) {
		throw InvalidInput();
	}
	//we need to add to both DS's
	if (!DoesExist(i, j))
		throw PlantDoesNotExist();
	if (DoesExist(fruit->getID()))
		throw FruitAlreadyExist();

	fruit->setLocation(PairID(i, j));
	Plant* temp = GetPlant(i, j);
	temp->AddFruit(fruit);
	Fruits.Insert(fruit->getID(), fruit);
}

Plant* Orchard::GetPlant(int i, int j) {
	if (!legalInput(i, j)) {
		throw InvalidInput();
	}
	if (!DoesExist(i, j)) {
		throw PlantDoesNotExist();
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
	if (!legalInput(i, j)) {
		throw InvalidInput();
	}
	return GetPlant(i, j)->GetBestFruit();
//TODO
}

void* Orchard::GetAllFruitsByRate(int i, int j, int **fruits,
		int *numOfFruits) {
	return GetPlant(i, j)->GetAllFruitsByRate();
}

void Orchard::AttackedBy(Insect insect) {
	//take care of this last
	Plant** plantsArray = Plants.getSortedArray();

	for (int i = 0; i < Plants.GetSize(); i++)
		plantsArray[i]->attackedBy(insect);

	delete plantsArray;
	return;
}

//TODO this function should return an int(flag), otherwise how will we know if there was a FAILURE
void Orchard::RateFruit(int id, int ripeness) {
	if (id < 0 || ripeness <= 0) {
		throw InvalidInput();
	}
	//we need to add to both DS's
	try {
		Fruit* fruit = GetFruit(id);
		Plant* plant = GetPlant(fruit->getLocation().msi,
				fruit->getLocation().lsi);
		Fruit* copy = new Fruit(*fruit);
		copy->setRipeRate(ripeness);

		plant->RemoveFruit(id);
		plant->AddFruit(copy);

		Fruits.Remove(id);
		Fruits.Insert(id, copy);

	} catch (KeyDoesNotExist& e) {
		throw Failure();
	}
}
/*
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
 }*/

void Orchard::RemoveFruit(int fruitID) {
	if (!legalFruitID(fruitID)) {
		throw InvalidInput();
	}
	//we need to remove from both DS's
	try {
		Fruit* fruit = GetFruit(fruitID);
		Plant* plant = GetPlant(fruit->getLocation().msi,
				fruit->getLocation().lsi);

		plant->RemoveFruit(fruitID); // deleting the fruit
		Fruits.Remove(fruitID);
		//delete fruit;
	} catch (KeyDoesNotExist& e) {
		throw Failure();
	}
}

bool Orchard::legalInput(int i, int j) {
	int fieldSize = getMaxSize();
	if (i < 0 || j < 0 || i >= fieldSize || j >= fieldSize) {
		return false;
	}
	return true;
}

bool Orchard::legalFruitID(int fruitID) {
	if (fruitID <= 0) {
		return false;
		//we should throw some type of error or flag here.
	}
	return true;
}

bool Orchard::DoesExist(int i, int j) {
	return Plants.DoesExist(PairID(i, j));
}

bool Orchard::DoesExist(int fruitID) {
	return Fruits.DoesExist(fruitID);
}
