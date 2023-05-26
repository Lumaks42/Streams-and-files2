// ichar.cpp
#include <fstream>									    // для файловых функций
#include <iostream>
using namespace std;

int main()
{
	char ch;										          // символ для считывания
	ifstream infile("TEST.TXT");					// входной файл
	while(infile)									        // читать до EOF или ошибки
		{
		infile.get(ch)								      // cчитать символ
		cout << ch;									        // и вывести его
		}
	cout << endl;
	return 0;
}
