#pragma once

#include "Library.h"

void Library::addBook(const Book& book)
{
    library.push_back(book);
}

void Library::printLib() const { //Вывод списка

    std::cout << std::setw(4) << "№" << std::setw(4) << "ID" << std::setw(45) << " Автор" << std::setw(30) << "Название" << std::setw(11)
        << "Страниц" << std::setw(16) << "ISBN" << std::endl;
    for (int i = 0; i < 114; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

    int i{ 1 };
    for (const auto& book : library)
    {
        std::cout << std::setw(4) << i++;
        book.printBook();
    }
    system("pause");
}

void Library::siftDownPage(int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (library[root * 2].getPage() > library[root * 2 + 1].getPage())
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (library[root].getPage() < library[maxChild].getPage())
        {
            swap(library[root], library[maxChild]);
            root = maxChild;
        }
        else
            done = 1;
    }
}

void Library::siftDownISBN(int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (library[root * 2].getISBN() > library[root * 2 + 1].getISBN())
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (library[root].getISBN() < library[maxChild].getISBN())
        {
            swap(library[root], library[maxChild]);
            root = maxChild;
        }
        else
            done = 1;
    }
}

void Library::siftDownAuthor(int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (library[root * 2].getAuthor() > library[root * 2 + 1].getAuthor())
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (library[root].getAuthor() < library[maxChild].getAuthor())
        {
            swap(library[root], library[maxChild]);
            root = maxChild;
        }
        else
            done = 1;
    }
}

void Library::siftDownNameBook(int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (library[root * 2].getName() > library[root * 2 + 1].getName())
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (library[root].getName() < library[maxChild].getName())
        {
            swap(library[root], library[maxChild]);
            root = maxChild;
        }
        else
            done = 1;
    }
}

void Library::sortLibrary()
{
    Menu m;
    string text{ "По какому значение произвести сортировку?\n" };
    vector<string >textMenu{ "ФИО Автора", "Название книги", "ISBN", "Количество страниц" };
    size_t k{ textMenu.size() };

    switch (m.printMenu(text, k, textMenu))
    {
    case 0: {
        for (int i = (library.size() / 2); i >= 0; i--)
            siftDownAuthor(i, library.size() - 1);
        for (int i = library.size() - 1; i >= 1; i--)
        {
            swap(library[0], library[i]);
            siftDownAuthor(0, i - 1);
        }
    }
          break;
    case 1: {
        for (int i = (library.size() / 2); i >= 0; i--)
            siftDownNameBook(i, library.size() - 1);
        for (int i = library.size() - 1; i >= 1; i--)
        {
            swap(library[0], library[i]);
            siftDownNameBook(0, i - 1);
        }
    }
          break;
    case 2: {
        for (int i = (library.size() / 2); i >= 0; i--)
            siftDownISBN(i, library.size() - 1);
        for (int i = library.size() - 1; i >= 1; i--)
        {
            swap(library[0], library[i]);
            siftDownISBN(0, i - 1);
        }
    }
          break;
    case 3: {
        for (int i = (library.size() / 2); i >= 0; i--)
            siftDownPage(i, library.size() - 1);
        for (int i = library.size() - 1; i >= 1; i--)
        {
            swap(library[0], library[i]);
            siftDownPage(0, i - 1);
        }
    }
          break;
    default:
        break;
    }
    
}

