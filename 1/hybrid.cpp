#include <iostream>
#include <ctime>
#include <cstdlib>
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
    int b = 0;
    int c = 0;
    int *a1000 = new int[1000];
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
            a1000[y] = x;

            if (k % 9 == 0)
            {
                if (k != 0)
                {

                    min = -2147483637;
                    for (int a = i * 10; a <= (i * 10) + 9; a++)
                    {
                        if (a1000[a] > min)
                        {
                            min = a1000[a];
                        }
                    }
                }
            }
        }
    }

    printArray(a1000, 1000, b, c);

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
    printArray(a1000, 1000, b, c);
    return 0;
}
