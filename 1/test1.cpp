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
        ++moveCount;
        int index = i;
        for (; (index > 0) && (arr[index - 1] > nextNumber); --index)
        {
            ++compCount;
            ++moveCount;
            arr[index] = arr[index - 1];
        }
        arr[index] = nextNumber;
        ++moveCount;
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
    int *a5000 = new int[5000];
    int *b5000 = new int[5000];
    int *c5000 = new int[5000];
    int *d5000 = new int[5000];
    int *e5000 = new int[5000];
    int *a10000 = new int[10000];
    int *b10000 = new int[10000];
    int *c10000 = new int[10000];
    int *d10000 = new int[10000];
    int *e10000 = new int[10000];
    int *a20000 = new int[20000];
    int *b20000 = new int[20000];
    int *c20000 = new int[20000];
    int *d20000 = new int[20000];
    int *e20000 = new int[20000];

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
            a1000[y] = x;
            b1000[y] = x;
            c1000[y] = x;
            d1000[y] = x;
            e1000[y] = x;

            if (k % 9 == 0)
            {
                if (k != 0)
                {

                    max = -2147483648;
                    for (int a = i * 10; a <= (i * 10) + 9; a++)
                    {
                        if (a1000[a] > max)
                        {
                            max = a1000[a];
                        }
                    }
                }
            }
        }
    }

    clock_t start1x = clock();
    insertionSort(a1000, 1000, c1, m1);
    clock_t end1x = clock();

    clock_t start2x = clock();
    selectionSort(b1000, 1000, c2, m2);
    clock_t end2x = clock();

    clock_t start3x = clock();
    mergeSort(c1000, 999, 0, c3, m3);
    clock_t end3x = clock();

    clock_t start4x = clock();
    quickSort(d1000, 999, 0, c4, m4);
    clock_t end4x = clock();

    clock_t start5x = clock();
    hybridSort(e1000, 1000, 0, c5, m5);
    clock_t end5x = clock();

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
                a5000[y] = x;
                b5000[y] = x;
                c5000[y] = x;
                d5000[y] = x;
                e5000[y] = x;

                if (k % 11 == 0)
                {
                    if (k != 0)
                    {

                        max = -2147483648;
                        for (int a = i * 11; a <= (i * 11) + 10; a++)
                        {
                            if (a5000[a] > max)
                            {
                                max = a5000[a];
                            }
                        }
                    }
                }
            }
        }
    }
    clock_t start11x = clock();
    insertionSort(a5000, 5000, c1, m1);
    clock_t end11x = clock();

    clock_t start21x = clock();
    selectionSort(b5000, 5000, c2, m2);
    clock_t end21x = clock();

    clock_t start31x = clock();
    mergeSort(c5000, 4999, 0, c3, m3);
    clock_t end31x = clock();

    clock_t start41x = clock();
    quickSort(d5000, 4999, 0, c4, m4);
    clock_t end41x = clock();

    clock_t start51x = clock();
    hybridSort(e5000, 5000, 0, c5, m5);
    clock_t end51x = clock();

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
            if (i == 769 && k == 2)
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
                a10000[y] = x;
                b10000[y] = x;
                c10000[y] = x;
                d10000[y] = x;
                e10000[y] = x;

                if (k % 12 == 0)
                {
                    if (k != 0)
                    {

                        max = -2147483648;
                        for (int a = i * 13; a <= (i * 13) + 12; a++)
                        {
                            if (a10000[a] > max)
                            {
                                max = a10000[a];
                            }
                        }
                    }
                }
            }
        }
    }

    clock_t start12x = clock();
    insertionSort(a10000, 10000, c1, m1);
    clock_t end12x = clock();

    clock_t start22x = clock();
    selectionSort(b10000, 10000, c2, m2);
    clock_t end22x = clock();

    clock_t start32x = clock();
    mergeSort(c10000, 9999, 0, c3, m3);
    clock_t end32x = clock();

    clock_t start42x = clock();
    quickSort(d10000, 9999, 0, c4, m4);
    clock_t end42x = clock();

    clock_t start52x = clock();
    hybridSort(e10000, 10000, 0, c5, m5);
    clock_t end52x = clock();

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
                a20000[y] = x;
                b20000[y] = x;
                c20000[y] = x;
                d20000[y] = x;
                e20000[y] = x;

                if (k % 13 == 0)
                {
                    if (k != 0)
                    {

                        max = -2147483648;
                        for (int a = i * 14; a <= (i * 14) + 13; a++)
                        {
                            if (a20000[a] > max)
                            {
                                max = a20000[a];
                            }
                        }
                    }
                }
            }
        }
    }
    clock_t start13x = clock();
    insertionSort(a20000, 20000, c1, m1);
    clock_t end13x = clock();

    clock_t start23x = clock();
    selectionSort(b20000, 20000, c2, m2);
    clock_t end23x = clock();

    clock_t start33x = clock();
    mergeSort(c20000, 19999, 0, c3, m3);
    clock_t end33x = clock();

    clock_t start43x = clock();
    quickSort(d20000, 19999, 0, c4, m4);
    clock_t end43x = clock();

    clock_t start53x = clock();
    hybridSort(e20000, 20000, 0, c5, m5);
    clock_t end53x = clock();

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
