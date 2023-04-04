#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

enum Key { Arrow = 224, Enter = 13, Up = 72, Down = 80 }; // коды клавиш
enum Menu { Menu1, Menu2, Exit };

string get_menu_name(Menu menu) {
	switch (menu)
	{
	case Exit:
		return "Выход";
	case Menu1:
		return "Меню 1";
	case Menu2:
		return "Меню 2";
	default:
		return "Unknown";
	}
}

void choice_menu1() {
	std::cout << "Вы выбрали меню1\n";
	system("pause");
}

void choice_menu2() {
	std::cout << "Вы выбрали меню2\n";
	system("pause");
}

void draw_menu(int current_choice) {
	system("cls");

	auto end = Menu::Exit;
	auto start = Menu::Menu1;

	for (int i = start; i <= end; i++) {
		cout << (current_choice == i ? '>' : ' ') << get_menu_name((Menu)i) << endl;
	}
}

void change_choice(int& choice) {
	auto key = _getch();
	switch (key)
	{
	case Up:
		choice--;
		choice = choice < 0 ? choice = 0 : choice;
		break;
	case Down:
		choice++;
		choice = choice > Menu::Exit ? choice = Menu::Exit : choice;
		break;
	}
}

void select_menu(const int& choice) {
	switch (choice) {
	case Menu1:
		choice_menu1();
		break;

	case Menu2:
		choice_menu2();
		break;

	case Exit:
		std::cout << "Выход из программы\n";
		break;
	}
}

void navigate_menu() {
	int choice = 0; // текущий выбранный пункт меню

	while (true) {
		draw_menu(choice);

		int key = _getch(); // считываем нажатую клавишу

		switch (key) {
		case Arrow:
			change_choice(choice);
			break;

		case Enter:
			select_menu(choice);
			if (choice == Menu::Exit)
				return;

			break;
		}
	}
}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);

	navigate_menu();

	return 0;
}