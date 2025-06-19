#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int w, h, a, b;
    int x1, y1, x2, y2;
    cin >> w >> h >> a >> b;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 >= x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    int x3 = x1 + a - 1;
    int y3 = y1 + b - 1;
    int x4 = x2 + a - 1;
    int y4 = y2 + b - 1;
    int mx = x2 - x3 - 1;
    if(x2 <= x3) {
       int m = 0;
       if(y1 > y2) m = y1 - y4 - 1;
       else m = y2 - y3 - 1;
       if(m % b != 0) cout << "No\n";
        else cout << "Yes\n";
        return;
    } 
    if(y1 >= y2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(x3, x4);
        swap(y3, y4);
    }
    if(y2 <= y3) {
        int m = 0;
       if(x1 > x2) m = x1 - x4 - 1;
       else m = x2 - x3 - 1;
       if(m % a != 0) cout << "No\n";
        else cout << "Yes\n";
        return; 
    }
    int my = y2 - y3 - 1;
    if(mx % a == 0 || my % b == 0) cout << "Yes\n";
    else cout << "No\n";
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