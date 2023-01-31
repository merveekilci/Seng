//============================================================================
// Name        : lab_heapsort.cpp
// Description : using priority queue for sorting
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int * random_array(int N){
	srand (time(NULL));
	int *Arr=new int[N];
	for (int i=0;i<10;i++)
		Arr[i]=rand()%100;
	return Arr;
}


void print_array(int *Arr,int N){
	for (int i=0;i<N;i++)
		cout<<Arr[i]<<"  ";
	cout<<endl;
}


//check if the array is sorted correctly
void pass_test(){
    
    bool is_sorted(queue<T> q) {
        if(!empty(q)) {
            for(T i = q.front(); size(q) > 1U; i = q.front()) {
                q.pop();

                if(i > q.front()) {
                    return false;
                }
            }
        }
        return true;
    }

}




int main() {
	int N=10;// the number of elements
	int *Arr=random_array(N);// 0<=A[i]<=99
	cout<<"Input array"<<endl;
	print_array(Arr,N); //print elements

	priority_queue<int> pq;//define a max priority queue

	//push all elements to the priority queue
	//...
    pq.push(25);

	//pop elements back to Arr in reverse order
	//...

	cout<<"\nSorted array"<<endl;
	print_array(Arr,N); //print sorted elements
	pass_test(Arr,N);
	Arr[0]=1234;//now it is not a sorted
	cout<<"\nArr[0]=1234-> Now it is not sorted"<<endl;
	print_array(Arr,N); //print elements
	pass_test(Arr,N); //pass test should fail
	return 0;
}
