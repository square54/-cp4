#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Node{
    private:
        Node *left;
        Node *right;
        int data;
    public:
        Node(){
            left = nullptr;
            right = nullptr;
            data = 0;
        }
        Node(int data){
            this->data = data;
            left = nullptr;
            right= nullptr;
        }
        ~Node(){
            delete this;
        }
        int getData(){
            return data;
        }
};

class BST{
    private:
        Node *root;
    public:
        BST();
        BST(Node n);
        ~BST();
        void insert(Node n);
        Node find(Node n);
        void remove(Node n);


};

#endif