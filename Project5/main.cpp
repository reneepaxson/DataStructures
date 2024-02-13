#include "Trie.h"


int main() {
    Trie tree;
    tree.insert("baa");
    tree.insert("ball");
    tree.insert("bab");

    Trie newTrie(tree);
    Trie tree2;

    tree.insert("back");
    int num =tree.completeCount("ba");
    cout << num << endl;
    tree2 = tree;

    bool i =tree.find("ball");
    i =tree.find("baller");

    
}