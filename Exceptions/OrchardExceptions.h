#include <iostream>
#include <exception>
using namespace std;

#ifndef ORCHARDEXCEPTIONS_H_
#define ORCHARDEXCEPTIONS_H_

class OutOfMemory:public exception {
public:
	const char* what() {
		return "I do not have the necessary resources for this allocation\n";
	}
};

class InvalidInput:public exception {
	public:
		const char* what() {
			return "You have sent me illegal input. WTF\n";
		}
};

class Failure:public exception {
public:
	const char* what() {
		return "This a general Failure message\n";
	}
};

#endif //ORCHARDEXCEPTIONS_H_
