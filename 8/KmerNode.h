/**
 * Title: Hash Tables
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 4
 * Description: KmerNode.h
 */
#include <string>
using namespace std;
#include <vector>

class KmerNode
{

public:
    string kmer;
    vector<int> startingPosition;
    KmerNode *next;
    KmerNode(string kmer, KmerNode *next);
};
