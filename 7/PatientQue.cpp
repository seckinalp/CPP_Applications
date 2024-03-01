/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : PatientQue.cpp
 */
#include "PatientQue.h"
#include <iostream>
PatientQue::PatientQue() : size(0)
{
    items = new HeapItemType[MAX_HEAP];
}

bool PatientQue::empty() const
{
    return (size == 0);
}
void PatientQue::heapInsert(const patient& newItem)
{
    if (size >= MAX_HEAP)
    {
    }
    items[size] = newItem;
    int place = size;
    int parent = (place - 1) / 2;
    while ((place > 0) && (items[place].priority > items[parent].priority))
    {
        HeapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    ++size;
}

void PatientQue::heapRebuild(int root)
{
    int child = 2 * root + 1;
    if (child < size)
    {
        int rightChild = child + 1;
        if ((rightChild < size) &&
            (items[child] < items[rightChild]))
            child = rightChild;
        if (items[root] < items[child])
        {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            heapRebuild(child);
        }
    }
}
void PatientQue::heapDelete(HeapItemType& rootItem)
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

int PatientQue::sizeOf()
{
    return size;
}
patient PatientQue::top()
{
    return items[0];
}
void PatientQue::pop()
{
    heapDelete(items[0]);
}

void PatientQue::push(patient push)
{
    heapInsert(push);
}
