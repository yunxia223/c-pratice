#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;

class Person {
public:
	Person() {};
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printIntArray(MyArray <int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i]<<endl;
	}
}

void printPersonArray(MyArray<Person>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "姓名：" << arr[i].m_Name << "年龄：" << arr[i].m_Age << endl;
	}
}

void test01() {
	MyArray<int>arr1(5);

	/*MyArray<int>arr2(arr1);

	MyArray<int>arr3(100);
	arr3 = arr1;*/
	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为:" << endl;
	printIntArray(arr1);

	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;

	MyArray<int>arr2(arr1);
	arr2.Pop_Back();
	printIntArray(arr2);
}



void test02() {
	MyArray<Person>arr(10);
	Person p1("孙悟空", 999);
	Person p2("韩信", 30);
	Person p3("妲己", 20);
	Person p4("赵云", 25);
	Person p5("安琪拉", 18);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonArray(arr);
	cout << "arr容量为：" << arr.getCapacity() << endl;
	cout << "arr的大小为：" << arr.getSize() << endl;
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}
