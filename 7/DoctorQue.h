/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : DoctorQueTime.h Priority Que According to arrival time.
 */

#include "doctor.h" // definition of KeyedItem
typedef doctor HeapItemType1;

class DoctorQue
{
public:
    DoctorQue();
    bool empty() const;
    void heapInsert(const HeapItemType1& newItem);
    void heapDelete(HeapItemType1& rootItem);
    void heapRebuild(int root);
    int sizeOf();
    doctor top();
    void pop();
    void push(doctor push);

private:
    HeapItemType1* items;
    int size;
};
