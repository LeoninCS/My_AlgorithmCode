#include<bits/stdc++.h>
using namespace std;

long long cc(long long a, long long b) 
{
	long long res1 = 1;
	long long res2 = 1;
	for(int i = 1; i <= b;i++) {
		res1 *= i;
		res2 *= (a - i + 1);
	}
	return res2/res1;
}


int main()
{
	int n = 10000;
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n - i; j++) {
			long long sum = 1;
			sum = cc(n,i)*cc(n - i,j) % (long long)(1e9 + 7);
			for(int z = 1; z <= n - i - j; z++) {
				sum = (sum * 7) % (long long)(1e9 + 7);
			}
			ans = (ans + sum) % (long long)(1e9 + 7);
		}
	}
	cout << ans;
}