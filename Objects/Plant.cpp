/*
 * Plant.cpp
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#include "../Objects/Plant.h"
#include "../Objects/Insect.h"
#include "../Exceptions/OrchardExceptions.h"
#include "../Exceptions/AVLExceptions.h"

Plant::Plant() {
	// TODO Auto-generated constructor stub
}

Plant::~Plant() {
	// releasing the memory of the fruits.
	Fruit** fruits = idSortedTree.getSortedArray(); // O(k)
	int length = idSortedTree.GetSize();

	for (int i = 0; i < length; i++)
		free(fruits[i]);

	// automatically call the AVLTrees DTOR, which release the pointers.
}

void Plant::AddFruit(Fruit* fruit) {
	if (DoesExist(fruit->getID()))
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
		PairID pid = PairID(fruit->getRipeRate(), id);
		rateSortedTree.Remove(pid);
		delete (fruit);
	} catch (KeyDoesNotExist& err) {
		// ignore, cause nothing to remove
	}
}

Fruit* Plant::GetBestFruit() {
	if (rateSortedTree.GetSize()<1){
		return NULL;
	}
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

int Plant::GetSize() {
	return rateSortedTree.GetSize();
}

bool Plant::DoesExist(int fruitID){
	return idSortedTree.DoesExist(fruitID);
}

void Plant::attackedBy(Insect& insect) {
	//if()
	int length = this->rateSortedTree.GetSize();
	if (length==0) return;
	Fruit** fruits = this->rateSortedTree.getSortedArray();

	// results arrays
	Fruit** updatedFruits = new Fruit*[length];
	PairID* updatedKeys = new PairID[length];

	// fill updated fruits using 2 pointers of fruits, and update fruits.
	int p1 = 0, p2 = 0, p3 = 0; // p1: fruit attack, p2: dont attack, p3: new array
	while (!insect.ShouldAttack(fruits[p1]))
		p1++; // set to first attack
	while (insect.ShouldAttack(fruits[p2]))
		p2++; // set to first safe

	insect.Attack(fruits[p1]);

	// every iteration moving one fruit
	while (p3 < length) {
		bool copyP1;
		if (p1 == length) { // remain only safe fruits
			copyP1 = false; // move p2
		} else if (p2 == length) { // remain only to attack
			copyP1 = true;
		} else {
			if (fruits[p1]->getPairID() < fruits[p2]->getPairID())
				copyP1 = true;
			else
				copyP1 = false;
		}

		// deciding whether to copy p1 or p2
		if (copyP1) {
			updatedFruits[p3++] = fruits[p1++];
			while (p1 < length && !insect.ShouldAttack(fruits[p1])) // calculate next p1
				p1++;
			if (p1 < length)
				insect.Attack(fruits[p1]);
		} else {
			updatedFruits[p3++] = fruits[p2++];
			while (p2 < length && insect.ShouldAttack(fruits[p2])) // calculate next p2
				p2++;
		}
	}

	delete (fruits);
	this->rateSortedTree.Reset();

	// converting array to a tree
	for (int i=0; i<length; i++)
		updatedKeys[i] = updatedFruits[i]->getPairID();

	this->rateSortedTree.LoadSortedArray(updatedKeys,updatedFruits,length);
}
