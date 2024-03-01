/**
 * Title: Binary Search Trees
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 2
 * Description: BSTNode.cpp
 */
#include "BSTNode.h"
using namespace std;

BSTNode::BSTNode(string key, int count, BSTNode *leftnode, BSTNode *rightnode)
{
    this->leftnode = leftnode;
    this->key = key;
    this->count = count;
    this->rightnode = rightnode;
}
/*
BSTNode::~BSTNode()
{
    if (leftnode != nullptr)
    {
        delete leftnode;
        leftnode = nullptr;
    }
    if (rightnode != nullptr)
    {
        delete rightnode;
        rightnode = nullptr;
    }
}
*/