/*
    Renee Paxson
    Project 6
    9 Dec 2023
    class HashTable
    includes hashing, probing, insert, remove, and find
    made with help from Jon Cole, the goat
*/

#include "Slot.h"
#include "hashfunction.h"
#include "shuffle.h"
#include <vector>
#include <array>
#include <iostream>
#include <iomanip>

#define MAXHASH 20




using namespace std;


class HashTable{

public:

    /// @brief default constructor
    HashTable();

    /// @brief insert new key/index pair into the table
    /// @param key student UID
    /// @param index location of the record in recordStore
    /// @return true on successful insert
    bool insert (int key, int index, int &collisions);
    // 

    /// @brief set slot type to emptyAfterRemoval, functionally deleting the record
    /// @param key student uid to delete
    /// @return true on successful deletion
    bool remove (int key);


    /// @brief find key in hashtable
    /// @param key student uid
    /// @param index copy of the index of record in recordStore
    /// @param collisions number of collisions encountered during probe
    /// @return true if found
    bool find (int key, int &index, int &collisions);


    /// @brief returns the current loading factor
    /// @return 
    float alpha();

    /// @brief updates the slot's index
    /// @param key student uid to search for 
    /// @param index the new index value
    /// @return 
    bool setIndex(int key, int index);

    /// @brief get slot given the slotArray index
    /// @param index the location in the slotArray
    /// @return Slot
    Slot getSlot(int index) const;

    /// @brief get size of slorArray
    /// @return int size
    int getSize() const;

    /// @brief prints the hashtable values slot number, key, and index
    /// @param os output stream
    /// @param me HashTable to print
    /// @return output stream of formatted HashTable values
    friend ostream& operator<<(ostream& os, const HashTable& me);

private:

    Slot slotArray [MAXHASH];
    int size;
    int count;

    array<int, MAXHASH - 1> probe_array;
        
};