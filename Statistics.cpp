/*
 * Statistics.cpp
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#include "Statistics.h"
#include "Exceptions/OrchardExceptions.h"
#include "Objects/Fruit.h"
#include "Objects/Plant.h"
#include "Objects/Orchard.h"

Statistics::Statistics(int N) {
	orchard.setMaxSize(N);
}

Statistics::~Statistics() {
	// TODO Auto-generated destructor stub
}

StatusType Statistics::PlantTree(int i, int j) {
	Plant* plant = NULL;
	try {
		plant = new Plant();
		orchard.AddPlant(i, j, plant);
	} catch (InvalidInput& e) {
		delete plant;
		return INVALID_INPUT;
	} catch (OutOfMemory& e) {
		delete plant;
		return ALLOCATION_ERROR;
	} catch (Failure& e) {
		delete plant;
		return FAILURE;
	}
	return SUCCESS;
}

StatusType Statistics::AddFruit(int i, int j, int fruitID, int ripeRate) {
	Fruit* fruit = NULL;
	try {
		fruit = new Fruit(fruitID, ripeRate);
		orchard.AddFruit(i, j, fruit);
	} catch (InvalidInput& e) {
		delete fruit;
		return INVALID_INPUT;
	} catch (OutOfMemory& e) {
		delete fruit;
		return ALLOCATION_ERROR;
	} catch (Failure& e) {
		delete fruit;
		return FAILURE;
	}
	return SUCCESS;
}

StatusType Statistics::PickFruit(int fruitID) {
	try {
		orchard.RemoveFruit(fruitID);
	} catch (InvalidInput& e) {
		return INVALID_INPUT;
	} catch (OutOfMemory& e) {
		return ALLOCATION_ERROR;
	} catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

StatusType Statistics::RateFruit(int fruitID, int ripeRate) {
	try {
		// orchard(fruitID); TODO
	} catch (InvalidInput& e) {
		return INVALID_INPUT;
	} catch (OutOfMemory& e) {
		return ALLOCATION_ERROR;
	} catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

StatusType Statistics::GetBestFruit(int i, int j, int *fruitID) {
	try {
			*fruitID = orchard.GetPlant(i, j)->GetBestFruit()->getID();
		} catch (InvalidInput& e) {
			return INVALID_INPUT;
		} catch (OutOfMemory& e) {
			return ALLOCATION_ERROR;
		} catch (Failure& e) {
			return FAILURE;
		}
	return SUCCESS;
}

StatusType Statistics::GetAllFruitsByRate(int i, int j, int **fruits,
		int *numOfFruits) {
		try {
			*numOfFruits = orchard.GetPlant(i,j)->GetSize();
			int size = *numOfFruits;
			int** data = (int**)malloc(sizeof(int)*(size)); //TODO nasty casting. this should be done automatically
			Fruit** temp = orchard.GetPlant(i, j)->GetAllFruitsByRate();
			for(int i = 0 ; i < *numOfFruits ; i++) {
				//(*fruits)[i] = temp[i]->getID();
				(*data)[i] = temp[i]->getID();
			}
			fruits = data;
			delete temp;
			free(data);

		} catch (InvalidInput& e) {
			return INVALID_INPUT;
		} catch (OutOfMemory& e) {
			return ALLOCATION_ERROR;
		} catch (Failure& e) {
			return FAILURE;
		}
		return SUCCESS;
}

StatusType Statistics::UpdateRottenFruits(int rottenBase, int rottenFactor) {
	return SUCCESS;
}

/////////// Private Function //////////////
