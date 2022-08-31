//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// FILES IN C++
//==================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// Writing data into file
	ofstream writeFile;										// create a file object
	writeFile.open("data.txt", ios::app);					// open the file

	//ofstream writeFile("data.txt", ios::app);

	string message;
	cout << "Enter a new message:";
	getline(cin, message, '\n');

	writeFile << message << endl;	// add data into file

	writeFile.close();										// close the file
	
	// Reading data from file
	ifstream readFile;										// create a file object
	readFile.open("data.txt", ios::in);					// open the file

	//ifstream readFile("data.txt", ios::in);
	//ifstream readFile("data.txt");
	
	if (readFile.is_open())								// wheck wherher the file is opened successfully or not
		cout << "The file is opened successfully\n";

	char readCharacter;

	while (!readFile.eof()) {						// read data line by line
		getline(readFile, message);					// read the current line
		cout << message << endl;
	}

	readFile.close();								// close the file
	return 0;
}
