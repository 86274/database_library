#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <conio.h> 
#include <string>
#include <vector>

using namespace std;

class Menu
{

public:
	Menu() : k{}, text{}, textMenu{} {}

	int printMenu(const string& text, const size_t& k, const vector<string>& textMenu);

private:
	int k;
	string text;
	vector<string> textMenu;

};

#endif