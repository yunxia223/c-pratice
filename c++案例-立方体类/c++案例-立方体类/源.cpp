#include <iostream>
using namespace std;

class Cube {
public:
	void setL(int l) {
		m_l = l;
	}
	int getL() {
		return m_l;
	}
	void setW(int w) {
		m_w = w;
	}
	int getW() {
		return m_w;
	}
	void setH(int h) {
		m_h = h;
	}
	int getH() {
		return m_h;
	}
	int calculateS() {
		return 2 * m_w * m_l + 2 * m_l * m_h + 2 * m_w * m_h;
	}
	int calculateV() {
		return m_w * m_l * m_h;
	}
private:
	int m_l;
	int m_w;
	int m_h;
};

int main() {
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout << "立方体的表面积为：" << c1.calculateS() << endl;
	cout << "立方体的体积为：" << c1.calculateV() << endl;
	system("pause");
	return 0;
}