#include<iostream>
#include<fstream>
#include"Stack.h"
using namespace std;
#define maxNum 32768;
int mark = 1;
int main() {
	int n, cost = 0, tmp = 1, tmp2, minCost = maxNum;//tmp是当前可能添加的数；
	int **CostMartrix;
	void callback(Stack&, int, int&);
	ifstream myfile("in.txt");
	ofstream myfile2("out.txt");
	myfile >> n;
	Stack order;
	InitialStack(order,n);
	CostMartrix = new int*[n];
	for (int i = 0; i < n; i++) {
		CostMartrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			myfile >> CostMartrix[i][j];
		}
	}
	while (order.data[0] < n) {//终止条件设为第一个位置成为n(超出上界)
		while (order.len < n) {
			for (int i = 0; i < order.len; i++) {
				if (order.data[i] == tmp) {
					mark = 0;
					break;
				}
			}
			if (mark == 1) {
				inStack(order, tmp);
				if (order.data[0] == n)break;
				tmp = 0;
			}
			else {
				if (tmp == n - 1) callback(order, n, tmp);
				else {
					tmp++;
					mark = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (order.data[0] == n)break;
			myfile2 << order.data[i];
		}
		if (order.len == n) {
			for (int i = 0; i < n; i++)cost+=CostMartrix[order.data[i]][order.data[(i+1)%n]];
			if (cost < minCost)minCost = cost;
		}
		myfile2 << "  " << cost << endl;
		cost = 0;
		callback(order, n, tmp);
	}
	cout << minCost << endl;
	system("pause");
}

void callback(Stack &order, int n, int& tmp) {
	int x;
	if (order.len == n) {
		outStack(order, x);
		outStack(order, x);
		tmp=x+1;
	}
	else {
		outStack(order, x);
		tmp=x+1; mark = 1;
	}
	if (tmp == n) {
		outStack(order, x);
		tmp = x + 1;
	}
}
