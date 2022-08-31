//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char.cpp
// Program that samples character variables
//==================================================

#include <iostream>
#include <conio.h>										// library to use getch() command										
 
using namespace std;

int main()
{
   char ch1, ch2 ;    									// declares a char type variable
   char ch3 = '\t';   									// declares a char type 'tab' variable
   
   ch1 = 'B';         									// assigns a value to char variable.
   cout << ch3<< ch1<<'\t'<<"\\ t"<<ch2<< endl ;       	// prints characters to screen
   
   cout << '\n';           								// prints a "new line" character to screen
   
   cout << 'We are in \'\SAKARYA UNIVERSITY \' ';

   char ch=getch(); 									// getch() => gets a character from user

   system("pause");
	
   return 0;
}
