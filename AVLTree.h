#ifndef AVLTREE_H
#define AVLTREE_H

#include "Data.h"

template <typename T>
class AVLTree {
private:
	struct AVLNode {
		AVLNode* leftChild;
		AVLNode* rightChild;
		T* data;
		int duplicates; // used if there are duplicate values in the tree
			// instead of changing rotation rules
		int height;
		AVLNode () :	// default constructor
			leftChild {nullptr},
			rightChild {nullptr},
			data {nullptr},
			duplicates {0},
			height {0} {};
		~AVLNode () = default;
		AVLNode (T& value) :
			leftChild {nullptr},
			rightChild {nullptr},
			duplicates {0},
			height {0} {
				data = new T{value};
			};
		AVLNode (T&& value):
			leftChild {nullptr},
			rightChild {nullptr},
			duplicates {0},
			height {0} {
				data = new T{value};
			}
		AVLNode (T& value, AVLNode* left, AVLNode* right) :
			leftChild {left},
			rightChild {right},
			duplicates {0},
			height {0} {
				data = new T{value};
			};
		AVLNode (T&& value, AVLNode* left, AVLNode* right) :
			leftChild {left},
			rightChild {right},
			duplicates {0},
			height {0} {
				data = new T{value};
			}
	};

	AVLNode* root;


	// accessors -------------------------------------------------------------

	// will return the height of a given AVLNode*. Look at the definition for
	// height. -1 if the tree is empty, or max height of children + 1.
	// Must use recursion, since it counts leaves-up and we start traversals
	// at root.
	int getHeight(AVLNode* node) const {
		// CODE HERE



		return 0; // PLACEHOLDER FOR COMPILATION
	}

	// returns the depth from the current subtree (node is subroot)
	// must use recursion.
	int getDepthAux(const T& value, AVLNode* node) const {
		// CODE HERE

		return 0; // PLACEHOLDER
	}

	// driver function for getDepthAux(T&,AVLNode*), which does the recursion.
	// getDepth(T&,AVLNode*) does an extra check for node not found in tree.
	int getDepth(const T& value, AVLNode* node) const {
		if (!findNode(value, node)){
			return -1;  // return -1 if node does not exist in tree
		} else {
			return getDepthAux(value, node);
		}
	}

	// returns the AVLNode* that points to the node containing the
	// parameter value in its data member.
	// the node parameter is the root of the current subtree.
	// Must use recursion.
	AVLNode* findNode(const T& value, AVLNode* node) const {
		// CODE HERE


		return nullptr; // PLACEHOLDER
	}

	// returns the AVLNode* that points to the node containing the
	// parameter value in its data member.
	AVLNode* findNode(const T& value) const {
		return findNode(value, root);
	}

	// method to clone a subtree and return it.
	AVLNode* clone (AVLNode* node) const {
		if (!node){
			return nullptr;
		} else {
			AVLNode* temp = new AVLNode (*node->data,
								clone(node->leftChild),
								clone(node->rightChild));
			temp->duplicates = node->duplicates;
			temp->height = getHeight(node);
			return temp;
		}
	}

	// Possibly several functions to be used by printing traversal functions
	// (below). These functions may need to know what the last leaf in a
	// subtree is to print nicely (by my standards, anyway).
		// CODE HERE

	// should print the tree in a preorder traversal
	void printPreorder(AVLNode* node) const {
		// CODE HERE
	}

	// should print the tree in an inorder traversal
	void printInorder(AVLNode* node) const {
		// CODE HERE
	}
	// should print the tree in a postorder traversal
	void printPostorder(AVLNode* node) const {
		// CODE HERE
	}

	// mutators ------------------------------------------------------------

	// inserts a new value into the given subtree with node as the root.
	// If the value already exists, just incrememnt the duplicates counter.
	// Else, create memory for it and place pointers appropriately.
	// Must use recursion.
	void insert(T& value, AVLNode* & node){
		// CODE HERE
	}

