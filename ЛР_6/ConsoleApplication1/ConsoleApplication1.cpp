/*Вариант 23
Класс - Строка.Дополнительно перегрузить следующие операции : 
< -сравнения строк в лексиграфическои порядке; 
+добавления числа к строке; 
-удаление последнего символа в строке; 
*– замена всех символов в строке на заданный.*/

#include "stdafx.h"
#include "iostream"
#include "string.h"

using namespace std;
class String
{
public:
	String(char *);
	void operator <(char*);
	void operator +(char*);
	void operator -(char);
	void operator *(char);
	void getStr(void);
private:
	char str[256];
	//int chislo;
};


String::String(char*s)
{
	strcpy(str, s);
}

void String::operator<(char*s)
{
	strcmp(str, s);
}

void String::operator+(char*s)
{
	strcat(str, s);
}

void String::operator-(char s)
{

	char temp[256]; // будем создавать новую строку
	int i, j; //счетчики циклов
	//Проходим по всей строке класса с помощью цикла и если символ строки не равен принятому символу (параметру), то копируем его в новую строку
	for (i = 0, j = 0; str[i]; i++) if (str[i] != s) temp[j++] = str[i];
	temp[j] = NULL;

	strcpy(str, temp); //Копируем новую строку в символьный массив класса}
}

void String::operator*(char s)
{
	for (int i = 1; i <= 27; i++)
	{
		if (str[i] = 'a-z') str[i] = s;
	}
}

void String::getStr()
{
	cout << str << endl; //вывод
}

void main()
{
	setlocale(LC_CTYPE, "rus");
	char n;
	char str1[256], str2[256];
	cout << "Please, write str1: ";
	cin >> str1;
	cout << "Please, write str2: ";
	cin >> str2;
	cout << endl;


	cout << "===============================================" << endl;
	cout << "COMPARISON: " << endl;
	if (strlen(str1) < strlen(str2) || strlen(str1) == strlen(str2)) cout << "True-True-True-True-True-True!!!!!" << endl;
	else cout << "False-False-False-False-False-False!!!!!" << endl;
	cout << "==============================================="<<endl;
	cout << endl;


	cout << "===============================================" << endl;
	cout << "ADDITIONS: " << endl;
	String string1(str1);
	cout << "Str1 + Str2: ";
	string1 + str2;
	string1.getStr();
	cout << "===============================================" << endl;
	cout << endl;
	
	
	cout << "===============================================" << endl;
	String string2(str2);
	cout << "Start Str2: ";
	string2.getStr();
	cout << "Last symbol str2: " << str2[strlen(str2) - 1] << endl;
	cout << "Write symbol for delete: ";
	cin >> n;
	string2 - n;
	cout << "Finish Str2: ";
	string2.getStr();
	cout << "===============================================" << endl;
	cout << endl;


	cout << "===============================================" << endl;
	char str3[10];
	cout << "Write str3: ";
	cin >> str3;
	String string3(str3);
	cout << "Str3: ";
	string3.getStr();
	string3 * 'q';
	cout << "New str3: ";
	string3.getStr();
	cout << endl;

//delete[] str1, str2;
}