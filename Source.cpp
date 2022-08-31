#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	//—жать(сдвинуть элементы) массив, удалив из него все 0, и заполнить освободившиес€ справа элементы значени€ми - 1.

	int menu;

	

	do
	{
		cout << "¬ведите задание : ";
		cin >> menu;
		switch (menu)
		{
		case 1: {
			const int size = 20;
			int arr[size] = { 0,1,2,30,0 };
			int arr2[size];
			int j = 0;
			

			for (int i = 0; i < size; i++)
			{
				if (arr[i] != 0) {
					arr2[j] = arr[i];
					j++;
				}
			}

			for (; j < size; j++)
			{
				arr2[j] = -1;
			}

			for (int i = 0; i < size; i++)
			{
				cout << arr2[i] <<"\t";
			}
			
		}
			  break;
		case 2: {
			const long size = 5;
			int arr[size] = {rand(),rand(),rand(),rand(),rand() };
			for (int i = 0; i < size - 1; i++) {
				
				for (int j = 0; j < size - i - 1; j++) {
					if (arr[j] > arr[j + 1]) {

						swap(arr[j], arr[j + 1]);

					}
				}
			}
			
			for (int i = 0; i < size; i++) {

				cout << arr[i] << "\t";
			}
			cout << "\n\n";
		}
			  break;
		case 3: {
		
			const int size  = 5;
			int arr[size]{1,213,123,3,77};
			int tmp = 0;
			

			for (int i = 0; i < size; i++)
			{
				int j;
				tmp = arr[i];
				for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
				{
					arr[j + 1] = arr[j];
				}
				arr[j + 1] = tmp;
			}

			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << endl;
			} break;
		}
		case 4: {

			const int size = 10;
			int goods[size] = {22,33,11,44,66,55,77,99,88,00};
			int price[size] = {12342314,7546,3452854};
			int what;

			do
			{
				cout << "¬ведите модель телефона" << endl;
				cout << "1 - сортировка" << endl;
				cout << "2 - поиск по товару" << endl;
				cout << "3 - сумма покупки" << endl;
				cin >> what;

				switch (what)
				{
				case 1: {

				} break;
				case 2: {

				}break;
				case 3: {
					
				}
					break;
				}
			} while (menu != 0);
			

		}
			break;

		}
	} while (menu != 0);



	system("pause");
	return(0);

}