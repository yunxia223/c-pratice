#include <iostream>
using namespace std;

class Point {
public:
	void setX(int x_1) {
		x = x_1;
	}
	int getX() {
		return x;
	}
	void setY(int y_1) {
		y = y_1;
	}
	int getY() {
		return y;
	}
private:
	int x;
	int y;
};


class Circle {
public:
	void setR(int r) {
		R = r;
	}
	int getR() {
		return R;
	}
	void setCen(Point center) {
		Center = center;
	}
	Point getCen() {
		return Center;
	}
private:
	int R;
	Point Center;
};

void test(Circle& c, Point& p) {
	int distance = (c.getCen().getX() - p.getX()) * (c.getCen().getX() - p.getX()) +
		(c.getCen().getY() - p.getY()) * (c.getCen().getY() - p.getY());
	int r = c.getR() * c.getR();
	if (r == distance) {
		cout << "点在圆上" << endl;
	}
	else if (r > distance) {
		cout << "点在圆内" << endl;
	}
	else {
		cout << "点在圆外" << endl;
	}
}


int main() {
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCen(center);
	Point p;
	p.setX(10);
	p.setY(11);
	test(c, p);

	system("pause");
	return 0;
}