#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int n;
int f[1000];
int c[10005],w[10005],p[10005];

int cal(string s)
{
	if(s.size() == 5) return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
	return (s[0] - '0') * 60 + (s[2] - '0') * 10 + (s[3] - '0');
}

void solve()
{
	cin >> s1 >> s2 >> n;
	int dif = cal(s2) - cal(s1);
	for(int i = 0; i < n; i++) {
		cin >> c[i] >> w[i] >> p[i];
		if(p[i] == 0) p[i] = dif / c[i]; 
		int num = min(p[i], dif / c[i]);
		for(int k = 1; num; k <<= 1) {
			if(k > num) k = num;
			num -= k;
			for(int j = dif; j >= c[i] * k; j--) {
				f[j] = max(f[j], f[j - c[i] * k] + w[i] * k);
			}
		}
	}
	cout << f[dif];
}

int main()
{
	solve();
}
