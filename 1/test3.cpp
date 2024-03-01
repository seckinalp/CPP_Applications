/**
 * Title: Algorithm analysis & Sorting
 * Author : Seçkin Alp Kargı
 * ID: 22001942
 * Section : 1
 * Homework : 1
 * Description : description of your code
 */

// mingw32-make
#include <iostream>
#include <cstdlib>
#include <ctime>

void swapping(int *arr, int x, int y, int &moveCount)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    moveCount = moveCount + 3;
}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount)
{
    bool sorted = false;

    for (int pass = 1; (pass < size) && !sorted; pass++)
    {
        sorted = true;
        for (int index = 0; index < size - pass; index++)
        {
            int nextIndex = index + 1;
            if (arr[index] > arr[nextIndex])
            {

                swapping(arr, index, nextIndex, moveCount);
                sorted = false;
            }
            compCount++;
        }
    }
}

int indexOfLargest(int *arr, int size, int &compCount)
{
    int indexsofar = 0;
    for (int current = 1; current < size; ++current)
    {
        if (arr[current] > arr[indexsofar])
        {

            indexsofar = current;
        }
        ++compCount;
    }
    return indexsofar;
}
void selectionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    for (int i = size - 1; i >= 1; --i)
    {
        int largest = indexOfLargest(arr, i + 1, compCount);

        swapping(arr, largest, i, moveCount);
    }
}

void insertionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    for (int i = 1; i < size; i++)
    {
        int nextNumber = arr[i];
        moveCount++;
        int index = i;
        for (; (index > 0) && (arr[index - 1] > nextNumber); --index)
        {
            compCount++;
            moveCount++;
            arr[index] = arr[index - 1];
        }
        arr[index] = nextNumber;
        moveCount++;
    }
}
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount)
{
    int temparr[last];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        if (arr[first1] < arr[first2])
        {
            moveCount++;
            temparr[index] = arr[first1];
            ++first1;
        }
        else
        {
            moveCount++;
            temparr[index] = arr[first2];
            ++first2;
        }
        compCount++;
    }

    for (; first1 <= last1; ++first1, ++index)
    {
        moveCount++;
        temparr[index] = arr[first1];
    }

    for (; first2 <= last2; ++first2, ++index)
    {
        moveCount++;
        temparr[index] = arr[first2];
    }

    for (index = first; index <= last; ++index)
    {
        moveCount++;
        arr[index] = temparr[index];
    }
}

void mergeSort(int *arr, const int size, const int first, int &compCount, int &moveCount)
{

    if (first < size)
    {
        int mid = (first + size) / 2;
        mergeSort(arr, mid, first, compCount, moveCount);
        mergeSort(arr, size, mid + 1, compCount, moveCount);
        merge(arr, first, mid, size, compCount, moveCount);
    }
}

void mergeSort2(int *arr, const int size, const int first, int &compCount, int &moveCount)
{

    if (first < size)
    {

        if (size > 20)
        {
            int mid = (first + size) / 2;
            mergeSort2(arr, mid, first, compCount, moveCount);
            mergeSort2(arr, size, mid + 1, compCount, moveCount);
            merge(arr, first, mid, size, compCount, moveCount);
        }
        else
        {
            bubbleSort(arr, size, compCount, moveCount);
        }
    }
}

void partition(int *arr, int first, int last, int &pivotindex, int &compCount, int &moveCount)
{

    int pivot = arr[first];
    moveCount++;
    int lastS1 = first;
    int firstUnknown = first + 1;

    for (; firstUnknown <= last; ++firstUnknown)
    {
        if (arr[firstUnknown] < pivot)
        {
            ++lastS1;
            swapping(arr, firstUnknown, lastS1, moveCount);
        }
        compCount++;
    }

    swapping(arr, first, lastS1, moveCount);
    pivotindex = lastS1;
}

void quickSort(int *arr, const int size, const int first, int &compCount, int &moveCount)
{
    int pivotindex;

    if (first < size)
    {
        partition(arr, first, size, pivotindex, compCount, moveCount);
        quickSort(arr, pivotindex - 1, first, compCount, moveCount);
        quickSort(arr, size, pivotindex + 1, compCount, moveCount);
    }
}

