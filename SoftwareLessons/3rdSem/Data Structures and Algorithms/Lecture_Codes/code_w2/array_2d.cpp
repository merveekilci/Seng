#include <cstdlib>
#include <iostream>

using namespace std;
/*
 * 2D arrays
 */
 
 /*Print 2d array*/
void print(int **A,int N,int M){
    cout<<"print 2D array:"<<endl;
    for (int i=0;i<N;i++){ 

        for (int j=0;j<M;j++){
            cout<<"\t"<<A[i][j];
        }
           cout<<endl;
    }
}

/*Fill 2d array with random numbers*/
void rand(int **A,int N,int M){
    for (int i=0;i<N;i++){        
        for (int j=0;j<M;j++){
            A[i][j]=rand()%99;
        }         
    }
}

int main(int argc, char** argv) {
    int N,M;
    N=5;M=4;
    
    //2d array definition on the stack
    int B[N][M];
    
    //Beginning address of the first dimension (stack)
    cout<<"B="<<B<<endl;  
    
    cout<<"Row addresses (Stack)"<<endl;
    for (int i=0;i<N;i++)
        cout<<"&B["<<i<<"]="<<B[i]<<endl; 
    
    //2d array definition on the heap
    int **A=new int*[N];
    for (int i=0;i<N;i++)
        A[i]=new int[M]; //
    //A[0]=new int[4];// rows maybe in different sizes
    //A[1]=new int[10];
    
    //Beginning address of the first dimension (heap)
    cout<<"A="<<A<<endl;    
    cout<<"Row addresses (Heap):"<<endl;
    for (int i=0;i<N;i++)
        cout<<"&A["<<i<<"]="<<A[i]<<endl; 
    

    rand(A,N,M);// fill with random numbers
    print(A,N,M);//print array    
    
    //delete
    for (int i=0;i<N;i++)
        delete[] A[i];
    delete[] A;
    
    //define another 2d array
    A=new int*[N];//heap 
    for (int i=0;i<N;i++)
        A[i]=new int[M];

    return 0;
}

