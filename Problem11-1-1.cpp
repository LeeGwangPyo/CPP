#include<iostream>
#include<cstring>

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum)
	{
	}
	void Shot()
	{
		std::cout << "BBANG!" << std::endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) :handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	Police(const Police& ref)
	{
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
	}
	Police& operator=(const Police& ref)
	{
		if (pistol != NULL)
			delete pistol;

		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
		handcuffs = ref.handcuffs;
		return *this;
	}
	void PutHandcuff()
	{
		std::cout << "SNAP!" << std::endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			std::cout << "Hut BBANG!" << std::endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman1(5, 3);
	Police pman2 = pman1;
	pman2.PutHandcuff();
	pman2.Shot();
	return 0;
}