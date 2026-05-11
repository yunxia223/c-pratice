#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray {
public:
	//Constructor with parameter
	MyArray(int capacity) {
		//cout << "MyArray constructor called" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	
	//Copy constructor
	MyArray(const MyArray& arr) {
		//cout << "MyArray copy constructor called" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//Assignment operator to prevent shallow copy
	MyArray& operator=(const MyArray& arr) {
		//cout << "MyArray operator= called" << endl;
		if (this->pAddress != nullptr) {
			delete[] this->pAddress;
			this->pAddress = nullptr;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val) {
		if (this->m_Capacity == this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back() {
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	//通过下标访问数据
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}

	int getSize() {
		return this->m_Size;
	}

	//Destructor
	~MyArray() {
		//cout << "MyArray destructor called" << endl;
		if (this->pAddress != nullptr) {
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
	}

private:
	T* pAddress;
	
	int m_Capacity;

	int m_Size;
};
