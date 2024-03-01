/**
 * Title: Hash Tables
 * Author: Seçkin Alp Kargı
 * ID: 22001942
 * Section: 1
 * Homework: 4
 * Description: HashTable.cpp
 */

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

HashTable::HashTable(int hashTableSize)
{
    this->hashTableSize = hashTableSize;
    hashTable = new KmerNode *[hashTableSize]();
}

HashTable::~HashTable()
{
    for (int i = 0; i < hashTableSize; i++)
    {

        KmerNode *current = hashTable[i];

        while (current != nullptr)
        {

            KmerNode *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] hashTable;
}

KmerNode *HashTable::findKmer_chain(std::string kmer)
{
    int hash = 0;

    for (char letter : kmer)
    {
        hash = hash + static_cast<int>(letter);
    }

    hash = hash % hashTableSize;

    KmerNode *tempkmer = hashTable[hash];

    while (tempkmer != nullptr)
    {
        if (kmer == tempkmer->kmer)
        {
            return tempkmer;
        }
        else
        {
            tempkmer = tempkmer->next;
        }
    }

    return nullptr;
}

void HashTable::addKmer_chain(std::string kmer, int position)
{
    int hash = 0;

    for (char letter : kmer)
    {
        hash = hash + static_cast<int>(letter);
    }

    hash = hash % hashTableSize;

    KmerNode *tempkmer = new KmerNode(kmer, nullptr);

    tempkmer->startingPosition.push_back(position);

    if (hashTable[hash] == nullptr)
    {

        hashTable[hash] = tempkmer;
    }
    else
    {
        KmerNode *addkmer = hashTable[hash];

        while (true)
        {
            if (kmer == addkmer->kmer)
            {
                addkmer->startingPosition.push_back(position);

                return;
            }
            if (addkmer->next == nullptr)
            {
                addkmer->next = tempkmer;
                return;
            }
            addkmer = addkmer->next;
        }
    }
}

void HashTable::fillHashTable_chain(std::string filename, int k)
{
    kValue = k;
    std::ifstream file(filename);
    if (file.is_open())
    {
        string text;
        string row;
        while (getline(file, row))
        {
            text = text + row;
        }
        dataText = text;
        for (char &chartolow : text)
        {
            chartolow = tolower(chartolow);
        }
        int correctedLength = text.length() - 1;
        while (correctedLength % k == 0)
        {
            correctedLength = correctedLength - 1;
        }
        for (int i = 0; i <= correctedLength; i = i + k)
        {
            std::string kmer = text.substr(i, k);

            if (find(printingKmers.begin(), printingKmers.end(), kmer) == printingKmers.end())
            {
                printingKmers.push_back(kmer);
            }

            addKmer_chain(kmer, i);
        }
    }
    else
    {
        cout << "Can not access the data file!" << endl;
    }
    file.close();
}
void HashTable::addKmer_quadratic(std::string kmer, int position)
{
    int hash = 0;
    int i = 0;
    for (char letter : kmer)
    {
        hash = hash + static_cast<int>(letter);
    }

    hash = hash % hashTableSize;
    int originalHash = hash;

    KmerNode *tempkmer = new KmerNode(kmer, nullptr);
    tempkmer->startingPosition.push_back(position);

    while (true)
    {
        if (hashTable[hash] == nullptr)
        {
            hashTable[hash] = tempkmer;
            break;
        }
        else if (kmer == hashTable[hash]->kmer)
        {
            hashTable[hash]->startingPosition.push_back(position);
            delete tempkmer;
            break;
        }
        else
        {
            i++;
            hash = (originalHash + i * i) % hashTableSize;
            if (i >= hashTableSize)
            {
                delete tempkmer;
                return;
            }
        }
    }
}

KmerNode *HashTable::findKmer_quadratic(std::string kmer)
{
    int hash = 0;
    int i = 0;
    for (char letter : kmer)
    {
        hash = hash + static_cast<int>(letter);
    }

    hash = hash % hashTableSize;
    int finalHash = hash;

    while (hashTable[finalHash] != nullptr)
    {
        i++;
        if (kmer == hashTable[finalHash]->kmer)
        {

            return hashTable[finalHash];
        }

        finalHash = (i * i + hash) % hashTableSize;
    }

    return nullptr;
}
void HashTable::fillHashTable_quadratic(std::string filename, int k)
{
    kValue = k;
    std::ifstream file(filename);

    if (file.is_open())
    {
        string text;
        string row;
        while (getline(file, row))
        {
            text = text + row;
        }
        dataText = text;
        for (char &chartolow : text)
        {
            chartolow = tolower(chartolow);
        }
        int correctedLength = text.length() - 1;
        while (correctedLength % k == 0)
        {
            correctedLength = correctedLength - 1;
        }
        for (int i = 0; i <= correctedLength; i = i + k)
        {
            std::string kmer = text.substr(i, k);
            if (find(printingKmers.begin(), printingKmers.end(), kmer) == printingKmers.end())
            {
                printingKmers.push_back(kmer);
            }
            addKmer_quadratic(kmer, i);
        }
    }
    else
    {
        cout << "Can not access the data file!" << endl;
    }
    file.close();
}
void HashTable::go_to_positions(std::string inputFileName, int range, KmerNode *found)
{
    ifstream file(inputFileName);

    if (found != nullptr)
    {
        if (file.is_open())
        {
            string text;
            string row;

            while (getline(file, row))
            {
                text = text + row;
            }

            for (int index : found->startingPosition)
            {

                if (text.length() > index + range)
                {
                    std::cout << "-> " << text.substr(index, found->kmer.length() + range) << " (generated from position " << index << ")\n";
                }
            }
        }
        else
        {
            cout << "File could not be opened.\n";
        }
    }
    else
    {
        cout << "kmerNode is nullptr!\n";
    }
    file.close();
}

void HashTable::printAll()
{
    if (hashTableSize == 71)
    {

        cout << "Input text = \"" << dataText << "\"" << endl;
        cout << "-> All of the " << kValue << "-mers generated from this text should be as follows:" << endl;
        bool check = false;
        for (const std::string &kmerr : printingKmers)
        {
            if (check)
            {
                std::cout << ", ";
            }
            check = true;
            cout << "'" << kmerr << "'";
        }

        cout << endl;
        cout << "-> The positions of the k-mers:" << endl;
        check = false;
        int size = printingKmers.size();
        for (int i = 0; i < size; i++)
        {

            string kmer = printingKmers.front();
            printingKmers.erase(printingKmers.begin());
            vector<int> places = findKmer_quadratic(kmer)->startingPosition;
            if (check)
            {
                cout << ", ";
            }
            cout << kmer << ": (";
            check = true;

            for (int m = 0; m < places.size(); m++)
            {
                cout << places[m];

                if (m < places.size() - 1)
                {
                    cout << ", ";
                }
            }
            std::cout << ")";
        }
        std::cout << endl;
    }
    else
    {
        cout << "Input text = \"" << dataText << "\"" << endl;
        cout << "-> All of the " << kValue << "-mers generated from this text should be as follows:" << endl;
        bool check = false;
        for (const std::string &kmerr : printingKmers)
        {
            if (check)
            {
                std::cout << ", ";
            }
            check = true;
            cout << "'" << kmerr << "'";
        }

        cout << endl;
        cout << "-> The positions of the k-mers:" << endl;
        check = false;
        int size = printingKmers.size();
        for (int i = 0; i < size; i++)
        {

            string kmer = printingKmers.front();
            printingKmers.erase(printingKmers.begin());
            vector<int> places = findKmer_chain(kmer)->startingPosition;
            if (check)
            {
                cout << ", ";
            }
            cout << kmer << ": (";
            check = true;

            for (int m = 0; m < places.size(); m++)
            {
                cout << places[m];

                if (m < places.size() - 1)
                {
                    cout << ", ";
                }
            }
            std::cout << ")";
        }
        std::cout << endl;
    }
}