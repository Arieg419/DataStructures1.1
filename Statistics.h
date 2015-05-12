/*
 * Statistics.h
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include "Objects/Orchard.h"
#include "library1.h"

class Statistics {
private:
	Orchard orchard;
	bool legalInput(int i, int j);
public:
	Statistics(int N);
	virtual ~Statistics();

	StatusType PlantTree(int i, int j);
	StatusType AddFruit(int i, int j, int fruitID, int ripeRate);
	StatusType PickFruit(int fruitID);
	StatusType RateFruit(int fruitID, int ripeRate);
	StatusType GetBestFruit(int i, int j, int *fruitID);
	StatusType GetAllFruitsByRate(int i, int j, int **fruits, int *numOfFruits);
	StatusType UpdateRottenFruits(int rottenBase, int rottenFactor);
};

#endif /* STATISTICS_H_ */
