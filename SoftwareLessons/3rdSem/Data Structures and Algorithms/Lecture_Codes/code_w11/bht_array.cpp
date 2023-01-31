//============================================================================
// Name        : BHT_array.cpp
// Description : Example Binary Heap Tree
//============================================================================
#include <iostream>
#include <exception>
using namespace std;
class MinBHT{
private:
	int *E;//Elements
	int capacity;
	int n;//number of nodes
public:
	MinBHT(int capacity){
		this->capacity=capacity;
		n=0;
		E=new int[capacity];
	}
	void heapifyUpward(int child){
		if (child==0) return;//stop at root node
		int parent=(child-1)/2;
		if (E[parent]>E[child]){//swap
			//swap(E[parent],E[child]);
			int tmp=E[parent];
			E[parent]=E[child];
			E[child]=tmp;
			heapifyUpward(parent);
		}

	}
	void add(int key){
		if (n==capacity) throw exception();
		E[n]=key;
		heapifyUpward(n);
		n++;
	}
	void heapifyDownward(int i){
		int l=2*i+1;//left child
		int r=2*i+2;//right child
		int min;

		//find small child
		if (r>=n){//no child on the right
			if(l>=n) return; //no child on the left: leaf case
			else
				min=l;//
		}
		else{// two child
			if (E[r]<E[l]) //select the small one
				min=r;
			else
				min=l;
		}

		//compare small child with parent
		if(E[min]<E[i]){//swap if child<parent
			int tmp=E[min];
			E[min]=E[i];
			E[i]=tmp;
			heapifyDownward(min);
		}
	}
	int deleteMin(){
		if (n==0) throw exception();
		int min=E[0];
		E[0]=E[n-1];//1-replace root with the rightmost node
		heapifyDownward(0);//2-heapify downward
		n--;
		return min;
	}
	int front()const{
		if (n==0) throw exception();
		return E[0];//root node
	}
	int length()const{
		return n;//number of nodes
	}
	bool isEmpty(){
		return n==0;
	}
	~MinBHT(){
		delete[] E;
	}
};

int main() {

	MinBHT bht(100);

	bht.add(50);
	bht.add(20);
	bht.add(70);
	bht.add(15);
	bht.add(9);
	bht.add(23);
	bht.add(44);
	bht.add(11);

	while(!bht.isEmpty())
		cout<<bht.deleteMin()<<endl;//cout<<bht.deleteMax()<<endl;

	return 0;
}
