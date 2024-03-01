/**
 * Title: Hash Tables
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 4
 * Description: HashTable.h
 */

#include "KmerNode.h"
using namespace std;

class HashTable
{

public:
    int hashTableSize;
    int kValue;
    vector<string> printingKmers;
    string dataText;
    vector<int> beginningIndexes;
    KmerNode **hashTable;
    HashTable(int hashTableSize);
    ~HashTable();
    KmerNode *findKmer_chain(std::string kmer);
    void addKmer_chain(std::string kmer, int position);
    void fillHashTable_chain(std::string filename, int k);
    void addKmer_quadratic(std::string kmer, int position);
    KmerNode *findKmer_quadratic(std::string kmer);
    void fillHashTable_quadratic(std::string filename, int k);
    void go_to_positions(std::string inputFileName, int range, KmerNode *found);
    void printAll();
};
