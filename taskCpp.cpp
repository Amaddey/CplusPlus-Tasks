#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <memory>
#include <iterator>

using namespace std;


//Написать программу ≪Автоматизированная информационная система ЖД вокзала≫.Система содержит :
//сведения об отправлении поездов дальнего следования.Для каждого поезда указываем : 
//номер, время отправления, станцию назначения.
// Обеспечить :
// Ввод данных в систему;
// Вывод информации о всех поездах;
// Вывод информации о запрашиваемом поезде.
//Использовать контейнерный класс vector


enum eFind
{
	NUMBER = 1,
	TIME,
	DESTINATION
};

class Train
{
private:
	string number, time, destination;
public:

	void InitTran()
	{
		cin.ignore();
		cout << "Number :";
		getline(cin, number);
		cout << "Time :";
		getline(cin, time);
		cout << "Destination :";
		getline(cin, destination);
	}

	void ShowTrain()
	{
		cout << "Number :" << number << endl;
		cout << "Time :" << time << endl;
		cout << "Destination :" << destination << endl;
	}

	string getNumber(){return number;}

	string getTime(){return time;}

	string getDestination(){return destination;}


	void FindBy(vector<Train> vecTrain ,eFind choice)
	{
		switch (choice)
		{
		case NUMBER:
		{
			cout << "Number of searching train :";
			string numTrain;
			getline(cin, numTrain);

			for (size_t i = 0; i < vecTrain.size(); i++)
			{
				if (vecTrain[i].getNumber() == numTrain)
				{
					vecTrain[i].ShowTrain();
				}
			}

		}
		break;
		case TIME:
		{
			cout << "Time of searching train :";
			string timeTrain;
			getline(cin, timeTrain);

			for (size_t i = 0; i < vecTrain.size(); i++)
			{
				if (vecTrain[i].getTime() == timeTrain)
				{
					vecTrain[i].ShowTrain();
				}
			}

		}
		break;
		case DESTINATION:
		{
			cout << "Destination of searching train :";
			string desTrain;
			getline(cin, desTrain);

			for (size_t i = 0; i < vecTrain.size(); i++)
			{
				if (vecTrain[i].getDestination() == desTrain)
				{
					vecTrain[i].ShowTrain();
				}
			}

		}
		break;
		default:
			cout << "Error\n";
			break;
		}


	}

};


int main()
{
	setlocale(LC_ALL, "Russian");

		Train train;
		vector<Train> vectorTrains;
	while (true)
	{
		system("cls");

		char ch;
		cout << "1 - Добавить поезд\n";
		cout << "2 - Вывод информации о всех поездах\n";
		cout << "3 - Вывод информации о запрашиваемом поезде\n";
		cout << "0 - выход\n";
		cout << "input :";
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			do
			{
				train.InitTran();

				vectorTrains.push_back(train);

				cout << "Добавить еще поезд (y/n) :";
				cin >> ch;


			} while (ch == 'y');
		}
		else if (choice == 2) 
		{
			for (size_t i = 0; i < vectorTrains.size(); i++)
			{
				cout << "Train #" << i + 1 << endl;
				vectorTrains[i].ShowTrain();
			}
		}
		else if (choice == 3)
		{
			cout << "Find train by :\n";
			cout << "1 - number of train\n";
			cout << "2 - number of time\n";
			cout << "3 - number of destination\n";
			cout << "input :";
			int input;
			cin >> input;
			cin.ignore();
			eFind input1 = static_cast<eFind>(input);
			train.FindBy(vectorTrains, input1);

		}
		else if (choice == 0)
		{
			exit(0);
		}

		system("pause");
	}


  return 0;		
}