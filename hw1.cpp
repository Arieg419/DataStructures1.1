#include<iostream>
#include<sstream>

using namespace std;

/* Declaring Node Class */

class treeNode {
	public:
		int rowID;
		int colID;
		int ripeVal;
		int fruitID;
		class treeNode *left;
		class treeNode *right;
}  *node;

/* Declaring AVL Tree Class */

class tree {
	public:
		tree() {
			node = NULL;
		}
		int calcHeight(treeNode*);
		int heightDifference(treeNode*);
		treeNode* rightRotation(treeNode* );
		treeNode* leftRotation(treeNode* );
		treeNode* leftRight_Rotation(treeNode* );
		treeNode* rightLeft_Rotation(treeNode* );
		treeNode* insert(treeNode* treeRoot, int val);
		treeNode* balance(treeNode* );
		void print(treeNode* firstNode, int level);
		void inorder(treeNode *);
        void preorder(treeNode *);
        void postorder(treeNode *);

};

int main() {
	cout << "Good morning Sir. Would you like to start planting?" << endl;
	cout << "Please plant your first seed." << endl;
	 int choice, item;
	    tree avl;
	    while (1)
	    {
	        cout<<"\n---------------------"<<endl;
	        cout<<"AVL Tree Implementation"<<endl;
	        cout<<"\n---------------------"<<endl;
	        cout<<"1.Insert Element into the tree"<<endl;
	        cout<<"2.Display Balanced AVL Tree"<<endl;
	        cout<<"3.InOrder traversal"<<endl;
	        cout<<"4.PreOrder traversal"<<endl;
	        cout<<"5.PostOrder traversal"<<endl;
	        cout<<"6.Exit"<<endl;
	        cout<<"Enter your Choice: ";
	        cin>>choice;
	        switch(choice)
	        {
	        case 1:
	            cout<<"Enter value to be inserted: ";
	            cin>>item;
	            node = avl.insert(node, item);
	            break;
	        case 2:
	            if (node == NULL)
	            {
	                cout<<"Tree is Empty"<<endl;
	                continue;
	            }
	            cout<<"Balanced AVL Tree:"<<endl;
	            avl.print(node, 1);
	            break;
	        case 3:
	            cout<<"Inorder Traversal:"<<endl;
	            avl.inorder(node);
	            cout<<endl;
	            break;
	        case 4:
	            cout<<"Preorder Traversal:"<<endl;
	            avl.preorder(node);
	            cout<<endl;
	            break;
	        case 5:
	            cout<<"Postorder Traversal:"<<endl;
	            avl.postorder(node);
	            cout<<endl;
	            break;
	        case 6:
	            return 0;
	            break;
	        default:
	            cout<<"Wrong Choice"<<endl;
	        }
	    }
	    return 0;
}

/*
Calculates any trees height, based on node supplied with.
Root can also refer to the root of a given sub tree.
*/

int tree::calcHeight(treeNode* root) {
	int height = 0;
	if(root) {
		int leftHeight = calcHeight(root->left);
		int rightHeight = calcHeight(root->right);
		height = max(leftHeight, rightHeight) + 1;
	}
	return height; 
}

/*
Calculates any trees height difference. Calculation is based on node supplied with.
Root can also refer to the root of a given sub tree.
*/

int tree::heightDifference(treeNode* root) {
	int difference;
	int leftHeight = calcHeight(root->left);
	int rightHeight = calcHeight(root->right);
	difference = leftHeight - rightHeight;
	return difference;
}

/*
Executes a Left Rotation in LL imbalance situations.
*/

treeNode* tree::leftRotation(treeNode* anchorNode) {
	treeNode* newNode = anchorNode->left; //newNode created. set to middle node.
	anchorNode->left = newNode->right; //anchorNodes left child is replaced by NULL pointer.
	newNode->right = anchorNode;  //our anchorNode is now the newNodes right child.
	return newNode;
}

/*
Executes a Right Rotation in RR imbalance situations.
*/

treeNode* tree::rightRotation(treeNode* anchorNode) {
	treeNode* newNode = anchorNode->right; //newNode which will become root of fixed subTree;
	anchorNode->right = newNode->left; // anchorNodes right is now pointing to NULL
	newNode->left = anchorNode; //the anchorNode is now newNodes left child
	return newNode;
}


