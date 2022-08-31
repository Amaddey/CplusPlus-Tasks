#pragma once //директива #pragma once не позволяет включать файл в проект несколько раз, 
             //то есть предотвращает переопределение.
#include<iostream>
using namespace std;
#define SIZE 10
int arr[SIZE]{ 8,44,67,12,13 };
void ShowArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int GetMax(int* arr, int size) {
	int temp = arr[0];
	for (int i = 1; i < size; i++) {
		if (temp < arr[i])
			temp = arr[i];
	}
	return temp;
}

int GetMin(int* arr, int size) {
	int temp = arr[0];
	for (int i = 1; i < size; i++) {
		if (temp > arr[i])
			temp = arr[i];
	}
	return temp;
}
