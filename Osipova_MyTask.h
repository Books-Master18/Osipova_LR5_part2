#ifndef _OSIPOVA_MYTASK_H
#define _OSIPOVA_MYTASK_H


#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

//проверка корректности вводимых данных 

bool UserChar(string input) {

	//если строка пустая - ввод некорректен
	if ((input.empty()) || (input.length() != 1)) return false;
	return true;

}


bool UserInput(string input) {

	//если строка пустая - ввод некорректен

	if ((input.empty()) && (input.length() != 1)) return false;

	//попытаться

	try {

		//преобразование введенного значения в тип int
		int number = stoi(input);
		if (number < 0) return false;

	}

	catch (...) //если возникла ошибка в блоке try

	{

		return false;

	}

	return true;
}



//функция ввода данных для выбора варианта



void enterNumber(int& varLink, string label)

{
	string str_input;
	cout << label << " = ";

	//ввод значения в текстовом виде
	getline(cin, str_input);

	//пока ввод некорректен

	while (!UserInput(str_input)) {
		cout << label << " = ";
		//ввод значения в текстовом виде
		getline(cin, str_input);

	}

	//присвоение переменной varLink преобразованного 
	// в тип int 
	//правильно введенного текстового значения 

	varLink = stoi(str_input);

}



//функция ввода данных

void enterChar(char& varLink, string label)

{
	string str_input;
	cout << label << " = ";

	//ввод значения в текстовом виде
	getline(cin, str_input);

	//пока ввод некорректен

	while (!UserChar(str_input)) {

		cout << label << " = ";

		//ввод значения в текстовом виде
		getline(cin, str_input);

	}

	//присвоение переменной varLink преобразованного 
	// в тип int 
	//правильно введенного текстового значения 

	varLink = str_input[0];

}


//глобальные переменные

char ch1, ch2;



void inputFirstChar() {
	enterChar(ch1, "Введите первый символ");

		//branch_fun_1

}



// Функция для ввода второго символа

void inputSecondChar() {
	enterChar(ch2, "Введите второй символ");


	//branch_fun_2

}





// Функция для вывода символа и его кода ASCII

void printCharAndAscii() {
	cout << "Символ: " << ch1 << ", Код ASCII: " << (int)ch1 << endl;
cout << "Символ: " << ch2 << ", Код ASCII: " << (int)ch2 << endl;


	//branch_fun_3

}



// Функция для вывода суммы кодов ASCII

int printAsciiSum(char ch1, char ch2) {
    int Sum = (int)ch1 + (int)ch2;
    cout << "Сумма кодов ASCII: " << Sum << std::endl;
    return Sum;
}

#endif