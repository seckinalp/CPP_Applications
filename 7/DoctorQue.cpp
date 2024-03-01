/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : DoctorQue.cpp - it uses bool operator < of doctor for achieving min heap priority que according to arrival time.
 */

#include "DoctorQue.h"
DoctorQue::DoctorQue() : size(0)
{
    items = new HeapItemType1[1000];
}

bool DoctorQue::empty() const
{
    return (size == 0);
}
void DoctorQue::heapInsert(const HeapItemType1& newItem)
{

    if (size >= 1000)
    {
    }
    items[size] = newItem;
    int place = size;
    int parent = (place - 1) / 2;
    while ((place > 0) && (items[parent] < items[place]))
    {
        HeapItemType1 temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    ++size;
}
void DoctorQue::heapRebuild(int root)
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
            HeapItemType1 temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            heapRebuild(child);
        }
    }
}
void DoctorQue::heapDelete(HeapItemType1& rootItem)
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

int DoctorQue::sizeOf()
{
    return size;
}
doctor DoctorQue::top()
{
    return items[0];
}
void DoctorQue::pop()
{
    heapDelete(items[0]);
}

void DoctorQue::push(doctor push)
{
    heapInsert(push);
}