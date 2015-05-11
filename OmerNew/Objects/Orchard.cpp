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

int Orchard::getMaxSize() {
	return maxSize;
}

void Orchard::AddPlant(int i, int j, Plant* plant) {
	if(!legalInput(i,j)) {
			return;
		}
	if(GetPlant(i, j)) {  //checking to see if we have already planted in i, j
		return;
	}
	PairID key;
	key.msi = i;
	key.lsi = j;
	Plants.Insert(i, plant);
	// changed msi lsi to public.
}

void Orchard::AddFruit(int i, int j, Fruit* fruit){ //this func should access specific plant in orchid
	if(!fruit) {
		return;
	}
	if(!legalInput(i,j)) {
			return ;
		}
	//we need to add to both DS's
	Plant* temp = GetPlant(i,j);
	temp->AddFruit(fruit);
	delete temp; //change was recorded because we accessed field with ptr.
}

Plant* Orchard::GetPlant(int i, int j) {
	if(!legalInput(i,j)) {
		return NULL;
	}
	//TODO confused by the code written here. I defined a plant coordinates class. this should be our key i think?
	//PlantCoordinates key;
	//key.xCoordinate = i;
	//key.yCoordinate = j;
	//I dont think that the declaration of Orchirds trees make sense. Id is a two dimensional paramter
	//How is that expressed in the current form.
	//return Plants.getByKey(key);
	PairID key;
	key.msi = i;
	key.lsi = j;
	return Plants.getByKey(key);
}

Fruit* Orchard::GetFruit(int fruitID) {
	if(!legalFruitID(fruitID)) {
		return NULL;
	}
	//goes to second DS sorted by FRUITID's and searches for Fruit ID;
	return Fruits.getByKey(fruitID);
}

Fruit* Orchard::GetBestFruit(int i , int j, int *fruitID) {
	//goes to DS and gets Fruit with lowest ripe rating, min is 1.
	return NULL;
}

void* Orchard::GetAllFruitsByRate(int i, int j,int **fruits, int *numOfFruits) {
 return NULL;
}

void UpdateRottenFruits(int rottenBase, int rottenFactor) {
	//take care of this last
	return;
}

//TODO this function should return an int(flag), otherwise how will we know if there was a FAILURE
void Orchard::RateFruit(int id, int ripeness) {
	if(!legalFruitID(id)) {
			//throw InvalidInput;
			return;
		}

}

void Orchard::RemovePlant(int i, int j){
	if(!legalInput(i,j)) {
		return;
	}
	Plant* temp = GetPlant(i,j);
	if(!temp) {
		return;
	}
	//Plants.RemoveNode(temp);
	//TODO need to decide how to delete and add. Two seperte calls to two diff DS's? Or on call that calls the other.
	delete temp;
}
void Orchard::RemoveFruit(int fruitID){
	if(!legalFruitID(fruitID)) {
			return;
		}
		Fruit* temp = GetFruit(fruitID);
		if(!temp) {
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
	if(fruitID < 0 || fruitID >= fieldSize) {
		return false;
		//we should throw some type of error or flag here.
	}
	return true;
}
