#include<iostream>
#include<string>

class String
{
private:
	int len;
	char* str1;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	
	friend std::ostream& operator <<(std::ostream& os, String& s);
	friend std::istream& operator >>(std::istream& is, String& s);
};

String::String()
{
	len = 0;
	str1 = NULL;
}

String::String(const char* s)
{
	len = strlen(s) - 1;
	str1 = new char[len];
	strcpy(str1, s);
}

String::String(const String& s)
{
	len = s.len;
	str1 = new char[len];
	strcpy(str1, s.str1);
}

String::~String()
{
	if (str1 != NULL)
		delete[]str1;
}

String String::operator+(const String& s)
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str1);
	strcat(tempstr, s.str1);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

String& String::operator+=(const String& s)
{
	len += (s.len - 1);
	char* tempstr = new char[len];
	strcpy(tempstr, str1);
	strcpy(tempstr, s.str1);

	if (str1 != NULL)
		delete[]str1;
	str1 = tempstr;
	return *this;
}

bool String::operator==(const String& s)
{
	return strcmp(str1, s.str1) ? false : true;
}

String& String::operator=(const String& s)
{
	if (str1 != NULL)
		delete[]str1;
	len = s.len;
	str1 = new char[len];
	strcpy(str1, s.str1);
	return *this;
}

std::ostream& operator<<(std::ostream& os, String& s)
{
	os << s.str1;
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

int main(void)
{
	std::string str1 = "I like ";
	std::string str2 = "string class";
	std::string str3 = str1 + str2;

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;

	str1 += str2;
	if (str1 == str3)
		std::cout << "동일 문자열!" << std::endl;
	else
		std::cout << "동일하지 않은 문자열!" << std::endl;

	std::string str4;
	std::cout << "문자열 입력: ";
	std::cin >> str4;
	std::cout << "입력한 문자열: " << str4 << std::endl;
	return 0;
}