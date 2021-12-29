#include <Windows.h>
#include "Library.h"

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Menu m;
	Library library;

	string text = "Главное меню\n";
	vector<string> textMenu{ "Новая книга", "Вывести список книг","Редактировать список", "Сортировка",
							"Поиск", "Записать базу в файл", "Считать базу с файла"};

	do
	{
		switch (m.printMenu(text, textMenu.size(), textMenu))
		{
		case 0:
			library.addBook(Book{});
			break;
		case 1: {
			library.printLib();
		}
			  break;
		case 2: {
			library.editBook();
		}
			  break;
		case 3: {
			library.sortLibrary();
			system("pause");
		}
			  break;
		case 4: {
			library.searchLibrary();
			system("pause");
		}
			  break;
		case 5: {
			cout << "Введите название файла" << endl;
			string file;
			cin >> file;
			library.writeFile(file);
			cout << "Успешно" << endl;
			system("pause");
		}
			  break;
		case 6: {
			cout << "Введите название файла" << endl;
			string file;
			cin >> file;
			library.readFile(file);
		}
			  break;
		default:
			break;
		}
	} while (true);

}
