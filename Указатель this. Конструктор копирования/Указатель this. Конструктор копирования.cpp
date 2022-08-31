#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int task;

	cout << "1 - задание \n";
	cout << "2 - задание \n";
	cout << "0 - выход \n";
	cout << "\nВыбор :";
	cin >> task;
	cin.ignore(123, '\n');
	switch (task)
	{
	case 1: {

		char* str = new char[80];

		String s3;

		cout << "Введите строку :";
		gets_s(str, 80);

		int size = strlen(str) + 1;

		cout << "\nВаша строка - ";

		s3.initString(str, size);



		String s(5, "Куку");

		String s2 = s;

		s2.getString();


		 String s4(move(s3));

		 s4.getString();

			cout << '\n';

			/*cout << "Кол-во созданных обьектов : " << String::getCount() << endl << endl;*/

		
		break;
	}
	case 2: {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		int choice;
		bool isInitArray = false;
		int* mass = new int[128];
		int size = 0;
		
		cout << "\nРазмер массива :";
		cin >> size;

		Array ar(size);
		
		cin.ignore(312, '\n');


		Array&& ar2{ move(ar) };
		Array& ar3 = ar;



		do
		{
			SetConsoleTextAttribute(hConsole, 7);

			system("cls");
			cout << "---------------------------------------------\n";
			cout << "-   Что будем делать с массивом?            -\n";
			cout << "-                                           -\n";
			cout << "-   1 - заполить массив значениями          -\n";
			cout << "-   2 - отображать содержимое массива       -\n";
			cout << "-   3 - изменять размер массива             -\n";
			cout << "-   4 - сортировать массив                  -\n";
			cout << "-   5 - определить мин. и макс. значения    -\n";
			cout << "-   6 - конструктор пересноса               -\n";
			cout << "-   7 - конструктор копирования             -\n";
			cout << "-   0 - выход                               -\n";
			cout << "---------------------------------------------\n";
			cout << "Выбор :";
			cin >> choice;

			switch (choice)
			{
			case 1: {
				
				ar.initArray(mass, size);


				SetConsoleTextAttribute(hConsole, 23);
				cout << "Массив успешно заполнен\n\n";
				SetConsoleTextAttribute(hConsole, 7);

				isInitArray = true;

				system("pause");
				break;
			}
			case 2: {

				if (isInitArray) {
					ar.showArray(mass, size);

				}
				else {

					SetConsoleTextAttribute(hConsole, 31);
					cout << "\n\tПодсказка - Массив еще не создан!\n\n";
					SetConsoleTextAttribute(hConsole, 15);
				}

				system("pause");
				break;
			}
			case 3: {

				int tmp = size;
				cout << "Новый размер массива :";
				cin >> size;
				cin.ignore(123, '\n');

				if (size == 1)
					cout << "\nТекущий размер массива на " << tmp << " элемент";
				if (size == 2 || size == 3 || size == 4)
					cout << "\nТекущий размер массива на " << tmp << " элемента";
				if (size >= 5)
					cout << "\nТекущий размер массива на " << tmp << " элементов";
		
				if (tmp > size) 
				{
					if (size == 1)
						cout << "\n\nБыл успешно уменьшен на " << size << " элемент" << endl << endl;
					if (size == 2 || size == 3 || size == 4)
						cout << "\n\nБыл успешно уменьшен на " << size << " элемента" << endl << endl;
					if (size >= 5)
						cout << "\n\nБыл успешно уменьшен на " << size << " элементов" << endl << endl;
				}
				else if (tmp < size)
				{
					if (size == 1)
						cout << "\n\nБыл успешно уменьшен на " << size << " элемент" << endl << endl;
					if (size == 2 || size == 3 || size == 4)
						cout << "\n\nБыл успешно уменьшен на " << size << " элемента" << endl << endl;
					if (size >= 5)
						cout << "\n\nБыл успешно уменьшен на " << size << " элементов" << endl << endl;
				}
				else if (tmp == size) {
					if (size == 1)
						cout << "\n\nОстался на " << size << " элемент" << endl << endl;
					if (size == 2 || size == 3 || size == 4)
						cout << "\n\nОстался на " << size << " элемента" << endl << endl;
					if (size >= 5)
						cout << "\n\nОстался на " << size << " элементов" << endl << endl;
				}
				
				system("pause");
				break;
			}
			case 4: {

				ar.sortArray(mass, size);

				if (!isInitArray) {
					SetConsoleTextAttribute(hConsole, 31);
					cout << "\n\tПодсказка - Массив еще не создан!\n\n";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else {
					SetConsoleTextAttribute(hConsole, 23);
					cout << "\nВаш массив отсортирован\n\n";
					SetConsoleTextAttribute(hConsole, 7);

				}

				system("pause");
				break;
			}
			case 5: {

				if (!isInitArray) cout << "\nДа здравствуют мусорные значения!\n";

				cout << "\nМаксимальный элемент в массиве - " << ar.maxArray(mass,size) << endl;

				cout << "\nМинимальный элемент в массиве - " << ar.minArray(mass, size) << endl << endl;

				SetConsoleTextAttribute(hConsole, 2);
				if (!isInitArray) cout << "Подсказка - Инициализируйте ваш массив\n\n";
				SetConsoleTextAttribute(hConsole, 7);


				system("pause");
				break;
			}
			case 6: {
				

				ar2.showArray(mass, size);

				system("pause");
				break;
			}
			case 7: {


				ar3.showArray(mass, size);

				system("pause");
				break;
			}
			case 0: {
				cout << "\nВыходим...\n";
				exit(0);
			}

			default:
				cout << "Error!\n";
				break;
			}


		} while (choice != 0);

		break;
	}
	case 0: {  cout << "Выходим...\n";  break;}
	default:
		cout << "Error!\n";
		break;
	}


	return 0;
}

