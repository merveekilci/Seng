#include <iostream>
using namespace std;

struct complex
{
	int real;
	int imaginary;
};




int main()
{
	complex numbers[5];

	complex* numbers2;

	int size;
	cout << "Enter size = ";  cin >> size;
	int MAX = size;


	numbers2 = new complex[MAX];

	numbers2[0].real = 10;
	numbers2[0].imaginary = 20;

	for  (int i = 0; i < MAX; i++)
	{
		cout << numbers2[i].real << "+" << numbers2[i].imaginary << "i\n";
	}

	//numbers2++;

	//cout >> numbers2

	delete[] numbers2;

	return 0;
}
