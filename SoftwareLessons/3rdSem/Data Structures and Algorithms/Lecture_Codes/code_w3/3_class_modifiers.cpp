#include <iostream>
using namespace std;

class Number
{
private:
	int number;	
public:
	Number() //constructor
	{
		cout<<"constructor"<<endl;
	}
	
	~Number() //destructor
	{
		cout<<"destructor"<<endl;
	}
	
	void setNum(int number){
		this->number=number;
	}
	int getNum(){
		return number;
	}
};


int main()
{

Number num1;
Number *num2=new Number();

cout<<"&num1="<<&num1<<endl;
cout<<"num2="<<num2<<endl;

num2->setNum(10);
cout<<"num2->getNum()="<<num2->getNum()<<endl;

num1.setNum(20);
cout<<"num1.getNum()="<<num1.getNum()<<endl;


delete num2;
return 0;
}
