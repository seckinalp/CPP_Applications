/**
 * Title: Binary Search Trees
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 2
 * Description: main.cpp
 */
#include <vector>
#include <iostream>
#include "KmerTree.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
// g++ KmerTree.cpp BST.cpp BSTNode.cpp main.cpp -o main
using namespace std;
void timeAnalysis(string inputfilename, int k)
{
    KmerTree *kmrtree = new KmerTree();
    ifstream text(inputfilename);
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
    int count = 1;
    clock_t start = clock();
    clock_t end = clock();
    for (int i = 0; i < leng - remainder; i += k)
    {
        string str = textt.substr(i, k);
        for (int i = 0; i < k; i++)
        {
            str[i] = tolower(str[i]);
        }
        kmrtree->addKmer(str);
        if (count == 1000 || count == 2000 || count == 3000 || count == 4000 || count == 5000 || count == 6000 || count == 7000 || count == 8000 || count == 9000 || count == 10000 || count == 11000 || count == 12000 || count == 13000 || count == 14000 || count == 15000)
        {
            end = clock();
            int u = kmrtree->getUniqueKmerCount();
            int h = kmrtree->getHeight();

            double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            cout << "Number of Addition: " << count << " Number of unique kmers: " << u << "\nHeight of BST: " << h << "\nTime taken: " << duration << endl;
            start = clock();
        }
        count++;
    }
    delete kmrtree;
}

int main(int argc, char *argv[])
{

    timeAnalysis("45000.txt", 3);
    timeAnalysis("45000.txt", 9);
    timeAnalysis("3sorted.txt", 3);
    timeAnalysis("9sorted.txt", 9);
    return 0;
}