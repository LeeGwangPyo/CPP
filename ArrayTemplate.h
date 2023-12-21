#ifndef __ARRAY_TEMPlATE_H_
#define __ARRAY_TEMPlATE_H_

#include<iostream>
#include<cstdlib>

template<typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const& arr){}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}
public:
	BoundCheckArray(int len);
	T& operator[](int idx);
	T operator[] (int idx) const;
	int GetArrLen()const;
	~BoundCheckArray();
};

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len):arrlen(len)
#endif // !__ARRAY_TEMPlATE_H_
