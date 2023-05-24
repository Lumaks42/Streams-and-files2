// formato.cpp
#include <fstream>							// для файлового ввода вывода
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ch = 'x';
	int j = 77;
	double d = 6.02;
	string str1 = "Kafka";					// строки без
	string str2 = "Proust";					// пробелов

	ofstream outfile("fdata.txt");			// создать объект ofstream

	outfile << ch							// внести данные
		<< ' '								  // пробелы между данными (да, да, можно было сделать цикл для пробелов)
		<< j
		<< ' '								
		<< d
		<< ' '
		<< str1
		<< ' '
		<< str2;

	cout << "File is recorded\n";
	return 0;
}
