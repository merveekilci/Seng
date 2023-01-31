//============================================================================
// Name        : selectionsort.cpp
// Author      : 
// Version     : v1.0
// Description : An example C++ implementation for the Selection sort algorithm
//============================================================================

#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void selection_sort(int a[],int N){
	int i,j;  //loop variables  advance the position through the entire array
	for (i = 0; i < N-1; i++) // it doesn't work for a single element
	{
		int jMin = i;// assume the min is the first element
		for (j = i+1; j < N; j++) // test against elements after i to find the smallest
		{
		    if (a[j] < a[jMin]) jMin = j;
		}
		    
		if (jMin != i)   swap(a[i], a[jMin]);
    }
}


int * randomArray(int N){
	int *A=new int[N];
	for (int i=0;i<N;i++)
		A[i]=rand()%1000;
	return A;
}

int main(int argc,char **argv) {//Test program for selection sort

	if (argc<2) 
	{
		cout<<"\tEnter the number of elements to be sorted!"<<endl;
		cout<<"\tExample: selection_sort 1000 "<<endl;
		return 0;
	}
	int N=atoi(argv[1]);
	int *A=randomArray(N);

	//run and print elapsed time
	auto start = chrono::steady_clock::now(); //take current time
	selection_sort(A,N);
	auto stop =  chrono::steady_clock::now(); //take current time
	chrono::duration<double> elapsed_seconds = stop - start; //compute elapsed time
	cout << "elapsed time    : " << elapsed_seconds.count()<< " seconds\n";

	delete[] A;//collect garbage. It is not really necessary here.
	return 0;
}
