#include <iostream>
#include <Windows.h>

using namespace std;


class Client {

	char* FIO;

public:

	Client() {
		FIO = new char[30];
	}

	Client(const Client& other)
	{
		cout << "\n Вызываем конструктор копирования\n";
		FIO = new char[strlen(other.FIO) + 1];
		strcpy_s(FIO, strlen(other.FIO) + 1, other.FIO);
	}

	void initClient() {
		cout << endl;
		cout << "FIO :";
		gets_s(FIO, 30);
		
		cout << endl;
	}

	void showClient() {
		cout << endl;
		cout << "FIO: " << FIO << endl;
		cout << endl;
	}

	~Client() {
		delete[] FIO;
	}
};

class Bank {
	Client* c;
	Bank* b;
	int countClient;
	bool IsOpenAcount;
	int account;

public:

	Bank() {
		account = 0;
		IsOpenAcount = false;
	}

	void initAccount(int countClient, int index) {
		this->countClient = countClient;
		for (int i = 0; i < countClient; i++)
		{
			if (i == index) {
				cout << "account is open \n";
				b[i].IsOpenAcount = true;
			}
		}
	}

	void PlusAccount(int countClient,int index,int sum) {
		bool isAccount = false;
		this->countClient = countClient;
		for (int i = 0; i < countClient; i++)
		{
			if (i == index && b[index].IsOpenAcount == true) {
				
				b[i].account += sum;
				isAccount = true;
				break;
			}
			else if (i == index && b[index].IsOpenAcount == false) {
				cout << "Откройте счет\n";
				isAccount = true;
				break;
			}
		}
		if(!isAccount)
		cout << "Такого номера клиента нет\n";
	}

	void MinusAccount(int countClient, int index, int sum) {
		bool isAccount = false;
		this->countClient = countClient;
		for (int i = 0; i < countClient; i++)
		{
			if (i == index && b[index].IsOpenAcount == true) {

				b[i].account -= sum;
				isAccount = true;
				break;
			}
			else if(i == index && b[index].IsOpenAcount == false) {
				cout << "Откройте счет\n";
				isAccount = true;
				break;
			}
		}
		if(!isAccount)
		cout << "Такого номера клиента нет\n";
	}


	void initAccountClient(int countClient)
	{
		this->countClient = countClient;
		c = new Client[countClient];
		b = new Bank[countClient];
		for (int i = 0; i < countClient; i++)
		{
			cout << i + 1 << " клиент\n";
			c[i].initClient();
		}

	}

	void showAccountClient(int countClient)
	{
		this->countClient = countClient;
		for (int i = 0; i < countClient; i++)
		{
			cout << i + 1 << " клиент\n";
			c[i].showClient();
			if (b[i].IsOpenAcount == true) {
				cout << "account: " << b[i].account << endl;
			}
		}

	}

	~Bank() {
		delete[] c;
	}

};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Bank b;

	Client c;

	cout << "Сколько будет клиентов банка? : ";
	int countClient;
	cin >> countClient;
	cin.ignore(30, '\n');

	b.initAccountClient(countClient);

	
	Bank newB = b;

	int choice;

	do
	{
		system("cls");
		cout << "-------------------------------\n";
		cout << "-        Банк Estorima        -\n";
		cout << "- 1 -  показать клиентов      -\n";
		cout << "- 2 - открыть счет клиента    -\n";
		cout << "- 3 -  пополнить счет         -\n";
		cout << "- 4 -  снять со счета         -\n";
		cout << "- 5 - конструктор копирования -\n";
		cout << "- 0 -        выход            -\n";
		cout << "-------------------------------\n";

		cout << "Выбор :";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			b.showAccountClient(countClient);

			system("pause");
			break;
		}
		case 2: {

			cout << "\nВведите индекс клиента для открытия счета :";
			int index;
			cin >> index;

			index--;
			b.initAccount(countClient,index);

			system("pause");
			break;
		}
		case 3: {

			cout << "\nВведите индекс клиента для открытия счета :";
			int index;
			cin >> index;
			index--;

			cout << "\nВведите сумму для пополнения :";
			int sum;
			cin >> sum;

			b.PlusAccount(countClient, index, sum);

			system("pause");
			break;
		}
		case 4: {

			cout << "\nВведите индекс клиента для открытия счета :";
			int index;
			cin >> index;
			index--;


			cout << "\nВведите сумму снятия  :";
			int sum;
			cin >> sum;

			b.MinusAccount(countClient, index, sum);

			system("pause");
			break;
		}
		case 5: {

			
			newB.showAccountClient(countClient);

			system("pause");
			break;
		}
		case 0: {
			cout << "Выходим...\n";
			exit(0);
			break;
		}
		default:
			cout << "Error\n";
			break;
		}
	} while (choice != 0);


	return 0;
}

