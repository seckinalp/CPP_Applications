/**
 * Title: Hash Tables
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 4
 * Description: main.cpp
 */

/*
    In dijsktra server I get this:
    Time taken for findKmer_chain: 0.0140000000000000002914335439641035918612 ms
    Time taken for findKmer_quadratic: 0.0020000000000000000416333634234433702659 ms

    The way that findKmer_chain (which uses separate chaining) and findKmer_quadratic (which uses quadratic probing)
    handle collisions in a hash table is the main cause of the differences in their execution speeds.
    If multiple elements hash to the same index, separate chaining may result in slower search times
    by storing colliding elements in a linked list at each index. In contrast, quadratic probing uses
    a quadratic function to locate new indices for collisions and saves elements directly in the table.
    This frequently leads to more efficient searches, particularly when the hash function is well-distributed
    and the load factor is low. Quadratic probing may have more consistent and predictable memory access patterns
    than separate chaining, which can experience longer traversal times in linked lists.The load factor, use case specifics,
    and consistency of the hash function are some of the criteria that influence which of these approaches is best.

*/
#include "HashTable.h"
#include <iostream>
#include <chrono>
#include <cstdio>

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        std::cout << "There is missing arguments!!" << endl;
    }
    else
    {
        string textName = argv[1];
        int kmerSize = atoi(argv[2]);

        HashTable hashTable_Chain(7);
        HashTable hashTable_Quadratic(71);

        hashTable_Chain.fillHashTable_chain(textName, kmerSize);
        hashTable_Quadratic.fillHashTable_quadratic(textName, kmerSize);

        clock_t start = clock();
        KmerNode *x = hashTable_Chain.findKmer_chain("bup");
        cout << x->kmer;
        clock_t end = clock();
        double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
        printf("Time taken for findKmer_chain: %.40f ms\n", duration);

        start = clock();
        KmerNode *y = hashTable_Quadratic.findKmer_quadratic("bup");
        cout << y->kmer;
        end = clock();
        duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
        printf("Time taken for findKmer_quadratic: %.40f ms\n", duration);
    }
    return 0;
}
