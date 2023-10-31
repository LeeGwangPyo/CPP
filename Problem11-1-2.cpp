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
	void ShowBookInfo()
	{
		std::cout << "제목: " << title << std::endl;
		std::cout << "ISBN: " << isbn << std::endl;
		std::cout << "가격: " << price << std::endl;
	}

	Book& operator=(const Book& ref)
	{
		title = new char[strlen(ref.Ttitle) + 1];
		isbn = new char[strlen(ref.Tisbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
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
	void ShowEBookInfo()
	{
		ShowBookInfo();
		std::cout << "인증키: " << DRMKey << std::endl;
	}
};
int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	std::cout << std::endl;
	EBook ebook("좋은 C++ Ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}