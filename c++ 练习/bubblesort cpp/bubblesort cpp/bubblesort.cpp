#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//#include <string>

void bubblesort(int* arr, int sz) {
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main() {
	int arr[] = {5,3,7,8,2,5,6};
	cout << "排序前数组：";
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if(i<sizeof(arr)/sizeof(arr[0])-1){
			cout << arr[i] << ",";
		}
		else {
			cout <<arr[i]<< "\n";
		}
	}
	bubblesort(arr, sizeof(arr) / sizeof(arr[0]));
	cout << "排序后数组：";
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (i < sizeof(arr) / sizeof(arr[0])-1) {
			cout << arr[i]<<",";
		}
		else {
			cout << arr[i] << "\n";
		}
	}
}