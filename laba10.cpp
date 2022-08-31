#include <iostream>
#include <string>
#include "Fraction.h"
#include <typeinfo>

using namespace std;

class Good
{
protected:
	string mBrand;
	int mDiagonal;
	int mPrice;
public:

	//virtual Good* randType() = 0;

	virtual void Show() = 0;

};

class Laptop : public Good
{
public:
	Laptop(string brand,int diagonal)
	{
		mBrand = brand;
		mDiagonal = diagonal;
	}

	void Show() override
	{
		cout << "-----What - Laptop-----" << endl;
		cout << "mBrand - " << mBrand << endl;
		cout << "mDiagonal - " << mDiagonal << endl;
	}

};

class Phone : public Good
{
public:

	Phone(int price)
	{
		mPrice = price;
	}

	void Show() override
	{
		cout << "-----What - Phone-----" << endl;
		cout << "mPrice - " << mPrice << endl;
	}
};

class Sausages : public Good
{
public:
	Sausages(string brand,int price)
	{
		mBrand = brand;
		mPrice = price;
	}

	void Show() override
	{
		cout << "-----What - Sausages-----" << endl;
		cout << "mBrand - " << mBrand << endl;
		cout << "mPrice - " << mPrice << endl;
	}
};


Good* randType() {

		int type = 1 + rand() % 3;
		string brand;
		int diagonal;
		int price;

		switch (type)
		{
		case 1: { // laptop

			cout << "Laptop brand : ";
			getline(cin, brand);
			cout << "Laptop diagonal : ";

			cin >> diagonal;
			cin.ignore();

			Good* goods = new Laptop(brand,diagonal);
			return goods;

		}
			  break;
		case 2: { //phone


			cout << "Phone price : ";
			

			cin >> price;
			cin.ignore();

			Good* goods = new Phone(price);
			return goods;

		}
			  break;
		case 3: { //sausages

			cout << "Sausage brand : ";
			getline(cin, brand);
			
			cout << "Sausage price : ";
			cin >> price;
			cin.ignore();


			Good* goods = new Sausages(brand, price);
			return goods;

		}
			  break;
		}


}

void checkType(Good* good, int& countL,int& countP, int& countS)
{
	if (typeid(*good) == typeid(Laptop))
	{
		countL++;
	}
	else if (typeid(*good) == typeid(Phone))
	{
		countP++;
	}
	else if (typeid(*good) == typeid(Sausages))
	{
		countS++;
	}

}


int main()
{
	setlocale(LC_ALL,"Russian");
	srand(time(0));
	
	const int size = 3;

	Good* goods[size];
	int countL = 0,countP = 0,countS = 0;


	for (size_t i = 0; i < size; i++)
	{
		goods[i] = randType();
		checkType(goods[i], countL,countP,countS);
	}

	cout << "-----Кол-во-----" << endl;
	cout << "Кол-во Laptop - " << countL << endl;
	cout << "Кол-во Phone - " << countP << endl;
	cout << "Кол-во Sausages - " << countS << endl;

	for (size_t i = 0; i < size; i++)
	{
		goods[i]->Show();
		delete goods[i];
	}

	return 0;
}
