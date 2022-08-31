#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <vector>
#include <windows.h>
#include <memory>
using namespace std;

class SecureClass
{
private:
	ifstream fin;
	ofstream fout;
	string path = "SecureFile.txt";
	string name, surname, age;
	bool isOpen;

public:


	SecureClass()
	{
		fout.open(path, ios::app);
		fin.open(path);
		isOpen = true;
	}

	SecureClass(string name,string surname,string age) : name(name),surname(surname),age(age)
	{
		fout.open(path, ios::app);
		fin.open(path);
		isOpen = true;
	}

	~SecureClass()
	{
		fin.close();
		fout.close();
		isOpen = false;
	}

	void InitObj()
	{
		cout << "Name :";
		getline(cin, name);
		cout << "Surname :";
		getline(cin, surname);
		cout << "Age :";
		getline(cin, age);
	}

	void Show()
	{
		cout << "Name :" << name << endl;
		cout << "Surname :" << surname << endl;
		cout << "Age :" << age << endl;
		}

	void ReadFile()
	{
		try
		{
			if (!isOpen)
				throw "File is not open";


			cout << "_______Чтение файла_______\n";
			string buff;
			while (!fin.eof())
			{
				getline(fin, buff);
				cout << buff << endl;
			}

		}
		catch (const char* ss)
		{
			cout << ss << endl;
		}

	}

	void WriteFile()
	{
		try
		{
			if (!isOpen)
				throw "File is not open";

			cout << "_______Запись в файл_______\n";

			fout << name << endl;
			fout << surname << endl;
			fout << age << endl;

		}
		catch (const char* ss)
		{
			cout << ss << endl;
		}
	}

	
};

class Worker
{
private:
	string path = "Worker.dat";
	string surname,age,position;
	ifstream fin;
	ofstream fout;
public:
	Worker() = default;

	void InitObj()
	{
		cout << "Surname :";
		getline(cin, surname);
		cout << "Age :";
		getline(cin, age);
		cout << "Position :";
		getline(cin, position);
	}

	void Save()
	{
		ofstream fout(path, ios::app | ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
	}

	void Load(int size)
	{
		ifstream fin(path, ios::binary);

		fin.seekg(size * sizeof(Worker));
		fin.read((char*)this, sizeof(*this));

		fin.close();
	}


	void Show()
	{
		cout << "Surname :" << surname << endl;
		cout << "Age :" << age << endl;
		cout << "Position :" << position << endl;
		
	}



	static int WorkerCount();

	
};



int Worker::WorkerCount()
{
	ifstream in("Directory.txt");
	in.seekg(0, ios::end);
	int k = (int)(in.tellg() / sizeof(Worker));
	in.close();
	return k;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	

	
	

	cout << "1/2 :";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		auto unq = make_unique<SecureClass>();

		cin.ignore();
		unq->InitObj();


		unq->WriteFile();

		unq->ReadFile();

		
	}
	break;
	case 2:
	{

		cout << "Кол-во рабочих :";
		int size1;
		cin >> size1;

		shared_ptr<Worker[]> workMass(new Worker[size1]);
		cin.ignore();

		for (size_t i = 0; i < size1; i++)
		{
			cout << "Worker #" << i + 1 << endl;
			
			workMass[i].InitObj();
			workMass[i].Save();
		}


		{
			cout << "______Show all workers______\n";
			for (size_t i = 0; i < size1; i++)
			{
				cout << "Worker #" << i + 1 << endl;
				workMass[i].Show();
			}


		}

	}
	break;
	default:
		cout << "Error\n";
		break;
	}


	return 0;
}
