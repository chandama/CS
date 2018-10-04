#include "AVLInterface.h"
#include "Node.h"
#include <stack>

class AVL : public AVLInterface {
public:
	AVL() { root = NULL;}
	virtual ~AVL() {clear();}
	stack <Node*> storage;

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);
	
	bool addRecursive(Node* &ptr, int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);
	
	bool removeRecursive(Node* &ptr, int data);
	int findMax(Node* ptr);
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	Node* rotateLeft(Node* rot);
	Node* rotateRight(Node* rot);
	void balance(Node* ptr);
	int checkBalance(Node* ptr);
	int checkHeight(Node* ptr);
	Node* getParent(Node* par, int data);
	Node * AVL::rebalance_left(Node* place);
	Node * AVL::rebalance_right(Node* place);
	
	
	
protected:
	Node *root;
};