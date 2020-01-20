#include <iostream> 

using namespace std;

class SomeClass
{
private:
	char* x1;
	char* x2;
public:
	SomeClass()//Конструктор по умолчания 
	{
		cout << "Default constructor worked here" << endl;
		this->x1 = new char[1024];
		this->x2 = new char[1024 * 1024];
	}

	SomeClass(char* x_1, char* x_2) : x1(x_1), x2(x_2)//Конструктор 
	{
		cout << "Constructor worked here" << endl;
		this->x1 = new char[1024];
		this->x2 = new char[1024 * 1024];
	}

	SomeClass(const SomeClass& someClass) : x1(someClass.x1), x2(someClass.x2)//Конструктор копирования 
	{
		cout << "Copy constructor worked here" << & someClass << endl;
	}

	SomeClass& operator = (const SomeClass& that)
	{
		if (&that == this)
			return *this;

		delete[] this->x1;
		delete[] this->x2;
		cout << "Copy-aligment worked here" << endl;
		this->x1 = new char[1024];
		this->x2 = new char[1024 * 1024];

		for (int i = 0; i < 1024; i++)
			this->x1[i] = that.x1[i];

		for (int i = 0; i < (1024 * 1024); i++)
			this->x2[i] = that.x2[i];

		return *this;
	}

	SomeClass(SomeClass&& someClass) : x1(someClass.x1), x2(someClass.x2)//Конструктор перемещения 
	{
		someClass.x1 = nullptr;
		someClass.x2 = nullptr;
		cout << "Move constructor worked here" << & someClass << endl;
	}

	SomeClass& operator = (SomeClass&& that)
	{
		if (&that == this)
			return *this;

		delete[] this->x1;
		delete[] this->x2;
		cout << "Move-aligment worked here" << endl;
		this->x1 = that.x1;
		this->x2 = that.x2;
		that.x1 = nullptr;
		that.x2 = nullptr;

		return *this;
	}

	void Setx1(char* x1) {//Установка значения x1 
		this->x1 = x1;
	}

	char* Getx1() {//Получение значения x1 
		return this->x1;
	}

	void Setx2(char* x2) {//Установка значения x2 
		this->x2 = x2;
	}

	char* Getx2() {//Получение значения x2 
		return this->x2;
	}

	~SomeClass()//Деструктор 
	{
		delete[] this->x1;
		this->x1 = nullptr;
		delete[] this->x2;
		this->x2 = nullptr;
		cout << "Destructing complete" << endl;
	}
};

int main()
{
	SomeClass someClass_ = SomeClass();

	SomeClass someClass(move(SomeClass((char*)'1', (char*)'1')));
	someClass = SomeClass((char*)'1', (char*)'1');

	SomeClass someClass0(SomeClass((char*)'1', (char*)'1'));
	someClass0 = someClass;

	return 0;
}