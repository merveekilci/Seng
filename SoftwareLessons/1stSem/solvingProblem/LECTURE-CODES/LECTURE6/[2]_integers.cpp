//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2020-2021 Fall Semester
//==================================================
// integers.cpp
// Program that samples integer variables
//==================================================

#include <iostream>
 
using namespace std;

int main()
{
   int number1;
   int number2;
   int total = 0;
   // The integer declarations above 
   // can also be written as follows:
   // int number1, number2, total = 0;
      
   number1 = 5;
   number2 = 10;
   //cin >> number1 >> number2; 
   
   total = number1 + number2;

   cout << "result : " << total << endl;
   
   system("pause");
   
   return 0;
}


