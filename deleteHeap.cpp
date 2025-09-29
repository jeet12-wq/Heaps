#include <iostream>
using namespace std;

class Heap
{
    int *arr;
    int capacity; // size of the array
    int index;    // no of elements in the heap which is it tracking

public:
    Heap(int n)
    {
        this->capacity = n;
        arr = new int[n];
        index = 0;
    }

    void print()
    {
        for (int i = 1; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int val)
    {
        if (index == capacity - 1)
        {
            cout << "overflow" << endl;
            return;
        }

        index++;
        arr[index] = val;
        int i = index;

        while (i > 1)
        {
            int parentIndex = i / 2;
            if (arr[parentIndex] < arr[i])
            {
                swap(arr[parentIndex], arr[i]);
                i = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void deletefromHeap()
    {
        // 1st step-swap
        swap(arr[1], arr[index]);

        index--;

        heapify(arr, index, 1);
    }

    void heapify(int *arr, int n, int currIndex)
    {
        //! n= no of element in the heap
        int i = currIndex;
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        // assuming ki current element hi largest hai
        int largestkaindex = i;

        if (leftIndex < n && arr[largestkaindex] < arr[leftIndex])
        {
            largestkaindex = leftIndex;
        }

        if (rightIndex < n && arr[largestkaindex] < arr[rightIndex])
        {
            largestkaindex = rightIndex;
        }

        if (largestkaindex != i)
        {
            swap(arr[i], arr[largestkaindex]);
            i = largestkaindex;
            heapify(arr, n, i);
        }
    }
};

int main()
{
    Heap H1(6);
    H1.insert(10);
    H1.print();
    H1.insert(20);
    H1.print();
    H1.insert(30);
    H1.print();
    H1.insert(40);
    H1.print();
    H1.insert(50);
    H1.print();

    H1.deletefromHeap();
    H1.print();

    H1.deletefromHeap();
    H1.print();

    H1.deletefromHeap();
    H1.print();
}