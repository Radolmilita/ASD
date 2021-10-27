#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//////////// Крок 1. Відкриття файлу ////////////
	const int len = 101; // довжина рядка
	char word[len], line[len];
	cout << "Введіть слово для пошуку:";
	cin >> word;
	int l_word = strlen(word); // довжина шуканого слова
	// потік читання з файлу
	ifstream fin("Shakespeare_Hamlet.txt");
	if (!fin) {
		cout << "Помилка відкриття файлу!";
		return 1;
	}
	///////// Крок 2. Кількість входжень слова /////////
	int count = 0;
	// читання з файлу рядків
	char lex[] = ",.- ";
	while (fin.getline(line, len)) {
		// зберігання у вказівнику р адреси поточного підрядку
		char* p = line;
		while (p = strstr(p, word)) { /* пошук входження
		підрядка word у рядок, на який вказує вказівник р і
		запам'ятовування адреси першого символу */
			cout << "Рядок:" << p << endl; /* Контрольне
			виведення підрядка з першим знайденим шуканим словом */
			char* c = p; // початок знайденого підрядку
			p += l_word; /* Переміщаємося на символ
			після шуканого слова */
			//// Аналіз символів до і після шуканого слова ////
			if (c != line) // слово не на початку рядка
				if (!strtok((c - 1), lex))
					continue; /* Перед словом не знак пунктуації
					або роздільник */
					// перехід до пошуку наступного входження слова
			/*if (ispunct(*p) || isspace(*p) || (*p == '\0'))*/
			if (strtok(p, lex));
			count++;
			// Після слова знак пунктуації, або роздільник, або кінець рядка
		}
	}
	cout << "Кількість входжень слова" << word << ":" << count << endl;
	system("pause");
}