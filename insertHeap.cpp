#include<iostream>
using namespace std;

class Heap
{
    int *arr;
    int capacity;
    int index;

   
    public:
    
     Heap(int n)
    {
        this->capacity = n;
        arr = new int[n];
        index = 0;
    }

    
    void printHeap()
    {
        for(int i = 1;i<capacity;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void insert(int val)
    {
        //already heap full
        if(index == capacity-1)
        {
            cout<<"overflow"<<endl;
            return;
        }
       
            index++;
            arr[index] = val;
            int i = index;

            while(i>1)
            {
                int parentIndex = i/2;
                if(arr[parentIndex]<arr[i])
                {
                    swap(arr[parentIndex],arr[i]);
                    i = parentIndex;
                }
                else{
                    break;
                }


            }
        
    }
};






int main()
{
    Heap pq(10);
    pq.insert(10);
    pq.printHeap();
    pq.insert(20);
    pq.printHeap();
    pq.insert(30);
    pq.printHeap();
    pq.insert(40);
    pq.printHeap();
     pq.insert(50);
    pq.printHeap();
    

}