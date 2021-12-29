#include "Menu.h"

int Menu::printMenu(const string& text, const size_t& k, const vector<string>& textMenu)
{
	auto key = 0;
	int code;

	do {
		system("cls");
		cout << text << endl;
		key = (key + k) % k;
		for (size_t i = 0; i < k; i++) {
			if (key == i) cout << "-> " << textMenu[i] << endl;
			else  cout << "   " << textMenu[i] << endl;
		}

		code = _getch();
		if ((code == 115) || (code == 119))
		{
			if (code == 115) key++;
			if (code == 119) key--;
		}
		else
			if (code == 224) {
				code = _getch();
				if (code == 80) key++;
				if (code == 72) key--;
			}

	} while (code != 13);
	system("cls");
	return key;
}


