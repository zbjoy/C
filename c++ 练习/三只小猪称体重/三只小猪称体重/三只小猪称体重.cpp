#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "������a������أ�";
	cin >> a ;
	cout << "������b������أ�";
	cin >> b;
	cout << "������c������أ�";
	cin >> c;
	if (a > b) {
		if (a > c) {
			cout << "a�����أ�Ϊ" << a << "ǧ��\n" ;//endl����1.7�룬\n��ֻ1.1��
		}
		else{
			cout << "c�����أ�Ϊ" << c << "ǧ��\n";
		}
	}
	else {
		if (b > c) {
			cout << "b�����أ�Ϊ" << b << "ǧ��\n";
		}
		else {
			cout << "c�����أ�Ϊ" << c << "ǧ��\n";
		}
	}
	return 0;
}