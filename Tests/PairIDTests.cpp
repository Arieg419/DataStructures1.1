/*
 * PairIDTests.cpp
 *
 *  Created on: May 9, 2015
 *      Author: dor
 */
#include "../DataStructures/PairID.h"
#include <iostream>

using namespace std;
/*
int main() {
	string success = "Success";
	string failed = "Failed";

	// all the "testers" pairs are going to be tested against "base"
	PairID base = PairID(10, 7);
	PairID testers[9] = { PairID(5, 3), PairID(11, 12), PairID(9, 12), PairID(
			11, 5), PairID(10, 3), PairID(10, 12), PairID(9, 7), PairID(12, 7),
			PairID(10, 7) };

	// Create correct results vector
	bool operatorGT[9] = { true, false, true, false, true, false, true, false,
			false };
	bool operatorGTE[9] = { true, false, true, false, true, false, true, false,
			true };
	bool operatorLT[9] = { false, true, false, true, false, true, false, true,
			false };
	bool operatorLTE[9] = { false, true, false, true, false, true, false, true,
			true };
	bool operatorEQ[9] = { false, false, false, false, false, false, false, false,
			true };
	bool operatorNEQ[9] = { true, true, true, true, true, true, true, true,
			false };

	// Perform the tests
	bool resultEQ = true, resultNEQ = true, resultGT = true, resultGTE = true,
			resultLT = true, resultLTE = true;
	for (int i = 0; i < 9; i++) {
		resultGT = resultGT && ((base > testers[i]) == operatorGT[i]);
		resultGTE = resultGTE && ((base >= testers[i]) == operatorGTE[i]);

		resultLT = resultLT && ((base < testers[i]) == operatorLT[i]);
		resultLTE = resultLTE && ((base <= testers[i]) == operatorLTE[i]);

		resultEQ = resultEQ && ((base == testers[i]) == operatorEQ[i]);
		resultNEQ = resultNEQ && ((base != testers[i]) == operatorNEQ[i]);
	}

	// Print results
	cout << "Testing operator>......."
			<< ((resultGT == true) ? success : failed) << endl;
	cout << "Testing operator>=......."
			<< ((resultGTE == true) ? success : failed) << endl << endl;

	cout << "Testing operato<......." << ((resultLT == true) ? success : failed)
			<< endl;
	cout << "Testing operator<=......."
			<< ((resultLTE == true) ? success : failed) << endl << endl;

	cout << "Testing operator==......."
			<< ((resultEQ == true) ? success : failed) << endl;
	cout << "Testing operator!=......."
			<< ((resultNEQ == true) ? success : failed) << endl;

	return 0;
}
*/
