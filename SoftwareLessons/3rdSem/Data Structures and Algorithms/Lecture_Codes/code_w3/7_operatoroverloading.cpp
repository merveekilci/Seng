#include <cstdlib>
#include <iostream>

using namespace std;

class Number{
public:
    Number(int x){
        this->x=x;
    }    
    int get(){
       return x; 
    }
    friend ostream& operator<<(ostream& out, Number &n){
		out<<n.x;
		return out;
    }
  
    Number* operator+(Number& n){
		Number *sonuc = new Number(this->x+n.x);
		return sonuc;
    }
    bool operator==(Number& n){
		return (this->x == n.x);
    }
    
private:
    int x;
};


int main() {
    Number s1(5);
    cout<<s1.get()<<endl; 
    
    cout<<s1<<endl;//operator overloading 
    Number s2(7);
    
    Number *s3;    
    s3=s1+s2;//operator overloading
    cout<<*s3<<endl;
    
    
    if (s1==s2)//operator overloading
        cout<<"Equal"<<endl;
    else
        cout<<"Not equal"<<endl;
    return 0;
}


