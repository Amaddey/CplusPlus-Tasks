#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

class MapTranslate {
private:
	map < string, vector<string>> mapOfVector;
public:

	void AddNewWords()
	{
		cout << "How many words to add? :";
		int size;
		cin >> size;
		cin.ignore();

		for (int i = 0;i < size;i++ )
		{
			vector<string> transWord;
			cout << "Word #" << i + 1 << endl;
			cout << "input word : ";
			string strEng;
			getline(cin, strEng);
			while (true)
			{
				cout << "Enter translation :";
				string strRus;
				getline(cin, strRus);
				if (strRus == "0") break;
				transWord.push_back(strRus);
			}
			mapOfVector.emplace(strEng,transWord);
		}

	}

	void Save()
	{
		ofstream out("file.txt", ios::app);
		for (auto it = mapOfVector.begin();it != mapOfVector.end(); it++)
		{
			out << "Word : " << it->first << " ";
			for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++)
			{
				out << *it1 << " ";
			}
			out << endl;
		}

		out.close();
	}

	void ShowAllWords()
	{
		for (auto it = mapOfVector.begin();it != mapOfVector.end(); it++)
		{
			cout << "Word : " << it->first << " - ";
			for (auto at = it->second.begin(); at != it->second.end(); at++)
			{
				cout << *at << "\t";
			}
		cout << endl;
		}
	}


	void searchOneWord()
	{
		cout << "Enter word to search :";
		string str;
		getline(cin, str);
		auto it = mapOfVector.find(str);
		
		if (it == mapOfVector.end())
			cout << "Word is not found\n";
		else
		{
			cout << it->first << endl;
		}

	}

	void searchToDelete()
	{
		cout << "Enter word to delete :";
		string str;
		getline(cin, str);
		auto it = mapOfVector.begin();

		for (; it != mapOfVector.end(); it++)
		{
			if (str == it->first)
				break;
		}
		mapOfVector.erase(it);
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MapTranslate mapT;

	
	while (true)
	{
		mapT.ShowAllWords();

		cout << "1 - add new words\n2 - search a word\n3 - delete a word\n4 - write words to file\n0 - exit\n";
		cout << ">>>";
		int choice;
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1: mapT.AddNewWords();
			break;
		case 2: mapT.searchOneWord();
			break;
		case 3: mapT.searchToDelete();
			break;
		case 4: mapT.Save();
			break;
		case 0: exit(0);
			break;
		default:
			cout << "Error\n";
			break;
		}
	}

	return 1;
}
