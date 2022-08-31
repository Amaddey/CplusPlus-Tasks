#include <iostream>
#include<string>
#include<algorithm>
#include<Windows.h>
#include<vector>

using namespace std;
class myFunctor {
	int count=0;
public:
	void operator()() {
		cout << "Functor" <<this<<" "<< count << endl;
		count++;
	}
	
	int operator()(int a, int b) {
		cout << "Functor" <<this<< endl;
		return a + b;
	}
};
class EvenFunctor {
	int evenSum = 0;
	int evenCount = 0;
public:
	void operator()(int val) {
		if (val % 2 == 0) {
			evenSum += val;
			evenCount++;
		}
	}
	void showEvenSum() {
		cout << "summary event: " << evenSum << endl;
	}
	void showEvenCount() {
		cout << "count event: " << evenCount << endl;
	}
};
//унарный предикат
bool FuncZero(int a) {
	return a > 0;
}
bool FuncLessZero(int a) {
	return a < 0;
}
class Person {
	string name;
	double score;
	int age;
public:
	Person(string name, double score) {
		this->name = name;
		this->score = score;		
	}
	Person(string name, double score, int age):Person(name,score) {
		this->age = age;
	}
	bool operator()(const Person& p) {
		return p.score > 180;
	}
	string getName() const{
		return this->name;
	}
	double getScore() const{
		return this->score;
	}
	int getAge() const{
		return this->age;
	}
};
void Show(Person p) {
	if(p.getAge()>18)
		cout << p.getName() << endl;

}
bool myPredecat(int a, int b) {
	return a > b;
}
class Summary : private vector<int> {
public:
	Summary(const vector<int>& ini) {
		for (auto x : ini) this->push_back(x);
	}
	int operator()(bool even) {
		int sum = 0;
		auto i = begin();
		if (even) i++;
		while (i < end()) {
			sum += *i++;
			if (i == end()) break;
			i++;
		}
		return sum;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int task;
	do
	{

		cout << "Enter task:\n";
		cin >> task;
		cin.ignore();
		switch (task)
		{
		case 1:
		{
			myFunctor f;
			f();
			f();
			cout<<f(2,5)<<endl;
			
		}
		break;
		case 2:
		{			
			vector<int> numbers = { 1, 2, 3, 4, 5 };
			EvenFunctor ef;
			for (auto item : numbers) {
				ef(item);
			}
			ef.showEvenSum();
			ef.showEvenCount();
			
		}
		break;
		case 3: {
			vector<int> n = { -1, 2, 3, -4, 5, -6 };			
			ptrdiff_t rez=count_if(n.begin(), n.end(), FuncZero);			
			cout << rez << endl;
		}
			  break;
		case 4: {
			vector<int> n = { 9,99,-5,10,55,3,9};
			int t;
			cin >> t;
			switch (t) {
			case 1: {
				sort(n.begin(), n.end(), myPredecat);

				for (auto item : n) {
					cout << item << "\t";
				}
				cout << endl;
				sort(n.begin(), n.end(), [](int a, int b) {
					return a < b;
					});
				
				for (auto item : n) {
					cout << item << "\t";
				}
				cout << endl;
			}
				  break;
			case 2: {
				auto rez = find(n.begin(), n.end(), 55);
				if (rez == n.end()) {
					cout << "don't find this \n";
				}
				else
					cout << "find this \n";
				//finf_if_not
				rez = find_if_not(n.begin(), n.end(), [](int a) {
					return a % 2 == 0;
					});
				if (rez == n.end()) {
					cout << "don't find event \n";
				}
				else
					cout << "find odd \n"; }
				  break;
			case 3: {
				auto rez = remove(n.begin(), n.end(), 9);
				n.erase(rez, n.end());
				cout << n.size();
				// Фильтруем элементы, перемещая уцелевшие элементы в начало массива
				auto newEnd = remove_if(n.begin(), n.end(), [](int num) {
					return num > 3;
					});
				// Удаляем все элементы, следующие после
				n.erase(newEnd, n.end());
				
				for (int num : n)
				{
					cout << num << "\n";
				}
			}
				  break;
			case 4: {
				auto res = max_element(n.begin(), n.end());
				cout << *res << endl;
				res= min_element(n.begin(), n.end());
				cout << *res << endl;
				
			}
				  break;
			}
		}
			  break;
		case 5: {
			vector<Person>people{
				Person("Ivan",101),
				Person("Petro",50),
				Person("Ann",200),
				Person("Oleg",180),
				Person("Sergey",30),
				Person("Lena",170),
				Person("Olga",198),
				Person("Ivan",167)
			};
			vector<Person>peoples{
				Person("Ivan",101,22),
				Person("Petro",50,19),
				Person("Ann",200,24),
				Person("Oleg",180,40),
				Person("Sergey",30,35),
				Person("Lena",170,53),
				Person("Olga",198, 18),
				Person("Ivan",167,20)
			};
			int task;
			cin >> task;
			switch (task) {
			case 1: {
				int rez = count_if(people.begin(), people.end(), people.front());
				cout << rez << endl;
			}
				  break;
			case 2: {
				sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
					return  p1.getName() < p2.getName();//v
					});
				for_each(peoples.begin(), peoples.end(), Show);
				/*for (auto item : people) {
					cout << "Name:\t" << item.getName() << "  balls:\t" << item.getScore() << endl;
				}*/
			}
				  break;
			case 3: {
				sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
					return  p1.getScore() > p2.getScore();
					});
				cout << endl << endl;
				for (auto item : people) {
					cout << "Name:\t" << item.getName() << "  balls:\t" << item.getScore() << endl;
				}
			}
				  break;
			case 4: {

				auto rezult = find_if(people.begin(), people.end(), [](const Person& p) {
					return p.getName() == "Ivan";
					});
				if (rezult == people.end()) {
					cout << "don't find \n";
				}
				else
					cout << "find \n";
			}
				  break;
			case 5: {
				//выборка элементов
				vector<Person>result;			
			/*	copy(people.begin(), people.end(), back_inserter(result));
				cout << "size: " << result.size() << endl;
				for (auto item : result) {
					cout << "Name:\t" << item.getName() << "  balls:\t" << item.getScore() << endl;
				}*/
				copy_if(peoples.begin(), peoples.end(), back_inserter(result), [](const Person& p) {
					return p.getName() == "Ivan";
					});
				cout << "size: " << result.size() << endl;
				for (auto item : result) {
					cout << "Name:\t" << item.getName() << "  balls:\t" << item.getScore() << endl;
				}
			}
				  break;
			case 6: {
				
				vector<Person>result;
				copy_if(peoples.begin(), peoples.end(), back_inserter(result), [](const Person& p) {
					return p.getAge()>25&&p.getScore()>140;
					});
				sort(result.begin(), result.end(), [](const Person& p1, Person& p2) {
					return p1.getAge() < p2.getAge();
					});
				cout << "size: " << result.size() << endl;
				for (auto item : result) {
					cout << "Name:\t" << item.getName() << "  balls:\t" << item.getScore()<<" age: "<<item.getAge() << endl;
				}
			}
				  break;
			case 7: {
				auto result=remove_if(peoples.begin(), peoples.end(), [](const Person& p) {
					return p.getScore() < 150;
					});
				peoples.erase(result, peoples.end());
				cout << "size: " << peoples.size() << endl;
				for (auto item : peoples) {
					cout << "Name:\t" << item.getName() << "  balls:\t" << item.getScore() << " age: " << item.getAge() << endl;
				}
			}
				  break;
			}
		}
			break;
		case 6: {
			Summary sums(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }));

			cout << "сумма чётных = " << sums(true) << endl
				<< "сумма нечётных = " << sums(false) << endl;
			
		}
			  break;
		case 7: {
			
		}
			  break;
		case 8: {
		
		}
			  break;
		}
		}while (task != 0);
		return 0;
	}
