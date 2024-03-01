/**
 * Title: Binary Search Trees
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 2
 * Description: BSTNode.h
 */
#ifndef BSTNODE_H
#define BSTNODE_H
#include <string>
using namespace std;
class BSTNode
{
public:
    BSTNode *leftnode;
    BSTNode *rightnode;
    string key;
    int count;
    BSTNode(string key, int count, BSTNode *leftnode, BSTNode *rightnode);
    // ~BSTNode();
};
#endif