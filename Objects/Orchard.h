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
	int maxSize;
	AVLTree<PairID, Plant*> Plants;
	AVLTree<int, Fruit*> Fruits;
public:
	Orchard();
	virtual ~Orchard();
	void setMaxSize(int N);

	void AddPlant(int i, int j, Plant* plant);
	void AddFruit(int i, int j, Fruit* fruit);

	Plant* GetPlant(int i, int j);
	Plant* GetFruit(int fruitID);

	void RemovePlant(int i, int j);
	void RemoveFruit(int fruitID);
};

#endif /* ORCHARD_H_ */
