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
        }
        int getData(){
            return data;
        }
        Node* getLeft(){
            return left;
        }
        Node* getRight(){
            return right;
        }
        void setLeft(Node* n){
            left = n;
        }
        void setRight(Node* n){
            right = n;
        }
        void setData(int n){
            data = n;
        }
};

class BST{
    private:
        Node *root;
        int count = 0;
        int total= 0;
    public:
        BST();
        BST(Node n);
        BST(vector<int> n);
        ~BST();
        bool insert(int n);
        bool insert(vector<int> n);
        Node* find(int n);
        int getHeight(int n);
        void remove(int n);
        void remove(vector<int> n);
        void print(int n);
        int getCount();
        void reset();
        int totalDepth(Node*n, int t);
        int avgDepth();
        void printAll(Node* t);
        Node* getRoot();
        int getTotal();
};

#endif