#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <string>
#include <vector>
#include "BST.h"
#include <algorithm>
using namespace std;

vector<int> shuffle(vector<int> n, int s){
    srand(time(0));

        for(int i = 0;i < s; i++){
            int j = rand()%n.size();
            int k = rand()%n.size();
            swap(n[k],n[j]);
        }

        cout << endl;
        return n;
    }

vector<int> shake(vector<int> S, int n, int R){

    for(int i =0; i < n; i++){
        int index = rand()%(S.size()-1);
        int distance = (rand()%(R-1))+1;
        int direction = rand()%2 ? 1 : -1;
        // cout << index <<" " << distance << " " << direction << "| ";
        for(int j = 0; j<distance; j++){
            if(index != 0 && index !=(int)S.size()-1){
                if(direction == 1){
                    swap(S[index],S[index+1]);
                    index++;
                }
                else{
                    swap(S[index],S[index-1]);
                    index--;
                }                
            }
        }

        // for(int i: S){
        //     cout << i << " ";
        // }
        // cout << endl;

    }
    return S;

}

int main(){
    /* Initialize numbers */
    srand(time(0));
    vector<int> test1(1000);
    vector<int> test2; // shake and shuffle not enough
    vector<int> test3; // shake and shuffle enough

    iota(std::begin(test1),std::end(test1),1);
    test2 = shuffle(test1,100);
    test2 = shake(test2,100, 700);

    test3 = shuffle(test1,2000);
    test3 = shake(test3,2000, 700);

    vector<int> countSaving1;
    vector<int> countSaving2;
    vector<int> countSaving3;

    // printf("set1(default): ");
    // for(int i: test1){
    //     printf("%d ",i);
    // }
    // cout << endl;

    // printf("set2(shuffle 10 times): ");
    // for(int i: test2){
    //     printf("%d ",i);
    // }
    // cout << endl << endl;


    ///////////////////////////////////////////////////////
    /* move Vectors into tree */
    BST* tree1 = new BST(test1);
    BST* tree2 = new BST(test2);
    BST* tree3 = new BST(test3);

    /////////////////////////////////////////////////////
    /* test1: average Depth */

    printf("tree1 average count: %d\n",tree1->getCount());
    printf("tree2 average count: %d\n",tree2->getCount());
    printf("tree3 average count: %d\n\n",tree3->getCount());
    

    cout << "tree1 preOrder: ";
    tree1->printAll(tree1->getRoot());
    cout << endl;
    cout << "tree2 preOrder: ";
    tree2->printAll(tree2->getRoot());
    cout << endl;
    cout << "tree3 preOrder: ";
    tree3->printAll(tree3->getRoot());
    cout << endl << endl;
    /////////////////////////////////////////////////////
    /* test1: average Depth */

    printf("tree1 average Depth: %d\n",tree1->avgDepth());
    printf("tree2 average Depth: %d\n",tree2->avgDepth());
    printf("tree3 average Depth: %d\n\n",tree3->avgDepth());
    
    //////////////////////////////////////////////////////
    /* average Height*/

    printf("tree1 max Height: %d\n",tree1->getHeight(tree1->getRoot()->getData()));
    printf("tree2 max Height: %d\n",tree2->getHeight(tree2->getRoot()->getData()));
    printf("tree3 max Height: %d\n\n",tree3->getHeight(tree3->getRoot()->getData()));

    //////////////////////////////////////////////////////
    /* check find operation count */

    countSaving1.clear();
    countSaving2.clear();
    countSaving3.clear();

    int t1=0, t2 = 0, t3 = 0; // tree1,2 total count
    
    for(int i=0;i<(int)test1.size(); i++){
        tree1->find(test1[i]);
        tree2->find(test2[i]);
        tree3->find(test3[i]);
        t1+= tree1->getCount();
        t2+= tree2->getCount();
        t3+= tree3->getCount();
        countSaving1.push_back(tree1->getCount());
        countSaving2.push_back(tree2->getCount());    
        countSaving3.push_back(tree3->getCount());
    }
    cout << endl;

    cout << "average count for find tree1: " << t1/countSaving1.size() << endl;
    cout << "average count for find tree2: " << t2/countSaving2.size() << endl;
    cout << "average count for find tree3: " << t3/countSaving3.size() << endl;
    cout << endl;
    //////////////////////////////////////////////////////////////////////
    /* remove operation*/

    countSaving1.clear();
    countSaving2.clear();
    countSaving3.clear();

    t1 = 0;
    t2 = 0;
    t3 = 0;

    cout << "removed ";
    for(int i= (test1.size());i>=0;i--){
        printf("%d ", i);
        tree1->remove(i);
        t1+=tree1->getCount();
        countSaving1.push_back(tree1->getCount());
    }
    cout << "in tree1\n\nremoved ";
    for(int i = (test2.size());i>=0;i--){
        printf("%d ", i);
        tree2->remove(i);
        t2+= tree2->getCount();
        countSaving2.push_back(tree2->getCount());  
    }
    cout << "in tree2\n\nremoved ";
    for(int i = (test3.size());i>=0;i--){
        printf("%d ", i);
        tree3->remove(i);
        t3+= tree3->getCount();
        countSaving3.push_back(tree3->getCount());  
    }
    cout << "in tree3\n\n";

    // for(int i:countSaving1){
    //     printf("%d ",i);
    // }
    // cout << endl;

    // for(int i:countSaving2){
    //     printf("%d ",i);
    // }
    // cout << endl;
    // cout << "tree1 preOrder after: ";
    // tree1->printAll(tree1->getRoot());
    // cout << endl;
    // cout << "tree2 preOrder after: ";
    // tree2->printAll(tree2->getRoot());
    // cout << endl;

    // tree1->remove(1);
    // cout << tree1->getCount();
    cout << "average count for remove tree1: " << t1/countSaving1.size() << endl;
    cout << "average count for remove tree2: " << t2/countSaving2.size() << endl;
    cout << "average count for remove tree3: " << t3/countSaving3.size() << endl;



}