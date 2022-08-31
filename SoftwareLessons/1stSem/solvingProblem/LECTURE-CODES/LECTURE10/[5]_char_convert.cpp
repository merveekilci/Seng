//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char_convert.cpp
//==================================================

#include <iostream>
#include <cctype>       // for character classification & transform functions
using namespace std;

int main()
{ 
    char pi[] = "3.14";

    unsigned int radius;

    cout << "Enter radius        : "; cin>>radius;
    cout << "Area of this circle : " 
         << atof(pi)*radius*radius << endl;     // atof(pi) => 3.14
    cout << "Area of this circle : "         
         << atoi(pi)*radius*radius << endl;     // atof(pi) => 3.0
    
    return 0;
}

