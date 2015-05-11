/*
 * PairID.h
 *
 *  Created on: May 8, 2015
 *      Author: dor
 */

#ifndef DATASTRUCTURES_PAIRID_H_
#define DATASTRUCTURES_PAIRID_H_

class PairID {
private:
	int msi,lsi; // Most/Least Significant Int
public:
	PairID(int msi = 0 , int lsi = 0);
	virtual ~PairID();

	bool operator==(const PairID& other);
	bool operator!=(const PairID& other);

	bool operator>(const PairID& other);
	bool operator>=(const PairID& other);

	bool operator<(const PairID& other);
	bool operator<=(const PairID& other);
};

#endif /* DATASTRUCTURES_PAIRID_H_ */
