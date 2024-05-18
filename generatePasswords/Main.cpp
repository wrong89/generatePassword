#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int complexity, length;

	cout << "Generate password\n" << endl;
	cout << "Enter the complexity (1-7): ";
	cin >> complexity;
	cout << "Enter the length: ";
	cin >> length;

	string password = generatePassword(complexity, length);
	cout << password << endl;

	system("pause");
	return 0;
}