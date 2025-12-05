#include<iostream>
#include<string>
#define max 1000
using namespace std;
//联系人的信息
struct person
{
	string p_name;
	string p_sex;
	int p_age;
	string p_phone;
	string p_address;
	
};
//通讯录
struct addressbook
{
	struct person persons[max];
	int p_size = 0;
};
//菜单栏
void menu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}
//1.添加联系人信息
void addperson(struct addressbook *ask)
{
	cout << "请输入联系人的姓名" << endl;
	cin >> ask->persons[ask->p_size].p_name;
	cout << "请输入联系人的性别" << endl;
	cin >> ask->persons[ask->p_size].p_sex;
	cout << "请输入联系人的年纪" << endl;
	cin >> ask->persons[ask->p_size].p_age;
	cout << "请输入联系人的电话" << endl;
	cin >> ask->persons[ask->p_size].p_phone;
	cout << "请输入联系人的住址" << endl;
	cin >> ask->persons[ask->p_size].p_address;
	ask->p_size++;
	system("pause");
	system("cls");
}
//2.显示联系人
void input(struct addressbook* ask)
{
	if (ask->p_size == 0)
	{
		cout << "暂时还没有数据等你添加捏A_A" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < ask->p_size; i++)
		{
			cout << "姓名：" << ask->persons[i].p_name << "\t" << "性别：" << ask->persons[i].p_sex << "\t" << "年纪：" << ask->persons[i].p_age << "\t" << "电话号：" << ask->persons[i].p_phone << "\t" << "家庭住址：" << ask->persons[i].p_address << endl;
		}
		system("pause");
		system("cls");
	}

}
//查找联系人
int found(struct addressbook* ask)
{
	string name;
	cin >>name;
	for (int i = 0; i < ask->p_size; i++)
	{
		if (name == ask->persons[i].p_name)
			return i;
	}
	return -1;
}
//3.输出该数所在地方的联系人信息
void accput(struct addressbook* ask)
{
	cout << "请输入你想查找的联系人" << endl;
	int i = found(ask);
	if (i >= 0)
		cout << "姓名：" << ask->persons[i].p_name << "\t" << "性别：" << ask->persons[i].p_sex << "\t" << "年纪：" << ask->persons[i].p_age << "\t" << "电话号：" << ask->persons[i].p_phone << "\t" << "家庭住址：" << ask->persons[i].p_address << endl;
	else
		cout << "联系人不存在请重新选择" << endl;
	system("pause");
	system("cls");
}
//4.修改联系人
void modify(struct addressbook* ask)
{
	cout << "请输入你想修改的联系人" << endl;
	int i = found(ask);
	if (i >= 0)
	{
		cout << "请输入你想修改联系人的什么信息   1.姓名 2.性别 3.年纪 4.电话 5.地址" << endl;
		int one;
		cin >> one;
		switch (one)
		{
		case 1:cout << "请输入联系人的姓名" << endl; cin >> ask->persons[i].p_name; break;
		case 2:cout << "请输入联系人的性别" << endl; cin >> ask->persons[i].p_sex; break;
		case 3:cout << "请输入联系人的年纪" << endl; cin >> ask->persons[i].p_age; break;
		case 4:cout << "请输入联系人的电话" << endl; cin >> ask->persons[i].p_phone; break;
		case 5:cout << "请输入联系人的地址" << endl; cin >> ask->persons[i].p_address; break;
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "联系人不存在请重新输入" << endl;
		system("pause");
		system("cls");
	}

}
//5.删除联系人
void dele(struct addressbook* ask)
{
	cout << "请输入你想删除的联系人" << endl;
	int i = found(ask);
	if (i >= 0)
	{
		for (; i < ask->p_size; i++)
		{
			ask->persons[i] = ask->persons[i + 1];
		}
		ask->p_size--;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "联系人不存在请重新输入" << endl;
		system("pause");
		system("cls");
	}
}
//6.清空联系人
void clearall(struct addressbook* ask)
{
	ask->p_size = 0;
	system("pause");
	system("cls");
}
int main()
{
	struct addressbook ask;
	int select = 0;
	while (1)
	{
		menu();
		cin >> select;
		switch (select)
		{
			case 1:addperson(&ask);break;
			case 2:input(&ask); break;
			case 3:dele(&ask); break;
			case 4:accput(&ask); break;
			case 5:modify(&ask); break;
			case 6:clearall(&ask); break;
			case 0:
			system("pause");
			return 0;
			break;
		}
	}
}