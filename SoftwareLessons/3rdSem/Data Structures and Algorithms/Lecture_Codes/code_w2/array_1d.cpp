
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * Arrays on stack and heap memory regions
 */

void print(int B[],int N){
    cout<<"Addresses:"<<endl;
    for (int i = 0; i < N; i++) {             
       	cout<<"\tB["<<i<<"]="<<B[i]; 
       	cout<<" "<<&B[i]<<endl;
    }
}
int main(int argc, char** argv) {
    int A[]={5,6,7,9,3,4,5};// An array on the stack
    //or: int A[7]; A[0]=5; A[1]=6; A[2]=7;....    
    
    //int N=7;
    int N= sizeof(A)/sizeof(int); // the number of elements  
    
    cout<<"N="<<N<<endl;
    cout<<"A="<<A<<endl;
     
   //addresses
    for (int i = 0; i < N; i++) {
        cout<<"A["<<i<<"]="<<A[i];
        cout<<" "<<&A[i]<<endl;
    }
      
    cout<<"-----------"<<endl;
    // print elements using * 
    for (int i = 0; i < N; i++) {
        cout<<"*(A+"<<i<<")="<<*(A+i);
        cout<<" "<<A+i<<endl;
    }
   
    
     int *B=new int[N];// An array on the heap
     // compare the addresses
     cout<<"stack  heap"<<endl;
     for (int i = 0; i < N; i++) {
     	B[i]=A[i];
       	cout<<&A[i];
       	cout<<" "<<&B[i]<<endl;       
      }
     
   
      print(B,N);
      
      delete[] B;
      
      
      cout<<"the same memory region following delete"<<endl;
      cout<<"B="<<B<<endl;      
      print(B,N);
      
      //assign B another array
      B=new int[N];
      
      
    return 0;
}

