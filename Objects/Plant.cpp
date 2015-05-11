/*
 * Plant.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Plant.h"
#include "../DataStructures/Exceptions.h"

Plant::Plant() {
	// TODO Auto-generated constructor stub

}

Plant::~Plant() {
	// TODO Auto-generated destructor stub
}

void Plant::AddFruit(Fruit* fruit) {
	//if (!fruit) throw NullInputException;
	idSortedTree.Insert(fruit->getID(), fruit);
	rateSortedTree.Insert(PairID(fruit->getRipeRate(),fruit->getID()), fruit);
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
