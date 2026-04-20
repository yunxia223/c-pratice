#include <iostream>
using namespace std;

class AbstractDrinking {
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;

	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee:public AbstractDrinking {
public:
	virtual void Boil() {
		cout << "煮开水" << endl;
	}
	virtual void Brew() {
		cout << "泡咖啡" << endl;
	}
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething() {
		cout << "加入牛奶或糖" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	virtual void Boil() {
		cout << "煮开水" << endl;
	}
	virtual void Brew() {
		cout << "泡茶" << endl;
	}
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething() {
		cout << "加入柠檬或枸杞" << endl;
	}
};

void doWork(AbstractDrinking* abs) {
	abs->makeDrink();
	delete abs;
}

void test01() {
	doWork(new Coffee);
	cout << "---------" << endl;
	doWork(new Tea);
}

int main() {
	test01();
	system("pause");
	return 0;
}