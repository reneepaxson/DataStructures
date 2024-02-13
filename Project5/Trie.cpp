#include "Trie.h"

Trie::Trie() // initializer list, setting size = 1 
            // since we're making a root node
    : size(1), wordCount(0), root(new Node())
{}


Trie::Trie(const Trie& old){
    size=old.size;
    wordCount=old.wordCount;
    root=old.root;
    // recursive copy 
    // make separate function for "loop"
}


Trie::~Trie(){
    destructor(root);
}

void Trie::destructor(Node* current){
    for (int i = 0; i < 26; i++){
        if (current->children[i] != nullptr){
            destructor(current->children[i]);
        }
        delete(current->children[i]);
    }
    return;

}


bool Trie::insert(string str){
    return insert(str, root);
}

bool Trie::insert(string str, Node* current){


    if (current->children[str[0]-'a'] == nullptr){
        // if there is no node for this letter in the string,
        // create one
        current->children[str[0]-'a'] = new Node();
        // and increment node count
        size++;

    } 

    if (str.size() == 1){
        // if we've reached the end of the string
        // check for duplicates
        if (current->children[str[0]-'a']->is_end){
            return false;
        }

        // else set is_end to true
        current->children[str[0]-'a']->is_end = true;
        // and notch another word
        wordCount++;

        return true;

    }
    
    return Trie::insert(str.substr(1), current->children[str[0]-'a']);
}

int Trie::count() const{
    return wordCount;
}

int Trie::getSize() const{
    return size;
}

bool Trie::find(string str) const {
    return find(str, root);
}

bool Trie::find(string str, Node * current) const{
    if (current-> children[str[0]-'a'] == nullptr){
        // if null then no
        return false;
    }
    if (str.size() == 1){
        // if we reach the end of the string that thang is found
        return true;
    }
    
    // else keep looking
    return Trie::find(str.substr(1), current->children[str[0]-'a']);
}

Node* Trie::findNode(string str, Node* current) {
    // already made sure it existed so we don't have to check for null
    if (str.size() == 0){
        // if we reach the node after the string that thang is found
        return current;
    }
    
    // else keep looking
    return Trie::findNode(str.substr(1), current->children[str[0]-'a']);
}

int Trie::completeCount(string str)  {
    if (Trie::find(str, root)){
        // if str exists in the tree, get to the node str ends at
        Node* node = findNode(str, root);
        return completeCount(node);
    }
    // else nvm :)
    return 0;
    
}

int Trie::completeCount(Node * current)  {
    
    if (current == nullptr){
        return 0;
    }
    int count = 0;
    if (current->is_end){
        count++;
    }
    for (Node* child: current->children){
        count += completeCount(child);
    }
    return count;
}

vector<string> Trie::complete(string str) const{

}

void Trie::operator=(const Trie& old){
    // destruct
    this->~Trie();
    // reassign
    size=old.size;
    wordCount=old.wordCount;
    root=old.root;
    return; 
    
}
