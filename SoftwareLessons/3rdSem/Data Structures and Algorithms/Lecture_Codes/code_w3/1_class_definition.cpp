#include <iostream>
using namespace std;


//1- Methods inside class definition -----------
class MyClass1 {// The class
   public:// Access specifier
    // Method/function defined inside the class
    void myMethod() {
	cout << "MyClass1::myMethod()"<<endl;
    }
};

//2- Methods outside class definition -----------
class MyClass2{// The class
    public:        // Access specifier
    void myMethod();// Method/function declaration
};

// Method/function definition outside the class
void MyClass2::myMethod() {
    cout << "MyClass1::myMethod()"<<endl;
}

int main() {
  //Instantiate an object of MyClass1
    MyClass1 myObj1;
  // Call the method
  myObj1.myMethod(); 
  
  // Instantiate an object of MyClass2
  MyClass2 myObj2; 
  // Call the method
 myObj2.myMethod();
 
 return 0;
}
