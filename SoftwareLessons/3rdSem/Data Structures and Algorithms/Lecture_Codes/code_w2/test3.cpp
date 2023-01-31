#include <iostream>
using namespace std;
int main()
{
// declare variables
int A[]={5,0,4,1,6,9,3,6};
//A[10]=6;
int N=sizeof(A)/sizeof(int);
cout<<"sizeof(A)="<<sizeof(A)<<endl;
cout<<"sizeof(int)="<<sizeof(int)<<endl;
for (int i=0;i<N;i++)
	cout<<"&A["<<i<<"]="<<&A[i]<<"="<<A[i]<<endl;

cout<<"A="<<A<<endl;// points to the first element of the array

int* p=&A[2];
for (int i=0;i<N;i++)
	cout<<"*(p+"<<i<<")="<<*(p+i)<<endl;

return 0;
}
