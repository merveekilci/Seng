//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// setw.cpp
// Program that uses setw manipulator
//==================================================
#include <iostream>
// library/header for setw() function
#include <iomanip>
using namespace std;
int main()
{
    long A = 1234567, B = 123, C = 2345;
    cout << "A " << A << endl
        << "B " << B << endl
        << "C " << C << endl;

    cout << setw(4)<< "A"<< setw(10) << A << endl
        << setw(4) << "B" << setw(10) << B << endl
        << setw(4) << "C" << setw(10) << C << endl;
    //system ("pause");     
    return 0;
}