void Library::searchLibrary() const {
    cout << "Введите значение по которому будете осуществлять поиск:" << endl;
    cout << " 1. Автор " << endl;
    cout << " 2. Название " << endl;
    cout << " 3. ISBN " << endl;
    cout << " 4. Количество страниц" << endl;

    int search{};
    std::cin.clear();
    if (std::cin >> search) {}
    else
    {
        std::cout << "Некорректное значение" << std::endl;
    }
    std::cin.ignore(1);

    if (search == 1) {
        cout << "Введите ФИО по которому будете осуществлять поиск:" << endl;
        string author;
        getline(cin, author);
        auto it = find_if(library.begin(), library.end(), [&](const Book& book)->bool
            {
                return book.getAuthor() == author;
            });
        if (it != library.end())
        {
            it->printBook();
        }
        else
        {
            cout << "Книга автора не найдено" << endl;
        }
    }

    if (search == 2) {
        cout << "Введите значение по которому будете осуществлять поиск:" << endl;
        string name;
        getline(cin, name);
        auto it = find_if(library.begin(), library.end(), [&](const Book& book)->bool
            {
                return book.getName() == name;
            });
        if (it != library.end())
        {
            it->printBook();
        }
        else
        {
            cout << "Книга не найдена" << endl;
        }
    }

    if (search == 3) {
        cout << "Введите ISBN по которому будете осуществлять поиск:" << endl;
        string ISBN;
        getline(cin, ISBN);
        auto it = find_if(library.begin(), library.end(), [&](const Book& book)->bool
            {
                return book.getISBN() == ISBN;
            });
        if (it != library.end())
        {
            it->printBook();
        }
        else
        {
            cout << "Мы не нашли книги с данным ISBN " << endl;
        }
    }

    if (search == 4) {
        cout << "Введите значение по которому будете осуществлять поиск:" << endl;
        int page{};
        if (std::cin >> page) {}
        else
        {
            std::cout << "Некорректное значение" << std::endl;
        }
        auto it = find_if(library.begin(), library.end(), [&](const Book& book)->bool
            {
                return book.getPage() == page;
            });
        if (it != library.end())
        {
            it->printBook();
        }
        else
        {
            cout << "Мы не нашли книги с данным количеством страниц" << endl;
        }
    }
}

void Library::editBook()
{

    int numberBook = selectBook(); //получение номера книги
    Menu m;
    string text = "Выберите атрибут для изменения\n";
    vector<string> textMenu { "Редактировать книгу", "Удалить книгу", "Назад" };
    size_t k{ textMenu.size() };
    while (k > 0)
    {
        switch (m.printMenu(text, k, textMenu))
        {
        case 0:
            library.at(numberBook).editBook();
            break;
        case 1:
        {
            library.erase(library.begin() + numberBook);
            k = 0;
        }
            break;
        case 2:
            k = 0;
            break;
        default:
            break;
        }
    }
}

int Library::selectBook()
{
    Menu m;
    size_t k = library.size();
    string text = "Выберите книгу";
    vector<string> textMenu;

    for (const auto& book : library)
    {
        textMenu.push_back(book.getAuthor() + " " + book.getName() + " " + to_string(book.getPage()) + " " + book.getISBN());
    }

    int numberBook = m.printMenu(text, k, textMenu);

    return numberBook;
}

void Library::readFile(const string& file) // считывание данных с файла
{
    ifstream fopen(file);

    if (!fopen.is_open())
    {
        std::cout << "error reading file" << endl;
        std::system("pause");
    }
    else
    {
        string author, name, ISBN;
        int page;
        size_t size;
        fopen >> size; //получение количества записей
        fopen.ignore(1);

        for (size_t i = 0; i < size; i++)
        {
            getline(fopen, author);
            getline(fopen, name);
            fopen >> ISBN;
            fopen.ignore(1);
            fopen >> page;
            fopen.ignore(1);
            library.push_back(Book{author, name, ISBN, page});
        }

        fopen.close();
    }
}

void Library::writeFile(const string& file) const //запись в файл 
{
    if (library.empty()){
        std::cout << "В списке нет записей" << endl;
    }
    else
    {
        ofstream table(file);

        if (!table.is_open()) //запись для считывания
        {
            std::cout << "error reading file";
        }
        else
        {
            table << library.size() << endl;
            for (const auto& book : library)
            {
                table << book.getAuthor() << endl;
                table << book.getName() << endl;
                table << book.getISBN() << endl;
                table << book.getPage() << endl;
            }
            table.close();
        }   
    }
}

