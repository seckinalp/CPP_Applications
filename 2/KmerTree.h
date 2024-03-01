/**
 * Title: Binary Search Trees
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 2
 * Description: KmerTree.h
 */

#include "BST.h"
#include <vector>
using namespace std;
class KmerTree
{
private:
    void increaseCount(BSTNode *node, string key);
    bool checkExistence(BSTNode *node, string key);
    vector<string> inorderTraversalCount(BSTNode *node, vector<string> result);
    int counter(BSTNode *node);
    int counter2(BSTNode *node, char ch);
    int counter3(BSTNode *node);
    int kNumber;

public:
    KmerTree(/* args */);
    ~KmerTree();
    BST *tree;
    void addKmer(string kmer);
    void printAll();
    int getUniqueKmerCount();
    int getNumberOfKmerThatStartWith(char ch);
    int getHeight();
    void generateTree(string fileName, int k);
    void searchTreeDelete(string deleteKmer);
    void inorderTraverse(vector<string> &vec);
};
