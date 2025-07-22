#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int len(int x)
{
	int res = 0;
	while(x) {
		res++;
		x /= 2;
	}
	return res;
}

void solve()
{
	i64 a, b, c;
	cin >> a >> b >> c;
	//int ta = a, tb = b, tc = c;
	if(a == 0 && b == 0 && c != 0) {
		cout << -1 << "\n";
		return;
	}
	vector<int> ans;
	if(a == 0) {
		
		a ^= b;
		ans.push_back(3);
	}
	int lena = len(a);
	int lenb = len(b);
	int lenc = len(c);
	while(lena < lenc) {
		a *= 2;
		lena++;
		ans.push_back(1);
	}
	while(lenb > lena) {
		b /= 2;
		lenb--;
		ans.push_back(2);
	}
	if(lenb  < lena) {
		b ^= a;
		lenb = lena;
		ans.push_back(4);
	}
	while(lenb) {
		int x = a & (1 << (lenb - 1));
		int y = c & (1 << (lenb - 1));
		if(x != y) {
			a ^= b;
			ans.push_back(3);
		}
		b /= 2;
		lenb--;
		ans.push_back(2);
	}

		b = b ^ a;
		ans.push_back(4);
	
	int n = ans.size();
	//cout << n << "\n";
	for(int i = 0; i < n; i++) {
		//cout << ans[i] << " ";	
	}
	cout << n << " " << a << " " << b << " " << c << endl;
	//cout << ta << " " << tb << " " << tc << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}