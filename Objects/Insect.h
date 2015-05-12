/*
 * Insect.h
 *
 *  Created on: May 11, 2015
 *      Author: dor
 */

#ifndef OBJECTS_INSECT_H_
#define OBJECTS_INSECT_H_

#include "Fruit.h"

class Insect {
private:
	int rottenBase;
	int rottenFactor;
public:
	Insect(int rottenBase, int rottenFactor);
	virtual ~Insect();
	bool ShouldAttack(Fruit* fruit);
	void Attack(Fruit* fruit);
};

#endif /* OBJECTS_INSECT_H_ */
