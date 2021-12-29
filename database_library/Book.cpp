#include "Book.h"

int Book::s_idGenerator{ 1 };

const std::string& Book::getAuthor() const
{
	return m_author;
}

const std::string& Book::getName() const
{
	return m_name;
}

const std::string& Book::getISBN() const
{
	return m_ISBN;
}

const int& Book::getPage() const
{
	return m_page;
}

const Book& Book::printBook() const
{
    std::cout << std::setw(4) << m_id << std::setw(45) << m_author << std::setw(30) << m_name << std::setw(11)
		<< m_page << std::setw(16) << m_ISBN << std::endl;

    return *this;
}

void Book::editBook()
{

    Menu m;
    string text{ "Выберите атрибут для изменения\n" };
    vector<string> textMenu{ "ФИО Автора", "Название книги", "ISBN", "Количество страниц", "Закончить редактирование" };
    size_t k = textMenu.size();

    while (k > 0)
    {
        switch (m.printMenu(text, k, textMenu))
        {
        case 0:
            setAuthor();
            break;
        case 1:
            setName();
            break;
        case 2:
            setISBN();
            break;
        case 3:
            setPage();
            break;
        case 4:
            k = 0;
            break;
        default:
            break;
        }
    }
}

void Book::setAuthor()
{
    std::cin.clear();
    std::cout << "Введите ФИО автора" << std::endl;
    getline(std::cin, m_author);
}

void Book::setName()
{
    std::cout << "Введите название книги" << std::endl;
    getline(std::cin, m_name);
}

void Book::setISBN()
{
    newISBN();
}

void Book::setPage()
{
    std::cout << "Введите количество страниц" << std::endl;
    if (std::cin >> m_page) {}
    else
    {
        std::cout << "Некорректное значение" << std::endl;
    }
}

void Book::newBook()
{
    m_id = s_idGenerator++;

    setAuthor();

    setName();

    /*template <typename Count> Count setPage(Count x)
    {
        cout << "Введите количество страниц" << endl;
        x = enterCount(x);
        return x;
    }*/

    setPage();

    setISBN();

}

void Book::newISBN()
{
    char buf;
     m_ISBN.append("978");

    std::cout << "Номер страны происхождения или группы стран, объединненых языком издания:" << std::endl;
    std::cout << "0- группа англоязычных стран относящихся, к 0 номеру" << std::endl;
    std::cout << "1- группа англоязычных стран относящихся, к 1 номеру" << std::endl;
    std::cout << "2- франкоязычные страны" << std::endl;
    std::cout << "3- немецкие страны" << std::endl;
    std::cout << "4- Япония" << std::endl;
    std::cout << "5- русскоязычные страны" << std::endl;
    std::cout << "7- Китай" << std::endl;
    std::cin >> buf;
    m_ISBN.push_back(buf);

    std::cout << "Введите код издательства:" << std::endl;
    for (int i = 4; i < 8; i++) { // код издательства
        std::cin >> buf;
        m_ISBN.push_back(buf);
    }

    std::cout << "Введите код книги:" << std::endl;
    for (int i = 8; i < 12; i++) { // код книги
        std::cin >> buf;
        m_ISBN.push_back(buf);
    }
    
    //Расчёт контрольной цифры
    int checkDigit{ 0 };
    for (int i = 0; i < 12; i++)
    {
        checkDigit += atoi(&m_ISBN[i]) * (i + 1);
    }
    m_ISBN.append(std::to_string(11 - checkDigit % 11));

}