#include <iostream>
#include <cstdlib>
using namespace std;
int binarySearch(int A[],int first,int last,int x){
    cout<<"binarySearch(first="<<first<<",last="<<last<<")"<<endl;    
if (first>last) return -1;
    int middle=(first+last)/2;    
    if (x==A[middle]) //Element found
          return middle;//Index of the element        
    else if (x <A[middle]){ //
        return binarySearch(A,first,middle-1,x);//smaller than middle
    }
    else{//(x >A[middle])
        return binarySearch(A,middle+1,last,x);//bigger than middle
    }  
}

int main()
{
    int A[]={1,3,5,6,8,11,23,45,67,89,99,111,122,134};  
    int N=sizeof(A)/sizeof(int);
int x=1;// seek for x in array
    int find=binarySearch(A,0,N-1,x); 
if (find==-1){
  cout<<"Element couldn't be found."<<endl;
}
else{
  cout<<"Element found at "<<find<<endl;
  cout<<"A["<<find<<"]="<<A[find]<<endl; 
}    
    return 0;
}
