#pragma once
typedef struct {
	int len;
	int *data;
}Stack;
void InitialStack(Stack &s,int n) {
	s.data = new int[n];
	s.len = 1;
	s.data[0] = 0;
}
void inStack(Stack& s, int x) {
	s.data[s.len] = x;
	s.len++;
}
void outStack(Stack& s, int &x) {
	if (s.len == 0)return;
	s.len--;
	x = s.data[s.len];
}