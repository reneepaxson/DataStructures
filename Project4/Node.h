/*
Renee Paxson
project 4
due Oct 27
made with assistance from Raymer, GFG [https://www.geeksforgeeks.org/insertion-in-an-avl-tree/]
also the textbook
MOST IMPORTANTLY, JON COLE, THE GOAT
*/

#include <iostream>
using namespace std;

class Node {
    public:

    int key;
    int height;
    string value;


    Node* left;
    Node* right;

    Node();
    Node(int newkey, string newvalue){
        key = newkey;
        value = newvalue;
        height = 0;
        left = nullptr;
        right = nullptr;
    }

};