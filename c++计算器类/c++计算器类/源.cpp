#include <iostream>
#include <string>

using namespace std;

//∆’Õ®–¥∑®
class Calculator{
public:
	int getResult(string oper) {
		if (oper == "+") {
			return n_num1 + n_num2;
		}
		else if (oper == "-") {
			return n_num1 - n_num2;
		}
		else if (oper == "*") {
			return n_num1 * n_num2;
		}
	}

	int n_num1;
	int n_num2;
};

class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}

	int n_num1;
	int n_num2;
};

class AddCalculator:public AbstractCalculator {
	int getResult() {
		return n_num1+n_num2;
	}
};

class SubCalculator :public AbstractCalculator {
	int getResult() {
		return n_num1 - n_num2;
	}
};

class MulCalculator :public AbstractCalculator {
	int getResult() {
		return n_num1 * n_num2;
	}
};


void test1() {
	Calculator c;
	c.n_num1 = 10;
	c.n_num2 = 10;
	cout << c.n_num1 << "+" << c.n_num2 << "=" << c.getResult("+") << endl;
	cout << c.n_num1 << "-" << c.n_num2 << "=" << c.getResult("-") << endl;
	cout << c.n_num1 << "*" << c.n_num2 << "=" << c.getResult("*") << endl;
}

void test2(){
	AbstractCalculator * abs = new AddCalculator;
	abs->n_num1 = 100;
	abs->n_num2 = 100;
	cout << abs->n_num1 << "+" << abs->n_num2 << "=" << abs->getResult() << endl;
	delete abs;
	abs = new SubCalculator;
	abs->n_num1 = 100;
	abs->n_num2 = 100;
	cout << abs->n_num1 << "-" << abs->n_num2 << "=" << abs->getResult() << endl;
	delete abs;
	abs = new MulCalculator;
	abs->n_num1 = 100;
	abs->n_num2 = 100;
	cout << abs->n_num1 << "*" << abs->n_num2 << "=" << abs->getResult() << endl;
	delete abs;
}



int main() {
	test1();
	test2();
	system("pause");
	return 0;
}