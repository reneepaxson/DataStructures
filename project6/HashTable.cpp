/*
    Renee Paxson
    Project 6
    9 Dec 2023
    class HashTable
    includes hashing, probing, insert, remove, and find
    made with help from Jon Cole, the goat
*/

#include "HashTable.h"

HashTable::HashTable() : size(MAXHASH), count(0), probe_array(makeShuffledArray()) {}

bool HashTable::insert (int key, int index, int& collisions){
    
    // check for duplicates
    if (find(key, index, collisions)){
        return false;
    }

    int home = (jsHash(key)) % MAXHASH;

    // if home slot is empty, put er there
    if (slotArray[home].isEmpty()){
        slotArray[home].load(key, index);
        collisions = 0;
        count++;
        return true;
    }

    // otherwise probe for next available slot
    for (int i = 0; i< probe_array.size(); i++){

        int probeHash = (home + probe_array[i]) % MAXHASH;

        if (slotArray[probeHash].isEmpty()){
            slotArray[probeHash].load(key, index);
            collisions = i + 1;
            count++;
            return true;
        }
    }

    // false if slotarray is full
    return false;
}

bool HashTable::remove (int key){

    int home = (jsHash(key)) % MAXHASH;
    
    // if home slot is empty since start, terminate
    // this key does not exist
    if (slotArray[home].isEmptySinceStart()){
        return false;
    }

    // else check if its key matches
    if (slotArray[home].getKey() == key){
        slotArray[home].kill();
        count--;
        return true;
    }

    // if home key doesn't match
    for (int i = 0; i< probe_array.size(); i++){
        int probeHash = (home + probe_array[i]) % MAXHASH;
        
        // if slot on sequence is empty since start, terminate
        if (slotArray[probeHash].isEmptySinceStart()){
            return false;
        }

        // else check if key matches
        if (slotArray[probeHash].isNormal()){
            if (slotArray[probeHash].getKey() == key) {
                slotArray[probeHash].kill();
                count--;
                return true;
            }
        }

        // if the slot is emptyOnRemoval the loop will continue

    }
    
    // false if key does not exist
    return false;

}


bool HashTable::find (int key, int &index, int &collisions){
    
    int home = (jsHash(key)) % MAXHASH;

    // if home slot is empty since start, terminate
    // this key does not exist
    if (slotArray[home].isEmptySinceStart()){
        return false;
    }

    // else check if its key matches
    if (slotArray[home].getKey() == key){
        index = slotArray[home].getIndex();
        collisions = 0;
        return true;
    }

    // if home key doesn't match
    for (int i = 0; i< probe_array.size(); i++){
        int probeHash = (home + probe_array[i]) % MAXHASH;
        
        // if slot on sequence is empty since start, terminate
        if (slotArray[probeHash].isEmptySinceStart()){
            return false;
        }

        // else check if key matches
        if (slotArray[probeHash].isNormal()){
            if (slotArray[probeHash].getKey() == key) {
                index = slotArray[probeHash].getIndex();
                collisions = i + 1;
                return true;
            }
        }

        // if the slot is emptyOnRemoval the loop will continue

    }

    return false;

}

bool HashTable::setIndex(int key, int index){

    int home = (jsHash(key)) % MAXHASH;
    
    // if home slot is empty since start, terminate
    // this key does not exist
    if (slotArray[home].isEmptySinceStart()){
        return false;
    }
    
    if (slotArray[home].getKey() == key){
        slotArray[home].setIndex(index);
        return true;
    }

    // if home key doesn't match, find it
    for (int i = 0; i< probe_array.size(); i++){
        int probeHash = (home + probe_array[i]) % MAXHASH;
        
        // if slot on sequence contains data
        if (slotArray[probeHash].isNormal()){
            // check if key matches
            if (slotArray[probeHash].getKey() == key) {
                // then update index!
                slotArray[probeHash].setIndex(index);
                return true;
            }
        }

        // if the slot is emptyOnRemoval the loop will continue

    }       
}

Slot HashTable::getSlot(int index) const{
    return slotArray[index];
}

int HashTable::getSize() const{
    return size;
}


float HashTable::alpha(){
    return float(count / size);
}

ostream& operator<<(ostream& os, const HashTable& me)
{
    os << "HashTable contents: \n";
    for (int i = 0; i<me.size; i++){
        if (me.slotArray[i].isEmpty()){
            continue;
        }
        os << "HashTable Slot "<< i<< ": " << "Key = " << me.slotArray[i].getKey()
            << ", Index = " << me.slotArray[i].getIndex() << "\n"; 

    }
    return os;
}
