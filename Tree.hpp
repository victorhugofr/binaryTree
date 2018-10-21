#include <iostream>
#include "Node.hpp"
using namespace std;
template<typename T>
class Tree{
private:
Node<T> *root;
void clear (Node<T> *&n){
    if(n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}
int insert(Node<T> *&root1,Node <T>*&novo){
    if(!root1){
        root1 = novo;
         return 0;
    }
    if(root1->i > novo->i){
        if(!root1->left){
            root1->left = novo;
             return 0;
        }
            return insert(root1->left, novo);
    }
    if(root1->i <= novo->i){
        if(!root1->right){
            root1->right = novo;
             return 0;
        }
          return  insert(root1->right,novo);
    }
     return -1;
}
void print(Node<T> *node) const{
    if(node){
        print(node->left);
        if(node->left || node->right){
            if(node->left){
                cout <<"root:"<< node->i <<" "<<endl;
                cout<<"folhas:"<<endl<<"left:"<<node->left->i<<endl;
            }
            if(node->right){
                  cout<<"right: "<<node->right->i<<" "<<endl;
            }
        }else{
           // cout <<"root:"<< node->i <<" "<<endl;
        }
        print(node->right);
    }
}

bool find (Node<T> *n, int i) const{
    if(n->i == i){
        return 1;
    }

    if(n->i <= i){
        if(n->right){
            return find(n->right,i);
        }
            return 0;
    }else{
        if(n->left){
            return find(n->left,i);
        }
        if(!n->right){
            return 0;
        }
    }
}
int count(Node<T> *n) const{
    if(n){
            return 1+ (count(n->left))+(count(n->right));
    }
        return 0;
}
//template<typename T>
void destroy(Node<T> *&n){
    if(!n->left && !n->right){
        delete n;
        n = NULL;
    }else{
        Node<T> *l;
        Node<T> *r;
        l = n->left;
        r = n->right;
        delete n;
        n = NULL;
        copy(l);
        copy(r);
    }
}

void copy(Node<T> *n){
    if(n){
        insert(root,n);
    }
}

public:
Tree(){
    root = NULL;
}

Tree(const Tree &rhs){
    root = NULL;
    operator=(rhs);
}

~Tree(){
    if(root){
        clear();
        delete root;
    }
}
Tree& operator = (const Tree &rhs){   
    if(root){
        clear(root);
        root = NULL;
    }

    Node<T> *temp;
    Node<T> *nerd;
    temp = rhs.root;
    if(!temp){
        return *this;
    }
    while(temp){
        if(!temp->left){
            insert(temp->i);
            temp = temp->right;
        }
        else{
           nerd = temp->left;
           while(nerd->right && nerd->right != temp){
               nerd = nerd->right;
           }
           if(!nerd->right){
               nerd->right = temp;
               temp = temp->left;
           }
           else{
               nerd->right = NULL;
               insert(temp->i);
               temp = temp->right;
           }
        }
    }
    return *this;
}
bool operator == (const Tree &rhs){
     int red[2];
     red[0] = count(root);
     red[1] = count(rhs.root);
     if(red[0] == red[1]){
         return 1;
     }
        return 0;
}
bool operator < (const Tree &rhs)
{
     int red[2];

     red[0] = count(root);
     red[1] = count(rhs.root);

     if(red[0] < red[1]){
         return 1;
     }
        return 0;
}
int seek(Node <T>*&n , int i){
    if(n->i == i){
        destroy(n);// call destroy
        return 0;
    }
    if(n->i <= i){
        if(n->right){
            return seek(n->right, i);
        }
        if(!n->left){
            return -1;
        }
    }
    if(n->i > i){
        if(n->left){
            return seek(n->left, i);
        }else{
            return -1;
        }
    }
    return -1;
}
bool isFull(){
    if(root){
        return 1;
    }
        return 0;
}

void clear(){
    if(root){
        clear(root);
        root = NULL;
    }
}
int insert(T i){
    Node<T> *temp;
    temp = new Node<T>(i);
    return insert(root,temp);
}

bool find(int i) const{
    if(root){
        return find(root, i);
    }
        return 0;
}

int remove (int i){
    if(root){
        return seek(root,i);
    }
        return -1;
}


void print() const{
    if(root){
        print(root);
        cout << endl;
    }
}
};