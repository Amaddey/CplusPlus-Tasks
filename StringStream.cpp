//#include <iostream>
//#include <sstream>
//#include <string>
//#include <iterator> 
//#include<Windows.h>
//using namespace std;
//
//
//using namespace std;
//template <typename T>
//inline string ToString(T tX)
//{
//	ostringstream oStream;
//	oStream << tX;
//	return oStream.str();
//}
//template <typename T>
//inline bool FromString(const string& sString, T& tX)
//{
//	istringstream iStream(sString);
//	// извлекаем значение в tX, возвращаем true (если удачно) или false (если неудачно)
//	return (iStream >> tX) ? true : false;
//}
//
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	int task;
//	do
//	{
//
//		cout << "Enter task\n: ";
//		cin >> task;
//		cin.ignore();
//		switch (task)
//		{
//		case 1:
//		{
//			string sFive(ToString(5));
//			string sSevenPointEight(ToString(7.8));
//			string sB(ToString('B'));
//			cout << sFive << endl;
//			cout << typeid(sFive).name() << endl;
//			cout << sSevenPointEight << endl;
//			cout << typeid(sSevenPointEight).name() << endl;
//			cout << sB << endl;
//			cout << typeid(sB).name() << endl;
//			
//
//		}
//		break;
//		case 2:
//		{
//			double dX;
//			if (FromString("4.5", dX))
//				cout << dX << endl;
//			cout << typeid(dX).name() << endl;
//			if (FromString("TOM", dX))
//				cout << dX << endl;
//			
//
//		}
//		break;
//		case 3:
//		{
//			stringstream myString;
//			myString << "336000 12.14" << endl;
//			cout << "myString: " << myString.str();
//
//			string part1;
//			myString >> part1;
//			string part2;
//			myString >> part2;
//
//			// ¬ыводим числа
//			cout << part1 << " and " << part2 << endl;
//			cout << typeid(part1).name() << "\n" << typeid(part2).name() << endl;
//		}
//		break;
//		case 4:
//		{
//			stringstream myString;
//			int nValue = 336000;
//			double dValue = 12.14;
//			myString << nValue << " " << dValue;
//
//			string strValue1, strValue2;
//			myString >> strValue1 >> strValue2;
//			cout << strValue1 << " " << strValue2 << std::endl;
//			cout << typeid(strValue1).name()<<"\n" << typeid(strValue2).name() << endl;
//		}
//		break;
//
//		case 5: {
//			stringstream myString;
//			myString << "336000 12.14"; // вставл€ем (числовую) строку в поток
//			int nValue;
//			double dValue;
//			myString >> nValue >> dValue;
//			cout << nValue << " " << dValue << endl;
//			cout << typeid(nValue).name() << "\n" << typeid(dValue).name() << endl;
//		}
//			  break;
//		case 6: {
//
//			stringstream myString;
//			myString << "Hello ";
//			myString.str(" "); // очищаем буфер
//			//myString.str(string()); // очищаем буфер
//			myString << "World!";
//			cout << myString.str() << endl;
//
//		}
//			  break;
//		
//			
//		
//
//		default: {}
//		}
//	} while (task != 0);
//
//
//
//	return 0;
//}
//
