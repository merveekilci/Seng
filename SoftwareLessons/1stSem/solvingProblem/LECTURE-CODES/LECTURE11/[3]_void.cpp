//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Functions - Function Overloading
// void.cpp
//==================================================

#include <iostream>
using namespace std;

const int MAX = 50;

void draw();                             // function prototype
void draw(char, int);                   // function prototype

float salary(float shift, float wage);
float salary(float wage);
float salary();

int main()
{
	draw('*', 60);						// "draw()" function call - 1
	
    cout << "DATA TYPE       INTERVAL" << endl;
	
    draw();                             // "draw()" function call - 2
	
    cout << "char        -128 to 127" << endl
         << "short       -32,768 to 32,767" << endl
         << "int         system dependent" << endl
         << "long        -2,147,483,648 to 2,147,483,647" << endl;
	
    draw('*', 60);						// "draw()" function call - 3
	 
	return 0;
}

void draw()                         // function body
{
   for(int j=0; j<MAX; j++)               
      cout << '-';

   cout << endl;
}

void draw(char ch, int N)           // function body
{
   for(int j=0; j<N; j++)               
      cout << ch;

   cout << endl;
}



