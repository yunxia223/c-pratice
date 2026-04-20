#include <iostream>
#include <string>
using namespace std;

class CPU {
public:
	virtual void calculate() = 0;
};

class VideoCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void doWork() {
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Intel的CPU正在计算" << endl;
	}
};

class IntelVideoCard :public VideoCard {
public:
	virtual void display () {
		cout << "Intel的显卡正在显示" << endl;
	}
};

class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel的内存条正在存储" << endl;
	}
};

class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Lenovo的CPU正在计算" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Lenovo的显卡正在显示" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << "Lenovo的内存条正在存储" << endl;
	}
};

void test01() {
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;

	Computer* computer1 =new Computer(intelCpu, intelVideoCard, intelMemory);
	computer1->doWork();
	delete computer1;

	cout << "-------------------" << endl;

	Computer* computer2 = new Computer(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
	computer2->doWork();
	delete computer2;

	cout << "-------------------" << endl;

	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new IntelMemory);
	computer3->doWork();
	delete computer3;
}

int main() {
	test01();
	system("pause");
	return 0;
}