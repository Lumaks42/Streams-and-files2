#include <fstream>                                      // для файловых функций
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Время - великий учитель, но, увы, "
                 "оно убивает своих учеников. Берлиоз";

    ofstream outline("TEST.TXT");                       // Создать выходной файл
    for (int j = 0; j < str.size(); j++)                // каждый символ
        outline.put(str[j]);                            // записывать в файл
    cout << "The file wrtites\n";
    return 0;


}
