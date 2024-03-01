/**
 * Title: Binary Search Trees
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 2
 * Description: BST.cpp
 */

#include "BST.h"
#include "iostream"
#include <vector>

BST::BST()
{
    node = nullptr;
}
BST::~BST()
{
    result.clear();
    cleantree(node);
}

void BST::cleantree(BSTNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    cleantree(node->leftnode);
    cleantree(node->rightnode);
    delete node;
}

void BST::searchTreeInsert(string key)
{
    node = searchTreeInsert2(node, key);
}

BSTNode *BST::searchTreeInsert2(BSTNode *node, string key)
{

    if (node == nullptr)
    {
        return (new BSTNode(key, 1, nullptr, nullptr));
    }
    else if (node->key > key)
    {
        node->leftnode = searchTreeInsert2(node->leftnode, key);
        return node;
    }
    else
    {
        node->rightnode = searchTreeInsert2(node->rightnode, key);
        return node;
    }
}

vector<string> BST::inorderTraversal(BSTNode *node)

{
    return inorderTraversal2(node, result);
}

vector<string> BST::inorderTraversal2(BSTNode *node, vector<string> result)

{
    if (node == nullptr)
    {
        return result;
    }
    result = inorderTraversal2(node->leftnode, result);
    string push = node->key;
    result.push_back(push);
    result = inorderTraversal2(node->rightnode, result);
    return result;
}

void BST::searchTreeDelete(string key)
{
    node = searchTreeDelete2(node, key);
}
BSTNode *BST::searchTreeDelete2(BSTNode *node, string key)
{

    if (node == nullptr)
    {
        return nullptr;
    }

    else if (node->key == key)
    {
        string key2;
        if (node->leftnode == nullptr && node->rightnode == nullptr)
        {
            delete node;
            node = nullptr;
            return nullptr;
        }
        else if (node->rightnode == nullptr)
        {
            BSTNode *temp = node;
            node = node->leftnode;
            temp->leftnode = nullptr;
            delete temp;
            return node;
        }

        else if (node->leftnode == nullptr)
        {
            BSTNode *temp = node;
            node = node->rightnode;
            temp->rightnode = nullptr;
            delete temp;
            return node;
        }
        else
        {
            leftfinder(node->rightnode, key2);
            node->key = key2;
            return node;
        }
    }

    else if (node->key > key)
    {
        node->leftnode = searchTreeDelete2(node->leftnode, key);
    }

    else
    {
        node->rightnode = searchTreeDelete2(node->rightnode, key);
    }
    return node;
}

void BST::leftfinder(BSTNode *&node, string &key)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->leftnode == nullptr)
    {
        key = node->key;
        BSTNode *temp = node;
        node = node->rightnode;
        temp->rightnode = nullptr;
        delete temp;
    }
    else
    {
        leftfinder(node->leftnode, key);
    }
}