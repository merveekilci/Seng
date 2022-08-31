//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Functions - Parameter Sending
// void.cpp
//==================================================

#include <iostream>
using namespace std;

const int MAX = 50;

void draw(char, int);                   // function prototype

int main()
{
	draw('*', 60);						// "draw()" function call - 1
	
    cout << "DATA TYPE       INTERVAL" << endl;
	
    draw('-',50);                       // "draw()" function call - 2
	
    cout << "char        -128 to 127" << endl
         << "short       -32,768 to 32,767" << endl
         << "int         system dependent" << endl
         << "long        -2,147,483,648 to 2,147,483,647" << endl;
	
    draw('*', 60);						// "draw()" function call - 3
	 
	return 0;
}

void draw(char ch, int N)           // function body
{
   for(int j=0; j<N; j++)               
      cout << ch;

   cout << endl;
}

