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
	// Reading data from file
	ifstream readFile;										// create a file object
	readFile.open("data.txt", ios::in);					// open the file

	//ifstream readFile("data.txt", ios::in);
	//ifstream readFile("data.txt");
	
	if (readFile.is_open())								// wheck wherher the file is opened successfully or not
		cout << "The file is opened successfully\n";

	char readCharacter;

	// NOTE: Reading by char by char does not read space characters
	while (!readFile.eof()) {						// read data char by char
		readFile >> readCharacter;					// read the current character 
		cout << readCharacter;						
	}

	// 2. way - reading line by line
	/*string readLine;
	while (!readFile.eof()) {						// read data line by line
		getline(readFile, readLine);				// read the current line
		cout << readLine;
	}*/

	
	readFile.close();								// close the file
	return 0;
}
