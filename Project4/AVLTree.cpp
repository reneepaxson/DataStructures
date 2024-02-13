/*
Renee Paxson
project 4
due Oct 27
made with assistance from Raymer, GFG [https://www.geeksforgeeks.org/insertion-in-an-avl-tree/]
also the textbook
MOST IMPORTANTLY, JON COLE, THE GOAT
*/

#include "AVLTree.h"

bool AVLTree::insert(int newkey, string newvalue, Node*& current){
    bool inserted = false;

    if (current == nullptr){
        //base case
        current = new Node(newkey, newvalue);
        size++;
        inserted = true;
    } 
    else if (newkey == current->key){
        inserted = false;
        //no duplicates
    }
    else if (newkey < current->key){
        //recursive call left if key is less than current
        inserted = insert(newkey, newvalue, current->left);
    }
    else {
        //recursive call right if key is greater than current
        inserted = insert (newkey, newvalue, current->right);
    }

    //update height
    //this will update height of all nodes as it steps back through the recursion
    int lChildheight = getHeight(current->left);
    int rChildheight = getHeight(current->right);
    // height = the largest height of all children nodes +1
    current->height = max(lChildheight, rChildheight)+1;
    // getBalance returns left->height - right->height
    int balance = getBalance(current);
    if (balance > 1 && newkey < current->left->key){
        //right rotate
        rightRotate(current);
    } else if (balance < -1 && newkey > current->right->key){
        //left rotate
        leftRotate(current);
    } else if (balance > 1 && newkey > current->left->key){
        //double right rotate
        leftRotate(current->left);
        rightRotate(current);
    }else if (balance < -1 && newkey < current->right->key){
        //double left rotate
        rightRotate(current->right);
        leftRotate(current);
    }

    return inserted; 
}

bool AVLTree::rightRotate(Node *& problem){
    // hook = problem's left node 
    Node * hook = problem->left;
    // temp = hook's right node
    Node * temp = hook->right;

    // hook's left node = problem
    hook->right = problem;
    // problem's left node = temp
    problem->left = temp;

    //recalculate heights, problem first then hook
    problem->height = max(getHeight(problem->left), getHeight(problem->right))+1;
    // hook holds the updated tree structure
    hook->height = max(getHeight(hook->left), getHeight(hook->right))+1;
    
    // so we set the referenced node to equal hook
    problem = hook;
    return true;
}

bool AVLTree::leftRotate(Node *& problem){
    // hook = problem's right node
    Node *hook = problem->right;
    // temp = hook's left node
    Node *temp = hook->left;
    
    // hook's left node = problem
    hook->left = problem;
    // problem's right node = temp
    problem->right = temp;

    //recalculate heights, problem first then hook
    problem->height = max(getHeight(problem->left), getHeight(problem->right))+1;
    // hook holds the updated tree structure
    hook->height = max(getHeight(hook->left), getHeight(hook->right))+1;
    
    // so we set the referenced node to equal hook
    problem = hook;
    return true;
}

int AVLTree::getHeight(Node * curr){
    //height starts count from leaf
    if (curr == nullptr){
        //empty node has height of -1
        return -1;
    }
    else {
        return curr->height;
    }

}


bool AVLTree::find(int k, string& v, Node* current){
    if (current == nullptr){
        //does not exist
        return false;
    } 
    else if (k == current->key){
        //found !
        return true;
    }
    else if (k < current->key){
        // key is smaller than current, search left nodes
        return find(k, v, current->left);
    }
    else {
        //key is larger than current, search right nodes
        return find(k, v, current->right);
    }
}


AVLTree::~AVLTree() {
    //while (current->next){
        //delete data
    //}
    //killmenext
}

ostream& operator<<(ostream& os, const AVLTree& s)
{
    //passes root to recursive revInOrder call
    return s.revInOrder(os, s.root);
}
 
ostream&  AVLTree::revInOrder(ostream& os, Node * current) const{
    if (current != nullptr){
        //calculates how many times to tab out based on node height
        //root is tabbed 0 times, level two is tabbed once, and so on
        int tab = root->height - current->height;
        
        revInOrder(os, current->right);

        os << string(tab, '\t') << current->key << ", " << current->value << endl;

        revInOrder(os, current->left);
    }

    return os;
}


vector<string> AVLTree::findRange(int lowkey, int highkey){
    vector<string> range;
    
    // calculations get a lil weird if the range doesn't include the root
    if (root->key < lowkey || root->key > highkey){
        //so we call findNode
        Node * tempNode = findNode(lowkey,highkey,root);
        //and pass tempnode to the recursive function
        inOrder(lowkey, highkey,tempNode, range);
    } else {
        //otherwise calling it normal with root is fine
        inOrder(lowkey, highkey, root, range);
    }

    return range;
}

Node* AVLTree::findNode(int low, int high,Node* current){
    // this returns the first found node within range
    if (current->key >= low && current->key <= high){
        return current;
    } else if (current->key < low){
        return findNode(low,high,current->right);
    } else if (current->key > high){
        return findNode(low, high, current->left);
    }
    
}

void AVLTree::inOrder(int low, int high, Node * current, vector<string> &vector){
    //organizes data from lowest to highest considering the bounds
    if (current != nullptr && current->key >= low && current->key <= high){
        inOrder(low,high,current->left, vector);
        vector.push_back(current->value);
        inOrder(low,high,current->right, vector);
    }
}