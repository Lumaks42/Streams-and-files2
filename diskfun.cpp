// diskfun.cpp 
// Чтение из файла и запись нескольких объектов
#include <iostream>
#include <fstream>                      // для файловых потоков
using namespace std;

class person                            // класс person
{
protected:
    char name[80];                      // имя человек
    int age;                            // его возраст

public:
    void getdata()                      // получить данные о человеке
    {
        cout << "\n Enter name: "; cin >> name;
        cout << " Enter age: ";    cin >> age;
    }

    void showData()                     // вывод данных о человеке
    {
        cout << "\n Name: " << name;
        cout << "\n Age: " << age;
    }
};

int main()
{
    char ch;
    person pers;                                                    // создаю объект person
    fstream file;                                                   // создаю входной и выходной файл
                                                                    // открываю для записи

    file.open("GROUP.DAT", ios::app | ios::out |
                            ios::in | ios::binary);      
                                                                    // данные от пользователя - файл

    do
    {
        cout << "Enter data about the person: ";
        pers.getdata();                                             // получаю данные
                                                                    // запишу их в файл

        file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
        cout << "Continue entering (y/n)? ";
        cin >> ch;
    } while (ch == 'y');                                            // выход по 'n'

    file.seekg(0);                                                  // поставлю указатель на начало файла
                                                                    // считаю данные о первом человеке

    file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    while (!file.eof())                                             // выход по EOF
    {
        cout << "\nPerson: ";                                       // вывожу данные
        pers.showData();                                            // считываю данные о следующем
        file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    }
    cout << endl;
    return 0;
}