	// will balance the tree with node as the offending root, like
	// alpha in our class discussions. Should call onf of the rotate functions.
	// Don't forget to set the height at the end!
	void balance(AVLNode* & node){
		// CODE HERE
	}

	// Rotate binary tree node with left child, i.e. a single rotation
	// for case 1. Update the heights, and set new root.
	void rotateLeft(AVLNode*& node){
		// CODE HERE
	}

	// Rotate binary tree node with right child, i.e. a single rotation
	// for case 4. Update the heights, and set new root.
	void rotateRight(AVLNode*& node){
		// CODE HERE
	}

	// Double rotate binary tree node: first left child with its right
	// child, then subroot with its new left child (was grandchild previously).
	// I.e. rotation case 2. Update the heights, and set new root.
	void rotateDoubleLeft(AVLNode*& node){
		// CODE HERE
	}

	// Double rotate binary tree node: first left child with its right
	// child, then subroot with its new left child (was grandchild previously).
	// I.e. rotation case 2. Update the heights, and set new root.
	void rotateDoubleRight(AVLNode*& node){
		// CODE HERE
	}

	// removes a given value from the tree. If the Node containing the value
	// has duplicates, decrement the duplicates. Else deallocate the memory and
	// recursively call remove to fix the tree, as discussed in class.
	void remove(T& value, AVLNode*& node){
		// CODE HERE
	}


	// private function to recursively empty
	void empty(AVLNode* node){
		// CODE HERE
	}





public:
	AVLTree():
		root {nullptr} {};
	~AVLTree(){
		empty();
	}
	// copy constructor: should copy all of the data from the other tree
	// into this tree.
	AVLTree(const AVLTree<T>& other){
		root = clone(other.root);
	}

	// accessors --------------------------------------------------------

	int getHeight() const {
		return getHeight(root);
	}

	// searches the tree for a value. If it is found, the height
	// is returned. If not, then -1 is returned.
	int getHeight(const T& value) const {
		AVLNode* node = findNode(value);
		return node ? node->height : -1; // ternary operator
	}

	// returns the depth for the whole tree. should be 0 if the
	// tree is nonempty, and -1 if it is empty.
	int getDepth() const {
		if (root){
			return 0;
		} else {
			return -1;
		}
	}
	// returns the depth for a given value.
	// should be -1 if tree is empty, or the number of steps
	// down from root node if not.
	int getDepth(T& value) const {
		if (!root){
			return -1;
		} else {
			return getDepth(value, root);
		}
	}

	// will return the balance factor of a value in the tree.
	// if the value does not exist, return -128 (the lowest value for
	// a 1-byte char). If it does exist, return the balance factor.
	char getBalanceFactor(T& value) const {
		// CODE HERE

		return 0; // PLACEHOLDER FOR COMPILATION
	}

	// driver function to call the private preorder traversal
	void printPreorder(){
		std::cout << "[";
		printPreorder(root);
		std::cout << "]" << std::endl;
	}

	// driver function to call the private preorder traversal
	void printInorder(){
		std::cout << "[";
		printInorder(root);
		std::cout << "]" << std::endl;
	}

	// driver function to call the private preorder traversal
	void printPostorder(){
		std::cout << "[";
		printPostorder(root);
		std::cout << "]" << std::endl;
	}

	// should print the tree in a level-order traversal (NOT driver function)
	void printLevelOrder(){
		// CODE HERE
	}

	// mutators -----------------------------------------------------

	// call private balance(1) on tree
	void balance(){
		balance(root);
	}

	// calls private remove function to remove starting at root
	void remove(T& value){
		remove(value, root);
	}
	void remove(T&& value){
		T temp = T{value};
		remove(temp);
	}

	// driver function for emptying the tree, since there is no public access
	// to root of tree (as many other functions do in this file)
	void empty(){
		// CODE HERE
	}

	// calls private insert function to insert starting at root
	void insert(T& value){
		insert(value, root);
	}
	void insert(T&& value){
		T temp = T{value};
		insert(temp);
	}

};



#endif
