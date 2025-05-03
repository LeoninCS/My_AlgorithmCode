#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	set<int> se;
	se.insert(1);
	int a = 1,b = 1,add = 1;
	for(int i = 1; i <= 7; i++) {
		a += add;
		b += (add + 1);
		se.insert(a);
		se.insert(b);
		add++;
	}
	for(int i = 1; i < 128; i++) {
		if(!se.count(i)) cout << i << " ";
	}
	return 0;
}