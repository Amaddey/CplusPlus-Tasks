#include <iostream>
#include <windows.h>

using namespace std;

class Circle {

int radius;
double length;

double const pi = 3.1415926535;

public:
	
	Circle() {
		this->radius = 0;
		this->length = 0;
	}

	Circle(const Circle& obj){
		this->radius = obj.radius;
		this->length = obj.length;
	}

	Circle(int radius, double length)
	{
		this->radius = radius;
		this->length = length;
	}
	// проверка на равенство 
	bool operator ==(const Circle& other)
	{
		if (this->radius == other.radius)
			return true;
		else if(this->radius != other.radius)
			return false;
	}
	// проверка длин 
	bool operator >(const Circle& other)
	{
		if (this->length > other.length)
			return true;
		else if (this->length <= other.length)
			return false;

	}


	void Show() {
		cout << "\nРадиус окружности : " << this->radius << endl;
		cout << "Длина окружности : " << this->length << endl;
	}

	void setRadius() {
		cout << "\nВведите радиус :";
		int radius;
		cin >> radius;
		this->radius = radius;
	}

	void setLength() {
		cout << "\nВведите длину :";
		double length;
		cin >> length;
		this->length = length;
	}

	int getRadius() {
		return this->radius;
	}

	
	double getLength() {
		return this->length;
	}
	//+= -=
	void operator +=(int n)
	{
		this->radius += n;
		this->length = 2 * pi * radius;
	}

	Circle& operator +=(const Circle other)
	{
		this->radius += other.radius;
		this->length = 2 * pi * radius;
		return *this;
	}

	void operator -=(int n)
	{
		this->radius -= n;
		this->length = 2 * pi * radius;
	}

	Circle& operator -=(const Circle other)
	{
		this->radius -= other.radius;
		this->length = 2 * pi * radius;
		return *this;
	}

};


class Airplane {
	int passengers;
	//char* typeOfplane = nullptr;
	int typeOfplane;
	int maxPassengers;
public:

	Airplane() {
		passengers = 0;
		typeOfplane = 0;
		maxPassengers = 0;
		//typeOfplane = new char[10];
	}

	void initPlane() {
		
		cout << "Тип самолёта (1 -пассажирский, 2 - грузовой) :";
		//gets_s(this->typeOfplane,10);
		cin >> this->typeOfplane;
		cout << "Максимальное кол-во людей на борту :";
		cin >> this->maxPassengers;
	}

	bool operator ==(const Airplane& obj) {
		return this->typeOfplane == obj.typeOfplane && this->passengers == this->passengers;
	}

	bool operator >(const Airplane& obj) {
		return this->maxPassengers > obj.maxPassengers;
	}

	bool operator <(const Airplane& obj) {
		return this->maxPassengers < obj.maxPassengers;
	}

	Airplane& operator++() {
		this->passengers++;

		return *this;
	}

	Airplane& operator--() {
		this->passengers--;
		return *this;
	}

	void setPassengers() {
		cout << "Пассажиры :";
		cin >> this->passengers;
	}

	int getPassengers() {
		return this->passengers;
	}

