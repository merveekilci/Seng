//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// for_numbers.cpp
// Program that calculates the sum
// of numbers between two numbers
//==================================================

#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
    int counter = 0;

	for(int counter=1;counter<=10;counter++)
		sum += counter; sum=sum+counter
	
	// Revised version of this example that 
    // calculates teh average between two numbers
    
    /*int lowerBound	= 10;
	int upperBound	= 20;

	for (int counter = lowerBound; counter <= upperBound; counter++)
		sum += counter;*/
	
   cout<<"Sum of numbers between [1-10]  = " << sum <<endl;
   
   return 0;
}


