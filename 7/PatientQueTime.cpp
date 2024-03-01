/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : PatientQueTime.cpp
 */
#include "PatientQueTime.h"
#include <iostream>
PatientQueTime::PatientQueTime() : size(0)
{
    items = new HeapItemType[1000];
}

bool PatientQueTime::empty() const
{
    return (size == 0);
}
void PatientQueTime::heapInsert(const HeapItemType& newItem)
{
    if (size >= 1000)
    {
    }
    items[size] = newItem;
    int place = size;
    int parent = (place - 1) / 2;
    while ((place > 0) && (items[place].number < items[parent].number))
    {
        HeapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    ++size;
}

void PatientQueTime::heapRebuild(int root)
{
    int child = 2 * root + 1;
    if (child < size)
    {
        int rightChild = child + 1;
        if ((rightChild < size) &&
            (items[child].number > items[rightChild].number))
            child = rightChild;
        if (items[root].number > items[child].number)
        {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            heapRebuild(child);
        }
    }
}
void PatientQueTime::heapDelete(HeapItemType& rootItem)
{
    if (empty())
    {
    }
    else
    {
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

int PatientQueTime::sizeOf()
{
    return size;
}
patient PatientQueTime::top()
{
    return items[0];
}
void PatientQueTime::pop()
{
    heapDelete(items[0]);
}

void PatientQueTime::push(patient push)
{
    heapInsert(push);
}
