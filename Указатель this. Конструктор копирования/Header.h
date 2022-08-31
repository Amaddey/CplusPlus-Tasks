#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

// String - String - String - String


class String {

	int size;
	char* str = nullptr;
	static int count;

public:

	String(const String& obj)
	{
		cout << "\nCopy constructor: ";
		str = new char[strlen(obj.str) + 1];
		strcpy_s(str, strlen(obj.str) + 1, obj.str);
	}



	String(String&& other) {
		cout << "\nTransfer constructor: ";
		this->size = other.size;
		this->str = new char[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->str[i] = other.str[i];
		}
		other.size = 0;
		other.str = nullptr;
	}



	explicit String(int size) : size(size)
	{
		str = new char[size];
		count++;
	}

	explicit String() : String(80) {};

	explicit String(int size, const char* str) : String(size) {

		strcpy_s(this->str, strlen(str) + 1, str);

	}
	

	//Функции

	void getString() {
		cout << str << endl;
	}

	static int getCount() {
		return count;
	}

	void initString(char* str, int size) {

		strcpy_s(this->str, strlen(str) + 1, str);

		cout << str << endl;
	}

	~String() {
		delete[] str;
	}
};


// Array - Array - Array - Array

class Array {

	int* mass = nullptr;
	int size;

public:
	Array();

	Array(int size) /*:size(size)*/ {
		mass = new int[size];
	}

	Array(const Array& obj) {
		cout << "\nCopy constructor: \n";
		size = obj.size;
		mass = new int[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			mass[i] = obj.mass[i];
		}

	}

	Array(Array&& other) {
		cout << "\nTransfer constructor: \n";
		this->size = other.size;
		this->mass = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->mass[i] = other.mass[i];
		}
		other.size = 0;
		other.mass = nullptr;
	}


	~Array() {
		delete[] mass;
	}

	//Функции

	void initArray(int* mass, int size);
	void showArray(int* mass, int size);
	void sortArray(int* mass, int size);
	int minArray(int* mass, int size);
	int maxArray(int* mass, int size);
};
