//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// struct.cpp
//==================================================


#include <iostream>
using namespace std;

// Declaring a struct 
struct structProduct
{
	int modelNumber;
	int pieceNumber;
	float price;
};


int main()
{
	structProduct product1;				// allocates memory for product1
	
	product1 = { 5235, 98, 153.15f };	// define product2 structure variable
	product1.modelNumber = 2020;		// assign first product's model number as 2020

	structProduct product2;				// define product2 structure variable
	product2 = product1; 				// assign first struct variable values 
										// to second struct variable

	cout << product2.modelNumber << endl;

	return 0;
}

