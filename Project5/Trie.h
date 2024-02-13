#include "Node.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Trie {
    
    public:

    /// @brief default constructor
    Trie();
        
    //copy constructor
    ///
    Trie(const Trie&);
    
    /// @brief 
    ~Trie();
    

    /// @brief Insert a new word into the trie. 
    ///        Duplicate words are not allowed
    /// @param  
    /// @return true if word inserted, false if not
    bool insert(string str);

    /// @brief 
    /// @return 
    int count() const;

    /// @brief 
    /// @return 
    int getSize() const;

    /// @param  
    /// @return 
    bool find(string str) const;

    //Node* findNode(string str, Node* node);

    /// @brief 
    /// @param  
    /// @return 
    int completeCount(string str) ;

    /// @brief 
    /// @param  
    /// @return vector of strings containing all the words in the 
    ///         dictionary that begin with the given input string 
    vector<string> complete(string str) const;

    /// remove all contents of trie1 and make a copy of trie2 in trie1
    void operator=(const Trie&);

    

    

private:
    
    Node* root;

    int size;

    int wordCount;

    //int completeWord;

    bool insert(string str, Node* node);

    bool find(string str, Node* node) const;

    int completeCount(Node* node) ;

    Node* findNode(string str, Node* node) ;

    void destructor(Node* node);
};