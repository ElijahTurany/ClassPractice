#include <iostream>
#include "Tree.h"
using namespace std;

int main(){
    Tree<int> t;
    TreeNode<int>* tn1 = new TreeNode<int>(1);
    TreeNode<int>* tn2 = new TreeNode<int>(2);
    TreeNode<int>* tn3 = new TreeNode<int>(3);
    TreeNode<int>* tn4 = new TreeNode<int>(4);
    cout << t.heightHelper(tn1);
    tn1->children.push_back(tn2);
    cout << t.heightHelper(tn1);
    tn2->children.push_back(tn3);
    cout << t.heightHelper(tn1);
    tn1->children.push_back(tn4);
    cout << t.heightHelper(tn1);
}