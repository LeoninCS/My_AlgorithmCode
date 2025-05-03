#include<bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	vector<int> v(n);
	vector<int> last(n + 1, -2);
	for(int i = 0; i < n; i++) cin >> v[i];
	int l = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if((i - l) % 2 == 0) {
			if(last[v[i]] == i - 1) l = last[v[i]];
			else if(last[v[i]] >= l) l = last[v[i]] + 1;
		}
		else {
			if(v[i] != v[i - 1]) l = i;
		}
		ans = max(ans, i - l + 1);
		last[v[i]] = i;
	}
	cout << 2 * (ans / 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
} 
