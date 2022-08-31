#include <iostream>

using namespace std;

class DomesticAnimal
{
protected:
	string mName;
	double mAge;
public:
	DomesticAnimal(string name) : mName(name)
	{
	}

	DomesticAnimal(double age) : mAge(age) {
	}

	DomesticAnimal(string name, double age) : mName(name), mAge(age)
	{
	}

	virtual void Sound() = 0;
	virtual void Show() = 0;
	virtual void Type() = 0;
	virtual void Age() = 0;
};

class Dog : public DomesticAnimal {
public:
	Dog(string name) : DomesticAnimal(name)
	{

	}
	
	Dog(double age) : DomesticAnimal(age) {

	}

	Dog(string name, double age) : DomesticAnimal(name, age) {

	}

	void Sound() override {
		cout << "-гав гав-" << endl;
	}

	void Show() override
	{
		if (mName.size() <= 0) cout << "name not entered\n";
		else
		cout << this->mName << endl;
	}

	void Type() override {
		cout << "-собака-" << endl;
	}

	void Age() {
		if (mAge < 0) cout << "age not entered\n";
		else
		cout << "age : " << mAge << endl;
	}
};

class Cat : public DomesticAnimal{
public:
	Cat(string name) : DomesticAnimal(name)
	{

	}

	Cat(double age) : DomesticAnimal(age)
	{

	}

	Cat(string name, double age) : DomesticAnimal(name, age) {

	}

	void Sound() override {
		cout << "-мяу мяу-" << endl;
	}

	void Show() override
	{
		if (mName.size() <= 0) cout << "name not entered\n";
		else
		cout << this->mName << endl;
	}

	void Type() override {
		cout << "-кошка-" << endl;
	}

	void Age() {
		if (mAge < 0) cout << "age not entered\n";
		else
			cout << "age : " << mAge << endl;
	}
};

class Parrot : public DomesticAnimal {
public:
	Parrot(string name) : DomesticAnimal(name)
	{
	}

	void Sound() override {
		cout << "-кеша хорррроший-" << endl;
	}

	void Show() override
	{
		if (mName.size() <= 0) cout << "name not entered\n";
		else
		cout << this->mName << endl;
	}

	void Type() override {
		cout << "-Попугай-" << endl;
	}
	void Age() override {
		if (mAge < 0) cout << "age not entered\n";
		else
			cout << "age : " << mAge << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	

	DomesticAnimal* dAnimal[3] = { new Dog(1), new Cat("Феликс",0.6), new Parrot("Кеша") };

	for (int i = 0; i < 3; i++)
	{
		cout << "--------------\n";
		dAnimal[i]->Type();
		dAnimal[i]->Sound();
		dAnimal[i]->Show();
		dAnimal[i]->Age();
		delete dAnimal[i];
	}


	return 0;
}

