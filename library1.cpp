/*
 * library1.cpp
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#include "library1.h"
#include "Objects/Orchard.h"
#include "Statistics.h"

void* Init(int N){
	if (N<=0)
		return NULL;
	Statistics * DS = new Statistics(N);
	return (void*)DS;
}

StatusType PlantTree(void *DS, int i, int j){
	if (!DS) return INVALID_INPUT;
	return ((Statistics*)DS)->PlantTree(i,j);
}

StatusType AddFruit(void *DS, int i, int j, int fruitID, int ripeRate){
	if (!DS) return INVALID_INPUT;
	return ((Statistics*)DS)->AddFruit(i,j,fruitID,ripeRate);
}

StatusType PickFruit(void *DS, int fruitID){
	if (!DS) return INVALID_INPUT;
	return ((Statistics*)DS)->PickFruit(fruitID);
}

StatusType RateFruit(void *DS, int fruitID, int ripeRate){
	if (!DS) return INVALID_INPUT;
	return ((Statistics*)DS)->RateFruit(fruitID,ripeRate);
}

StatusType GetBestFruit(void *DS, int i, int j, int *fruitID){
	if (!DS) return INVALID_INPUT;
	return ((Statistics*)DS)->GetBestFruit(i,j,fruitID);
}

StatusType GetAllFruitsByRate(void *DS, int i, int j, int **fruits, int *numOfFruits){
	if (!DS) return INVALID_INPUT;
	return ((Statistics*)DS)->GetAllFruitsByRate(i,j,fruits,numOfFruits);
}

StatusType UpdateRottenFruits(void *DS, int rottenBase, int rottenFactor){
	if (!DS) return INVALID_INPUT;
	return ((Statistics*)DS)->UpdateRottenFruits(rottenBase,rottenFactor);
	return SUCCESS;
}

void Quit(void** DS){
	delete ((Statistics*)*DS);
}
