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
    BST* hand = new BST;
    hand->insert(10);
    hand->insert(200);
    hand->insert(5);

    cout << "total nodes after insert by manually: " << hand->getTotal() << endl;
    cout << "preorder of BST(10-200-5)\n";
    hand->printAll(hand->getRoot());
    cout << endl;

    cout << "removed 200\n";
    hand->remove(200);
    hand->printAll(hand->getRoot());
    cout << endl;
    cout << "removed 10\n";
    hand->remove(10);
    hand->printAll(hand->getRoot());
    cout << endl;
    cout << "removed 5\n";
    hand->remove(5);
    hand->printAll(hand->getRoot());
    cout << endl;
    cout << endl;


    

    delete hand;





    /* Initialize numbers */
    srand(time(0));
    vector<int> test1(1000);
    vector<int> test2; // shake and shuffle not enough
    vector<int> test3; // shake and shuffle enough

    vector<int> difSize1(2000);
    vector<int> difSize2;
    vector<int> difSize3;


    iota(std::begin(test1),std::end(test1),1);
    test2 = shuffle(test1,100);
    test2 = shake(test2,100, 700);

    test3 = shuffle(test1,2000);
    test3 = shake(test3,2000, 700);

    vector<int> countSaving1;
    vector<int> countSaving2;
    vector<int> countSaving3;


    iota(std::begin(difSize1),std::end(difSize1),1);
    difSize2 = shuffle(difSize1,100);
    difSize2 = shake(difSize2,100, 700);

    difSize3 = shuffle(difSize1,4000);
    difSize3 = shake(difSize1,4000, 700);

    vector<int> difCountSaving1;
    vector<int> difCountSaving2;
    vector<int> difCountSaving3;


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
    
    BST* dtree1 = new BST(difSize1);
    BST* dtree2 = new BST(difSize2);
    BST* dtree3 = new BST(difSize3);
    
    /////////////////////////////////////////////////////
    /* test1: insert count */

    printf("tree1(1000) after insert all nodes: %d\n",tree1->getTotal());
    printf("tree2(1000, not enough shuffle(100) and shake(100)) insert count: %d\n",tree2->getTotal());
    printf("tree3(1000, enough shuffle(2000) and shake(2000)) insert count: %d\n\n",tree3->getTotal());

    printf("dtree1(2000) average count: %d\n",dtree1->getTotal());
    printf("dtree2(2000, not enough shuffle (100) and shake (100)) average count: %d\n",dtree2->getTotal());
    printf("dtree3(2000, enough shuffle(4000) and shake(4000)) average count: %d\n\n",dtree3->getTotal());

    printf("tree1(1000) insert count: %d\n",tree1->getCount());
    printf("tree2(1000, not enough shuffle(100) and shake(100)) insert count: %d\n",tree2->getCount());
    printf("tree3(1000, enough shuffle(2000) and shake(2000)) insert count: %d\n\n",tree3->getCount());

    printf("dtree1(2000) average count: %d\n",dtree1->getCount());
    printf("dtree2(2000, not enough shuffle (100) and shake (100)) average count: %d\n",dtree2->getCount());
    printf("dtree3(2000, enough shuffle(4000) and shake(4000)) average count: %d\n\n",dtree3->getCount());

    // cout << "tree1 preOrder: ";
    // tree1->printAll(tree1->getRoot());
    // cout << endl;
    // cout << "tree2 preOrder: ";
    // tree2->printAll(tree2->getRoot());
    // cout << endl;
    // cout << "tree3 preOrder: ";
    // tree3->printAll(tree3->getRoot());
    // cout << endl << endl;

    /////////////////////////////////////////////////////
    /* test1: average Depth */

    printf("tree1 average Depth: %d\n",tree1->avgDepth());
    printf("tree2 average Depth: %d\n",tree2->avgDepth());
    printf("tree3 average Depth: %d\n\n",tree3->avgDepth());
    
    printf("dtree1 average Depth: %d\n", dtree1->avgDepth());
    printf("dtree2 average Depth: %d\n", dtree2->avgDepth());
    printf("dtree3 average Depth: %d\n\n", dtree3->avgDepth());
    //////////////////////////////////////////////////////
    /* average Height*/

    printf("tree1 max Height: %d\n",tree1->getHeight(tree1->getRoot()->getData()));
    printf("tree2 max Height: %d\n",tree2->getHeight(tree2->getRoot()->getData()));
    printf("tree3 max Height: %d\n\n",tree3->getHeight(tree3->getRoot()->getData()));

    printf("dtree1 max Height: %d\n",dtree1->getHeight(dtree1->getRoot()->getData()));
    printf("dtree2 max Height: %d\n",dtree2->getHeight(dtree2->getRoot()->getData()));
    printf("dtree3 max Height: %d\n\n",dtree3->getHeight(dtree3->getRoot()->getData()));

    //////////////////////////////////////////////////////
    /* check find operation count */

    countSaving1.clear();
    countSaving2.clear();
    countSaving3.clear();

    difCountSaving1.clear();
    difCountSaving2.clear();
    difCountSaving3.clear();

    int t1=0, t2 = 0, t3 = 0;// tree1,2 total count
    int dt1= 0, dt2 = 0, dt3 = 0;
    
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

    for(int i=0;i<(int)difSize1.size(); i++){
        dtree1->find(difSize1[i]);
        dtree2->find(difSize2[i]);
        dtree3->find(difSize3[i]);
        dt1+= dtree1->getCount();
        dt2+= dtree2->getCount();
        dt3+= dtree3->getCount();
        difCountSaving1.push_back(dtree1->getCount());
        difCountSaving2.push_back(dtree2->getCount());    
        difCountSaving3.push_back(dtree3->getCount());
    }
    cout << endl;

    cout << "average count for find tree1: " << t1/countSaving1.size() << endl;
    cout << "average count for find tree2: " << t2/countSaving2.size() << endl;
    cout << "average count for find tree3: " << t3/countSaving3.size() << endl;
    cout << endl;

    cout << "average count for find dtree1: " << dt1/countSaving1.size() << endl;
    cout << "average count for find dtree2: " << dt2/countSaving2.size() << endl;
    cout << "average count for find dtree3: " << dt3/countSaving3.size() << endl;
    cout << endl;
    //////////////////////////////////////////////////////////////////////
    /* remove operation*/

    countSaving1.clear();
    countSaving2.clear();
    countSaving3.clear();

    t1 = 0;
    t2 = 0;
    t3 = 0;

    // cout << "removed ";
    for(int i= (test1.size());i>=0;i--){
        // printf("%d ", i);
        tree1->remove(i);
        t1+=tree1->getCount();
        countSaving1.push_back(tree1->getCount());
    }
    // cout << "in tree1\n\nremoved ";
    for(int i = (test2.size());i>=0;i--){
        // printf("%d ", i);
        tree2->remove(i);
        t2+= tree2->getCount();
        countSaving2.push_back(tree2->getCount());  
    }
    // cout << "in tree2\n\nremoved ";
    for(int i = (test3.size());i>=0;i--){
        // printf("%d ", i);
        tree3->remove(i);
        t3+= tree3->getCount();
        countSaving3.push_back(tree3->getCount());  
    }
    // cout << "in tree3\n\n";


    // cout << "removed ";
    for(int i= (difSize1.size());i>=0;i--){
        // printf("%d ", i);
        dtree1->remove(i);
        dt1+=dtree1->getCount();
        difCountSaving1.push_back(dtree1->getCount());
    }
    // cout << "in tree1\n\nremoved ";
    for(int i = (difSize2.size());i>=0;i--){
        // printf("%d ", i);
        dtree2->remove(i);
        dt2+= dtree2->getCount();
        difCountSaving2.push_back(dtree2->getCount());  
    }
    // cout << "in tree2\n\nremoved ";
    for(int i = (difSize3.size());i>=0;i--){
        // printf("%d ", i);
        dtree3->remove(i);
        dt3+= dtree3->getCount();
        difCountSaving3.push_back(dtree3->getCount());  
    }
    // cout << "in tree3\n\n";
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
    cout << "after removing all nodes tree1: " << tree1->getTotal() << endl;
    cout << "after removing all nodes tree2: " << tree2->getTotal() << endl;
    cout << "after removing all nodes tree3: " << tree3->getTotal() << endl << endl;

    cout << "after removing all nodes dtree1: " << dtree1->getTotal() << endl;
    cout << "after removing all nodes dtree2: " << dtree2->getTotal() << endl;
    cout << "after removing all nodes tree3: " << dtree3->getTotal() << endl << endl;


    cout << "average count for remove tree1: " << t1/countSaving1.size() << endl;
    cout << "average count for remove tree2: " << t2/countSaving2.size() << endl;
    cout << "average count for remove tree3: " << t3/countSaving3.size() << endl << endl;

    cout << "average count for remove dtree1: " << dt1/difCountSaving1.size() << endl;
    cout << "average count for remove dtree2: " << dt2/difCountSaving2.size() << endl;
    cout << "average count for remove dtree3: " << dt3/difCountSaving3.size() << endl;

}