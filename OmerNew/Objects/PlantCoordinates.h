/*
 * PlantCoordinates.h
 *
 *  Created on: May 11, 2015
 *      Author: omer
 */

#ifndef PLANTCOORDINATES_H_
#define PLANTCOORDINATES_H_

class PlantCoordinates {
private:
	//int msi,lsi; // Most/Least Significant Int
	//todo changed this to public;
public:
	int xCoordinate, yCoordinate;
	PlantCoordinates(int xCoordinate = 0 , int yCoordinate = 0);
};


#endif /* PLANTCOORDINATES_H_ */
