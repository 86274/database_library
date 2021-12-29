#ifndef LIBRARY_H
#define LIBRARY_H

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <chrono>
#include "Book.h"

class Library
{
public:
	Library() : library{} {};

	void addBook(const Book& book);

	void printLib() const; 

	//heapsort
	void sortLibrary();
	
	void searchLibrary() const;

	void editBook();

	void readFile(const string&);
	void writeFile(const string&) const;

private:
	vector<Book> library;

	int selectBook();

	void siftDownPage(const int root, int bottom);
	void siftDownISBN(int root, int bottom);
	void siftDownAuthor(int root, int bottom);
	void siftDownNameBook(int root, int bottom);
};

#endif