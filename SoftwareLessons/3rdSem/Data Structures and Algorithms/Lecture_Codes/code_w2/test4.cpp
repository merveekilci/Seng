#include <iostream>
using namespace std;
int main()
{
// declare variables
int A[]={5,0,4,1,6,9,3,6};
//A[10]=6;
int N=sizeof(A)/sizeof(int);
cout<<"\nSTACK region"<<endl;
for (int i=0;i<N;i++)
	cout<<"&A["<<i<<"]="<<&A[i]<<"="<<A[i]<<endl;
int x;
cout<<"&x="<<&x<<endl;

int *B=new int[N];
for (int i=0;i<N;i++)
	B[i]=A[i]+5;

cout<<"\nHEAP region"<<endl;
for (int i=0;i<N;i++){
	cout<<"&B["<<i<<"]="<<&B[i]<<"="<<B[i]<<endl;
}
int *y=new int;
cout<<"&y="<<&y<<endl;
cout<<"y="<<y<<endl;
return 0;
}
