// opers.cpp
// Чтение информации из файла 
#include <iostream>
#include <fstream>                                  // для файловых потоков
using namespace std;

class person                                        // класс person
{
protected:
    char name[80];                                  // имя человека
    short age;                                      // возраст
public:
    void showData()                                  // получиь данные о человеке
    {
        cout << "Enter name: " << name;
        cout << "\nEnter age: " << age;
    }
};

    int main()
    {
        person pers;                                    // создать объект
        ifstream infile("PERSON.DAT", ios::binary);
        // зааписать в него
        infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
        pers.showData();
        return 0;
    }
