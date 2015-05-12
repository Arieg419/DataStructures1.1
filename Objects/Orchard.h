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
	bool legalInput(int i, int j);
	bool legalFruitID(int fruitID);
public:
	Orchard();
	virtual ~Orchard();
	void setMaxSize(int N);
	int getMaxSize();
	void AddPlant(int i, int j, Plant* plant);
	void AddFruit(int i, int j, Fruit* fruit);
	void RateFruit(int ID, int ripeness);
	Plant* GetPlant(int i, int j);
	Fruit* GetFruit(int fruitID);
	Fruit* GetBestFruit(int i, int j, int *fruitID);
	void* GetAllFruitsByRate(int i, int j, int **fruits, int *numOfFruits);
	void RemovePlant(int i, int j);
	void RemoveFruit(int fruitID);
	void AttackedBy(Insect insect);
	bool DoesExist(int i, int j);
	bool DoesExist(int fruitID);
};

#endif /* ORCHARD_H_ */
