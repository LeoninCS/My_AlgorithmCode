#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	vector<int> cnt(26,0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'A';
        cnt[idx]++;
    }
    int idxx = 'T' - 'A';
    //cout << idxx << " " << cnt[idxx];
    for(int i = 0; i < cnt[idxx]; i++) cout << "T";
    for(int i = 0; i < 26; i++) {
        if(i == idxx) continue;
        for(int j = 0; j < cnt[i]; j++) {
            char ch = 'A' + i;
            cout << ch;
        }
    }
    cout << "\n";
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