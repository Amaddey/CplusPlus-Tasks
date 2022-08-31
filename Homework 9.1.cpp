#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

		//int num1, num2, num3, sum, res = 0, temp;
		//for (int i = 100; i <= 999; i++)
		//{
		//	sum = 0;
		//	num3 = i % 10;
		//	temp = i / 10;
		//	num2 = temp % 10;
		//	num1 = temp / 10;

		//	if ((num1 == num2) && (num1 != num3) && (num2 != num3))
		//	{
		//		sum++;
		//	}
		//	if ((num1 != num2) && (num1 == num3) && (num2 != num3))
		//	{
		//		sum++;
		//	}
		//	if ((num1 != num2) && (num1 != num3) && (num2 == num3))
		//	{
		//		sum++;
		//	}
		//	if (sum == 1)
		//	{
		//		cout << i << "\n";
		//		res++;
		//	}
		//}
		//cout << "Номеров с двумя одинаковыми цифрами : " << res;

	// ЗАДАНИЕ №2

	//int num1, num2, num3, resN, temp;
	//resN = 0;

	//for (int i = 100; i <= 999; i++)
	//{
	//	num3 = i % 10;
	//	temp = i / 10;
	//	num2 = temp % 10;
	//	num1 = temp / 10;
	//	if ((num1 != num2) && (num1 != num3) && (num2 != num3))
	//	{
	//		resN++;
	//	}
	//}
	//cout << "Количество номеров с разными цифрами : " << resN;


	//
	//int num, digit, i, newNum;
	//cout << "Ваш номер : ";
	//cin >> num;
	//i = 0;
	//	newNum = 0;
	//while (num > 0)
	//{
	//	digit = num % 10;
	//	if ((digit != 3) && (digit != 6))
	//	{
	//		newNum = newNum + digit * pow(10, i);
	//		i++;
	//	}
	//	num = num / 10;
	//}
	//cout << "Ваш новый номер : " << newNum;


	//int num1, num2;
	//cout << "Ваш номер : ";
	//cin >> num1;
	//for (int i = num1 - 1; i > 1; i--)
	//{
	//	num2 = i;
	//	if ((num1 % (num2 * num2) == 0) && (num1 % (num2 * num2 * num2) != 0))
	//	{
	//		cout << num2 << "\n";
	//	}
	//}


	//int A, A1, sum = 0;
	//cout << "A="; cin >> A;
	//if (A < 0) A = -A;
	//A1 = A;
	//while (A > 0)
	//{
	//	sum += A % 10;
	//	A /= 10;
	//}
	//if (sum * sum * sum == A1 * A1) cout << "YES\n";
	//else cout << "NO\n";
}


