#include <iostream>

using namespace std;
/*
void Vending_Machine();
int Input_Coin();
int Show_Menu(int _iCoin);

void main()
{
	Vending_Machine();
}

int Input_Coin()
{
	int iCoin = 0;

	cout << "������: ";
	cin >> iCoin;

	return iCoin;
}

int Show_Menu(int _iCoin)
{
	int iSelect = 0;

	cout << "������: " << _iCoin << endl;
	cout << "========================================" << endl;
	cout << "1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.��ȯ" << endl;

	cout << "========================================" << endl;
	cout << "�Է�: ";
	cin >> iSelect;

	return iSelect;
}

void Vending_Machine()
{
	int iCoin = 0, iSelect = 0;
	bool bCheck = true;

	iCoin = Input_Coin();

	while (bCheck)
	{
		system("cls");
		iSelect = Show_Menu(iCoin);

		switch (iSelect)
		{
		case 1:
			if (100 <= iCoin)
			{
				cout << "�ݶ� ����!" << endl;
				iCoin -= 100;
			}
			else
				cout << "������ ����" << endl;
			break;
		case 2:
			if (200 <= iCoin)
			{
				cout << "���̴� ����!" << endl;
				iCoin -= 200;
			}
			else
				cout << "������ ����" << endl;
			break;
		case 3:
			if (300 <= iCoin)
			{
				cout << "ȯŸ ����!" << endl;
				iCoin -= 300;
			}
			else
				cout << "������ ����" << endl;
			break;
		case 4:
			bCheck = false;
			continue;
		default:
			continue;
		}
		system("pause");
	}

	system("cls");

	cout << "�Ž��� ���� " << iCoin << "�� �Դϴ�." << endl;
}
*/

struct Item {
	char *name;
	int price;
};

Item menu[4] = { "�ݶ�" , 500, "���̴�" , 400, "���䷹��" , 600, "��Ŀ��", 700 };

class Machine {
	Item* m_Menu;
	int inMoney;
	int itemNum;
	int change;
public:
	Machine();
	Machine(const Machine&);
	~Machine();

	void displayMenu();
	void getMoney();
	void selectItem();
	void calcChange();
	void giveItem();

};
Machine::Machine() {
	m_Menu = new Item[4];
	for (int i = 0; i < 4; i++) {
		m_Menu[i].name = new char[strlen(menu[i].name) + 1];
		strcpy(m_Menu[i].name, menu[i].name);
		m_Menu[i].price = menu[i].price;
	}
	inMoney = change = 0;
}
Machine::Machine(const Machine& y) {
	m_Menu = new Item[4];
	for (int i = 0; i < 6; i++) {
		m_Menu[i].name = new char[strlen(y.m_Menu[i].name) + 1];
		strcpy(m_Menu[i].name, y.m_Menu[i].name);
		m_Menu[i].price = y.m_Menu[i].price;
	}
	inMoney = change = 0;
}

Machine::~Machine() {
	delete[] m_Menu;
}

void Machine::displayMenu() {
	cout << "---------- Menu -----------" << endl;
	cout << " 1. �ݶ�        500\n";
	cout << " 2. ���̴�      400\n";
	cout << " 3. ���䷹��    600\n";
	cout << " 4. ��Ŀ��      700\n";
	cout << "-----------------------\n";
}

void Machine::getMoney() {
	cout << "���� �־��ּ��� :";
	cin >> inMoney;
}

void Machine::selectItem() {
	cout << "���ϴ� ������ ��ȣ�� ? ";
	cin >> itemNum;
}

void Machine::calcChange() {
	change = inMoney - m_Menu[itemNum - 1].price;

	if (change < 0) {
		cout << "�ݾ��� �����մϴ�. " << -change << "���� �� �־��ּ���. \n";
	}
}
void Machine::giveItem() {
	if (change < 0) {}
	else {
		cout << endl << m_Menu[itemNum - 1].name << "������� ��µǾ����ϴ�. ���ְ� �弼�� !\n";
		cout << change << "���� ���ҽ��ϴ�. �����մϴ�. ! \n";
	}
}

void main() {
	Machine m;
	Machine _m(m);
	_m.displayMenu();
	_m.getMoney();
	_m.selectItem();
	_m.calcChange();
	_m.giveItem();
}