void hybridSort(int *arr, const int size, const int first, int &compCount, int &moveCount)
{

    if (first < size)
    {

        if (size > 20)
        {
            mergeSort2(arr, size - 1, first, compCount, moveCount);
        }
        else
        {
            bubbleSort(arr, size, compCount, moveCount);
        }
    }
}
/*
void printArray(int *arr, const int size, int &compCount, int &moveCount)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << "comp: " << compCount << " move: " << moveCount << std::endl;
    std::cout << std::endl;
}
*/
int main(int argc, char const *argv[])
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int x = 0;
    int c1 = 0;
    int m1 = 0;
    int c3 = 0;
    int m3 = 0;
    int c2 = 0;
    int m2 = 0;
    int c4 = 0;
    int m4 = 0;
    int c5 = 0;
    int m5 = 0;
    int *a1000 = new int[1000];
    int *b1000 = new int[1000];
    int *c1000 = new int[1000];
    int *d1000 = new int[1000];
    int *e1000 = new int[1000];

    for (int i = 0; i < 1000; ++i)
    {
        x = rand();
        a1000[i] = x;
        b1000[i] = x;
        c1000[i] = x;
        d1000[i] = x;
        e1000[i] = x;
    }
    clock_t start1 = clock();
    insertionSort(a1000, 1000, c1, m1);
    clock_t end1 = clock();

    selectionSort(b1000, 1000, c2, m2);
    clock_t end2 = clock();

    mergeSort(c1000, 999, 0, c3, m3);
    clock_t end3 = clock();

    quickSort(d1000, 999, 0, c4, m4);
    clock_t end4 = clock();

    hybridSort(e1000, 1000, 0, c5, m5);
    clock_t end5 = clock();

    double duration1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
    double duration2 = static_cast<double>(end2 - end1) / CLOCKS_PER_SEC;
    double duration3 = static_cast<double>(end3 - end2) / CLOCKS_PER_SEC;
    double duration4 = static_cast<double>(end4 - end3) / CLOCKS_PER_SEC;
    double duration5 = static_cast<double>(end5 - end4) / CLOCKS_PER_SEC;
    printf("Part 2-b-1: Performance analysis of random integers array\n");
    printf("Array Size: 1000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration1, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration2, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration3, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration4, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration5, c5, m5);
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    c5 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;
    int *a5000 = new int[5000];
    int *b5000 = new int[5000];
    int *c5000 = new int[5000];
    int *d5000 = new int[5000];
    int *e5000 = new int[5000];

    for (int i = 0; i < 5000; ++i)
    {
        srand((int)time(NULL));
        x = rand();
        a5000[i] = x;
        b5000[i] = x;
        c5000[i] = x;
        d5000[i] = x;

        e5000[i] = x;
    }

    clock_t start11 = clock();
    insertionSort(a5000, 5000, c1, m1);
    clock_t end11 = clock();

    clock_t start21 = clock();
    selectionSort(b5000, 5000, c2, m2);
    clock_t end21 = clock();

    clock_t start31 = clock();
    mergeSort(c5000, 4999, 0, c3, m3);
    clock_t end31 = clock();

    clock_t start41 = clock();
    quickSort(d5000, 4999, 0, c4, m4);
    clock_t end41 = clock();

    clock_t start51 = clock();
    hybridSort(e5000, 5000, 0, c5, m5);
    clock_t end51 = clock();

    double duration11 = static_cast<double>(end11 - start11) / CLOCKS_PER_SEC;
    double duration21 = static_cast<double>(end21 - start21) / CLOCKS_PER_SEC;
    double duration31 = static_cast<double>(end31 - start31) / CLOCKS_PER_SEC;
    double duration41 = static_cast<double>(end41 - start41) / CLOCKS_PER_SEC;
    double duration51 = static_cast<double>(end51 - start51) / CLOCKS_PER_SEC;
    printf("Array Size: 5000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration11, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration21, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration31, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration41, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration51, c5, m5);
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    c5 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;
    int *a10000 = new int[10000];
    int *b10000 = new int[10000];
    int *c10000 = new int[10000];
    int *d10000 = new int[10000];
    int *e10000 = new int[10000];

    for (int i = 0; i < 10000; ++i)
    {
        srand((int)time(NULL));
        x = rand();
        a10000[i] = x;
        b10000[i] = x;
        c10000[i] = x;
        d10000[i] = x;
        e10000[i] = x;
    }

    clock_t start12 = clock();
    insertionSort(a10000, 10000, c1, m1);
    clock_t end12 = clock();

    clock_t start22 = clock();
    selectionSort(b10000, 10000, c2, m2);
    clock_t end22 = clock();

    clock_t start32 = clock();
    mergeSort(c10000, 9999, 0, c3, m3);
    clock_t end32 = clock();

    clock_t start42 = clock();
    quickSort(d10000, 9999, 0, c4, m4);
    clock_t end42 = clock();

    clock_t start52 = clock();
    hybridSort(e10000, 10000, 0, c5, m5);
    clock_t end52 = clock();

    double duration12 = static_cast<double>(end12 - start12) / CLOCKS_PER_SEC;
    double duration22 = static_cast<double>(end22 - start22) / CLOCKS_PER_SEC;
    double duration32 = static_cast<double>(end32 - start32) / CLOCKS_PER_SEC;
    double duration42 = static_cast<double>(end42 - start42) / CLOCKS_PER_SEC;
    double duration52 = static_cast<double>(end52 - start52) / CLOCKS_PER_SEC;
    printf("Array Size: 10000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration12, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration22, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration32, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration42, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration52, c5, m5);
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    c5 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;
    int *a20000 = new int[20000];
    int *b20000 = new int[20000];
    int *c20000 = new int[20000];
    int *d20000 = new int[20000];
    int *e20000 = new int[20000];

    for (int i = 0; i < 20000; ++i)
    {
        srand((int)time(NULL));
        x = rand();
        a20000[i] = x;
        b20000[i] = x;
        c20000[i] = x;
        d20000[i] = x;
        e20000[i] = x;
    }
    clock_t start13 = clock();
    insertionSort(a20000, 20000, c1, m1);
    clock_t end13 = clock();

    clock_t start23 = clock();
    selectionSort(b20000, 20000, c2, m2);
    clock_t end23 = clock();

    clock_t start33 = clock();
    mergeSort(c20000, 19999, 0, c3, m3);
    clock_t end33 = clock();

    clock_t start43 = clock();
    quickSort(d20000, 19999, 0, c4, m4);
    clock_t end43 = clock();

    clock_t start53 = clock();
    hybridSort(e20000, 20000, 0, c5, m5);
    clock_t end53 = clock();

    double duration13 = static_cast<double>(end13 - start13) / CLOCKS_PER_SEC;
    double duration23 = static_cast<double>(end23 - start23) / CLOCKS_PER_SEC;
    double duration33 = static_cast<double>(end33 - start33) / CLOCKS_PER_SEC;
    double duration43 = static_cast<double>(end43 - start43) / CLOCKS_PER_SEC;
    double duration53 = static_cast<double>(end53 - start53) / CLOCKS_PER_SEC;

    printf("Array Size: 20000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration13, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration23, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration33, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration43, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration53, c5, m5);

    delete[] a1000;
    delete[] b1000;
    delete[] c1000;
    delete[] d1000;
    delete[] e1000;

    delete[] a5000;
    delete[] b5000;
    delete[] c5000;
    delete[] d5000;
    delete[] e5000;

    delete[] a10000;
    delete[] b10000;
    delete[] c10000;
    delete[] d10000;
    delete[] e10000;

    delete[] a20000;
    delete[] b20000;
    delete[] c20000;
    delete[] d20000;
    delete[] e20000;
    return 0;
}
