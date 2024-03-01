/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : PatientQue.h it uses patient < operator for buildiing heap based priority que.
 */

const int MAX_HEAP = 1000;
#include "patient.h"
typedef patient HeapItemType;

class PatientQue
{
public:
    PatientQue();
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
