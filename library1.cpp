/*
 * library1.cpp
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#include "library1.h"
#include "Objects/Orchard.h"

void* Init(int N){
	return new Orchard();
}

StatusType PlantTree(void *DS, int i, int j){

	return SUCCESS;
}

StatusType AddFruit(void *DS, int i, int j, int fruitID, int ripeRate){
	return SUCCESS;
}

StatusType PickFruit(void *DS, int fruitID){
	return SUCCESS;
}

StatusType RateFruit(void *DS, int fruitID, int ripeRate){
	return SUCCESS;
}

StatusType GetBestFruit(void *DS, int i, int j, int *fruitID){
	return SUCCESS;
}

StatusType GetAllFruitsByRate(void *DS, int i, int j, int **fruits, int *numOfFruits){
	return SUCCESS;
}

StatusType UpdateRottenFruits(void *DS, int rottenBase, int rottenFactor){
	return SUCCESS;
}
