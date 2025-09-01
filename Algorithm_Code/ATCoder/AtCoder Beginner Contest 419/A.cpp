#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	string s;
    cin >> s;
    if(s == "red") cout << "SSS";
    else if(s == "blue") cout << "FFF";
    else if(s == "green") cout << "MMM";
    else cout << "Unknown";
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