#define _CRT_SECURE_NO_WARNINGS
//#define _UNICODE
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <io.h>//setmode
#include <fcntl.h>//_O_U16TEXT
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include<locale>
#include<codecvt>
using namespace std;
void main()
{
	SetConsoleOutputCP(1251);
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
	int menu;
	cin >> menu;
	switch (menu) {
	case 1: {
		// ANSI-���������
		char szBuf1[15] = "Hello,";
		strcat_s(szBuf1, " world!");
		cout << sizeof(szBuf1) << " bytes\n"; // 15 ����
		// UNICODE-���������
		wchar_t szBuf2[15] = L"Hello,";
		wcscat_s(szBuf2, L" world!");
		cout << sizeof(szBuf2) << " bytes\n"; // 30 ����
		wcout << szBuf2 << endl;
	}
		  break;
	case 2: {
		wstring name;
		wcout << L"Enter your name: ";
		wcin >> name;
		wcout << L"Hello, " << name << endl;
		wcout << L"Hi,\u005E!\n";
	}
		  break;
	case 3: {
		/*SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);*/
		// ������������ ������������ ������ ������ � ������ �������
		_setmode(_fileno(stdout), _O_U8TEXT);
		wchar_t ch[125] = L"����� ���";
		int j = 77;
		double d = 6.02;
		wstring str1 = L"Kafka";
		wstring str2 = L"�����";
		wofstream outfile(L"1.txt");
		outfile.imbue(utf8_locale);//������ ��� ����� � ������������ ����� �������
		outfile << ch << j << L' ' << d << str1 << L' ' << str2;
		wcout << L"���� �������\n";
		outfile.close();

	}
		  break;
	case 4: {
		// ������������ ������������ ������ ������ � ������ �������
		_setmode(_fileno(stdout), _O_U8TEXT);
		wchar_t ch[125];
		int j;
		double d;
		wstring str1;
		wstring str2;
		wifstream infile(L"1.txt");
		infile.imbue(utf8_locale);
		infile >> ch >> j >> d >> str1 >> str2;
		wcout << ch << endl
			<< j << endl
			<< d << endl
			<< str1 << endl
			<< str2 << endl;
		infile.close();
	}
		  break;
	case 5: {
		TCHAR szBuf3[15] = _TEXT("Hello,");
		_tcscat_s(szBuf3, _TEXT("world!"));
		wcout << szBuf3 << '\n';
		cout << "The size of array:" << sizeof(szBuf3) <<
			" bytes\n"; // 30 ����
	}
		  break;
	case 6: {
		char buffer[] = "MultiByteToWideChar converts ANSI - string to Unicode - string";
		// ��������� ������ ������, �����������
		// ��� �������� Unicode-������
		int length = MultiByteToWideChar(CP_ACP, 0, buffer, -1, NULL, 0);
		cout << length << endl;
		wchar_t* ptr = new wchar_t[length];
		// ������������ ANSI-������ � Unicode-������
		MultiByteToWideChar(CP_ACP, 0, buffer, -1, ptr, length);
		wcout << ptr << endl;
		cout << "Length of Unicode-string: " << wcslen(ptr) << endl;
		cout << "Size of allocated memory: " << _msize(ptr) << endl;
		delete[] ptr;

	}
		  break;
	case 7: {
		wchar_t buffer[] = L"WideCharToMultiByte converts Unicode - string to ANSI - string";
		// ��������� ������ ������, ����������� ���
		// �������� ANSI-������
		int length = WideCharToMultiByte(CP_ACP, 0, buffer, -1, NULL, 0, 0, 0);
		char* ptr = new char[length];
		// ������������ Unicode-������ � ANSI-������
		WideCharToMultiByte(CP_ACP, 0, buffer, -1, ptr, length, 0, 0);
		cout << ptr << endl;
		cout << "Length of ANSI-string: " << strlen(ptr) << endl;
		cout << "Size of allocated memory: " << _msize(ptr) << endl;
		delete[] ptr;

	}
		  break;
	case 8: {
		char buffer[] = "mbstowcs converts ANSI-string to Unicode - string";
		// ��������� ������ ������, ����������� ���
		// �������� Unicode-������
		int length = mbstowcs(NULL, buffer, 0);
		wchar_t* ptr = new wchar_t[length];
		// ������������ ANSI-������ � Unicode-������
		mbstowcs(ptr, buffer, length);
		wcout << ptr;
		cout << "\nLength of Unicode-string: " << length << endl;
		cout << "Size of allocated memory: " << _msize(ptr) << " bytes" << endl;
		delete[] ptr;
	}
		  break;
	case 9: {
		wchar_t buffer[] = L"wcstombs converts Unicode-string to ANSI - string";
		// ��������� ������ ������, ����������� ���
		// �������� ��������������� ANSI-������
		int length = wcstombs(NULL, buffer, 0);
		char* ptr = new char[length + 1];
		// ������������ Unicode-������ � ANSI-������
		wcstombs(ptr, buffer, length + 1);
		cout << ptr;
		cout << "\nLength of ANSI-string: " << strlen(ptr) << endl;
		cout << "Size of allocated memory: " << _msize(ptr) << " bytes" << endl;
		delete[] ptr;
	}
		  break;
	case 10: {
		_setmode(_fileno(stdout), _O_U8TEXT);		
		wchar_t buff[260];
	
		wifstream file(L"2.txt");
		file.imbue(utf8_locale);
		//�������� �� ��������
		if (file.is_open()) {
			wcout << L"���� ������� ������!\n**********************" << endl;
			//������� ���� �� �����
			while (!file.eof()) {
				file.getline(buff, 255);
				wcout << buff << endl;
			}
		}
		else
		{
			wcout << L"���� �� ����� ���� ������!" << endl;
			
		}
		//������� ����
		file.close();
	}
		   break;

	}
}

