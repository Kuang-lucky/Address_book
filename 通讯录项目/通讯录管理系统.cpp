#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //宏常量
//联系人结构体
struct Person {
	string m_name;
	int m_sex;//性别：1男、2女
	int m_age;
	string m_phone;
	string m_add;
};
//通讯录结构体
struct  Addrssbooks {
	struct Person personArray[MAX];//通讯录中保存的联系人数组
	int m_size;//通讯录中当前记录联系人个数
};
//添加联系人
void addPerson(Addrssbooks *abs) {
	//如果通讯录已满，则添加失败
	if (abs->m_size == MAX) {
		cout << "联系人已满" << endl;
		return;
	}
	else {//添加具体联系人 
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		//性别
		cout << "请输入性别： " << endl;
		cout << "1 --  男" << endl;
		cout << "2 --  女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age >= 1 && age <= 150) {
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
		}
		//电话
		cout << "请输入电话号码： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;
		//住址
		cout << "请输入家庭住址: " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_add = address;
		//更新通讯录
		abs->m_size++;

		cout << "添加成功！" << endl;

		//清屏
		system("pause");//请按任意键继续
		system("cls");//清屏操作

	}	
}
//显示联系人
void showPerson(Addrssbooks* abs) {
	if (abs->m_size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名： " << abs->personArray[i].m_name << "\t";
			cout << "性别： " << (abs->personArray[i].m_sex==1?"男":"女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_age << "\t";
			cout << "电话： " << abs->personArray[i].m_phone << "\t";
			cout << "住址： " << abs->personArray[i].m_add<< endl;
		}
	}

	//清屏
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}
//检测联系人是否存在，如果存在，返回联系人所在数组位置，不存在则返回-1.
//参数1 通讯录   参数2  对比姓名
int isExist(Addrssbooks* abs, string name) { 
	for (int i = 0; i < abs->m_size; i++) {
		//找到用户输入姓名
		if (abs->personArray[i].m_name == name) {
			return i;//找到了，返回位置
		}
	}
	return -1;
}
//删除联系人:
void deletePerson(Addrssbooks* abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	//ret=-1 未找到此人
	int ret = isExist(abs, name);
	if (ret != -1) { //找到要删除的人
		//删除李四，将李四后面的人依次进行前移
		for (int i = ret; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
	}
	else {
		cout << "查无此人" << endl;
	}
}
//查找联系人
void findPerson(Addrssbooks* abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断指定联系人是否存在
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名： " << abs->personArray[ret].m_name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_age << "\t";
		cout << "电话： " << abs->personArray[ret].m_phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_add << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(Addrssbooks* abs) {
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1：男  2：女 " << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_sex = sex;
				break;
			}
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string  address;
		cin>> address;
		abs->personArray[ret].m_add = address;
	}
	system("pause");
	system("cls");
}
//清空通讯录
void cleanPerson(Addrssbooks *abs) {
	cout << "确定要清空通讯录吗？" << endl;
	cout << "1：确定 2:取消" << endl;
	int tag = 0;
	cin >> tag;
	if (tag == 1 || tag == 2) {
		if (tag == 1) {
			abs->m_size = 0;//将人数置为0
			cout << "通讯录已清空" << endl;
		}
		else
			cout << "已取消清空通讯录" << endl;
	}
	system("pause");
	system("cls");
}
//1.用户选择功能的界面
void  showMenu() {
	cout << "******************************" << endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "*****	6、清空联系人	*****" << endl;
	cout << "*****	0、退出通讯录	*****" << endl;
	cout << "******************************" << endl;
}

int main() {
	//创建通讯录结构体变量
	Addrssbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_size = 0;

	int select = 0;
	//菜单调用
	showMenu();
	//0.退出通讯录
	
	while(true) {
		cin >> select;
		switch (select) {
		case 1://1、添加联系人
			addPerson(&abs); //利用地址传递可以修饰实参
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
		{
			deletePerson(&abs);
			cout << "删除成功" << endl;
				/*cout << "请输入删除联系人姓名： " << endl;
				string name;
				cin >> name;
				if (isExist(&abs, name)==-1) {
					cout << "查无此人！" << endl;
				}
				else {
					cout << "找到此人！" << endl;
				}*/
		}
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:   //0、退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
		showMenu();
	}
	
	system("pause");
	return 0;
}
/*
	1.用户选择功能的界面
		（1）封装函数显示该界面，如void showMenu()
		 (2)在main函数中调用封装好的函数
	2.添加联系人
		(1)设计联系人结构体
		(2)设计通讯录结构体
		(3)main函数中创建通讯录
		(4)封装添加联系人函数
		(5 )测试添加联系人功能
	3.显示联系人
		（1）封装显示人函数：如果当前联系人数为空，则提示联系人为空，否则显示所有联系人。
		 (2)测试显示联系人功能
	4.删除联系人
		(1)封装检测联系人是否存在
		(2)封装删除联系人函数
		(3)测试删除联系人功能
	5.查找联系人
	6.修改联系人
	7.清空联系人
	8.退出通讯录
		（1）当用户选择0时，执行退出，选择其它则不退出
*/