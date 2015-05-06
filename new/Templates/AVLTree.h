/*
 * AVLTree.h
 *
 *  Created on: May 3, 2015
 *      Author: dor
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_
//#define T int // TODO: REMOVE(for debugging only).

#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

template<class T> // TODO: UNCOMMENT(for debugging only).
class AVLTree {
private:
	struct Node {
		int key;
		T data;
		int height;
		Node* left;
		Node* right;
		Node* parent;

		int getBalance() {
			int leftHeight = 0, rightHeight = 0;
			if (left) {
				leftHeight = left->height;
			}
			if (right) {
				rightHeight = right->height;
			}
			return leftHeight - rightHeight;
		}
	};

	// variables
	Node* root;
	int size;

	// functions
	void updateHeights(Node* node);
	void balance(Node* node);
	void llRotation(Node* node);
	void rrRotation(Node* node);
	void rlRotation(Node* node);
	void lrRotation(Node* node);
	void print2(Node* nodeToPrint, int level);
	T* getSortedArray2(T* array, Node* node);

public:
	AVLTree();
	virtual ~AVLTree();
	int GetSize();
	void Insert(int key, T data);
	void Remove(int key);
	T getByKey(int key);
	T* getSortedArray();
	void print();
};

/********************************* Public Functions *******************************/

template<class T>
AVLTree<T>::AVLTree() {
	root = NULL;
	size = 0;
}

template<class T>
AVLTree<T>::~AVLTree() {
	// TODO Auto-generated destructor stub
}

// Time complexity: O(1)
template<class T>
int AVLTree<T>::GetSize() {
	return this->size;
}

// Time complexity: O(log(n))
template<class T>
void AVLTree<T>::Insert(int key, T data) {
	/*if (getByKey(key)) { // TODO: add this part after supporting getByKey
	 return;
	 }*/

	// Create the node
	Node* new_node = new Node();
	new_node->height = 1; // height of the subtree with this node as root.
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	new_node->key = key;
	new_node->data = data;

	this->size++;

	// choose where to add the node and add it.
	if (root == NULL) { // tree is empty
		root = new_node;
		return;
	} else { // tree is not empty.
		Node* current = root;
		// TODO: rewrite loop to be similar to getByKey ?
		while (new_node->parent == NULL) { // while wasn't placed yet
			if (key == current->key) {
				return; // TODO: return failure, cause id already exist
			} else if (key < current->key) { // left subtree
				if (current->left == NULL) {
					current->left = new_node;
					new_node->parent = current;
				} else {
					current = current->left;
				}
			} else { // right subtree
				if (current->right == NULL) {
					current->right = new_node;
					new_node->parent = current;
				} else {
					current = current->right;
				}
			}
		}
		updateHeights(new_node);
		this->balance(new_node);
		return;
	}
}

// Time complexity: O(log(n))
template<class T>
void AVLTree<T>::Remove(int key) {
	this->size--;
	return;
}

// Time complexity: log(n)
template<class T>
T AVLTree<T>::getByKey(int key) {
	Node* current = root;
	while ((current != NULL) && (current->key != key)) { // while wasn't placed yet
		if (key < current->key) { // left subtree
			current = current->left;
		} else { // right subtree
			current = current->right;
		}
	}
	return current;
}

// allocating an array using malloc, which hold the entire tree sorted.
// Time complexity: O(n)
template<class T>
T* AVLTree<T>::getSortedArray() {
	T* result = (T*) malloc(sizeof(T) * this->size);
	getSortedArray2(result, root); // placing the tree in "result"
	return result;
}

// printing the tree. using the recursion print2
template<class T>
void AVLTree<T>::print() {
	print2(root, 1);
}

/********************************* Private Functions *******************************/

// Updating the height property of all the parents nodes.
template<class T>
void AVLTree<T>::updateHeights(Node* node) {
	Node* current = node;
	while (current != NULL) {
		int leftHeight = 0, rightHeight = 0;
		if (current->left) {
			leftHeight = current->left->height;
		}
		if (current->right) {
			rightHeight = current->right->height;
		}
		current->height =
				((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
		current = current->parent;
	}
}

template<class T>
void AVLTree<T>::balance(Node* node) {
	int balanceFactor = node->getBalance();
	if (balanceFactor >= 2) { //left Heavy
		//assert(node->left->getBalance() != 0);
		if (node->left->getBalance() >= 0) {
			llRotation(node);
		} else {
			lrRotation(node);
		}
	} else if (balanceFactor <= -2) { //left Heavy
		//assert(node->right->getBalance() != 0);
		if (node->right->getBalance() > 0) {
			rlRotation(node);
		} else {
			rrRotation(node);
		}
	}
// TODO: verify that it works(might call some other node since changed
	if (node->parent) {
		balance(node->parent);
	}

}

// node: the node with the |balance|>=2
template<class T>
void AVLTree<T>::llRotation(Node* node) {
	Node* parent = node->parent;
	Node* lChild = node->left;

	// parent-node relation
	if (node == root) {
		root = node->left;
	} else {
		if (parent->left == node) {
			parent->left = lChild;
		} else {
			parent->right = lChild;
		}
	}
	lChild->parent = parent;

	Node* lrChild = node->left->right; //backup
	// node-child relation
	lChild->right = node;
	node->parent = lChild;
	// restore lost chain
	node->left = lrChild;

	updateHeights(node);
}

// node: the node with the |balance|>=2
template<class T>
void AVLTree<T>::rrRotation(Node* node) {
	Node* parent = node->parent;
	Node* rChild = node->right;

	// parent-node relation
	if (node == root) {
		root = node->right;
	} else {
		if (parent->left == node) {
			parent->left = rChild;
		} else {
			parent->right = rChild;
		}
	}
	rChild->parent = parent;


	Node* rlChild = node->right->left; //backup
	// node-child relation
	rChild->left = node;
	node->parent = rChild;
	// restore lost chain
	node->right = rlChild;

	updateHeights(node);
}

// node: the node with the |balance|>=2
template<class T>
void AVLTree<T>::lrRotation(Node* node) {
	rrRotation(node->left);
	llRotation(node);
}

// node: the node with the |balance|>=2
template<class T>
void AVLTree<T>::rlRotation(Node* node) {
	llRotation(node->right);
	rrRotation(node);
}

/************************************* Recursions ***********************************/

template<class T>
void AVLTree<T>::print2(Node* nodeToPrint, int level) {
	int i;
	if (nodeToPrint) {
		print2(nodeToPrint->right, level + 1);
		cout << "\n";
		if (nodeToPrint == root) {
			cout << "Root ->";
		}

		for (i = 0; i < level && nodeToPrint != root; i++) {
			cout << "       ";
		}
		cout << nodeToPrint->key;
		//cout << nodeToPrint->data;
		//cout << nodeToPrint->height;
		//cout << nodeToPrint->getBalance();

		print2(nodeToPrint->left, level + 1);
	}
}

// placing the subtree starts with node in the array, and return pointer to the next place in the array
template<class T>
T* AVLTree<T>::getSortedArray2(T* array, Node* node) {
	if (node == NULL)
		return array;
	array = getSortedArray2(array, node->left);
	*array = node->data;
	array++;
	return getSortedArray2(array, node->right);

}

#endif /* AVLTREE_H_ */
