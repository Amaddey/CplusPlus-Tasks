#include "Header.h"

// String - String - String - String


int String::count = 0;


// Array - Array - Array - Array



void Array::initArray(int* mass, int size) {

	this->mass = mass;
	this->size = size;

	for (int i = 0; i < size; i++)
	{
		cout << "\nArray[" << i + 1 << "] :";
		cin >> mass[i];
		cin.ignore(123, '\n');
	}
	cout << endl;
}

void Array::showArray(int* mass, int size) {
	this->mass = mass;
	this->size = size;

	for (int i = 0; i < size; i++)
	{
		cout << endl << i + 1 << " - элемент " << mass[i] << endl;
	}
	cout << endl;
}



void Array::sortArray(int* mass, int size) {
	this->mass = mass;
	this->size = size;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (mass[j] > mass[j + 1])
				swap(mass[j], mass[j + 1]);
		}
	}

}

int Array::minArray(int* mass, int size) {
	this->mass = mass;
	this->size = size;

	int min = mass[0];

	for (int i = 0; i < size; i++)
	{
		if (mass[i] < min)
			min = mass[i];
	}


	return min;
}

int Array::maxArray(int* mass, int size) {
	this->mass = mass;
	this->size = size;

	int max = mass[0];

	for (int i = 0; i < size; i++)
	{
		if (mass[i] > max)
			max = mass[i];
	}
	return max;
}