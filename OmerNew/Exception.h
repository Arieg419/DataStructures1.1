#include <iostream>
#include <exception>
using namespace std;

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
		return "this a general Failure message\n";
	}
};
