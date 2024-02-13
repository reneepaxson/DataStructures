/*
    Renee Paxson
    Project 6
    9 Dec 2023
    class Database
    includes functions to modify vector of student records and hash table of indeces 
    insert, remove, find
    made with help from Jon Cole, the goat
*/

#include "Record.h"
#include "HashTable.h"

using namespace std;

class Database {
public:
    
    /// @brief default constructor
    Database();


    /// @brief insert a new student record into the database
    /// @param newRecord student record (firstname, lastname, uid, year)
    /// @param collisions number of collisions during probe in HashTable insert
    /// @return true if record is inserted into the DB
    bool insert (const Record &newRecord, int &collisions);

    
    /// @brief delete record if key exists in database
    /// @param key key of the record to be deleted
    /// @return true if deletion is successful
    bool remove(int key);


    /// @brief using the given uid, call HashTable::find to verify
    /// @param uid key to search for
    /// @param foundRecord copy of the found record
    /// @param collisions number of collisions that occur in the HashTable::find probe
    /// @return true if found
    bool find(int uid, Record &foundRecord, int &collisions);

    
    /// @brief returns the current loading factor
    /// @return 
    float alpha();

    

    /// @brief prints the database values of HashTable slot, recordStore slot, student name, uid, and year
    /// @param os output stream
    /// @param me database to print
    /// @return output stream of formatted database values
    friend ostream& operator<<(ostream& os, const Database& me);

private:

    HashTable indexTable;
    vector <Record> recordStore;

};