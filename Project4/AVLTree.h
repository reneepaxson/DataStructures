/*
Renee Paxson
project 4
due Oct 27
made with assistance from Raymer, GFG [https://www.geeksforgeeks.org/insertion-in-an-avl-tree/]
also the textbook
MOST IMPORTANTLY, JON COLE, THE GOAT
*/
// File: AVLTree.h
// CLASS: AVLTree
#include "Node.h"
#include <iostream>
#include <vector>
using namespace std;

class AVLTree {
    
    private:
    //gotta set size to 0 or it'll iterate to something crazy
    int size = 0;
    Node* root;

    /// @brief recursive insert call
    /// @param newkey the number to insert into a node
    /// @param newvalue the value to insert into a node
    /// @param current the node, starting with root on the first call
    /// @return T/F
    bool insert(int newkey, string newvalue, Node*& current);


    /// @brief recursive find call
    /// @param key key to search for
    /// @param value value in the node
    /// @param current node we're currently on
    /// @return T/F
    bool find (int key, string& value, Node* current);



    /// @brief the find function that returns a node within a given range
    /// @param low lower bound
    /// @param high upper bound
    /// @param current the current node we're on
    /// @return first node in tree within range
    Node* findNode (int low, int high, Node* current);
    
public:    
    // I defined all the littlest functions in this header file
    // to keep AVLTree.cpp crisp

    /// @brief Default constructor
    AVLTree(){
        root = nullptr;
    };

    /// destructor
    ~AVLTree();

    /// @brief insert default, calls insert + root
    /// @param key the number to insert into a node
    /// @param value the value to insert into a node
    /// @return T/F
    bool insert(int key, string value){
        // recursive: pass root pointer
        return insert(key, value, root);
    };


    /// @brief returns node height, counting from the leaf
    /// @param c current node
    /// @return int height
    int getHeight(Node *c);



    /// @brief return overall height of a tree
    /// @return int height
    int getHeight(){
        return root->height;
    };

    
    /// @brief performs right rotation on tree
    /// @param node the "problem" node with a bad balance
    /// @return T/F
    bool rightRotate(Node *&node);
    

    /// @brief performs left rotation on tree
    /// @param node the "problem" node with a bad balance
    /// @return T/F
    bool leftRotate(Node *&node);



    /// @brief returns total size of tree
    /// @return int size
    int getSize(){
        return size;
    };
   

    /// @brief prints the tree in reverse order with proper spacing
    /// @param os print stream to cout
    /// @param me tree we're printing
    /// @return ostream object to print
    friend ostream& operator<<(ostream& os, const AVLTree& me);


    /// @brief called by operator<< to organize the data 
    ///        recusively in reverse inOrder
    /// @param os print stream to cout
    /// @param current tree passed by operator<<
    /// @return ostream containing formatted text
    ostream& revInOrder(ostream& os, Node * current) const;
    


    /// @brief find default, calls find + root
    /// @param key key to search for
    /// @param value value in node
    /// @return T/F
    bool find(int key, string& value){
        // recursive: passes root pointer to find
        return find(key, value, root);
    };


    /// @brief calculates balance of a node
    /// @param current the node we're calculating the balance of
    /// @return int balance
    int getBalance(Node* current){
        if (current == nullptr){
            return 0;
        }
        return (getHeight(current->left) - getHeight(current->right));
    }


    /// @brief returns vector of strings of all the values within a 
    ///         given range in the tree
    /// @param lowkey lower bound
    /// @param highkey upper bound
    /// @return vector of strings
    vector<string> findRange(int lowkey, int highkey);
    
    
    /// @brief called by findRange to recursively organize data into 
    ///        a vector
    /// @param lowkey lowest value to print
    /// @param highkey highest value to print
    /// @param current current node for traversal 
    /// @param vector organized vector of strings
    void inOrder(int lowkey, int highkey, Node * current, vector<string> &vector);
};