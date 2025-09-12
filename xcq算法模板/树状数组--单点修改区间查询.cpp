#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int c[100005]; // 树状数组
int n, m; // n个数，m次操作
int a[100005]; // 原数组


int lowbit(int x) { return x & -x; } // 1的个数


//单点修改区间和
void add(int x, int k) {
    while (x <= n) {  // 不能越界
      c[x] = c[x] + k;
      x = x + lowbit(x);
    }
  }

int getsum(int x) {  // a[1]..a[x]的和
    int ans = 0;
    while (x > 0) {
      ans = ans + c[x];
      x = x - lowbit(x);
    }
    return ans;
}

void solve()
{
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}