/*
    Renee Paxson
    Project 6
    9 Dec 2023
    class Database
    includes functions to modify vector of student records and hash table of indeces 
    insert, remove, find
    made with help from Jon Cole, the goat
*/

#include "Database.h"

Database::Database(){}

bool Database::insert(const Record &newRecord, int &collisions){
    int i;

    //if record already exists return false
    if (indexTable.find(newRecord.getUID(), i, collisions)){
        return false;
    }

    // insert newrecord into recordStore
    recordStore.push_back(newRecord);
    // get the index of newRecord
    i = recordStore.size() - 1;

    // insert into indexTable
    indexTable.insert(newRecord.getUID(), i, collisions);
    return true;
}

bool Database::remove(int key){
    
    int i, c;

    //check that key exists
    if (indexTable.find(key, i, c)){
        
        // if record is located at the end of recordStore, EZ
        if (i == (recordStore.size() - 1)){
            // delete indexTable entry
            indexTable.remove(key);
            // pop recordStore record
            recordStore.pop_back();
            return true;
        }
        
        int swapUID;
        // i = index to put into swapped uid hashTable

        // save end uid to swapUID
        swapUID = recordStore[recordStore.size()-1].getUID();

        // update index
        indexTable.setIndex(swapUID, i);
        
        // swap record to be deleted with the end
        swap(recordStore[i], recordStore[recordStore.size() - 1]);
        
        // and kill it
        recordStore.pop_back();
        // also kill the item in indexTable
        indexTable.remove(key);

        return true;
        
    }   

    // else key does not exist, return false
    return false;
}

bool Database::find(int uid, Record &foundRecord, int &collisions){
    
    int i;
    
    if (indexTable.find(uid, i, collisions)){
        foundRecord = recordStore[i];
        return true;
    }

    return false;
}

float Database::alpha(){
    return indexTable.alpha();
}

ostream& operator<<(ostream& os, const Database& me){
    os << "Database contents:\n";
    for (int i = 0; i < (me.indexTable.getSize()); i++){

        if (me.indexTable.getSlot(i).isEmpty()){
            continue;
        }
        os << "HashTable Slot: "<< i<< ", recordStore slot " << me.indexTable.getSlot(i).getIndex()
            << " -- " << me.recordStore[me.indexTable.getSlot(i).getIndex()] << "\n"; 

    }
    return os;
    
}