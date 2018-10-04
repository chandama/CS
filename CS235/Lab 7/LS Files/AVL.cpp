#include "AVL.h"
    /*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * AVL::getRootNode() const
	{
	    //cout << "getRootNode"<<endl;
	    return root;
	}

	/*
	* Attempts to add the given int to the AVL tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool AVL::add(int data)
	{
        while (!storage.empty())
        {
            storage.pop();
        }
        if (root == NULL)
        {
            root = new Node(data);
            return true;
        }
        
        else if(addRecursive(this->root, data))
        {
            return true;
        }
        else return false;
	}
	
	bool AVL::addRecursive(Node* &ptr, int data) {
		if (ptr == NULL) {
			ptr = new Node(data);
			ptr->leftChild = NULL;
			ptr->rightChild = NULL;
			ptr->item = data;
			
			while(!(storage.empty())) 
			{
			    Node* ptr = storage.top();
			    cout << "ptr" << ptr->item <<endl;
			    storage.pop();
			    if(!storage.empty())
			    {   
			        Node* temp = storage.top();
			        cout << "temp" << temp->item << endl;
			        balanceTree(ptr, temp); //(2,1)
			    }
			}
			//cout << "Inserting value: " << data << endl;
			return true;
		}
		else if (data < ptr->item) {
			//cout << "Recursive left" << endl;
			storage.push(ptr);
			addRecursive(ptr->leftChild, data);
		}
		else if (data > ptr->item) {
			//cout << "Recursive right" << endl;
			storage.push(ptr);
			addRecursive(ptr->rightChild, data);
		}
		else return false;
	}

	/*
	* Attempts to remove the given int from the AVL tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool AVL::remove(int data)
	{
	    //cout << "remove"<<endl;
	    if (removeRecursive(root, data)) {
	    	//Call recursive function passing the root node and the data to remove
	    	return true;
	    }
	    else return false;
	    //Look for similarity in Binary_search_tree.h
	    //They have insert and erase functions that correspong to add and remove.
	}
	
	bool AVL::removeRecursive(Node* &ptr, int data) {
		if (ptr == NULL) {
			//cout << "The AVL is empty!" << endl;
			return false;
		}
		if (data == ptr->item) {
			if (ptr->leftChild == NULL && ptr->rightChild != NULL) {
				//Left child empty, move ptr to right node and delete the old node with temp ptr
				Node* temp_node = ptr;
				ptr = ptr->rightChild;
				delete temp_node;
				return true;
			}
			else if (ptr->leftChild != NULL && ptr->rightChild == NULL) {
				//Right child empty
				Node* temp_node = ptr;
				ptr = ptr->leftChild;
				delete temp_node;
				return true;
			}
			else if (ptr->leftChild == NULL && ptr->rightChild == NULL) {
				//Both children empty, set ptr = NULL and delete node.
				Node* temp_node = ptr;
				ptr = NULL;
				delete temp_node;
				return true;
			}
			else {
				/*
				* These functions find the largest number in the left side of the 
				* tree and sets the root equal to that value before deleting 
				* that value from the left branch. It does this recursively
				* which will delete all values from the left side in order from
				* greatest to least.
				*/
				ptr->item = findMax(ptr->leftChild);
				removeRecursive(ptr->leftChild, ptr->item);
			}
		}
		else if (data > ptr->item) {
			//If data doesn't match current node and is greater than ptr->item
			//Call the recursive function on the right child
			removeRecursive(ptr->rightChild, data);
		}
		else if (data < ptr->item) {
			//If less, call function on leftChild
			removeRecursive(ptr->leftChild, data);
		}
		else return false;
	}
	
	int AVL::findMax(Node* ptr)
	{
		//Only run function if current ptr != NULL else return -1
		if (ptr != NULL) 
		{
			Node* temp_left = ptr->leftChild;
			Node* temp_right = ptr->rightChild;
			int start_value = ptr->item;
			if (temp_left != NULL) 
			{
				//Recursive left call
				int left_value = findMax(temp_left);
				if (left_value > start_value) 
				{
					start_value = left_value;
				}
			}
			if (temp_right != NULL)
			{
				//Recursive right call
				int right_value = findMax(temp_right);
				if (right_value > start_value)
				{
					start_value = right_value;
				}
			}
			return start_value;
		}

		else return -1;
	}
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void AVL::clear()
	{
	   // cout << "clear"<<endl;
	    while (root != NULL) {
	    	//Call remove function until root == NULL
			remove(root->item);
	    }
	    return;
	}
	
	Node* AVL::rotateRight(Node *rot) 
	{
	    cout << "Rotate Right\n";
	    Node* ptr = rot->leftChild;
	    if (ptr->rightChild != NULL)
	    {
	        rot->leftChild = ptr->rightChild;
	    }
	    else
	    {
	        rot->leftChild = NULL;
	    }
	    ptr->rightChild = rot;
	    if (rot == root) 
	    {
	        root = ptr;
	    }
	    return ptr;
	}
	
	Node* AVL::rotateLeft(Node* place)
	{
	    cout << "RL start" << endl;
	    int dat = place->item;
	    Node* temp = place->rightChild;
	    place->rightChild = temp->leftChild;
	    temp->leftChild = place;
	    place = temp;
	    if (root->item == dat)
	    {
	        root = place;
	    }
	    cout << "RL complete" << endl;
	    return temp;
	    /*cout << "RL\n";
	    int dat = place->item;
	    Node* nptr = place->rightChild;
	    if (nptr->leftChild != NULL)
	    {

	        place->rightChild = nptr->leftChild;
	    }
	    else 
	    {
	        place->rightChild = NULL;
	    }
	    
	    nptr->leftChild = place;
	    cout <<"nptr->leftChild->item " << nptr->leftChild->item << endl;
	    cout << "nptr->rightChild->item " <<nptr->rightChild->item <<endl;
	    cout << "nptr->item " <<nptr->item<<endl;
	    cout << "root->item " <<root->item<<endl;
	    cout<< "place->item " <<place->item<<endl;
	    if (root->item == dat)
	    {  
	        root = nptr;
	    }
	    cout << "RL complete" <<endl;
	    return nptr;*/
	}
	
	void AVL::balanceTree(Node* n, Node* p)
	{
	    
	    
	    
	    /*cout << "Balance Tree\n";
	    if (checkBalance(p) == 2)
	    {
	        cout << "2bf\n";
	        int temp = checkBalance(p->leftChild);
	        if (temp == 1 || temp == 0) 
	        {
	            Node* gp = getParent(root, p->item);
	            if (gp != NULL)
	            {
	                if (p->item < gp->item)
	                {
	                    gp->leftChild = rotateRight(p);
	                }
	                else
	                {
	                    gp->rightChild = rotateRight(p);
	                }
	            }
	            else rotateRight(p);
	        }
	        //Tree is a left right
	        else
	        {
	            cout <<"leftright\n";
	            p->leftChild = rotateLeft(p->leftChild);
	            Node* gp = getParent(root, p->item);
	            if (gp != NULL)
	            {
	                if (p->item < gp->item)
	                {
	                    gp->leftChild = rotateRight(p);
	                }
	                else
	                {
	                    gp->rightChild = rotateRight(p);
	                }
	            }
	            else rotateRight(p);
	        }
	    }
	    else if (checkBalance(p) == -2)
	    {
	        cout << "-2bf\n";
	        int temp = checkBalance(p->rightChild);
	        if (temp == -1 || temp == 0)
	        {
    	        if (temp == -1 || temp == 0)
    	        {
    	            Node* gp = getParent(root, p->item);
    	            if (gp != NULL)
    	            {
    	                gp->rightChild = rotateLeft(p);
    	            }
                    else
                    {
                        cout <<"gp: " << gp << endl;
                        //ERROR ORRURS HERE gp left child messes things up
                        gp->leftChild = rotateLeft(p);
                        cout << "after" << endl;
                    }
    	        }
    	        else 
    	        {
    	            rotateLeft(p);
    	        }
	        }
	        //Tree is right left
	        else
	        {
	            cout <<"rightleft\n";
	            p->rightChild = rotateRight(p->rightChild);
	            Node* gp = getParent(root, p->item);
	            if (gp != NULL)
	            {
	                if (p->item < gp->item)
	                {
	                    gp->rightChild = rotateLeft(p);
	                }
	                else
	                {
	                    gp->leftChild = rotateLeft(p);
	                }
	            }
	            else
	            {
	                rotateLeft(p);
	            }
	        }
	    }
	    else if(p->parent != NULL)
	    {
	        cout << "null\n";
	        return;
	    }
	    else return;*/
	}
	
	int AVL::checkBalance(Node* ptr)
	{
	    cout << "Balance Factor\n";
	    return checkHeight(ptr->leftChild)-checkHeight(ptr->rightChild);
	}
	
	int AVL::checkHeight(Node* ptr)
	{
	    if(ptr == NULL)
	    {
	        return 0;
	    }
	    else return max(checkHeight(ptr->leftChild), checkHeight(ptr->rightChild))+1;
	}
	
	Node* AVL::getParent(Node* par, int data) 
	{   
	    cout << "get parent" << endl;
	    cout <<"passed item" << par->item << endl;
	    cout << "passed left" << par->leftChild << endl;
	    //RIGHT CHILD OF THIS PARENT IS A MEM LOCATION
	    cout << "passed right" << par->rightChild << endl;
	    if (data == par->item)
	    {
	        return NULL;
	    }
	    else
	    {
	        if ((par->leftChild != NULL && data == par->leftChild->item)
	        || (par->rightChild != NULL && data == par->rightChild->item))
	        {
	            return par;
	        }
	        else if (data < par->item)
	        {
	            return getParent(par->leftChild, data);
	        }
	        else if (data > par->item)
	        {
	            return getParent(par->rightChild, data);
	        }
	    }
	}