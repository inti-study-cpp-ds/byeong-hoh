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

	cout << "소지금: ";
	cin >> iCoin;

	return iCoin;
}

int Show_Menu(int _iCoin)
{
	int iSelect = 0;

	cout << "소지금: " << _iCoin << endl;
	cout << "========================================" << endl;
	cout << "1.콜라(100원) 2.사이다(200원) 3.환타(300원) 4.반환" << endl;

	cout << "========================================" << endl;
	cout << "입력: ";
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
				cout << "콜라 구매!" << endl;
				iCoin -= 100;
			}
			else
				cout << "소지금 부족" << endl;
			break;
		case 2:
			if (200 <= iCoin)
			{
				cout << "사이다 구매!" << endl;
				iCoin -= 200;
			}
			else
				cout << "소지금 부족" << endl;
			break;
		case 3:
			if (300 <= iCoin)
			{
				cout << "환타 구매!" << endl;
				iCoin -= 300;
			}
			else
				cout << "소지금 부족" << endl;
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

	cout << "거스름 돈은 " << iCoin << "원 입니다." << endl;
}
*/

struct Item {
	char *name;
	int price;
};

Item menu[4] = { "콜라" , 500, "사이다" , 400, "게토레이" , 600, "냉커피", 700 };

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
	cout << " 1. 콜라        500\n";
	cout << " 2. 사이다      400\n";
	cout << " 3. 게토레이    600\n";
	cout << " 4. 냉커피      700\n";
	cout << "-----------------------\n";
}

void Machine::getMoney() {
	cout << "돈을 넣어주세요 :";
	cin >> inMoney;
}

void Machine::selectItem() {
	cout << "원하는 음료의 번호는 ? ";
	cin >> itemNum;
}

void Machine::calcChange() {
	change = inMoney - m_Menu[itemNum - 1].price;

	if (change < 0) {
		cout << "금액이 부족합니다. " << -change << "원을 더 넣어주세요. \n";
	}
}
void Machine::giveItem() {
	if (change < 0) {}
	else {
		cout << endl << m_Menu[itemNum - 1].name << "음료수가 출력되었습니다. 맛있게 드세요 !\n";
		cout << change << "원이 남았습니다. 감사합니다. ! \n";
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