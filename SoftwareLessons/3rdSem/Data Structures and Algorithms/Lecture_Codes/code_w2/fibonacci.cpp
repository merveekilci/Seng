#include<iostream>
using namespace std;
int c=0;
int fibonacci(int);
int main(void)
{    
    int num;
    cout<<"n=";cin>>num;       
    cout<<fibonacci(num)<<endl;
    cout<<"number of calls="<<c<<endl;
    return 0;
}

int fibonacci(int num)
{    
	cout<<"f("<<num<<")"<<endl;
	c++;
    //base condition
    if(num == 0 || num == 1)
    {
        return num;
    }
    else
    {
        // recursive call
	
        return fibonacci(num-1) + fibonacci(num-2);
    }
}
