/*
 * Fruit.h
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#ifndef FRUIT_H_
#define FRUIT_H_

#include "../DataStructures/PairID.h"

class Fruit {
private:
	int id;
	int ripeRate;
	int i,j;
	// more optional fields
public:
	Fruit(int fruitID,int ripeRate=1);
	int getID();
	int getRipeRate();
	void setRipeRate(int ripeRate);
	PairID getPairID();

	virtual ~Fruit();
};

#endif /* FRUIT_H_ */

