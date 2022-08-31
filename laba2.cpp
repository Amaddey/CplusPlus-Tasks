#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct Book
{
    char title[30];
    char author[30];
    char publisher[30];
    char genre[30];
};

Book* Create(int size) {

    Book* books = new Book[size];
    return books;
}

void Edit(Book* books, int index) {
    cin.ignore();
    books[index - 1] = inputBook();
}



Book inputBook() {
    Book book;
    cout << "Название:\n";
    cin.ignore();
    gets_s(book.title, 20);
    cout << "Автор:\n";
    cin.ignore();
    gets_s(book.author, 20);
    cout << "Издатель:\n";
    cin.ignore();
    gets_s(book.publisher, 20);
    cout << "Жанр:\n";
    cin.ignore();
    gets_s(book.genre, 20);

    return book;
}

void printBook(Book book) {

    cout << book.title << endl;
    cout << book.author << endl;
    cout << book.publisher << endl;
    cout << book.genre << endl;
}


void listBooks(Book* books, int size) {

    cout << "Вывод книг:" << endl;

    for (int i = 0; i < size; i++)
    {
        printBook(books[i]);
    }
    cout << "\n";
}

void deleteBook(Book* books) {
    delete[] books;
}

Book* addBook(Book* books, int& size, Book book) {
    Book* tmp = Create(size + 1);

    for (int i = 0; i < size; i++)
    {
        *(tmp + i) = *(books + i);
    }
    *(tmp + size) = book;
    deleteBook(books);
    size++;
    return tmp;
}


void Edit(Book* books, int index) {

    cin.ignore();
    books[index - 1] = inputBook();
}


void sortByTitleBook(Book* books, int size) {
    for (int i = 0; i < size; i++)
    {
        Book tmp = books[i];
        int j;
        for (j = i - 1; j >= 0 && strcmp(books[j].title, tmp.title) > 0; j--)
        {
            books[j + 1] = books[j];
        }
        books[j + 1] = tmp;
    }


}

void searchAuthorBook(Book* books, int& size, char* searhcAuthor) {

    for (int i = 0; i < size; i++)
    {
        if (strcmp(searhcAuthor, books[i].author) == 0) {
            printBook(books[i]);
            cout << "\n";
        }
    }


}

void searchAuthorBook(Book* books, int& size, char* searhcAuthor) {

    for (int i = 0; i < size; i++)
    {
        if (strcmp(searhcAuthor, books[i].author) == 0) {
            printBook(books[i]);
            cout << "\n";
        }
    }


}


//
//Book* deleteTitleBooks(Book*  books, int& size, char* searchTitle) {
//    Book* tmp = Create(size - 1);
//    int gg = 0;
//
//    for (int i = 0; i < size; i++)
//    {
//        if (strcmp(searchTitle, books[i].title == 0)) 
//        {
//            continue;
//        }
//        tmp[gg] = books[i];
//            gg++;
//    }
//    
//} // Пишет ошибку в интернене ответа не нашел

void SearchTitleBook(Book* books, int& size, char* searchTitle) {

    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchTitle, books[i].title) == 0) {

            printBook(books[i]);
            cout << endl;
        }
    }


}


int main()
{
    setlocale(LC_ALL, "Russian");


    int size = 10;
    Book* books = Create(size);
    books[0] = { "Ремонт_ПК", "Мюллер", "Вильямс", "Справочник" };
    books[1] = { "Язык_програмирования_С", "Керниган", "Вильямс", "Учебник" };
    books[2] = { "Java_8", "Шилдт", "Oracle Press", "Руководство" };
    books[3] = { "Head_First_Java", "Sierra", "Oreilly", "Учебник" };
    books[4] = { "Google_Android", "Голощапов", "БХВ-Петербург", "Учебник" };
    books[5] = { "Справочное_руководство_по_С", "Страустрап", "Бином", "Справочник" };
    books[6] = { "Head_First Android", "Гриффитс", "Oreilly", "Учебник" };
    books[7] = { "Язык_програмирования_С", "Прата", "Вильямс", "Лекции" };
    books[8] = { "Стандарт_С++", "Чупринов", "Интерстрон", "Справочник" };
    books[9] = { "Ява_и_С++", "Мартин", "Диалектика", "Справочник" };

    int menu;

    do
    {
        cout << "\t Меню библиотеки |\n";
        cout << "1 - Редактировать книгу |\n";
        cout << "2 - Печать всех книга |\n";
        cout << "3 - Поиск книги по автору |\n";
        cout << "4 - Поиск книги по названию |\n";
        cout << "5 - Сортировка массива по названию книг|\n";
        cout << "6 - Сортировка массива по автору|\n";
        cout << "7 - Сортировка массива по издательству|\n";
        cout << "8 - Добавление новой книги|\n";
        cout << "9 - Удаление книги по названию|\n";
        cout << ":";
        cin >> menu;
        system("cls");

        switch (menu)
        {
        case 1: {
            cout << "Enter iinde of book:";
            int indexOfBook;
            cin >> indexOfBook;
            Edit(books, indexOfBook);


            break;
        }
        case 2: {

            listBooks(books, size);

            break;
        }
        case 3: {

            cout << "Enter an author of book:";
            char searhByAuthor[20];
            cin.ignore();
            gets_s(searhByAuthor, 20);
            searchAuthorBook(books, size, searhByAuthor);

            break;
        }
        case 4: {

            char searchTitle[20];
            cout << "Enter title book:";
            cin.ignore();
            gets_s(searchTitle, 20);
            SearchTitleBook(books, size, searchTitle);


            break;
        }
        case 5: {

            sortByTitleBook(books, size);
            listBooks(books, size);

            break;
        }
        case 6: {

            listBooks(books, size);

            
            break;
        }
        case 7: {

            listBooks(books, size);


            break;
        }
        case 8: {

            addBook(books, size, inputBook());
            listBooks(books, size);


            break;
        }
        case 9: {
            char searchTitle[20];
            cout << "Enter title book:\n";
            cin.ignore();
            gets_s(searchTitle, 20);
            //books = deleteTitleBook(books,size,searhcTitle);
            listBooks(books, size);

            break;
        }

        default:
            cout << "Error\n";
            break;
        }




    } while (menu != 0);




    return 0;
}
