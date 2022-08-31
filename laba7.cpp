#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <iomanip>

using namespace std;

class Person
{
    string mName, mBirthDay, mHobby;
	fstream ff;

public:

	Person()
	{
	} 

	void add()
	{
		ff.open("hat.txt",ios::out|ios::app);

		cout << "Name :";
		getline(cin, mName);
		cout << "birthDay :";
		getline(cin, mBirthDay);
		cout << "hobby :";
		getline(cin, mHobby);
		ff << "\n|" << mName << setw(25 - mName.length() + 1) << setfill(' ') << "|" << mBirthDay << setw(19 - mBirthDay.length() + 1) << setfill(' ') << "|" << mHobby << setw(19 - mHobby.length() + 1) << setfill(' ') << "|";
		ff << "\n|" << setw(26) << setfill('-') << "+" << setw(20) << setfill('-') << "+" << setw(20) << setfill('-') << "|";
		//ff << "\n--------------------------------------------------------------------------------\n" << endl;
		ff.close();
	}

	void show()
	{
		ff.open("hat.txt", ios::in);
		string s;
		while (getline(ff,s))
		{
			cout << s << endl;
		}
		ff.close();
	}

};

class Student {
	static int count;

	char* FIO = new char[128];
	char* age = new char[128];
	char* birthDay = new char[128];
	char* phone = new char[128];
	char* city = new char[128];
	char* country = new char[128];
	char* ucheb = new char[128];
	char* cityContyUcheb = new char[128];
	char* numGroup = new char[128];

	fstream fstudent;
	string path = "Student.txt";

public:
	Student() { count++; }
	~Student() {
		cout << "Деструктор\n";
		delete[] FIO;
		delete[] birthDay;
		delete[] phone;
		delete[] city;
		delete[] country;
		delete[] ucheb;
		delete[] cityContyUcheb;
	}
	void GetAllData(char* FIO, char* age, char* birthDay, char* phone, char* city,
		char* country, char* ucheb, char* cityContyUcheb, char* numGroup);
	void PrintData();
	static int getCount() { return count; };

	void Save()
	{
		fstudent.open(path, ios::app | ios::out);
		fstudent << "FIO :" << FIO << endl;
		fstudent << "Age :" << age << endl;
		fstudent << "birthDay :" << birthDay << endl;
		fstudent << "phone :" << phone << endl;
		fstudent << "city :" << city << endl;
		fstudent << "country :" << country << endl;
		fstudent << "ucheb :" << ucheb << endl;
		fstudent << "cityContyUcheb :" << cityContyUcheb << endl;
		fstudent << "numGroup :" << numGroup << endl;

		cout << "Данные сохранены\n";
		fstudent.close();
	}

	void Load()
	{
		cout << "Загрузка данных...\n";
		fstudent.open(path, ios::in);

		string loading;

		while (getline(fstudent, loading))
		{
			cout << loading << endl;
		}
		fstudent.close();

	}

	void init()
	{
		cout << "FIO  : ";
		gets_s(FIO, 128);
		cout << "Age :";
		gets_s(age, 128);
		cout << "birthDay  : ";
		gets_s(birthDay, 128);
		cout << "phone  : ";
		gets_s(phone, 128);
		cout << "city  : ";
		gets_s(city, 128);
		cout << "country  : ";
		gets_s(country, 128);
		cout << "ucheb  : ";
		gets_s(ucheb, 128);
		cout << "cityContyUcheb  : ";
		gets_s(cityContyUcheb, 128);
		cout << "numGroup :";
		cin >> numGroup;
		gets_s(numGroup, 128);
	}
};

//void Student::GetAllData(char* FIO, char* age, char* birthDay, char* phone, char* city,
//    char* country, char* ucheb, char* cityContyUcheb, char* numGroup) {
//    this->FIO = FIO;
//    this->age = age;
//    this->birthDay = birthDay;
//    this->phone = phone;
//    this->city = city;
//    this->country = country;
//    this->ucheb = ucheb;
//    this->cityContyUcheb = cityContyUcheb;
//    this->numGroup = numGroup;
//}


void Student::PrintData() {
	cout << endl;
	cout << "FIO :" << FIO << endl;
	cout << "Age :" << age << endl;
	cout << "birthDay :" << birthDay << endl;
	cout << "phone :" << phone << endl;
	cout << "city :" << city << endl;
	cout << "country :" << country << endl;
	cout << "ucheb :" << ucheb << endl;
	cout << "cityContyUcheb :" << cityContyUcheb << endl;
	cout << "numGroup :" << numGroup << endl;
	cout << endl;
}

int Student::count = 0;

int main() {
	setlocale(LC_ALL,"Russian");

	cout << "1/2/3 : ";
	int globalMenu;
	cin >> globalMenu;

	switch (globalMenu)
	{
	case 1 : {

		fstream fout;
		string text;
		int count = 0;

		try
		{

			fout.open("File.txt", ios::app);

			if (!fout.is_open())
				throw "File is not found";

			cin.ignore();
			while (true)
			{
				cout << "Text : ";
				getline(cin, text);
                
				if (text == "0")
					break;

				fout << text << endl;

				cout << "Записано...\n";
				count++;
			}
			fout.close();

			cout << "\n-----------------------------\n";
						
			fout.open("File.txt");

			char ch;
			while (fout.get(ch))
			{
				cout << ch;
			}
			cout << endl;

			fout.close();

		}
		catch (const char* ss)
		{
			cerr << ss << endl;
		}

		}
	break;
	case 2: {

		
		
		Person p;
		fstream ff("hat.txt", ios::out);
		ff << "--------------------------------------------------------------------------------" << endl;
		ff << "|   ФИО                        |  Дата          | Хобби                        |" << endl;
		ff << "--------------------------------------------------------------------------------" << endl;

		while (true)
		{
			
		cout << "1 - Добавить :\n";
		cout << "2 - Показать :\n";
		cout << "input :";
		int choice;
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			p.add();
		}
		else if (choice == 2)
		{
			p.show();
			break;
		}

		}

			


	}
    break;
	case 3:
	{
		Student s;
		cin.ignore();
		s.init();

		s.PrintData();



		s.Save();

		s.Load();
	}
	break;
	default:
		cout << "Error\n";
		break;
	}



	return 0;
}