#pragma once
#include<iostream>
using namespace std;
#define SIZE 5
#ifdef INTEGER
void ShowArrayInt(int* arr, int size);
int GetMaxInt(int* arr, int size);
int GetMinInt(int* arr, int size);
#define ShowArray(arr,size) ShowArrayInt(arr,size)
#define GetMax(arr, size) GetMaxInt(arr, size)
#define GetMin(arr, size) GetMinInt(arr, size)
#endif // INTEGER

#ifdef DOUBLE
void ShowArrayDouble(double* arr, int size);
double GetMaxDouble(double* arr, int size);
double GetMinDouble(double* arr, int size);
#define ShowArray(arr,size) ShowArrayDouble(arr,size)
#define GetMax(arr, size) GetMaxDouble(arr, size)
#define GetMin(arr, size) GetMinDouble(arr, size)
#endif // DOUBLE

#ifdef CHAR
void ShowArrayChar(char* arr, int size);
char GetMaxChar(char* arr, int size);
char GetMinChar(char* arr, int size);
#define ShowArray(arr,size) ShowArrayChar(arr,size)
#define GetMax(arr, size) GetMaxChar(arr, size)
#define GetMin(arr, size) GetMinChar(arr, size)
#endif // CHAR