#include<iostream>

using namespace std;

int main()
{
	int g;
	cin >> g;
	cout << "you must write number 2~9 ! thank you" << endl;
	while (g > 9)

		cin >> g;

	for (int i = 1; i < 10; i++)
		cout << g << "*" << i << "=" << g * i << endl;

	return 0;
}