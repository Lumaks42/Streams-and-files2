// englerr.cpp 
// программа 1
#include <iostream>
#include <string>
#include <cstdlib>                  // для atoi(), atof()
using namespace std;
int isFeet(string);                 // объявление
class Distance                      // класс английских растояний
{
private:
    int feet;
    float inches;
public:
    Distance()                      // конструктор без аргументов
        { feet = 0; inches = 0.0; }
    Distance(int ft, float in)      // конструктор (2арг.)
        { feet = ft; inches = in; }
    void showdist()
        { cout << feet << "\'-" << inches << '\"'; }
    void getdist();                 // запросить длину полдьзователя
};

void Distance::getdist()            // получение длины от полтьзователя
{
    string instr;                   // для входной строки

    while (true)                    // цикл пока ввод футов не будет верен
    {
        cout << "\n\nEnter feet: ";
        cin.unsetf(ios::skipws);    // не пропускать разделители
        cin >> instr;
        if (isFeet(instr))          // Првыильное значение? Да
        {
            cin.ignore(10, '\n');           // своровать символы, включая разделитель строк
            feet = atoi(instr.c_str());     // перевести значение в целочисленное
            break;                          // выход из цикла while
        }
        cin.ignore(10, '\n');
        cout << "The feet must be whole < 1000\n"; // trans: Футы должны быть целыми
    }                               // конец цикла while

    while (true)                    // проверим дюймы, тодже цикл
    {
        cout << "Enter inches: ";
        cin.unsetf(ios::skipws);    // не пропускать разделители
        cin >> inches;              // получем дюймы (float)
        if (inches >= 12.0 || inches < 0.0)
            {
                cout << "Inches should be between 0.0 and 11.99\n"; // trans: Дюймы должны быть между 0.0 и 11.9
                cin.clear(ios::failbit);                            // "искусственно" устанавливаю флаг ошибки
            }
        if (cin.good())
            {
                cin.ignore(10, '\n');       // своровать разделитель
                break;                      // ввод успешен, выйти
            }
        cin.clear();                                                    // ошибка; зачищаю статус
        cin.ignore(10, '\n');                                           // съесть символы с разделителем
        cout << "Sorry, the inches are not entered correctly\n";        // снова trans: Простите, неверно введены дюймы
    }                                       // конец цикла для дюймов
}

int isFeet(string str)                      // true если введена строка
    {
    int slen = str.size();                  // получить длину
    if (slen == 0 || slen > 5)              // не было или слишком много данных
        return 0;
    for (int j = 0; j < slen; j++)
    if ((str[j] < '0' || str[j] > '9') && str[j] != '-')             // если не цифры или минус
        return 0;                           // строка неправильных футов
    double n = atof(str.c_str());           // перевод в double
    if (n < -999.0 || n > 999.0)            // вне допустимых значений?
        return 0;                           // если да, неправильные футы
    return 1;                               // правильные футы
}

int main()
{
    Distance d;                     // создать объект Distance
    char ans;
        do
            {
            d.getdist();                // получить его значение
            cout << "\nDistance = ";
            d.showdist();               // вывести его
            cout << "\nAgain (y/n)?";
            cin >> ans;
            cin.ignore(10, '\n');       // своровать символ и разделить
        } while (ans != 'n');           // цикл до 'n'
     return 0;
}
