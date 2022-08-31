//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// string_class.cpp
//==================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string message1("HELLO");
	string message2 = "WORLD";
	string message3 = "TODAY IS ";
    
    string message4;

	//cin >> message4;  cout << ad1;	    // 'cin' can no get characters after whitespace
	
	
    getline(cin, message4);                 // reads after the whitespace
	cout << message4;

	//message4=message1;
	message4.assign(message1);		        // message4=message1
	cout << message4;
    
	message3.append(" MONDAY");		        // adds " MONDAY" after 'message3' 
	cout << message1.compare(message2);	    // compares 'message1' with 'message2' 
									        // if same returns 0s

	cout << message1 << message2 << endl;

	cout << message3.substr(10,6) << endl;  // writes some character of message3		
	cout << message1.find("he");	        // returns the location of "he"in 'message1'

    return 0;
}

