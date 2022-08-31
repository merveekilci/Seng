//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// FILES IN C++
//==================================================

#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>				// header file, used for purposes of localization.
using namespace std;

struct phoneBook {
	string fullName;		// name + surname
	string email;
	string telNumber;
};

int main() {
	setlocale(LC_ALL, "Turkish");	// support Turkish alphabeth

	phoneBook person1, person2;

	person1.fullName = "Gülüzar ÇİT";
	person1.email = "gulizar@sakarya.edu.tr";
	person1.telNumber = "000000000";

	person2.fullName = "A.Salih BAYRAKTAR";
	person2.email = "asbayraktar@sakarya.edu.tr";
	person2.telNumber = "11111111";

	// 1 - open the file
	ofstream writeData("data.txt", ios::out);

	// 2 - write relevant into the file 
	writeData << person1.fullName << "\t"
			  << person1.email << "\t"
		      << person1.telNumber << endl;

	writeData << person2.fullName << "\t"
		      << person2.email << "\t"
		      << person2.telNumber << endl;

	// 3 - close the file
	writeData.close();
	//-----------------------------------
	
	return 0;
}

