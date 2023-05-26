// iline.cpp 

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    const int MAX = 80;                             // размер буфера
    char buffer[MAX];                               // буфер символов
    ifstream infile("TEST.TXT");                    // создать входной файл
    while (!infile.eof())                           // цикл до EOF
        {
        infile.getline(buffer, MAX);                // читает строку текста
        cout << buffer << endl;                     // и выводит ее 
        }
    return 0;
}
