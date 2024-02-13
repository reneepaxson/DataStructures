#include <vector>

using namespace std;

class Node { 
        public: 

        //each node has pointers to 26 children
        vector<Node*> children;

        bool is_end;
        
        //initialize
        Node()
            : children(26, nullptr)
        {}
        //parameterized
        // Node(string str){

        // }        
    };