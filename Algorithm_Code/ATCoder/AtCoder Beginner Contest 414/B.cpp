/*
 * @Author: Leon 147289645+LeoninCS@users.noreply.github.com
 * @Date: 2025-07-19 16:02:53
 * @LastEditors: Leon 147289645+LeoninCS@users.noreply.github.com
 * @LastEditTime: 2025-07-19 16:08:41
 * @FilePath: \My_AlgorithmCode\Algorithm_Code\ATCoder\AtCoder Beginner Contest 414\B.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    string s = "";
    vector<i64> l(n);
    vector<char> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> l[i];
    }
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        sum += l[i];
        if(sum > 100) {
            cout << "Too Long";
            return; 
        }
        s += string(l[i], c[i]);
    }
    cout << s;
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