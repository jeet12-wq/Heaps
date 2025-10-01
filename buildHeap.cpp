#include<iostream>
using namespace std;

class Heap
{
    int *arr;
    int capacity;
    int index = 0;

    public:
    Heap(int n)
    {
        this->capacity = n;
        arr = new int[n];
        index = 0;
    }

   
};

 void heapify(int* arr, int n, int currIndex) {
	//n -> number of elements in heap
	int i = currIndex;
	int leftIndex = 2*i;
	int rightIndex = 2*i + 1;

	int largestKaIndex = i;
	//assuming i pr value hi sabse sabse badi value h 
	//pr ho skta h , sabse badi value left  ya right me hu 

	//check for left
	if(leftIndex < n && arr[leftIndex] > arr[largestKaIndex]) {
		//left me badi value mil gyi
		largestKaIndex = leftIndex;
	}

	//check for Right
	if(rightIndex < n && arr[rightIndex] > arr[largestKaIndex]) {
		//right me badi value mil gyi
		largestKaIndex = rightIndex;     //!updated largestkaIndex hai jo upr leftIndex se aaya hai
	}
	//jab yaha aaoge, tb tumhare paas, sabse bade value ka index hoga 

	//largestValue still i wali hi h, then no need to do anything
	//agar largestKaIndex left ya right me se koi, then swap logic

	if(largestKaIndex != i) {
		//left ya right me se koi h 
		cout << "replacing "<< arr[i] << " with " << arr[largestKaIndex] << endl;
		swap(arr[i], arr[largestKaIndex]);
		i = largestKaIndex;
		//baaaki recursion sambhal lega 
		heapify(arr, n, i);
	}
}

void buildHeap(int* arr, int n) {
	for(int i=n/2; i>=1; i--) {
		heapify(arr, n, i);
	}
}

void HeapSort(int *arr,int n)
{
    //n->size of the array hai
    while(n!=1)
    {
        swap(arr[1],arr[n-1]);  //n-1 = last element ka index hai
        n--;  //delete the index
        heapify(arr,n,1); //1 index wala ke saath heapify kardo!
    }
}


   


int main()
{
   int arr[] = {-1, 10,20,30,40,50};
	int n = 6;

	buildHeap(arr, n);
	cout<<endl << "Printing heap" << endl;
	for(int i=1; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	HeapSort(arr, n);

	cout<<endl << "Printing heap" << endl;
	for(int i=1; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
    

}