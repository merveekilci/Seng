//============================================================================
// Name        : quicksort.cpp
// Author      : 
// Version     : v1.0
// Description : An example C++ implementation for the Quick sort algorithm
//============================================================================

#include <iostream>
#include <algorithm> //for the swap function
using namespace std;

// A utility function to swap two elements
/*void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}*/

/* Function to print an array */
void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void print(int a[], int low,int high) {
	for (int i = low; i <= high; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than or equal to pivot
		if (arr[j] <= pivot) {
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	cout<<"pivot="<<pivot;cout << "     ";print(arr, low,high);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int p = partition(arr, low, high);/* p is partitioning index, arr[p] is now at right place */
		quickSort(arr, low, p - 1); // Separately sort elements before p and after p
		quickSort(arr, p + 1, high);
	}
}

int main() {
	//Example test array to be sorted
	int arr[] = {9, 11, 5, 1, 3, 8, 9, 4, 7, 5, 6,9 };
	int N = sizeof(arr) / sizeof(arr[0]); // the number of elements
	cout << "Initial array:" << endl;
	cout << "     ";print(arr, N);
	quickSort(arr, 0, N - 1); //apply quick sort
	cout << "\nSorted array:" << endl;
	cout << "     ";print(arr, N);
	return 0;
}
