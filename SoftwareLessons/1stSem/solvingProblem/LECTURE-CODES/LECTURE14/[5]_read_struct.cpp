//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// FILES IN C++
//==================================================

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	// Writing data into file
	ofstream writeFile;										// create a file object
	writeFile.open("data.txt", ios::out);					// open the file

	//ofstream writeFile("data.txt", ios::out);
	//ofstream writeFile("data.txt");

	writeFile << "Now, I am writing into a file	... \n";	// write data into file
	
	writeFile.close();										// close the file

	return 0;
}
