//#include<iostream>
//#include "array.h"
//using namespace std;
//
//#define forever for(;;)
//#define begin {
//#define end }
//#define Write cout <<
//
//#define STROKA "\n Multum, non multa ­ \
// mnogoe, no nemnogo!"
//#define X 2
//#define SQUARE(X) X*X
//#define TED 10
//#define NAME 3 
//#define my_str(s) #s 
//#define concat(a,b) a##b
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	srand(time(NULL));
//	int menu;
//	do
//	{
//		cout << "Enter task: " << endl;
//		cin >> menu;
//		switch (menu) {
//		case 1: {
//			forever
//				begin
//				Write "Hello world\n";
//			    end
//		}
//			  break;
//		case 2: {
//          /* #undef SIZE;
//           #define SIZE 15*/
//			int sum = 0;
//			for (int i = 0; i < SIZE; i++) sum += arr[i];
//			cout << sum << endl;
//            /*#undef SIZE;
//			int SIZE = 0;
//			SIZE++;*/
//		}
//			  break;
//		case 3: {
//			Write STROKA;
//		}
//			  break;
//		case 4: {
//			int y = SQUARE(X);
//			cout << "SQUARE= " << y << endl;
//		}
//			  break;
//		case 5: {
//#ifdef TED
//			cout << "Hi Ted\n";
//#else
//			cout << "Hi anyone\n";
//#endif
//#ifndef RALPH
//			cout << "RALPH not defined\n";
//#endif
//		}
//			  break;
//		case 6: {
//			//Компилятор использует номер строки и необязательное имя файла для ссылки на ошибки,
//			//которые он обнаруживает во время компиляции.
//			//Номер строки обычно относится к текущей строке ввода, 
//			//а имя файла относится к текущему файлу ввода.
//#line 20 "Sorce.cpp"
//			cout << "This code is on line: " << __LINE__ << " , in file: " << __FILE__ <<" date: "<<__DATE__<<" time: "<<__TIME__<< endl;
//#line 27 "Sorce.cpp"
//			cout << "This code is on line: " << __LINE__ << " , in file: " << __FILE__ << endl;
//		}
//			  break;
//		case 7: {
//#if (NAME == 5)// ошибка на этапе компиляции
//			// несогласованности программы или нарушении ограничения
//#error NAME должно быть равно 5!
//#endif
//
//		}
//			  break;
//		case 8: {
//			cout << my_str(I love C++) << endl; // Для компилятора cout<<"I love C";
//		}
//			  break;
//
//		case 9: {
//			int xy = 100;			
//			cout << concat(x, y)<<endl;
//			cout << concat(10, 20) << endl;
//			cout << concat("Ivan", " Ivanov") << endl;
//		}
//			  break;
//		case 10: {
//			ShowArray(arr, SIZE);
//			cout << endl;
//			// минимум
//			cout << "Minimum: " << GetMin(arr, SIZE) << endl;
//			// максимум
//			cout << "Maximum: " << GetMax(arr, SIZE) << endl;
//
//		}
//			   break;
//		}
//
//	} while (menu != 0);
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
