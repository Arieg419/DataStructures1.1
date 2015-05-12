/*
 * Plant.h
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#ifndef PLANT_H_
#define PLANT_H_

#include "../DataStructures/AVLTree.h"
#include "../DataStructures/PairID.h"
#include "Fruit.h"
#include "Insect.h"

class Plant {
private:
	AVLTree<int, Fruit*> idSortedTree;
	AVLTree<PairID, Fruit*> rateSortedTree; // Paird: msb=rate, lsb=id


public:
	Plant();
	virtual ~Plant();
	void AddFruit(Fruit* fruit);
	Fruit* GetFruit(int id);
	void RemoveFruit(int id);
	Fruit* GetBestFruit();
	Fruit** GetAllFruitsByRate(); // Array of Pointers to Fruits
	void attackedBy(const Insect& insect);
};

#endif /* PLANT_H_ */