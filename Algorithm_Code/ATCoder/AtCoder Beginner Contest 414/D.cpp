/*
 * @Author: Leon 147289645+LeoninCS@users.noreply.github.com
 * @Date: 2025-07-19 17:02:21
 * @LastEditors: Leon 147289645+LeoninCS@users.noreply.github.com
 * @LastEditTime: 2025-07-19 17:38:33
 * @FilePath: \My_AlgorithmCode\Algorithm_Code\ATCoder\AtCoder Beginner Contest 414\D.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
    cin >> n >> m;
    vector<i64> a;
    set<i64> se; 
    for(int i = 0; i < n; i++) {
        i64 b;
        cin >> b;
        if(se.count(b)) continue;
        a.push_back(b);
        se.insert(b);
    }
    sort(a.begin(),a.end());
    n = a.size();
    vector<i64> b;
    for(int i = 1; i < n; i++) {
        i64 add = a[i] - a[i - 1];
        b.push_back(add);
    }
    sort(b.begin(), b.end());
    n = b.size();
    i64 ans = 0;
    for(int i = 0; i <= n - m; i++) {
        ans += b[i];
    }
    cout << ans;
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