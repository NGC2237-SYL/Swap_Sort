#include<iostream>
#include <cstdlib>
using namespace std;

int main() {
	void Bubble_Sort(int*, int);//冒泡排序
	void Quick_Sort(int*, int, int);//快速排序
	srand((unsigned)time(0));
	int n;
	cout << "输入数组长度:";
	cin >> n;
	int* num = new int[n];
	cout << "得到数组：" << endl;
	for (int i = 0; i < n; i++) {
		num[i] = rand() % 100;
		cout << num[i] << " ";
	}
	cout << endl;
	//Bubble_Sort(num, n);
	Quick_Sort(num,0,n-1);
	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++) {
		cout << num[i] << " ";
	}
	return 0;
}

void Bubble_Sort(int *num,int n) {//冒泡排序
	void swap(int&, int&);
	if (n <= 1) {
		return;
	}
	int i, j;
	for (i = 0; i < n; i++) {
		bool flag = true;
		for (j = n - 1; j >i; j--) {
			if (num[j] < num[j - 1]) {
				flag = false;
				swap(num[j], num[j - 1]);
			}
		}
		if (flag) {
			return;
		}
	}
}

void swap(int &a,int &b) {//交换
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}

void Quick_Sort(int* num, int low,int high) {//快速排序
	int partition(int*, int, int);
	if (low < high) {
		int part = partition(num, low, high);
		Quick_Sort(num, low, part-1);
		Quick_Sort(num, part+1, high);
	}
}

int partition(int* num, int low, int high) {//划分
	void swap(int&, int&);
	int temp = num[low];
	while (low < high) {
		while (low<high&&num[high] >= temp) {
			high--;
		}
		num[low] = num[high];
		while (low < high && num[low] < temp) {
			low++;
		}
		num[high] = num[low];
	}
	num[low] = temp;
	return low;
}