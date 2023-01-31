
#include <iostream>
using namespace std;

class Number{

	int num;
	double num2;
	public:
	Number(int num):num(num)
	{
		this->num=num;
	}
	void set_number(int num)
	{		
		this->num=num;
	}
	
	int get_number(){	
		return num;
	}	
	~Number(){
		//cout<<"destructor"<<endl;
	}
	
};

int main(){

	cout<<"Example array of objects"<<endl;
	Number num2[5]={Number(5),Number(15),Number(25),Number(35),Number(45)};
	cout<<"sizeof(num2)="<<sizeof(num2)<<endl;
	cout<<"print elements"<<endl;
	for (Number n:num2){
		cout<<"n.get_number()="<<n.get_number()<<endl;
		n.set_number(10); //change the object value
	}
	cout<<endl;
	cout<<"print again to see if the elements are changed"<<endl;
	cout<<"for (Number n:num2) :"<<endl;
	for (Number n:num2){
		cout<<"n.get_number()="<<n.get_number()<<endl;
	}
	cout<<endl;
	cout<<"Note that we are using & operator to get the address of selected object"<<endl;
	cout<<"for (Number &n:num2) :"<<endl;
	for (Number &n:num2){ //for (const Number &n:num2){
		cout<<"n.get_number()="<<n.get_number()<<endl;
		n.set_number(10);//change the object value
	}
	cout<<endl;
	cout<<"Now print again to see if the elements are changed"<<endl;
	for (Number &n:num2){
		cout<<"n.get_number()="<<n.get_number()<<endl;
	}
	return 0;
}
