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
    cout << "��������:\n";
    cin.ignore();
    gets_s(book.title, 20);
    cout << "�����:\n";
    cin.ignore();
    gets_s(book.author, 20);
    cout << "��������:\n";
    cin.ignore();
    gets_s(book.publisher, 20);
    cout << "����:\n";
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

    cout << "����� ����:" << endl;

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
//} // ����� ������ � ��������� ������ �� �����

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
    books[0] = { "������_��", "������", "�������", "����������" };
    books[1] = { "����_���������������_�", "��������", "�������", "�������" };
    books[2] = { "Java_8", "�����", "Oracle Press", "�����������" };
    books[3] = { "Head_First_Java", "Sierra", "Oreilly", "�������" };
    books[4] = { "Google_Android", "���������", "���-���������", "�������" };
    books[5] = { "����������_�����������_��_�", "����������", "�����", "����������" };
    books[6] = { "Head_First Android", "��������", "Oreilly", "�������" };
    books[7] = { "����_���������������_�", "�����", "�������", "������" };
    books[8] = { "��������_�++", "��������", "����������", "����������" };
    books[9] = { "���_�_�++", "������", "����������", "����������" };

    int menu;

    do
    {
        cout << "\t ���� ���������� |\n";
        cout << "1 - ������������� ����� |\n";
        cout << "2 - ������ ���� ����� |\n";
        cout << "3 - ����� ����� �� ������ |\n";
        cout << "4 - ����� ����� �� �������� |\n";
        cout << "5 - ���������� ������� �� �������� ����|\n";
        cout << "6 - ���������� ������� �� ������|\n";
        cout << "7 - ���������� ������� �� ������������|\n";
        cout << "8 - ���������� ����� �����|\n";
        cout << "9 - �������� ����� �� ��������|\n";
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
