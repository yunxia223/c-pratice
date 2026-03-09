#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Student {
	string sName;
	int score;
};

struct Teacher {
	string tName;
	Student sArray[5];
};

void allocte(Teacher tArray[],int len) {
	string nameSeed= "ABCDE";
	for (int i = 0; i < len; i++) {
		tArray[i].tName = "teacher_";
		tArray[i].tName += nameSeed[i];
		for (int j = 0; j < 5; j++) {
			tArray[i].sArray[j].sName = "student_";
			tArray[i].sArray[j].sName += nameSeed[j];
			tArray[i].sArray[j].score = rand() % 61 + 40;
		}
	}

}

void print(Teacher tArray[],int len) {
	for (int i = 0; i < len; i++) {
		cout << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t" << tArray[i].sArray[j].sName
				<<" score: "
				<< tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	Teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocte(tArray, len);
	print(tArray, len);
	system("pause");
	return 0;
}