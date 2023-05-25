#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream outfile("TEST.TXT");					//  создать выходной файл

	// отправить текст в файл
	outfile << "Мир кажется простым понятным\n";
	outfile << "Пока мы мыслить не начинаем внятно\n";

	cout << "the text is written";
	return 0;
}
