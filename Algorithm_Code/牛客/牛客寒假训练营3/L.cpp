#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

int n = 0;
int sum = 1;

void print3(int root, int num, int mul)
{
	if(num == 0) return;
	cout << root - mul << " ";
	print3(root - mul,num - 1,mul - 1);
}

void print2(int root, int h)
{
	if(h > n) return;
	cout << root + 1 << " ";
	cout << root << " ";
	//cout << root + h + 2 << " ";
	//cout << root + h + 1 << " ";
	if(h == n) print3(root,sum - root - 1,h);
	print2(root + h + 1,h + 1);
}



void print1(int root, int h)
{
	if(h > n) return;
	cout << root << " ";
	print1(root + h + 1, h + 1);
	print2(root + h, h);
}

void solve()
{
	cin >> n;
	for(int i = 1; i<= n; i++) sum += (i + 1);
	cout << "Yes" << endl;
	print1(1, 1);
	cout << 1;
}


int main()
{
	int  T = 1;
	//cin >> T;
	
	while(T--) solve();
	
	return 0;
}