
/**
 * Title: Binary Search Trees
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 2
 * Description: KmerTree.cpp
 */
#include "KmerTree.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
KmerTree::KmerTree(/* args */)
{
    tree = new BST();
}

KmerTree::~KmerTree()
{
    delete tree;
}

void KmerTree::searchTreeDelete(string deleteKmer)
{
    tree->searchTreeDelete(deleteKmer);
}
void KmerTree::inorderTraverse(vector<string> &vec)
{
    vec = tree->inorderTraversal(tree->node);
    for (auto &key : vec)
    {
        string change = key.substr(0, kNumber);
        key = change;
    }
}
void KmerTree::addKmer(string kmer)
{
    if (checkExistence(tree->node, kmer) == true)
    {
        increaseCount(tree->node, kmer);
    }
    else
    {
        tree->searchTreeInsert(kmer);
    }
}

bool KmerTree::checkExistence(BSTNode *node, string key)
{
    if (node == nullptr)
    {
        return false;
    }
    else if (node->key == key)
    {
        return true;
    }
    else if (key > node->key)
    {
        return (checkExistence(node->rightnode, key));
    }
    else if (key < node->key)
    {
        return (checkExistence(node->leftnode, key));
    }
    return false;
}

void KmerTree::increaseCount(BSTNode *node, string key)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->key == key)
    {
        node->count++;
    }
    else if (key > node->key)
    {
        increaseCount(node->rightnode, key);
    }
    else if (key < node->key)
    {
        increaseCount(node->leftnode, key);
    }
}

vector<string> KmerTree::inorderTraversalCount(BSTNode *node, vector<string> result)

{
    if (node == nullptr)
    {
        return result;
    }
    result = inorderTraversalCount(node->leftnode, result);
    string push = to_string(node->count);
    result.push_back(push);
    result = inorderTraversalCount(node->rightnode, result);
    return result;
}

void KmerTree::printAll()
{
    std::vector<std::string> keys = tree->inorderTraversal(tree->node);
    std::vector<std::string> counts2;
    std::vector<std::string> counts = inorderTraversalCount(tree->node, counts2);
    for (int i = 0; i < keys.size(); ++i)
    {
        std::cout << "        " << keys[i] << ", frequency = " << counts[i] << std::endl;
    }
}

int KmerTree::getUniqueKmerCount()
{
    return counter(tree->node);
}

int KmerTree::counter(BSTNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int count = 1;

    count += counter(node->rightnode);
    count += counter(node->leftnode);
    return count;
}

int KmerTree::getNumberOfKmerThatStartWith(char ch)
{
    return counter2(tree->node, ch);
}

int KmerTree::counter2(BSTNode *node, char ch)
{
    if (node == nullptr)
    {
        return 0;
    }
    int count = 0;
    if (node->key[0] == ch)
    {
        count = 1;
    }
    count += counter2(node->leftnode, ch);
    count += counter2(node->rightnode, ch);
    return count;
}

int KmerTree::getHeight()
{
    return counter3(tree->node);
}

int KmerTree::counter3(BSTNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int a = 0;
    int b = 0;

    a += counter3(node->rightnode);
    b += counter3(node->leftnode);

    if (a > b)
    {
        return a + 1;
    }
    else
    {
        return b + 1;
    }
}

void KmerTree::generateTree(string fileName, int k)
{
    kNumber = k;
    ifstream text(fileName);
    if (text.is_open() == false)
    {
        return;
    }
    stringstream bf;
    bf << text.rdbuf();
    string textt = bf.str();
    text.close();
    int leng = textt.length();

    if (k > leng)
    {
        return;
    }

    int remainder = leng % k;

    for (int i = 0; i < leng - remainder; i += k)
    {
        string str = textt.substr(i, k);
        for (int i = 0; i < k; i++)
        {
            str[i] = tolower(str[i]);
        }
        addKmer(str);
    }
}