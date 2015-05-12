//#include <iostream>
//
////#include "Objects/Fruit.h"
//#include "DataStructures/AVLTree.h"
//#include "Objects/Fruit.h"
//#include "Objects/Plant.h"
//#include "Objects/Orchard.h"
//using namespace std;
//
//void AVLTest();
//
//int main(int argc, const char**argv) {
//	/*Fruit* frt = Fruit(17,0);
//	 Plant plant = Plant();
//	 plant.AddFruit(frt);*/
//	AVLTest();
//	return 0;
//}
//
////////////////////////////////////////////////////////////////////////////
//
//void AVLTest() {
//	cout << "Good morning Sir. Would you like to start planting?" << endl;
//	cout << "Please plant your first seed." << endl;
//	int choice, item, ID, *arr;
//
//	AVLTree<int, int> avl;
//	while (1) {
//		cout << "\n\n-----------------------" << endl;
//		cout << "AVL Tree Implementation" << endl;
//		cout << "-----------------------" << endl;
//		cout << "1.Add new fruit into the tree" << endl;
//		cout << "2.Remove fruit from the tree" << endl;
//		cout << "3.Display Balanced AVL Tree" << endl;
//		cout << "4.AVL Tree to Array" << endl;
//		cout << "5.Get leftest" << endl;
//		cout << "9.Exit" << endl;
//		cout << "Enter your Choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			cout << "What is the ID? ";
//			cin >> ID;
//			cout << "Enter Item: ";
//			cin >> item;
//			//avl.Insert(ID, new int(item));
//			avl.Insert(ID, item);
//			break;
//		case 2:
//			cout << "What is the ID? ";
//			cin >> ID;
//			avl.Remove(ID);
//			break;
//		case 3:
//			cout << "Balanced AVL Tree:" << endl;
//			avl.print();
//			break;
//		case 4:
//			cout << "array:" << endl;
//			arr = avl.getSortedArray();
//			cout << arr[0];
//			for (int i = 1; i < avl.GetSize(); i++) {
//				cout << "," << arr[i];
//			}
//			cout << endl;
//			free(arr);
//			break;
//		case 5:
//			cout << "minimin key is:" << endl;
//			cout << avl.getSmallest() << endl;
//			break;
//		case 9:
//			exit(0);
//			break;
//		default:
//			cout << "Wrong Choice" << endl;
//		}
//	}
//}
