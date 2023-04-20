#include "BST.h"

BST::BST(){
    root = nullptr;
}

BST::BST(vector<int> n){
    root = nullptr;
    insert(n);
}

BST::~BST(){
    
    delete root;
}

bool BST::insert(vector<int> n){
    for(int i:n){
        insert(i);
    }
    return true;
}

bool BST::insert(int n){
    reset();
    Node* temp = new Node(n);
    if(root == nullptr){
        count++;
        total++;
        root = temp;
        return true;
    }

    else{
        Node* currNode = root;
        while(currNode != nullptr){
            count++;
            if(currNode->getData() == n){
                return false;
            }
            else if(n < currNode->getData()){
                if(currNode->getLeft() == nullptr){
                    currNode->setLeft(temp);
                    total++;
                    return true;
                }else{
                
                    currNode = currNode->getLeft();
                }
            }else{
                if(currNode->getRight() == nullptr){
                    currNode->setRight(temp);
                    total++;
                    return true;
                }else{
                    currNode = currNode->getRight();
                }
            }
        }
    }
    
    return false;

}

Node* BST::find(int n){
    reset();
    Node* cur = root;
    while(cur != nullptr){
        count++;
        if(cur->getData() == n){
            return cur;
        }
        else if(cur->getData() > n){
            cur = cur->getLeft();
        }
        else{
            cur = cur->getRight();
        }
    }
    return nullptr;
}

void BST::remove(int n){
    reset();
    Node* par = nullptr;
    Node* curr = root;
    Node* temp = nullptr;

    while(curr != nullptr){
        count++;
        if(curr->getData() == n){
            if(curr->getLeft() == nullptr && curr->getRight() == nullptr){
                if(par == nullptr){
                    delete root;
                    total--;
                    root = nullptr;

                }
                else if(par->getLeft() == curr){
                    delete par->getLeft();
                    par->setLeft(nullptr);
                    total--;
                }
                else{
                    delete par->getRight();
                    par->setRight(nullptr);
                    total--;
                }
            }
            else if(curr->getRight() == nullptr){
                if(par == nullptr){
                    temp = curr;
                    root = curr->getLeft();
                    delete temp;
                    total--;
                }
            
                else if(par->getLeft() == curr){
                    temp = curr;
                    par->setLeft(curr->getLeft());
                    delete temp;
                    total--;
                }
                else{
                    temp = curr;
                    par->setRight(curr->getLeft());
                    delete temp;
                    total--;
                }
            }
            else if(curr->getLeft() == nullptr){
                if(par == nullptr){
                    temp = curr;
                    root = curr->getRight();
                    delete temp;
                    total--;
                }
                else if(par->getLeft() == curr){
                    temp = curr;
                    par->setLeft(curr->getRight());
                    delete temp;
                    total--;
                }
                else{
                    temp = curr;
                    par->setRight(curr->getRight());
                    delete temp;
                    total--;
                }
            }
            else{
                Node* suc = curr->getRight();
                while(suc->getLeft() != nullptr){
                    suc = suc->getLeft();
                }
                int i = suc->getData();
                remove(suc->getData());
                curr->setData(i);
            }
            return;      
        }
        else if(curr->getData() < n){
            par = curr;
            curr = curr->getRight();
        }
        else{
            par = curr;
            curr = curr->getLeft();
        }
    }
}

void BST::remove(vector<int> n){
    for(int i:n){
        remove(i);
    }
}
void BST::print(int n){
    Node* node = find(n);
    if(node != nullptr){
        print(node->getLeft()->getData());
        cout << node->getData();
        print(node->getRight()->getData());
    }
}

int BST::getHeight(int n) {
    Node* node = find(n);
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if(node->getLeft()!=nullptr)
        leftHeight = getHeight(node->getLeft()->getData());
    if(node->getRight() != nullptr)
        rightHeight = getHeight(node->getRight()->getData());
    return 1 + max(leftHeight, rightHeight);
}

int BST::getCount(){
    return count;
}

void BST::reset(){
    count = 0;
}

int BST::totalDepth(Node* n, int t){
    if(n == nullptr){
        return 0;
    }
    return (t+totalDepth(n->getLeft(),t+1)+ totalDepth(n->getRight(), t+1));
}

int BST::avgDepth(){
    return totalDepth(root, 0)/total;
}

void BST::printAll(Node* t){
    if(t == nullptr){
        return;
    }
    Node* temp = t;

    cout << t->getData() << " ";
    printAll(temp->getLeft());
    printAll(temp->getRight());
    
}

Node* BST::getRoot(){
    return root;
}

int BST::getTotal(){
    return total;
}
/*
getCount done
shuffle 
shake 
getHeight done
reset done
averagedepth done
*/
