//============================================================================
// Name        : insertionsort.cpp
// Author      : 
// Version     : v1.0
// Description : An example C++ implementation for the Insertion sort algorithm
//============================================================================

#include <iostream>
using namespace std;

// A utility function to print an array of size n
void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];//select the following element as key
        j = i - 1;
        while (j >= 0 && arr[j] > key)//
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        //cout<<"i="<<i<<": ";print(arr, n);
    }
}


int main()//Test program for insertion sort
{
	//Example test array to be sorted
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);// the number of elements
    cout<<"initial array:"<<endl;
    cout<<"i=0: ";print(arr, n);
    insertionSort(arr, n);
    cout<<"\nsorted array:"<<endl;
    print(arr, n);
    return 0;
}
