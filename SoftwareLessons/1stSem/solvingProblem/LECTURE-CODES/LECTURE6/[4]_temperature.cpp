//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// temperature.cpp
// Program that calculates temperature
//==================================================

#include <iostream>
 
using namespace std;

int main()
{
   int fTemp, cTemp;  										// variables for temperature values in fahrenheit and celcius 

   cout << "Input Temperature \"as fahrenheit\"  \n";
   cin >> fTemp;											// cin >> variable_name   : command for data input from keyboard
   
   cTemp = (fTemp - 32) * 5 / 9;  
 
   cout << fTemp << " Fahrenheit = " 
		<< cTemp << " Celcius" << endl; 	
   
   system("pause");
	
   return 0;
}


