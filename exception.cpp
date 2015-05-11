#include <iostream>
#include <exception>
using namespace std;

class OutOfMemory:public exception {
public:
	const char* what() {
		return "I do not have the necessary resources for this allocation" << endl;		
	}
};

class NULLinput:public exception {
	public:
		const char* what() {
			return "You have sent me NULL input. WTF" << endl;		
		}
};

class Failure:public exception {
public:
	const char* what() {
		return cout << "this a general Failure message" << endl;
	}
}

class Fruit {
public:
	OutOfMemory errorObj;
	if() {
		throw errorObj;
	}
}

int main () {
	try{

	} catch(OutOfMemory errorObj) {
		cout << errorObj.what() << endl ;
	}
return 0;
}