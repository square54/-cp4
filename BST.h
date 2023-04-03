#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Node{
    private:
        Node *left;
        Node *right;
        int data;
    public:
        Node();
        Node(int data);
        ~Node();
};

class BST{
    private:
        Node *root;
    public:
        BST();
        ~BST();
        void insert();
        Node find();
        void remove();

};

#endif