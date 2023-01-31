#include <iostream>
#include "operators.hpp"
using namespace std;
int main(int narg,char** argv)
{
	cout<<"argv[1]="<<argv[1]<<endl;
	double a,b;
	char op='*';	
	cout<<"\tenter a= ";cin>>a;
	cout<<"\tenter b= ";cin>>b;	
	cout<<"\tenter +,-,* or /= ";cin>>op;
	cout<<endl;
	switch(op){
		case '+':
		cout<<"\ta+b= "<<add(a,b)<<endl;
		break;
		case '*':
		cout<<"\ta*b= "<<mul(a,b)<<endl;
		break;
		case '/':
		cout<<"\ta/b= "<<div(a,b)<<endl;
		break;
		case '-':
		cout<<"\ta-b= "<<sub(a,b)<<endl;
		break;
		default:
		cout<<"\twrong selection!";
		break;		
	}	
	return 0;
}

