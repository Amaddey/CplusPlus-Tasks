#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
//Создать интерфейс приложения, который пользователь сможет использовать для регулирования папок.
//В итоге у нас должна получиться программа для настройки псевдо файловой системы.
//Вот какой функционал она будет иметь :
//1.	Добавление новых элементов.
//2.	Удаление одного или сразу всех элементов со значением
//3.	Использование операции lower_bound для поиска папок.
//4.	Оперирование операцией upper_bound для поиска папок.
//5.	Оперирование операцией equal_range для поиска папок.

class FileSystem
{
private:
    multiset<string> fNameSet;
    multiset<string>::iterator it;
public:
    FileSystem() = default;

    void InsertEl()
    {
        cout << "Size : ";
        int size;
        cin >> size;
        string newName;

        for (size_t i = 0; i < size; i++)
        {
            cout << "File #" << i + 1 << " name : ";
            cin >> newName;
            fNameSet.insert(newName);
        }
    }

    void EraseEl()
    {
        cout << "Enter folder name :";
        string folderName;
        getline(cin, folderName);

        it = fNameSet.find(folderName);

        if (fNameSet.find(folderName) != fNameSet.end())
            fNameSet.erase(it);
        else
            cout << "File isn't found\n";

    }

    void lBound()
    {
        cout << "Enter lBound :";
        string str;
        getline(cin, str);

        it = fNameSet.lower_bound(str);

        if (it == fNameSet.end())
        {
            cout << "Not found\n";
        }
        else
        {
        cout << "lBond :" << *it << endl;
        }

    }

    void uBound()
    {
        cout << "Enter uBound :";
        string str;
        getline(cin, str);

        it = fNameSet.upper_bound(str);

        if (it == fNameSet.end())
        {
            cout << "Not found\n";
        }
        else
        {
            cout << "uBond :" <<  *it << endl;
        }

    }

    void Range()
    {
        cout << "Enter equalRange :";
        string str;
        getline(cin, str);

        auto it1 = fNameSet.equal_range(str).first;
        auto it2 = fNameSet.equal_range(str).second;


        if (it1 == fNameSet.end() || it2 == fNameSet.end())
        {
            cout << "Not found\n";
        }
        else
        {
            cout << "equal :" << *it1 << " , " << *it2 << endl;
        }


    }
    void PrintFolder() //sort by alphabet (default)
    {
        int count = 0;
        for (auto it : fNameSet)
        {
            cout << "File #" << count + 1 << endl;
            cout << it << endl;
            count++;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");   
    FileSystem fs;


    while (true)
    {
        system("cls");    


cout << " 1. 	Добавление новых элементов.                               " << endl;
cout << " 2.	Удаление одного или сразу всех элементов со значением " << endl;
cout << " 3.	Использование операции lower_bound для поиска папок.  " << endl;
cout << " 4.	Оперирование операцией upper_bound для поиска папок.  " << endl;
cout << " 5.	Оперирование операцией equal_range для поиска папок.  " << endl;
cout << " 6.    Вывести " << endl;
cout << " 0.    Выйти " << endl;
cout << "Input : ";
int inp;
cin >> inp;
cin.ignore();
    switch (inp)
    {
    case 1:
    {
        fs.InsertEl();
    }
    break;
    case 2:
    {
        fs.EraseEl();
    }
    break;
    case 3:
    {
        fs.lBound();
    }
    break;
    case 4:
    {
        fs.uBound();
    }
    break;
    case 5:
    {
        fs.Range();
    }
    break;
    case 6:
    {
        fs.PrintFolder();
    }
    break;
    case 0:
    {
        exit(0);
    }
    break;
    default:
        cout << "Error\n";
        break;
    }

    system("pause");

    }

    return 0;
}
