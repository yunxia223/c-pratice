#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//联系人结构体
struct Person {
	string m_Name;
	int m_Age;
	int m_Sex;//1代表男 2代表女
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks {
	Person personArray[MAX];
	int m_Size;
};

//添加联系人函数
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		//添加姓名
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//添加性别
		cout << "请输入性别：" << endl;
		cout << "1-性别男" << endl;
		cout << "2-性别女" << endl;
		int sex=0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "请输入正确的数字" << endl;
		}
		//添加年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//添加电话号码
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//添加住址
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}

//显示菜单函数
void showMenu() {
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}

//显示联系人信息
void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "当前通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女") << "\t";
			cout << "电话号码：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}


//检测联系人信息，若存在，返回其在数组中的具体位置，否则返回-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}


//删除联系人-3
void deletePerson(Addressbooks *abs) {
	cout << "请输入想删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (-1 != ret) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


//4.查找联系人
void findPerson(Addressbooks* abs) {
	cout << "请输入你要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (-1 != ret) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "电话号码：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


//5.修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入想修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		cout << "请输入修改后的联系人姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		while (true) {
			cout << "1---男" << endl << "2---女" << endl;
			cout << "请输入性别：" << endl;
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
				cout << "请输入正确的性别代码" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}



//6.清空联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	while (true) {
		showMenu();
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}