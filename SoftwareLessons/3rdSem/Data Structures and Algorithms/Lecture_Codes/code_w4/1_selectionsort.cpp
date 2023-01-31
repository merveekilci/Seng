//============================================================================
// Name        : selectionsort.cpp
// Author      : 
// Version     : v1.0
// Description : An example C++ implementation for the Selection sort algorithm
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void selection_sort(int a[],int N){
	int i,j;//loop variables  advance the position through the entire array
		for (i = 0; i < N-1; i++) // it doesn't work for a single element
		{
		    int jMin = i;// assume the min is the first element
		    for (j = i+1; j < N; j++) // test against elements after i to find the smallest
		    {
		        if (a[j] < a[jMin])// if this element is less, then it is the new minimum
		        {
		            jMin = j;// found new minimum; remember its index
		        }
		    }
		    if (jMin != i) // if a smaller element found, swap it
		    {
		        swap(a[i], a[jMin]);
		    }
		    cout<<"i="<<i<<": ";print(a, N);
		}
}

//below is the simplified but inefficient selection sort due to the number of swaps
void selection_sort2(int *a,int N){
	int i,j;
		for (i = 0; i < N-1; i++) // it doesn't work for a single element
		{
		    int jMin = i;
		    for (j = i+1; j < N; j++)
		    	if (a[j] < a[jMin]) swap(a[j], a[jMin]);

		}
}

int main() {//Test program for selection sort
	// Example array
	int a[]={11,5,1,3,8,9,4,7,5,2};
	int N=sizeof(a)/sizeof(int); // the number of elements
	cout<<"Initial array:"<<endl;
	cout<<"     ";print(a,N);
	selection_sort(a,N);
	cout<<"\nSorted array:"<<endl;
	cout<<"     ";print(a,N);
	return 0;
}
