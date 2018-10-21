#include <iostream>
#include "Tree.hpp"
int main(){
    /**
     *      7
     *  5       9
     * 2  6   8
     *1
     */
    Tree<int> *t = new Tree<int>();
    t->insert(7);
    t->insert(5);
    t->insert(2);
    t->insert(6);
    t->insert(9);
    t->insert(8);
    t->insert(1);
    if(t->find(3)){
         cout<<"achou"<<endl;
    }
    t->print();
}