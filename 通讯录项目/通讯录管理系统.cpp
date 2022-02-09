#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //�곣��
//��ϵ�˽ṹ��
struct Person {
	string m_name;
	int m_sex;//�Ա�1�С�2Ů
	int m_age;
	string m_phone;
	string m_add;
};
//ͨѶ¼�ṹ��
struct  Addrssbooks {
	struct Person personArray[MAX];//ͨѶ¼�б������ϵ������
	int m_size;//ͨѶ¼�е�ǰ��¼��ϵ�˸���
};
//�����ϵ��
void addPerson(Addrssbooks *abs) {
	//���ͨѶ¼�����������ʧ��
	if (abs->m_size == MAX) {
		cout << "��ϵ������" << endl;
		return;
	}
	else {//��Ӿ�����ϵ�� 
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1 --  ��" << endl;
		cout << "2 --  Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		
		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age >= 1 && age <= 150) {
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
		}
		//�绰
		cout << "������绰���룺 " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;
		//סַ
		cout << "�������ͥסַ: " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_add = address;
		//����ͨѶ¼
		abs->m_size++;

		cout << "��ӳɹ���" << endl;

		//����
		system("pause");//�밴���������
		system("cls");//��������

	}	
}
//��ʾ��ϵ��
void showPerson(Addrssbooks* abs) {
	if (abs->m_size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "������ " << abs->personArray[i].m_name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_sex==1?"��":"Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_phone << "\t";
			cout << "סַ�� " << abs->personArray[i].m_add<< endl;
		}
	}

	//����
	system("pause");//�밴���������
	system("cls");//��������
}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������λ�ã��������򷵻�-1.
//����1 ͨѶ¼   ����2  �Ա�����
int isExist(Addrssbooks* abs, string name) { 
	for (int i = 0; i < abs->m_size; i++) {
		//�ҵ��û���������
		if (abs->personArray[i].m_name == name) {
			return i;//�ҵ��ˣ�����λ��
		}
	}
	return -1;
}
//ɾ����ϵ��:
void deletePerson(Addrssbooks* abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	//ret=-1 δ�ҵ�����
	int ret = isExist(abs, name);
	if (ret != -1) { //�ҵ�Ҫɾ������
		//ɾ�����ģ������ĺ���������ν���ǰ��
		for (int i = ret; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
	}
	else {
		cout << "���޴���" << endl;
	}
}
//������ϵ��
void findPerson(Addrssbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ����ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������ " << abs->personArray[ret].m_name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_phone << "\t";
		cout << "סַ�� " << abs->personArray[ret].m_add << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyPerson(Addrssbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1����  2��Ů " << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_sex = sex;
				break;
			}
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;
		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string  address;
		cin>> address;
		abs->personArray[ret].m_add = address;
	}
	system("pause");
	system("cls");
}
//���ͨѶ¼
void cleanPerson(Addrssbooks *abs) {
	cout << "ȷ��Ҫ���ͨѶ¼��" << endl;
	cout << "1��ȷ�� 2:ȡ��" << endl;
	int tag = 0;
	cin >> tag;
	if (tag == 1 || tag == 2) {
		if (tag == 1) {
			abs->m_size = 0;//��������Ϊ0
			cout << "ͨѶ¼�����" << endl;
		}
		else
			cout << "��ȡ�����ͨѶ¼" << endl;
	}
	system("pause");
	system("cls");
}
//1.�û�ѡ���ܵĽ���
void  showMenu() {
	cout << "******************************" << endl;
	cout << "*****	1�������ϵ��	*****" << endl;
	cout << "*****	2����ʾ��ϵ��	*****" << endl;
	cout << "*****	3��ɾ����ϵ��	*****" << endl;
	cout << "*****	4��������ϵ��	*****" << endl;
	cout << "*****	5���޸���ϵ��	*****" << endl;
	cout << "*****	6�������ϵ��	*****" << endl;
	cout << "*****	0���˳�ͨѶ¼	*****" << endl;
	cout << "******************************" << endl;
}

int main() {
	//����ͨѶ¼�ṹ�����
	Addrssbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;

	int select = 0;
	//�˵�����
	showMenu();
	//0.�˳�ͨѶ¼
	
	while(true) {
		cin >> select;
		switch (select) {
		case 1://1�������ϵ��
			addPerson(&abs); //���õ�ַ���ݿ�������ʵ��
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
		{
			deletePerson(&abs);
			cout << "ɾ���ɹ�" << endl;
				/*cout << "������ɾ����ϵ�������� " << endl;
				string name;
				cin >> name;
				if (isExist(&abs, name)==-1) {
					cout << "���޴��ˣ�" << endl;
				}
				else {
					cout << "�ҵ����ˣ�" << endl;
				}*/
		}
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:   //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
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
	1.�û�ѡ���ܵĽ���
		��1����װ������ʾ�ý��棬��void showMenu()
		 (2)��main�����е��÷�װ�õĺ���
	2.�����ϵ��
		(1)�����ϵ�˽ṹ��
		(2)���ͨѶ¼�ṹ��
		(3)main�����д���ͨѶ¼
		(4)��װ�����ϵ�˺���
		(5 )���������ϵ�˹���
	3.��ʾ��ϵ��
		��1����װ��ʾ�˺����������ǰ��ϵ����Ϊ�գ�����ʾ��ϵ��Ϊ�գ�������ʾ������ϵ�ˡ�
		 (2)������ʾ��ϵ�˹���
	4.ɾ����ϵ��
		(1)��װ�����ϵ���Ƿ����
		(2)��װɾ����ϵ�˺���
		(3)����ɾ����ϵ�˹���
	5.������ϵ��
	6.�޸���ϵ��
	7.�����ϵ��
	8.�˳�ͨѶ¼
		��1�����û�ѡ��0ʱ��ִ���˳���ѡ���������˳�
*/