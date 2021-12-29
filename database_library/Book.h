#ifndef BOOK_H
#define BOOK_H

#include <iomanip>
#include "Menu.h"

class Book
{
public:

	Book() { newBook(); };
	Book(const std::string& author, const std::string& name, const std::string& ISBN, const int& page)
		: m_author{ author }, m_name{ name }, m_ISBN{ ISBN }, m_page{ page }, m_id{ s_idGenerator++ } {}

	const std::string& getAuthor() const;
	const std::string& getName() const;
	const std::string& getISBN() const;
	const int& getPage() const;

	const Book& printBook() const;
	void editBook();

private:
	std::string m_author; //ФИО автора, название книги, ISBN
	std::string m_name;
	std::string m_ISBN;
	int m_page; 
	static int s_idGenerator;
	int m_id;

	void newBook();

	void setAuthor();
	void setName();
	void setISBN();
	void setPage();

	void newISBN();
};

#endif