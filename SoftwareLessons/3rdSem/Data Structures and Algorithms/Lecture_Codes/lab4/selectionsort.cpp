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


int* randomArray(int N){
			//initialize and fill with random numbers
			//...

		 
 		
 		



 		int array;
         
 		srand((unsigned)time(0)); 
     
    	for(int i=0; i<N; i++){ 
        array[i] = rand()%100 +1; 
         
      
 		} 
		return array[N]; 

		/*int* randomarray=new int [N];
		for(int i){
			int 
		}*/
}

int main(int argc,char **argv) {//Test program for selection sort

	//.. check the number of elements

	int N=0;
	try{
		if (argc>=2){
			N=stoi(argv[1]);
		}
	}
	
	catch (string x){
		cout<<"Enter the number of elements to be sorted!\n Example: selection_sort 1000 "<<endl;
		return 0;
	}
	//get the number of elements using argv
	//....
	
	//initialize array
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
