#include <iostream>
template<typename T>
class Node{
    public:
    T i;
    Node *left;
    Node *right;
    Node(T a){
        i=a;
        left=NULL;
        right=NULL;
    }
    ~Node(){
        i=567;
        delete this->left;
        delete this->right;
    }
};