#include <iostream>
#include <functional>
#include "Osipova_MyTask.h"

struct MenuItem {
    std::string title;
    std::function<void()> action;

    MenuItem(std::string t, std::function<void()> a) : title(t), action(a) {}
};



int main() {

	setlocale(LC_ALL, "ru");

	map<int, MenuItem> menu = 

	{

		{ 1,{" Ввести первый символ", inputFirstChar } },
		{2, {" Ввести второй символ", inputSecondChar}},
		{3, {" Вывести каждый символ и код ASCII", printCharAndAscii}},
		{4, {" Вывести сумму кодов ASCII символов ch1 и ch2", printAsciiSum}},

	};

	int choice = 0;



	while (true) {

		cout << "Меню:" << endl;

		for (const auto& item : menu) {

			cout << "Task " << item.first << ". " << item.second.title << endl;

		}

		cout << "0. Выход" << std::endl;

		enterNumber(choice, "Введите пункт из меню ");

		if (choice == 0) {

			cout << "© 2025 FirstName LastName" << endl;

			break;

		}

		cout << endl;

		if (menu.find(choice) != menu.end()) {

			menu[choice].action();

		}

		else {

			cout << "Некорректный ввод.";

		}

		cout << endl;

	}

	return 0;

}