	~Airplane() {
		/*delete[] typeOfplane;*/
	}

};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice;
	Circle inputC1;
	Circle inputC2;
	/*
	Circle c1(200, 1.0);
	Circle c2(100, 2.3);

	cout << (c1 == c2) << endl;*/

	do
	{
		system("cls");
		cout << "-----------------\n";
		cout << "1 - Circle \n";
		cout << "2 - Airplane \n";
		cout << "0 - Выход \n";
		cout << "-----------------\n";
		cout << "Выбор :";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			SetConsoleTextAttribute(hConsole, 14);
			cout << "\n1 Круг :\n";
			SetConsoleTextAttribute(hConsole, 7);
			

			inputC1.setRadius();
			

			inputC1.setLength();

			inputC1.Show();

			SetConsoleTextAttribute(hConsole, 14);
			cout << "\n2 круг :\n";
			SetConsoleTextAttribute(hConsole, 7);


			inputC2.setRadius();
			
			inputC2.setLength();

			inputC2.Show();

			SetConsoleTextAttribute(hConsole, 22);
			cout << "\nРезультат\n";
			SetConsoleTextAttribute(hConsole, 7);
			int innerChoice;
			int oneZero;

			do
			{
				system("cls");
				cout << "1 - Операция ==\n";
				cout << "2 - Операция >\n";
				cout << "3 - Операция += и -= 1 круга\n";
				cout << "4 - Операция += и -= 2 круга\n";
				cout << "0 - ввести заново\n";
				cin >> innerChoice;
				switch (innerChoice)
				{
				case 1: {

					cout << "\nОперация == \n";
					oneZero = (inputC1 == inputC2);

					if (oneZero)
						cout << "\nОкружности равны\n";
					else
						cout << "\nОкружности не равны\n";
					system("pause");
					break;
				}
				case 2: {

					oneZero = (inputC1 > inputC2);

					cout << "\nОперация > \n";
					if (oneZero)
						cout << "\n1 круг больше 2 круга\n";
					else
						cout << "\n1 круг не больше 2 круга\n";
					system("pause");

					break;
				}
				case 3: {

					cout << "\n+= и -=  1 круг\n";

					inputC1 -= inputC2;
					cout << "\nОперация += " << inputC1.getLength() << endl;
					inputC1 -= 10;
					cout << "\nОперация -= " << inputC1.getLength() << endl;
					system("pause");

					break;
				}
				case 4: {
					cout << "\n+= и -=  2 круг\n";
					inputC2 += 7;
					cout << "\nОперация += " << inputC2.getLength() << endl;
					inputC2 -= 4;
					cout << "\nОперация -= -= " << inputC2.getLength() << endl;
					system("pause");

					break;
				}
				case 0: {
					cout << "Вводим заново...\n";
					break;
				}
				default:
					cout << "Error\n";
					system("pause");

					break;
				}

			} while (innerChoice != 0);

			system("pause");
			break;
		}
		case 2: {

			Airplane a;

			Airplane b;
			cout << "\n1 Самолёт\n";
			a.setPassengers();
			a.initPlane();
			cout << "\n2 Самолёт\n";
			b.setPassengers();
			b.initPlane();
			do
			{
				/*system("cls");*/
				cout << "--------------------------------------------------------------------------------\n";
				cout << "1 - Проверка на равенство типов\n";
				cout << "2 - Увеличение и уменьшение пассажирова в салоне самолета\n"; //++ --
				cout << "3 - Сравнение двух самолетов по макc. возможному кол-ву пассажиров на борту\n";
				cout << "0 - выход\n";
				cout << "--------------------------------------------------------------------------------\n";
				int innerChoice;
				cout << "Выбор :";
				cin >> innerChoice;
				switch (innerChoice)
				{
				case 1: {

					if (a == b)
						cout << "Типы самолётов равны\n";
					else 
						cout << "Типы самолётов не равны\n";

					/*system("pause");*/
					break;
				}
				case 2: {

					cout << "Увеличиваем на одного пассажира (++a ++b)\n";
					++a; ++b;
					cout << a.getPassengers() << endl;
					cout << b.getPassengers() << endl;

					cout << "Уменьшаем на одного пассажира (--a --b)\n";
					--a; --b;

					cout << a.getPassengers() << endl;
					cout << b.getPassengers() << endl;

					/*system("pause");*/
					break;
				}
				case 3: {

					if (a > b)
						cout << "1 самолёт больше по макс. кол-ву пассажиров\n";
					else if (a < b)
						cout << "2 самолёт больше по макс. кол-ву пассажиров\n";
					else if (a == b)
						cout << "Самолёты равны по макс. кол-ву пассажиров\n";


					/*system("pause");*/
					break;
				}
				case 0 :{
					cout << "Выходим...\n";
					exit(1);
					break;
					  }

				default:
					cout << "Error\n";
					break;
				}

			} while (true);



			system("pause");
			break;
		}
		case 0: {
			exit(1);
			system("pause");
			break;
		}
		default:
			cout << "Error\n";
			break;
		}

	} while (true);


	



	

	return 0;
}
