#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

bool check(string s) 
{
    stack<char> sta;
    for(char c : s) {
        if(c == '(' || sta.empty()) sta.push(c);
        else if(c == ')') {
            char ch = sta.top();
            if(ch == '(') sta.pop();
            else sta.push(c);
        }
    }
    return sta.empty();
}

void solve()
{
	int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(m);
    for(int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    v.push_back({0,0});
    m++;
    sort(v.begin(), v.end(),[&](pair<int,int> a, pair<int,int> b) {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    });
    string s(2 * n, ')');
    int l = v[0].first, r = v[0].second;
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(v[i].second < l) {
            s[l] = '(';
            l = v[i].first;
            r = v[i].second;
            cnt++;
            continue;
        }
        l = max(l, v[i].first);
        r = min(r, v[i].second);
    }
    
    if(cnt < n) {
        for(int i = 0; i < 2 * n; i++) {
            if(s[i] == '(') continue;
            s[i] = '(';
            cnt++;
            if(cnt == n) break;
        }
    }
    //cout << s << "\n";
    if(check(s)) cout << s << "\n";
    else cout << -1 << "\n";
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