#include<iostream>
#include<cstring>

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* Ttitle, const char* Tisbn, int Tprice) : price(Tprice)
	{
		title = new char[strlen(Ttitle) + 1];
		isbn = new char[strlen(Tisbn) + 1];
		strcpy(title, Ttitle);
		strcpy(isbn, Tisbn);
	}
	Book(const Book& ref) :price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}
	void ShowBookInfo()
	{
		std::cout << "제목: " << title << std::endl;
		std::cout << "ISBN: " << isbn << std::endl;
		std::cout << "가격: " << price << std::endl;
	}

	Book& operator=(const Book& ref)
	{
		delete[]title;
		delete[]isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
};

class EBook :public Book
{
private:
	char* DRMKey;
public:
	EBook(const char* mtitle, const char* misbn, int price, const char* Drm) :Book(mtitle, misbn, price)
	{
		DRMKey = new char[strlen(Drm) + 1];
		strcpy(DRMKey, Drm);
	}
	EBook(const EBook& ref) :Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		std::cout << "인증키: " << DRMKey << std::endl;
	}
	EBook& operator=(const EBook& ref)
	{
		delete[]DRMKey;
		Book::operator=(ref);
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
};
int main(void)
{
	Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2 = book1;
	book2.ShowBookInfo();
	std::cout << std::endl;
	EBook ebook1("좋은 C++ Ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2("좋은 C++", "555-12345-890-0", 20000, "dfex2w7iw1u");
	ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	return 0;
}