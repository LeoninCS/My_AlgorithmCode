#include<bits/stdc++.h>
using namespace std;


unsigned n, m, k, seed;
long long ans;
long long h[205];
set<int> se[205];
long long f[20005][205];

unsigned rnd() {
    unsigned ret = seed;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return ret;
}

void print()
{
	  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	if(h[j] && !f[i][j]) cout << h[j] << " ";
        	if(h[j] && f[i][j]) cout << f[i][j]<< " ";
        	if(h[j] == 0) cout << 0 << " ";
    	}
    	cout << endl;
    }
    cout << endl;
}

void solve() {
    cin >> n >> m >> k >> seed;
    int a,b,c;
    for (int i = 0; i < k; i++) {
        a = (rnd() % 2) + 1;  
        
        if (a == 1) {
            b = (rnd() % m) + 1; 
            c = (rnd() % (n * m)) + 1;
			if(h[b - 1] == 0) h[b - 1] = c;
			else {
				for(int d:se[b - 1]) f[d][b - 1] = c;
				se[b - 1].clear(); 
			}
			//cout << a << " " << b << " "  << c << endl << endl;
			//print();		   
        }
        
        if (a == 2) {
            b = (rnd() % n) + 1;  
            c = (rnd() % m) + 1;  
            if(h[c - 1]) {
            	f[b - 1][c - 1] = -1;
            	se[c - 1].insert(b - 1);	
			}
            //cout << a << " " << b << " "  << c << endl;
		    //print();
        }
    }
  	//print();  
  	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	if(f[i][j] == -1) continue;
        	if(h[j] && !f[i][j]) ans ^= (h[j] * (i * m + j +1));
        	if(h[j] && f[i][j]) ans ^= (f[i][j] * (i * m + j +1));
    	}
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

