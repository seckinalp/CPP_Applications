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

void printArray(int *arr, const int size, int &compCount, int &moveCount)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << "comp: " << compCount << " move: " << moveCount << std::endl;
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
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
    /*
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

    delete[] a1000;
    delete[] b1000;
    delete[] c1000;
    delete[] d1000;
    delete[] e1000;

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

    delete[] a5000;
    delete[] b5000;
    delete[] c5000;
    delete[] d5000;
    delete[] e5000;

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

    delete[] a10000;
    delete[] b10000;
    delete[] c10000;
    delete[] d10000;
    delete[] e10000;

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

    delete[] a20000;
    delete[] b20000;
    delete[] c20000;
    delete[] d20000;
    delete[] e20000;
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
*/
    int *a1000x = new int[1000];
    int *b1000x = new int[1000];
    int *c1000x = new int[1000];
    int *d1000x = new int[1000];
    int *e1000x = new int[1000];

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

    int max = -2147483648;

    for (int i = 0; i < 100; i++)
    {
        for (int k = 0; k < 10; k++)
        {

            if (i == 0)
            {
                x = rand() - 1000000;
            }
            else
            {
                x = max + std::abs(rand());
            }

            int y = k + (i * 10);
            a1000x[y] = x;
            b1000x[y] = x;
            c1000x[y] = x;
            d1000x[y] = x;
            e1000x[y] = x;

            if (k % 9 == 0)
            {
                if (k != 0)
                {

                    max = -2147483648;
                    for (int a = i * 10; a <= (i * 10) + 9; a++)
                    {
                        if (a1000x[a] > max)
                        {
                            max = a1000x[a];
                        }
                    }
                }
            }
        }
    }

    clock_t start1x = clock();
    insertionSort(a1000x, 1000, c1, m1);
    clock_t end1x = clock();

    clock_t start2x = clock();
    selectionSort(b1000x, 1000, c2, m2);
    clock_t end2x = clock();

    clock_t start3x = clock();
    mergeSort(c1000x, 999, 0, c3, m3);
    clock_t end3x = clock();

    clock_t start4x = clock();
    quickSort(d1000x, 999, 0, c4, m4);
    clock_t end4x = clock();

    clock_t start5x = clock();
    hybridSort(e1000x, 1000, 0, c5, m5);
    clock_t end5x = clock();

    delete[] a1000x;
    delete[] b1000x;
    delete[] c1000x;
    delete[] d1000x;
    delete[] e1000x;

    double duration1x = static_cast<double>(end1x - start1x) / CLOCKS_PER_SEC;
    double duration2x = static_cast<double>(end2x - start2x) / CLOCKS_PER_SEC;
    double duration3x = static_cast<double>(end3x - start3x) / CLOCKS_PER_SEC;
    double duration4x = static_cast<double>(end4x - start4x) / CLOCKS_PER_SEC;
    double duration5x = static_cast<double>(end5x - start5x) / CLOCKS_PER_SEC;

    printf("\n");
    printf("\n");
    printf("Part 2-b-2: Performance analysis of partially ascending integers array\n");
    printf("Array Size: 1000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration1x, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration2x, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration3x, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration4x, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration5x, c5, m5);

    int *a5000x = new int[5000];
    int *b5000x = new int[5000];
    int *c5000x = new int[5000];
    int *d5000x = new int[5000];
    int *e5000x = new int[5000];

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

    max = -2147483648;

    for (int i = 0; i < 417; i++)
    {

        for (int k = 0; k < 12; k++)
        {
            if (i == 416 && k == 7)
            {
                i = 1000;
                k = 1000;
            }
            else
            {

                if (i == 0)
                {
                    x = rand() - 1000000;
                }
                else
                {
                    x = max + std::abs(rand());
                }

                int y = k + (i * 12);
                a5000x[y] = x;
                b5000x[y] = x;
                c5000x[y] = x;
                d5000x[y] = x;
                e5000x[y] = x;

                if (k % 11 == 0)
                {
                    if (k != 0)
                    {

                        max = -2147483648;
                        for (int a = i * 11; a <= (i * 11) + 10; a++)
                        {
                            if (a5000x[a] > max)
                            {
                                max = a5000x[a];
                            }
                        }
                    }
                }
            }
        }
    }
    clock_t start11x = clock();
    insertionSort(a5000x, 5000, c1, m1);
    clock_t end11x = clock();

    clock_t start21x = clock();
    selectionSort(b5000x, 5000, c2, m2);
    clock_t end21x = clock();

    clock_t start31x = clock();
    mergeSort(c5000x, 4999, 0, c3, m3);
    clock_t end31x = clock();

    clock_t start41x = clock();
    quickSort(d5000x, 4999, 0, c4, m4);
    clock_t end41x = clock();

    clock_t start51x = clock();
    hybridSort(e5000x, 5000, 0, c5, m5);
    clock_t end51x = clock();

    delete[] a5000x;
    delete[] b5000x;
    delete[] c5000x;
    delete[] d5000x;
    delete[] e5000x;

    double duration11x = static_cast<double>(end11x - start11x) / CLOCKS_PER_SEC;
    double duration21x = static_cast<double>(end21x - start21x) / CLOCKS_PER_SEC;
    double duration31x = static_cast<double>(end31x - start31x) / CLOCKS_PER_SEC;
    double duration41x = static_cast<double>(end41x - start41x) / CLOCKS_PER_SEC;
    double duration51x = static_cast<double>(end51x - start51x) / CLOCKS_PER_SEC;
    printf("Array Size: 5000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration11x, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration21x, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration31x, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration41x, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration51x, c5, m5);
    int *a10000x = new int[10000];
    int *b10000x = new int[10000];
    int *c10000x = new int[10000];
    int *d10000x = new int[10000];
    int *e10000x = new int[10000];
    c2 = 0;
    c1 = 0;
    c3 = 0;
    c4 = 0;
    c5 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;

    max = -2147483648;

    for (int i = 0; i < 770; i++)
    {

        for (int k = 0; k < 13; k++)
        {
            if (i == 769 && k == 4)
            {
                i = 1000;
                k = 1000;
            }
            else
            {

                if (i == 0)
                {
                    x = rand() - 1000000;
                }
                else
                {
                    x = max + std::abs(rand());
                }

                int y = k + (i * 13);
                a10000x[y] = x;
                b10000x[y] = x;
                c10000x[y] = x;
                d10000x[y] = x;
                e10000x[y] = x;

                if (k % 12 == 0)
                {
                    if (k != 0)
                    {

                        max = -2147483648;
                        for (int a = i * 13; a <= (i * 13) + 12; a++)
                        {
                            if (a10000x[a] > max)
                            {
                                max = a10000x[a];
                            }
                        }
                    }
                }
            }
        }
    }

    clock_t start12x = clock();
    insertionSort(a10000x, 10000, c1, m1);
    clock_t end12x = clock();

    clock_t start22x = clock();
    selectionSort(b10000x, 10000, c2, m2);
    clock_t end22x = clock();

    clock_t start32x = clock();
    mergeSort(c10000x, 9999, 0, c3, m3);
    clock_t end32x = clock();

    clock_t start42x = clock();
    quickSort(d10000x, 9999, 0, c4, m4);
    clock_t end42x = clock();

    clock_t start52x = clock();
    hybridSort(e10000x, 10000, 0, c5, m5);
    clock_t end52x = clock();

    delete[] a10000x;
    delete[] b10000x;
    delete[] c10000x;
    delete[] d10000x;
    delete[] e10000x;
    int *a20000x = new int[20000];
    int *b20000x = new int[20000];
    int *c20000x = new int[20000];
    int *d20000x = new int[20000];
    int *e20000x = new int[20000];
    double duration12x = static_cast<double>(end12x - start12x) / CLOCKS_PER_SEC;
    double duration22x = static_cast<double>(end22x - start22x) / CLOCKS_PER_SEC;
    double duration32x = static_cast<double>(end32x - start32x) / CLOCKS_PER_SEC;
    double duration42x = static_cast<double>(end42x - start42x) / CLOCKS_PER_SEC;
    double duration52x = static_cast<double>(end52x - start52x) / CLOCKS_PER_SEC;
    printf("Array Size: 10000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration12x, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration22x, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration32x, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration42x, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration52x, c5, m5);

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

    max = -2147483648;
    for (int i = 0; i < 1429; i++)
    {

        for (int k = 0; k < 14; k++)
        {
            if (i == 1728 && k == 8)
            {
                i = 2000;
                k = 1000;
            }
            else
            {

                if (i == 0)
                {
                    x = rand() - 1000000;
                }
                else
                {
                    x = max + std::abs(rand());
                }

                int y = k + (i * 14);
                a20000x[y] = x;
                b20000x[y] = x;
                c20000x[y] = x;
                d20000x[y] = x;
                e20000x[y] = x;

                if (k % 13 == 0)
                {
                    if (k != 0)
                    {

                        max = -2147483648;
                        for (int a = i * 14; a <= (i * 14) + 13; a++)
                        {
                            if (a20000x[a] > max)
                            {
                                max = a20000x[a];
                            }
                        }
                    }
                }
            }
        }
    }
    clock_t start13x = clock();
    insertionSort(a20000x, 20000, c1, m1);
    clock_t end13x = clock();

    clock_t start23x = clock();
    selectionSort(b20000x, 20000, c2, m2);
    clock_t end23x = clock();

    clock_t start33x = clock();
    mergeSort(c20000x, 19999, 0, c3, m3);
    clock_t end33x = clock();

    clock_t start43x = clock();
    quickSort(d20000x, 19999, 0, c4, m4);
    clock_t end43x = clock();

    clock_t start53x = clock();
    hybridSort(e20000x, 20000, 0, c5, m5);
    clock_t end53x = clock();

    delete[] a20000x;
    delete[] b20000x;
    delete[] c20000x;
    delete[] d20000x;
    delete[] e20000x;
    double duration13x = static_cast<double>(end13x - start13x) / CLOCKS_PER_SEC;
    double duration23x = static_cast<double>(end23x - start23x) / CLOCKS_PER_SEC;
    double duration33x = static_cast<double>(end33x - start33x) / CLOCKS_PER_SEC;
    double duration43x = static_cast<double>(end43x - start43x) / CLOCKS_PER_SEC;
    double duration53x = static_cast<double>(end53x - start53x) / CLOCKS_PER_SEC;

    printf("Array Size: 20000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration13x, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration23x, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration33x, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration43x, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration53x, c5, m5);

    int *a1000y = new int[1000];
    int *b1000y = new int[1000];
    int *c1000y = new int[1000];
    int *d1000y = new int[1000];
    int *e1000y = new int[1000];

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

    int min = 2147483647;

    for (int i = 0; i < 100; i++)
    {
        for (int k = 0; k < 10; k++)
        {

            if (i == 0)
            {
                x = rand() + 1000000;
            }
            else
            {
                x = min - std::abs(rand());
            }

            int y = k + (i * 10);
            a1000y[y] = x;
            b1000y[y] = x;
            c1000y[y] = x;
            d1000y[y] = x;
            e1000y[y] = x;

            if (k % 9 == 0)
            {
                if (k != 0)
                {

                    min = -2147483637;
                    for (int a = i * 10; a <= (i * 10) + 9; a++)
                    {
                        if (a1000y[a] > min)
                        {
                            min = a1000y[a];
                        }
                    }
                }
            }
        }
    }
    clock_t start1z = clock();
    insertionSort(a1000y, 1000, c1, m1);
    clock_t end1z = clock();

    clock_t start2z = clock();
    selectionSort(b1000y, 1000, c2, m2);
    clock_t end2z = clock();

    clock_t start3z = clock();
    mergeSort(c1000y, 999, 0, c3, m3);
    clock_t end3z = clock();

    clock_t start4z = clock();
    quickSort(d1000y, 999, 0, c4, m4);
    clock_t end4z = clock();

    clock_t start5z = clock();
    hybridSort(e1000y, 1000, 0, c5, m5);
    clock_t end5z = clock();

    delete[] a1000y;
    delete[] b1000y;
    delete[] c1000y;
    delete[] d1000y;
    delete[] e1000y;

    double duration1z = static_cast<double>(end1z - start1z) / CLOCKS_PER_SEC;
    double duration2z = static_cast<double>(end2z - start2z) / CLOCKS_PER_SEC;
    double duration3z = static_cast<double>(end3z - start3z) / CLOCKS_PER_SEC;
    double duration4z = static_cast<double>(end4z - start4z) / CLOCKS_PER_SEC;
    double duration5z = static_cast<double>(end5z - start5z) / CLOCKS_PER_SEC;

    printf("\n");
    printf("\n");
    printf("Part 2-b-3: Performance analysis of partially descending integers array\n");
    printf("Array Size: 1000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration1z, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration2z, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration3z, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration4z, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration5z, c5, m5);
    int *a5000y = new int[5000];
    int *b5000y = new int[5000];
    int *c5000y = new int[5000];
    int *d5000y = new int[5000];
    int *e5000y = new int[5000];
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

    min = 2147483647;

    for (int i = 0; i < 417; i++)
    {
        for (int k = 0; k < 12; k++)
        {
            if (i == 416 && k == 7)
            {
                i = 1000;
                k = 1000;
            }
            else
            {

                if (i == 0)
                {
                    x = rand() + 1000000;
                }
                else
                {
                    x = min - std::abs(rand());
                }

                int y = k + (i * 12);
                a5000y[y] = x;
                b5000y[y] = x;
                c5000y[y] = x;
                d5000y[y] = x;
                e5000y[y] = x;

                if (k % 11 == 0)
                {
                    if (k != 0)
                    {

                        min = -2147483637;
                        for (int a = i * 12; a <= (i * 12) + 11; a++)
                        {
                            if (a5000y[a] > min)
                            {
                                min = a5000y[a];
                            }
                        }
                    }
                }
            }
        }
    }

    clock_t start11z = clock();
    insertionSort(a5000y, 5000, c1, m1);
    clock_t end11z = clock();

    clock_t start21z = clock();
    selectionSort(b5000y, 5000, c2, m2);
    clock_t end21z = clock();

    clock_t start31z = clock();
    mergeSort(c5000y, 4999, 0, c3, m3);
    clock_t end31z = clock();

    clock_t start41z = clock();
    quickSort(d5000y, 4999, 0, c4, m4);
    clock_t end41z = clock();

    clock_t start51z = clock();
    hybridSort(e5000y, 5000, 0, c5, m5);
    clock_t end51z = clock();

    delete[] a5000y;
    delete[] b5000y;
    delete[] c5000y;
    delete[] d5000y;
    delete[] e5000y;
    double duration11z = static_cast<double>(end11z - start11z) / CLOCKS_PER_SEC;
    double duration21z = static_cast<double>(end21z - start21z) / CLOCKS_PER_SEC;
    double duration31z = static_cast<double>(end31z - start31z) / CLOCKS_PER_SEC;
    double duration41z = static_cast<double>(end41z - start41z) / CLOCKS_PER_SEC;
    double duration51z = static_cast<double>(end51z - start51z) / CLOCKS_PER_SEC;

    printf("Array Size: 5000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration11z, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration21z, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration31z, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration41z, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration51z, c5, m5);
    int *a10000y = new int[10000];
    int *b10000y = new int[10000];
    int *c10000y = new int[10000];
    int *d10000y = new int[10000];
    int *e10000y = new int[10000];
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

    min = 2147483647;

    for (int i = 0; i < 770; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            if (i == 769 && k == 3)
            {
                i = 1000;
                k = 1000;
            }
            else
            {

                if (i == 0)
                {
                    x = rand() + 1000000;
                }
                else
                {
                    x = min - std::abs(rand());
                }

                int y = k + (i * 13);
                a10000y[y] = x;
                b10000y[y] = x;
                c10000y[y] = x;
                d10000y[y] = x;
                e10000y[y] = x;

                if (k % 12 == 0)
                {
                    if (k != 0)
                    {

                        min = -2147483637;
                        for (int a = i * 13; a <= (i * 13) + 12; a++)
                        {
                            if (a10000y[a] > min)
                            {
                                min = a10000y[a];
                            }
                        }
                    }
                }
            }
        }
    }

    clock_t start12z = clock();
    insertionSort(a10000y, 10000, c1, m1);
    clock_t end12z = clock();

    clock_t start22z = clock();
    selectionSort(b10000y, 10000, c2, m2);
    clock_t end22z = clock();

    clock_t start32z = clock();
    mergeSort(c10000y, 9999, 0, c3, m3);
    clock_t end32z = clock();

    clock_t start42z = clock();
    quickSort(d10000y, 9999, 0, c4, m4);
    clock_t end42z = clock();

    clock_t start52z = clock();
    hybridSort(e10000y, 10000, 0, c5, m5);
    clock_t end52z = clock();

    delete[] a10000y;
    delete[] b10000y;
    delete[] c10000y;
    delete[] d10000y;
    delete[] e10000y;
    double duration12z = static_cast<double>(end12z - start12z) / CLOCKS_PER_SEC;
    double duration22z = static_cast<double>(end22z - start22z) / CLOCKS_PER_SEC;
    double duration32z = static_cast<double>(end32z - start32z) / CLOCKS_PER_SEC;
    double duration42z = static_cast<double>(end42z - start42z) / CLOCKS_PER_SEC;
    double duration52z = static_cast<double>(end52z - start52z) / CLOCKS_PER_SEC;

    printf("Array Size: 10000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration12z, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration22z, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration32z, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration42z, c4, m4);

    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration52z, c5, m5);
    int *a20000y = new int[20000];
    int *b20000y = new int[20000];
    int *c20000y = new int[20000];
    int *d20000y = new int[20000];
    int *e20000y = new int[20000];
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

    min = 2147483647;

    for (int i = 0; i < 1429; i++)
    {
        for (int k = 0; k < 14; k++)
        {
            if (i == 1428 && k == 8)
            {
                i = 10000;
                k = 10000;
            }
            else
            {

                if (i == 0)
                {
                    x = rand() + 1000000;
                }
                else
                {
                    x = min - std::abs(rand());
                }

                int y = k + (i * 14);
                a20000y[y] = x;
                b20000y[y] = x;
                c20000y[y] = x;
                d20000y[y] = x;
                e20000y[y] = x;

                if (k % 13 == 0)
                {
                    if (k != 0)
                    {

                        min = -2147483637;
                        for (int a = i * 14; a <= (i * 14) + 13; a++)
                        {
                            if (a20000y[a] > min)
                            {
                                min = a20000y[a];
                            }
                        }
                    }
                }
            }
        }
    }

    clock_t start13z = clock();
    insertionSort(a20000y, 20000, c1, m1);
    clock_t end13z = clock();

    clock_t start23z = clock();
    selectionSort(b20000y, 20000, c2, m2);
    clock_t end23z = clock();

    clock_t start33z = clock();
    mergeSort(c20000y, 19999, 0, c3, m3);
    clock_t end33z = clock();

    clock_t start43z = clock();
    quickSort(d20000y, 19999, 0, c4, m4);
    clock_t end43z = clock();

    clock_t start53z = clock();
    hybridSort(e20000y, 20000, 0, c5, m5);
    clock_t end53z = clock();

    delete[] a20000y;
    delete[] b20000y;
    delete[] c20000y;
    delete[] d20000y;
    delete[] e20000y;
    double duration13z = static_cast<double>(end13z - start13z) / CLOCKS_PER_SEC;
    double duration23z = static_cast<double>(end23z - start23z) / CLOCKS_PER_SEC;
    double duration33z = static_cast<double>(end33z - start33z) / CLOCKS_PER_SEC;
    double duration43z = static_cast<double>(end43z - start43z) / CLOCKS_PER_SEC;
    double duration53z = static_cast<double>(end53z - start53z) / CLOCKS_PER_SEC;

    printf("Array Size: 20000  Elapsed time  Comp.count  Move count\n");
    printf("Insertion Sort    %.10f  -  %d  -  %d\n", duration13z, c1, m1);
    printf("Selection Sort    %.10f  -  %d  -  %d\n", duration23z, c2, m2);
    printf("Merge Sort        %.10f  -  %d  -  %d\n", duration33z, c3, m3);
    printf("Quick Sort        %.10f  -  %d  -  %d\n", duration43z, c4, m4);
    printf("Hybrid Sort       %.10f  -  %d  -  %d\n", duration53z, c5, m5);

    return 0;
}
