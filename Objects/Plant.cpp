/*
 * Plant.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Plant.h"
#include "../Exception.h"

Plant::Plant() {
	// TODO Auto-generated constructor stub

}

Plant::~Plant() {
	// TODO Auto-generated destructor stub
}

void Plant::AddFruit(Fruit* fruit) {
	if (!GetFruit(fruit->id)) throw Failure;
	idSortedTree.Insert(fruit->getID(), fruit);
	PairID pid(fruit->getRipeRate(),fruit->getID());
	rateSortedTree.Insert(pid, fruit);
}

Fruit* Plant::GetFruit(int id) {
	return idSortedTree.getByKey(id);
}

Fruit* Plant::RemoveFruit(int id) {
	Fruit* fruit = idSortedTree.getByKey(id);
	idSortedTree.Remove(id);
	rateSortedTree.Remove(PairID(fruit->getRipeRate(),id));
	delete(fruit);
	return NULL;
}

Fruit* Plant::GetBestFruit() {
	return NULL;
}

// Returns array of Pointers to Fruits
Fruit** Plant::GetAllFruitsByRate() {
	return NULL;
}

