#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve(){
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    int ip = 0;
    if(l1 == l2 && l1 == l3) {
        int b = b1 + b3 + b2;
        if(b == l1) ip = 1;
    } 
    if(l1 == l2 + l3 && b2 == b3) {
        int b = b2 + b1;
        if(b == l1) ip = 1;
    }

    if(b1 == b2 && b1 == b3) {
        int l = l1 + l3 + l2;
        if(l == b1) ip = 1;
    } 
    if(b1 == b2 + b3 && l2 == l3) {
        int l = l2 + l1;
        if(l == b1) ip = 1;
    }
    if(ip) cout << "YES\n";
    else cout << "NO\n";
  
}


int main(){
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}