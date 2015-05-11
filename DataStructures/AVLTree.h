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

template<class K, class T> // TODO: UNCOMMENT(for debugging only).
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
	void RemoveNode(Node* node);
	void updateHeights(Node* node);
	void balance(Node* node);
	void llRotation(Node* node);
	void rrRotation(Node* node);
	void rlRotation(Node* node);
	void lrRotation(Node* node);
	Node* getNode(int key);
	void ParentPointTo(Node* child, Node* newChild);
	void print2(Node* nodeToPrint, int level);
	T* getSortedArray2(T* array, Node* node);\
	void destroy2(Node* node);

public:
	AVLTree();
	virtual ~AVLTree();
	int GetSize();
	void Insert(K key, T data);
	void Remove(K key);
	T getByKey(K key);
	T* getSortedArray();
	void print();
};

/********************************* Public Functions *******************************/

template<class K, class T>
AVLTree<K, T>::AVLTree() {
	root = NULL;
	size = 0;
}

template<class K, class T>
AVLTree<K, T>::~AVLTree() {
	destroy2(root); // release allocated memory
	root=NULL;
	return;
}

// Time complexity: O(1)
template<class K, class T>
int AVLTree<K, T>::GetSize() {
	return this->size;
}

// Time complexity: O(log(n))
template<class K, class T>
void AVLTree<K, T>::Insert(K key, T data) {
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
template<class K, class T>
void AVLTree<K, T>::Remove(K key) {
	Node* node = getNode(key);
	if (node)
		RemoveNode(getNode(key));
	return;
}

// Time complexity: log(n)
template<class K, class T>
T AVLTree<K, T>::getByKey(K key) {
	Node* node = getNode(key);
	if (!node)
		return NULL;
	return node->data;
}

// allocating an array using malloc, which hold the entire tree sorted.
// Time complexity: O(n)
template<class K, class T>
T* AVLTree<K, T>::getSortedArray() {
	T* result = (T*) malloc(sizeof(T) * this->size);
	getSortedArray2(result, root); // placing the tree in "result"
	return result;
}

// printing the tree. using the recursion print2
template<class K, class T>
void AVLTree<K, T>::print() {
	print2(root, 1);
}

/********************************* Private Functions *******************************/
template<class K, class T>
void AVLTree<K, T>::RemoveNode(Node* node) {
	// if leaf
	if (!(node->left) && !(node->right)) {
		ParentPointTo(node, NULL);
		if (node->parent) {
			updateHeights(node->parent);
			this->balance(node->parent);
		}
		delete node;
		this->size--;
		return;
	}
	// if only right child
	else if (!(node->left) && (node->right)) {
		ParentPointTo(node,node->right);
		node->right->parent = node->parent;

		updateHeights(node->parent);
		this->balance(node->parent);
		delete node;
		this->size--;
		return;
	}

	// if only left child
	else if ((node->left) && !(node->right)) {
		ParentPointTo(node,node->left);
		node->left->parent = node->parent;

		updateHeights(node->parent);
		this->balance(node->parent);
		delete node;
		this->size--;
		return;
	}

	// if node has 2 childrens
	else {
		// find new root for subtree
		Node* current = node->right;
		while (current->left)
			current = current->left;

		// switch current and node.
		int backupInt = current->key;
		current->key = node->key;
		node->key = backupInt;

		T backupT = current->data;
		current->data = node->data;
		node->data = backupT;

		RemoveNode(current); // recursive call. will happen only once, because now node doesn't have 2 children.
	}
}

// Updating the height property of the node and his ancestors.
template<class K, class T>
void AVLTree<K, T>::updateHeights(Node* node) {
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

template<class K, class T>
void AVLTree<K, T>::balance(Node* node) {
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
template<class K, class T>
void AVLTree<K, T>::llRotation(Node* node) {
	Node* parent = node->parent;
	Node* lChild = node->left;

	// parent-node relation
	ParentPointTo(node,lChild);
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
template<class K, class T>
void AVLTree<K, T>::rrRotation(Node* node) {
	Node* parent = node->parent;
	Node* rChild = node->right;

	// parent-node relation
	ParentPointTo(node,rChild);
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
template<class K, class T>
void AVLTree<K, T>::lrRotation(Node* node) {
	rrRotation(node->left);
	llRotation(node);
}

// node: the node with the |balance|>=2
template<class K, class T>
void AVLTree<K, T>::rlRotation(Node* node) {
	llRotation(node->right);
	rrRotation(node);
}

template<class K, class T>
typename AVLTree<K, T>::Node* AVLTree<K, T>::getNode(int key) {
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

template<class K, class T>
void AVLTree<K, T>::ParentPointTo(Node* child, Node* newChild) {
	if (child->parent == NULL)
		root = newChild;
	else {
		if (child->parent->left == child) {
			child->parent->left = newChild;
		} else {
			child->parent->right = newChild;
		}

	}
}

/************************************* Recursions ***********************************/

template<class K, class T>
void AVLTree<K, T>::print2(Node* nodeToPrint, int level) {
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
template<class K, class T>
T* AVLTree<K, T>::getSortedArray2(T* array, Node* node) {
	if (node == NULL)
		return array;
	array = getSortedArray2(array, node->left);
	*array = node->data;
	array++;
	return getSortedArray2(array, node->right);
}

// destroying the array, post order
template<class K, class T>
void AVLTree<K, T>::destroy2(Node* node) {
	if (node == NULL)
		return;
	destroy2(node->left);
	destroy2(node->right);
	delete node;
}


#endif /* AVLTREE_H_ */
