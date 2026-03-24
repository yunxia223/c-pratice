#include <iostream>
#include <string>
using namespace std;

class MyInteger {
public:
	friend ostream& operator<<(ostream& cout, MyInteger myint);
	MyInteger() {
		m_Num = 0;
	}
	MyInteger& operator++() {
		m_Num++;
		return *this;
	}
	MyInteger operator++(int) {
		MyInteger temp = *this;
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.m_Num ;
	return cout;
}

void test() {
	MyInteger myint;
	cout << myint++ << endl;
	cout << ++myint << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}