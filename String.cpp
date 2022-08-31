//#include <iostream>
//#include <string>
//#include<Windows.h>
//
//using namespace std;
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
//			string s1("Hello!"); // инициализация - конструктор string(const char * str)
//			string s2 = "Hello!"; // инициализация - конструктор string(const char * str)
//			cout << s2.max_size() << endl;
//			cout << s2.capacity() << endl;
//			cout << s2.size() << endl;
//			//cout << s2[7] << endl;
//			cout << s2.at(7) << endl;
//			const char* ps = "Hello";
//			string s3(ps); // инициализация
//			string s4(s3); // инициализация - конструктор string(const string & str)
//			string s5; // инициализация - конструктор string()		
//			
//		}
//		break;
//		case 2:
//		{
//			string s1 = "s-1";
//			string s2 = "s-2";
//			string s3;
//			bool b;			
//			s3 = s1; 			
//			s3 = s3 + s2; 			
//			s3 = "s-3";
//			s3 += "abc"; 			
//			b = s2 == s1; 
//			b = s2 == "s-2";
//			s1 = "s1";
//			s2 = "s2";
//			b = s1 != s2; 			
//			s1 = "abcd";
//			s2 = "de";
//			b = s1 > s2; // b = false
//			b = s1 < s2; // b = true			
//			s1 = "abcd";
//			s2 = "ab";
//			b = s1 >= s2; // b = true
//			b = s1 <= s2; // b = false
//			b = s2 >= "ab"; // b = true
//
//			// операция [] - индексация
//			char c;
//			s1 = "abcd";
//			c = s1[2]; 
//			c = s1[0]; 
//		}
//		break;
//		case 3: {
//			string fullname, nickname;
//			string greeting("Здраствуйте, ");
//			cout << "Введите фамилию и имя\n";
//			getline(cin, fullname);
//			cout << "Введите псевдоним\n";
//			cin >> nickname;
//			greeting += nickname;
//			cout << greeting<<endl;
//		}
//			  break;
//		case 4: {
//			// присваивание строк, функция assign()
//			string s1 = "bestprog.net";
//			string s2;
//			string s3;
//			const char* ps = "bestprog.net";
//			s3 = s1; 
//			s2.assign(s1); 
//			s2.assign(s1, 0, 4); 
//			s2.assign(ps, 8); 
//		}
//			  break;
//		case 5: {
//			string s1 = "abcdef";
//			string s2 = "1234567890";
//			s1.append(s2, 3, 4); // string &append(const string & s, size_type start);
//			cout << s1 << endl;
//			const char* ps = "1234567890";			
//			s1.append(ps, 3); //string& append(const char* s, size_type num);
//		}
//			  break;
//		case 6: {
//			string s1 = "abcdef";
//			string s2 = "1234567890";
//			s1.insert(3, s2); // string & insert(size_type start, const string &s);
//			cout << s1 << endl;
//			s2.insert(2, s1, 1, 3); //string & insert(size_type start, const string &s, size_type insStart, size_type num);
//			cout << s2 << endl;
//		}
//			  break;
//		case 7: {
//			string s1 = "abcdef";
//			string s2 = "1234567890";
//			//string &replace(size_type start, size_type num, const string &s);
//			s2.replace(2, 4, s1); // s2 = "12abcdef7890"
//			s2 = "1234567890";
//			s2.replace(3, 2, s1); // s2 = "123abcdef67890"
//			s2 = "1234567890";
//			s2.replace(5, 1, s1); // s2 = "12345abcdef7890"
//			//string& replace(size_type start, size_type num, const string & s, size_type replStart, size_type replNum);			
//			s2 = "1234567890";
//			s2.replace(5, 1, s1, 2, 3); // s2 = "12345cde7890"
//			s2 = "1234567890";
//			s2.replace(4, 2, s1, 0, 4); // s2 = "1234abcd7890"
//		}
//			  break;
//		case 8: {
//			//string& erase(size_type index = 0, size_type num = npos);
//			string s = "01234567890";
//			s.erase(3, 5); // s = "012890"
//			s = "01234567890";
//			s.erase(); // s = ""
//		}
//			  break;
//		case 9: {
//			string s1 = "01234567890";
//			string s2 = "345";
//			string s3 = "abcd";
//			int pos;
//			//size_type find(const string & s, size_type start = 0) const;
//			pos = s1.find(s2); // pos = 3
//			pos = s1.find(s2, 1); // pos = 3
//			pos = s1.find("jklmn", 0); // pos = -1
//			pos = s1.find(s3); // pos = -1
//			//size_type rfind(const string& s, size_type start = npos) const;
//			string s4 = "abcd---abcd";			
//			pos = s1.rfind(s2); // pos = 3			
//			pos = s1.rfind(s2, 12); // pos = 3
//			pos = s1.rfind(s2, 3); // pos = 3
//			pos = s1.rfind(s2, 2); // pos = -1
//			// разница между функциями find() и rfind()
//			pos = s4.rfind(s3); // pos = 7
//			pos = s4.find(s3); // pos = 0
//		}
//			  break;
//		case 10: {
//			string s1 = "В лесу родилась елочка, в лесу она росла\n";
//			int n;
//			n = s1.find("елочка");
//			cout << "Елочка найдена: " << n << endl;
//			n = s1.find_first_of("заец");
//			cout << "Первый из зайцев: " << n << endl;
//			n = s1.find_first_not_of("абвгдАБВГД");
//			cout << "Первый не из: " << n << endl;
//
//		}
//			   break;
//		case 11: {
//			string s1 = "012345";
//			string s2 = "0123456789";
//			int res;
//			res = s1.compare(s2); // res = -1
//			res = s1.compare("33333"); // res = -1
//			res = s1.compare("012345"); // res = 0					
//			res = s1.compare(0, 5, "012345"); // res = -1
//			res = s2.compare(s1); // res = 1			
//			res = s2.compare("000000"); // res = 1
//			s1.swap(s2);
//			cout << "s1: " << s1 << " ,s2: " << s2 << endl;
//		}
//			  break;
//		case 12: {
//			//const char* c_str() const;
//			string s = "abcdef";
//			const char* ps;
//			ps = s.c_str(); // ps = "abcdef"
//			cout << ps << endl;
//			int len = s.length();
//			cout << len << endl;
//		}
//			  break;
//		case 13: {
//			string s = "Hello world\n";
//			int res = s.find(' ');
//			string sub_str = s.substr(0, res);
//			cout << "s: " << s.c_str() << endl;
//			cout << "sub_str: " << sub_str.c_str() << endl;
//		}
//			  break;
//		case 14: {
//			string s1("Все хорошо прекрасная маркиза.");
//			string s2("принцесса");
//			string s3("Приветствую ");
//			s1.erase(s1.size() - 1, 1);
//			s1.append(3, '!');
//			int x = s1.find(' ');
//			while (x < s1.size()) {
//				s1.replace(x, 1, "/");
//				x = s1.find(' ');
//			}
//			cout << "s1: " << s1 << endl;
//		}
//			  break;
//		
//		default: {}
//		}
//	} while (task != 0);
//	
//	return 0;
//}