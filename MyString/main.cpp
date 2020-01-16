#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString & other);
	MyString(MyString && other);
	~MyString();
	MyString & operator = (const MyString &other);
	MyString operator + (const MyString & other);
	char & operator[](int index);
	bool operator == (const MyString & other);
	bool operator != (const MyString & other);

	friend std::ostream& operator <<(std::ostream& out, const MyString& str);
	void print();
	int getLenght();
private:
	char* m_str;
	int m_lenght;
};

MyString::MyString() : m_str(nullptr), m_lenght(0) { std::cout << "Constructor "<< this << std::endl; }

MyString::MyString(const char* str)
{
	std::cout << "Constructor " << this << std::endl;

	m_lenght = std::strlen(str);

	m_str = new char[m_lenght+1];
	
	for (int i = 0; i < m_lenght; i++)
	{
		m_str[i] = str[i];
	}
	m_str[m_lenght] = '\0';

}

MyString::MyString(const MyString & other)
{
	std::cout << "Copy constructor " << this << std::endl;

	m_lenght = other.m_lenght;

	m_str = new char[m_lenght+1];

	for (int i = 0; i < m_lenght; i++)
	{
		m_str[i] = other.m_str[i];
	}
	m_str[m_lenght] = '\0';
}

MyString::MyString(MyString && other)
{
	this->m_lenght = other.m_lenght;
	this->m_str = other.m_str;
	other.m_str = nullptr;
}

MyString::~MyString()
{
	std::cout << "Destructor " << this << std::endl;
	delete[] m_str;
}

MyString & MyString::operator=(const MyString & other)
{
	std::cout << "Operator = " << this << std::endl;

	m_lenght = other.m_lenght;

	if (m_str != nullptr)
		delete[] m_str;

	m_str = new char[m_lenght + 1];

	for (int i = 0; i < m_lenght; i++)
	{
		m_str[i] = other.m_str[i];
	}
	m_str[m_lenght] = '\0';

	return *this;
}

MyString MyString::operator+(const MyString & other)
{
	std::cout << "Operator + " << this << std::endl;
	MyString newStr;
		
	int lenght = this->m_lenght + other.m_lenght;

	newStr.m_lenght = lenght;
	
	newStr.m_str = new char[lenght + 1];
	int i = 0;
	for (; i < this->m_lenght; i++)
	{
		newStr.m_str[i] = this->m_str[i];
	}

	for (int j = 0; j < other.m_lenght; j++, i++)
	{
		newStr.m_str[i] = other.m_str[j];
	}

	newStr.m_str[lenght] = '\0';

	return newStr;
}

char & MyString::operator[](int index)
{
	return m_str[index];
}

bool MyString::operator==(const MyString & other)
{
	if (this->m_lenght != other.m_lenght)
		return false;

	for (int i = 0; i < this->m_lenght; i++)
	{
		if (this->m_str[i] != other.m_str[i])
			return false;
	}

	return true;
}

bool MyString::operator!=(const MyString & other)
{
	return !(*this == other);
}

void MyString::print()
{
	for (int i = 0; i < m_lenght; i++)
	{
		std::cout << m_str[i];
	}
	std::cout << '\n';
}

int MyString::getLenght(){	return m_lenght;}

std::ostream& operator<< (std::ostream& out,const MyString& str)
{

}

int main()
{
	MyString str1("Hello1");
	MyString str2("Hello2");
	
	bool ravno;
	ravno = str1 != str2;
	system("pause");
	return 0;
}