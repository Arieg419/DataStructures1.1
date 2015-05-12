/*
 * Plant.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Plant.h"
#include "../Exceptions/OrchardExceptions.h"
#include "../Exceptions/AVLExceptions.h"

Plant::Plant() {
	// TODO Auto-generated constructor stub
}

Plant::~Plant() {
	// releasing the memory of the fruits.
	Fruit** fruits = idSortedTree.getSortedArray(); // O(k)
	int length = idSortedTree.GetSize();

	for (int i = 0; i<length; i++)
		free(fruits[i]);

	// automatically call the AVLTrees DTOR, which release the pointers.
}

void Plant::AddFruit(Fruit* fruit) {
	if (!GetFruit(fruit->getID()))
		throw Failure();
	idSortedTree.Insert(fruit->getID(), fruit);
	PairID pid(fruit->getRipeRate(), fruit->getID());
	rateSortedTree.Insert(pid, fruit);
}

Fruit* Plant::GetFruit(int id) {
	try {
		return idSortedTree.getByKey(id);
	} catch (KeyDoesNotExist& err) {
		return NULL;
	}
}

void Plant::RemoveFruit(int id) {
	try {
		Fruit* fruit = idSortedTree.getByKey(id);
		idSortedTree.Remove(id);
		rateSortedTree.Remove(PairID(fruit->getRipeRate(), id));
		delete (fruit);
	} catch (KeyDoesNotExist& err) {
		// ignore, cause nothing to remove
	}
}

Fruit* Plant::GetBestFruit() {
	try {
		return rateSortedTree.getSmallest();
	} catch (KeyDoesNotExist& err) {
		return NULL;
	}
}

// Returns array of Pointers to Fruits
Fruit** Plant::GetAllFruitsByRate() {
	return rateSortedTree.getSortedArray();
}

void Plant::attackedBy(const Insect& insect){
	int length = this->rateSortedTree.GetSize();
	Fruit** fruits = this->rateSortedTree.getSortedArray();
	this->rateSortedTree.Reset();
	Fruit** updatedFruits = new Fruit*[length]; // temporary array
	// TODO: fill updated fruits using 2 pointers of fruits, and update fruits.
	free(fruits);
	// TODO: create rateSortedTree
}
