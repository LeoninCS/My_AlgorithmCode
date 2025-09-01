#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int sum = 0;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] == 0) cnt0++;
        if(a[i] == 1) cnt1++;
        if(a[i] == 2) cnt2++;
    }
    if(sum > s) {
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    sum = s - sum;
    bool flag = false;
    //cout << sum << "\n";
    for(int i = 0; i <= (sum + 1) / 2; i++) {
        if((sum - 2 * i) % 3 == 0) flag = true;
    }
    if(flag) {
        cout << -1 << "\n";
        return;
    }
    for(int i = 0; i < cnt0; i++) cout << 0 << " ";
    for(int i = 0; i < cnt2; i++) cout << 2 << " ";
    for(int i = 0; i < cnt1; i++) cout << 1 << " ";
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