/*
Executes a Right Left Rotation in RL imbalance situations.
*/

treeNode* tree::rightLeft_Rotation(treeNode* anchorNode) {
	treeNode* newNode;
	newNode = anchorNode->right; //we will first straighten out the sub tree.
	anchorNode->right = leftRotation(newNode);  //after this func call we are in a RR situation.
	return rightRotation(anchorNode); 
}

/*
Executes a Left Right Rotation in LR imbalance situations.
anchorNode represents the parent node with the imbalance.
Thus we we execute the turn around the anchorNode making it an anchor.
*/

treeNode* tree::leftRight_Rotation(treeNode* anchorNode) {
	treeNode* newNode;
	newNode = anchorNode->left; //we will first straighten out our subTree.
	anchorNode->left = rightRotation(newNode); //after this func we are in a LL situation.
	return anchorNode->left = leftRotation(anchorNode);
} 

/*
Insert function receives the root node of a possible tree, and values to input.
If root is a valid pointer we will continue to traverse the tree until reaching 
the last node. Upon arriving at the last valid node, we will create an additiional
leaf and then add a new leaf with the relevant Information. 
After every Insert it is crucial to check the current balance of the tree and fix it, 
if need be.
*/

treeNode* tree::insert(treeNode* newNode, int ripeness) {
	if(newNode == NULL) {
		newNode = new treeNode;  //making it into a new nodePointer.
		newNode->ripeVal = ripeness; //inserting data. will fix later.
		newNode->left = NULL; //initializing left child
		newNode->right = NULL; //initializing right child
		return newNode;
	}
	
	if (ripeness < newNode->ripeVal) {
		newNode->left = insert(newNode->left, ripeness);
		newNode = balance(newNode);
	}

	if (ripeness >= newNode->ripeVal) {
		newNode->right = insert(newNode->right, ripeness);
		newNode = balance(newNode); //after inserting newNode, must check bFactor.
	}

	return newNode;
}

/*
Height difference function will calculate the height of the left and right subtree.
*/

treeNode* tree::balance(treeNode* nodeToCheck) {
	int balanceFactor = heightDifference(nodeToCheck);
	if (balanceFactor >= 2) {
		if(heightDifference(nodeToCheck->left) > 0) {
			nodeToCheck = leftRotation(nodeToCheck);
		} else {
			nodeToCheck = leftRight_Rotation(nodeToCheck);
		}
	}

	if (balanceFactor <= -2) {
		if(heightDifference(nodeToCheck->right) <= 0) {
			nodeToCheck = rightRotation(nodeToCheck);
		} else {
			nodeToCheck = rightLeft_Rotation(nodeToCheck);
		}
	}
	return nodeToCheck;	
}


	/*
	Printing function to ease debugging.
	*/

void tree::print(treeNode* nodeToPrint, int level) {
	int i;
	//making sure pointer received is not NULL
	if(nodeToPrint) {
		print(nodeToPrint->right, level + 1);
		cout << "\n";
		if(nodeToPrint == node) {
			cout<<"Root ->";
		}

		for (i = 0 ; i < level && nodeToPrint != node; i++) {
				cout << "        ";
		}
			cout << nodeToPrint->ripeVal;
			print(nodeToPrint->left, level + 1);
		}

}

/*
 * Inorder Tree
 */
void tree::inorder(treeNode* nodeToPrint)
{
    if (nodeToPrint == NULL)
        return;
    inorder (nodeToPrint->left);
    cout<< nodeToPrint->ripeVal <<"  ";
    inorder (nodeToPrint->right);
}
/*
 * Preorder of tree
 */
void tree::preorder(treeNode* nodeToPrint)
{
    if (nodeToPrint == NULL)
        return;
    cout<< nodeToPrint->ripeVal <<"  ";
    preorder (nodeToPrint->left);
    preorder (nodeToPrint->right);
 
}
 
/*
 * Postorder of Tree
 */
void tree::postorder(treeNode* nodeToPrint)
{
    if (nodeToPrint == NULL)
        return;
    postorder ( nodeToPrint ->left );
    postorder ( nodeToPrint ->right );
    cout<< nodeToPrint->ripeVal <<"  ";
}








