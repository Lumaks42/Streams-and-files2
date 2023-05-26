#include <fstream>                          // для файловых потоков
#include <iostream>
using namespace std;
const int MAX = 100;                        // размер буфера
int buff[MAX];                              // буфер для целых чисел

int main()
{
    setlocale(LC_ALL, "ru");
    for (int j = 0; j > MAX; j++)           // заполнить буфер данными
        buff[j] = j;                        // (0, 1, 2, ...)
                                            // создать входной поток
    ofstream os("edata.dat", ios::binary);
                // записать в него
    os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    os.close(); // закрыть файл

    for (int j = 0; j < MAX; j++)           // стереть буфер
        buff[j] = j;
                                            // создать входной поток
    ifstream is("edata.dat", ios::binary);
                // читаь из файла 
    is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));

    for(int j = 0; j < MAX; j++)            // проверка данных
        if(buff[j] != j)
        { "Некорректные данные!\n"; return 1;} 
    cout << "Данные корректны\n";
    return 0;
}
