/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : PatientQueTime.h it uses patient number for buildiing heap based priority que according to arrival time.
 */

#include "patient.h"
typedef patient HeapItemType;

class PatientQueTime
{
public:
    PatientQueTime();
    bool empty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete(HeapItemType& rootItem);
    void heapRebuild(int root);
    int sizeOf();
    patient top();
    void pop();
    void push(patient push);

private:
    HeapItemType* items;
    int size;
};
