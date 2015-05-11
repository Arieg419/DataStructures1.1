/*
 * Orchard.h
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#ifndef ORCHARD_H_
#define ORCHARD_H_

#include "../DataStructures/AVLTree.h"
#include "Plant.h"

class Orchard {
private:
	AVLTree<PairID, Plant*> Plants;
public:
	Orchard();
	virtual ~Orchard();
	void AddPlant(Plant* plant);
	Plant* GetPlant(int i, int j);
	Plant* RemovePlant(int i, int j);
};

#endif /* ORCHARD_H_ */
