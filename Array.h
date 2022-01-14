/*
 * Array.h
 *  Title :-> Dynamic Array
 *  Functionality : size(),capacity(),insert(),push_back(),front(),back(),begin(),end(),find()
 *  Created on: 19-Mar-2021
 *  Author: jagdeep
 */
#ifndef ARRAY_H
#define ARRAY_H
#include <string>
//#include <exception>
#include <cstdlib>
#include <iostream>
using std::cerr;
template<class T>
class Array
{
private:
	T* ptr;
	signed int length;  //capacity of vector
	signed int cntr;   // denots the size of vector
public:
	Array(signed int n = 0);
	~Array();
	signed int size()const;
	signed int capacity()const;
	void push_back(const T&);
	void push_front(const T&);
	T& operator[](int index);
	T& operator *();
	T& front();
	T& back();
	T* begin();
	T* end();
	T* find(T* first,T* last,const T val);
	void insert(T* ref,const T& val);
	void isSame(T*,T*);
};
template<class T>
Array<T>::Array(signed int n)
{
	ptr = new T[n];
	length = n;
	cntr = 0;
}
template<class T>
signed int Array<T>::size()const
{
	return cntr;
}
template<class T>
signed int Array<T>::capacity()const
{
	return length;
}
template<class T>
void Array<T>::insert(T* ref, const T& val)
{
	int j = 0;
	bool flag = false;
	T* tmp;
	tmp = new T[++length];
	while(j < cntr)
	{
		if(&ptr[j] == ref)
		{
			tmp[j] = val;  // put the value in address
			tmp[j+1] = ptr[j];
			flag = true;
		}
		else
		{
			if(flag == true)
			{
				tmp[j+1] = ptr[j];
			}
			else
			{
				tmp[j] = ptr[j];
			}
		}
		++j;
	}
	delete[] ptr;
	ptr = tmp;
	++cntr;
}
template<class T>
void Array<T>::push_back(const T& elem)
{
	if(cntr >= length)
	{
		if(length == 0)
		{
			length=1;
		}
		length*=2;
		T* tmp = new T[length];     // allocate 1 more memory blocks..
		for(int i=0 ; i < cntr; i++)
			tmp[i] = ptr[i];
		delete[] ptr; // we have to delete the old ptr memory to free it up
		ptr = tmp;   // now ptr points to the memory assigned to tmp  so there is no need to delete tmp
		*(ptr + cntr) = elem;
		++cntr;
	}
	else
	{
		*(ptr + cntr) = elem;
		++cntr;
	}
}
//extra functionality to vector..

template<class T>
void Array<T>::push_front(const T& elem)
{
	T* tmp = new T[++length];
	tmp[0] = elem;
	for(int i = 0; i < cntr; ++i )
	{
		tmp[i+1] = ptr[i];
	}
	++cntr;
	delete[] ptr;
	ptr = tmp;
}
template<class T>
T& Array<T>::operator *()
{
	return *ptr;
}
template<class T>
T& Array<T>::operator[] (int index)
{
	if(index >= cntr)
	{
		std::cerr << "index out of range \n";
	}
	return ptr[index];
}
template<class T>
T& Array<T>::front()
{
	return ptr[0];
}
//back const
template<class T>
T& Array<T>:: back()
{
	return ptr[cntr - 1];
}
// return pointer to begin
template<class T>
void Array<T>::isSame(T* val1 ,T* val2)
{
	if(*val1 == *val2)
		cerr << "both are equal\n";
	else
		cerr << "both are not equal\n";
}
template<class T>
T* Array<T>::begin()
{
	return (ptr+0);
}
// return end pointer
template<class T>
T* Array<T>::end()
{
	return (ptr + (cntr));
}
template<class T>
T* Array<T>::find(T* first , T* last, const T val)
{
	while(first != last)
	{
		if(*first == val)
		{
			return first;
		}
		++first;
	}
	return last;
}
//destructor
template<class T>
Array<T>:: ~Array()
{
	delete[] ptr;
}
#endif


