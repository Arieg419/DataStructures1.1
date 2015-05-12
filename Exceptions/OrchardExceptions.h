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

class PlantDoesNotExist:public exception {
public:
	const char* what() {
		return "Consider planting the plant first\n";
	}
};

class PlantAlreadyExist:public exception {
public:
	const char* what() {
		return "You can not take back what's already been done\n";
	}
};

class FruitDoesNotExist:public exception {
public:
	const char* what() {
		return "Only hard work reaps fruits.\n";
	}
};

class FruitAlreadyExist:public exception {
public:
	const char* what() {
		return "You can may now reap the fruits of your labor.\n";
	}
};
#endif //ORCHARDEXCEPTIONS_H_
