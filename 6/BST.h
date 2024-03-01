/**
 * Title: Binary Search Trees
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 2
 * Description: BST.h
 */

#ifndef BST_H
#define BST_H
#include <vector>
#include <string>
using namespace std;
#include "BSTNode.h"

class BST
{
private:
    BSTNode *searchTreeInsert2(BSTNode *node, string key);
    BSTNode *searchTreeDelete2(BSTNode *node, string key);
    vector<string> inorderTraversal2(BSTNode *node, vector<string> result);

    void cleantree(BSTNode *node);
    void leftfinder(BSTNode *&node, string &key);

public:
    BST();
    ~BST();
    BSTNode *node;
    vector<string> result;
    void searchTreeInsert(string key);
    void searchTreeDelete(string key);
    vector<string> inorderTraversal(BSTNode *node);
};
#endif