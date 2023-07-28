#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "请输入a猪的体重：";
	cin >> a ;
	cout << "请输入b猪的体重：";
	cin >> b;
	cout << "请输入c猪的体重：";
	cin >> c;
	if (a > b) {
		if (a > c) {
			cout << "a猪最重，为" << a << "千克\n" ;//endl运行1.7秒，\n后只1.1秒
		}
		else{
			cout << "c猪最重，为" << c << "千克\n";
		}
	}
	else {
		if (b > c) {
			cout << "b猪最重，为" << b << "千克\n";
		}
		else {
			cout << "c猪最重，为" << c << "千克\n";
		}
	}
	return 0;
}