/*
 * Fruit.h
 *
 *  Created on: May 4, 2015
 *      Author: dor
 */

#ifndef FRUIT_H_
#define FRUIT_H_

class Fruit {
private:
	int id;
	int ripeRate;
	// more optional fields
public:
	Fruit(int fruitID);
	Fruit(int fruitID,int ripeRate);
	int getID();
	int getRipeRate();
	void setRipeRate(int ripeRate);
	virtual ~Fruit();
};

#endif /* FRUIT_H_ */

