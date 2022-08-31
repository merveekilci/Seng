//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// FILES IN C++ (random access)
//==================================================

// This program creates a file with empty data fields
#include <iostream>
#include <fstream>
using namespace std;

enum CATEGORY { FOOD = 1, DRINK, JUNK, STATIONARY };

// Envanter yapısı
struct PRODUCT {
	char name[100];		// if defined as string special "access violation" error occurs when reading from the file 
	int id;
	CATEGORY type;
	float price;
};

const int MAX = 5;

int main()
{
	ofstream writeGrocery("grocery.dat", ios::out | ios::binary);		// create a binary file
	PRODUCT products[MAX] = { { "test", 0, FOOD, 0.0 } };

	for (int i = 0; i < MAX; i++) {
		cout << products[i].name << ",";
		cout << products[i].id << endl;
	}

	cout << sizeof(enum CATEGORY) << " bytes " << endl;
	cout << sizeof(string) << " bytes " << endl;
	cout << "--------------------------\n";

	// Boş kayıtlar yazılıyor
	for (int i = 0; i < 5; i++)
	{
		cout << "Now writing record " << i << endl;
		//writeGrocery.write((char*)&products[i].name, sizeof(string));
		//writeGrocery.write((char*)&products[i].id, sizeof(int));
		//writeGrocery.write((char*)&products[i].type, sizeof(enum CATEGORY));
		//writeGrocery.write((char*)&products[i].price, sizeof(float));
		//grocery.write((char*)&products, sizeof(products)/MAX);

		writeGrocery.write((char*)&products[i], sizeof(products[i]));
	}
	writeGrocery.close();
	

	fstream readGrocery("grocery.dat", ios::in | ios::binary);

	PRODUCT record;

	//cout << sizeof(record) << " bytes" << endl;

	// kayıtlar okunuyor ve gösteriliyor
	readGrocery.read((char*)&record, sizeof(record));

	while (!readGrocery.eof())
	{
		cout << "NAME.......: " << record.name<< endl;
		cout << "ID.........: " << record.id<< endl;
		cout << "TYPE.......: ";

		switch (record.type) {
		case 1:cout << "FOOD\n"; break;
		case 2:cout << "DRINK\n"; break;
		case 3:cout << "JUNK\n"; break;
		case 4:cout << "STATIONARY\n"; break;
		default:cout << "\n"; break;
		}

		cout << "PRICE......: " << record.price << " TL\n" << endl;
		cout << "-----------------------------------------------\n";

		readGrocery.read((char*)&record, sizeof(record));
	}

	readGrocery.close();


	system("pause");
	return 0;
}




