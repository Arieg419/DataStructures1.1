/*
 * Statistics.cpp
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#include "Statistics.h"
#include "Exception.h"
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

//TODO in regard to Fruit Rate. IMPORTANT - 1 is the best fruit rate possible. The higher the worse.

StatusType Statistics::RateFruit(int fruitID, int ripeRate) {
	try {
		orchard.RateFruit(fruitID, ripeRate);
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
			orchard.GetBestFruit(i, j, fruitID);
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
				orchard.GetAllFruitsByRate(i, j, fruits, numOfFruits);
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
	try {
				//orchard.UpdateRottenFruits(rottenBase, rottenFactor);
				//TODO getting undefined ..
				} catch (InvalidInput& e) {
					return INVALID_INPUT;
				} catch (OutOfMemory& e) {
					return ALLOCATION_ERROR;
				} catch (Failure& e) {
					return FAILURE;
				}
	return SUCCESS;
}

/////////// Private Function //////////////

//added a getter function to obtain access to private variable.
bool Statistics::legalInput(int i, int j) {
	int fieldSize = orchard.getMaxSize();
	if (i < 0 || j < 0 || i > fieldSize || j > fieldSize)
		return false;
	return true;
}
