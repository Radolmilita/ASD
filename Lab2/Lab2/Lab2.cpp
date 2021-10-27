#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

int main()
{
    //2.1
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // довжина рядка файлу і довжина послідовності
    const int len = 81;
    char word[len], line[len]; // 1
    cout << "Введіть слово для пошуку:";
    cin >> word;
    ifstream fin("text_city_ukr.txt"); // 2
    // перевірка успішності створення об'єкта fin
    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }
    while (fin.getline(line, len)) { // 3
        if (strstr(line, word)) {
            cout << "Присутній!" << endl;
            system("pause");
            return 1;
        }
    }
    cout << "Відсутній!" << endl;
    system("pause");
}
