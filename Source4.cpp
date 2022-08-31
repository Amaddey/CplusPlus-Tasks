#include <iostream>
#include <string>
#include<vector>
#include<functional>
#include <algorithm>
#include <array>

using namespace std;
void Foo() {
	cout << "Foo()" << endl;
}
void Range(int a) {
	if (a > 10 && a < 40)
		cout << a << endl;
}
void Even(int a) {
	if (a % 2 == 0) {
		cout << a << endl;
	}
}
void VecFunc(vector<int>& vc, function<void(int)>func) {
	for (auto el : vc) {
		func(el);
	}
}
int Sum(int a, int b) {
	return a + b;
}
struct Car
{
	string make{};
	string model{};
};
// Функция возвращает лямбду
auto makeWalrus(const string& name)
{
	// Захват переменной name по ссылке и возврат лямбды
	return [&]() {
		cout << "I am a walrus, my name is " << name << '\n';
	};
}
void invoke(const function<void(void)>& fn)
{
	fn();
}
class MyClass {
	int x = 1;
	int y = 2;
public:
	MyClass() :x(10), y(20) {}
	void doSomthing() {
		auto lambda = [this](int _x) {
			cout << x * _x*y << endl;
		};
		lambda(5);
	}
	int getX() {
		return x;
	}
};
int main()
{

	int menu;

	do
	{
		cout << "Enter choose : ";
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			void(*pfunc)() = Foo;
			(*pfunc)();
			function<void()>fun = Foo;
			fun();
			function<int(int, int)>fSum;
			fSum = Sum;
			int rez = fSum(2, 5);
			cout << rez << endl;
			break;
		}
		case 2:
		{
			vector<int> vc = { 1,10,50,3,45,78,3,63 };
			VecFunc(vc, Even);
			VecFunc(vc, [](int a) {
				if (a % 2 == 0)
					cout << "Анонимная функция с параметром - " << a << endl;
				});

			break;
		}
		case 3:
		{
			array<string, 4> arr{ "apple", "banana", "walnut", "lemon" };
			auto found = find_if(arr.begin(), arr.end(),
				[](string str)
				{
					return (str.find("nut") != string::npos);
				});

			if (found == arr.end())
			{
				cout << "No nuts\n";
			}
			else
			{
				cout << "Found " << *found << '\n';
			}
			break;
		}

		case 4:
		{
			int x=0;
			double (*addNumbers1)(double, double) {
				[](double a, double b) {					
					return (a + b);
				}
			};

			cout << addNumbers1(1, 2) << endl;


			function<double(double, double)> addNumbers2{
			  [](double a, double b) {
				return (a + b);
			  }
			};

			cout << addNumbers2(3, 4) << endl;

			// Используем auto. Храним лямбду с её реальным типом
			auto addNumbers3{
			  [](double a, double b) {
				return (a + b);
			  }
			};
			cout << addNumbers3(5, 6) << endl;
			break;
		}
		case 5: {
			auto print{
		   [](auto value) {
			 static int callCount{ 0 };
			 cout << callCount++ << ": " << value << '\n';
		   }
			};

			print("hello");
			print("world");
			print(1);
			print(2);
			print("ding dong");
		}
			  break;
		case 6: {
			//  Явно указываем тип double для возвращаемого значения
			auto divide{ [](int x, int y, bool bInteger)->double{
			  if (bInteger)
				return x / y; // выполнится неявное преобразование в тип double
			  else
				return static_cast<double>(x) / y;
			} };

			cout << divide(3, 2, true) << '\n';
			cout << divide(3, 2, false) << '\n';
		}
			  break;
		case 7: {
			int max = 4;
			vector<int> vec = { 1,10,50,3,45,78,3,63 };
			sort(vec.begin(), vec.end(), [max](int a, int b) {								
				return a < b;
				});
			cout << max << endl;
			for (int item : vec) {
				cout << item << " ";
			}
			cout << endl;
			sort(vec.begin(), vec.end(), [&max](int a, int b) {
				max = 10;
				return a < b;
				});
			cout << max << endl;
			for (int item : vec) {
				cout << item << " ";
			}
			cout << endl;
		}
			  break;
		case 8:
		{

			int p = 0;
			auto f = [&p]() {p = 5; cout << p << endl; };
			f();
			int a=5, b=2;
			auto f1 = [&a,b]() {return (++a) + b; };
			auto q = f1();
			cout << q << endl;
			break;
		}
		case 9:
		{

			array<string, 4> arr{ "apple", "banana", "walnut", "lemon" };
			cout << "search for: ";
			string search{};
			cin >> search;

			// Захват переменной search
			auto found{ find_if(arr.begin(), arr.end(), [search](string str) {
			  return (str.find(search) != string::npos);
			}) };

			if (found == arr.end())
			{
				cout << "Not found\n";
			}
			else
			{
				cout << "Found " << *found << '\n';
			}
			break;
		}
		case 10: {
			int ammo{ 10 };
			auto shoot{
				[ammo]() mutable {
					--ammo;
					cout << "Pew! " << ammo << " shot(s) left.\n";
				  }
			};

			shoot();
			shoot();
			cout << ammo << " shot(s) left\n";
		}
			   break;
		case 11: {
			array<Car, 3> cars{ { { "Volkswagen", "Golf" },
							 { "Toyota", "Corolla" },
							 { "Honda", "Civic" } } };

			int comparisons{ 0 };

			sort(cars.begin(), cars.end(),
				// Захват переменной comparisons по ссылке
				[&comparisons](const auto& a, const auto& b) {
					++comparisons;
					return (a.make < b.make);
				});

			cout << "Comparisons: " << comparisons << '\n';

			for (const auto& car : cars)
			{
				cout << car.make << ' ' << car.model << '\n';
			}
		}
			   break;
		case 12: {
			array<int, 5> areas{ 100, 25, 121, 40, 56 };
			int width{};
			int height{};
			cout << "Enter width and height: ";
			cin >> width >> height;

			auto found{ find_if(areas.begin(), areas.end(),
			[=](int knownArea) { // выполняется захват по умолчанию по значению переменных width и height
			return (width * height == knownArea); // потому что они здесь упомянуты
			}) };

			if (found == areas.end())
			{
				cout << "I don't know this area :(\n";
			}
			else
			{
				cout << "Area found :)\n";
			}
		}
			   break;
		case 13: {
			array<int, 5> areas{ 100, 25, 121, 40, 56 };
			int width{};
			int height{};
			cout << "Enter width and height: ";
			cin >> width >> height;

			// Прежде, чем выполнить операцию поиска, мы должны вычислить значение площади (area)
			auto found{ find_if(areas.begin(), areas.end(),
				// Объявляем новую переменную, которая видима только для лямбды.
				// Тип переменной userArea автоматически выведен как тип int
				[userArea{ width * height }](int knownArea) {
				  return (userArea == knownArea);
				}) };

			if (found == areas.end())
			{
				cout << "I don't know this area :(\n";
			}
			else
			{
				cout << "Area found :)\n";
			}

		}
			   break;
		case 14: {
			string name = "Vasya";
			auto sayName{ makeWalrus("Roofus") };
			sayName();
		}
			   break;

		case 15: {
			MyClass obj;
			obj.doSomthing();
			cout << obj.getX() << endl;
		}
			   break;
		case 0:
		{
			break;
		}
		default:
			cout << "Error. Enter right choose!" << endl;
			break;
		}
		system("pause");
		system("cls");

	} while (menu != 0);
	return 0;
}
