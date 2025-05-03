#include<bits/stdc++.h>
using namespace std;

int M,S,T;
int f[300005];

int main()
{
	cin >> M >> S  >> T;
	for(int i = 1; i <= T; i++) {
		if(M >= 10) {
			M -= 10;
			f[i] = f[i - 1] + 60;
		}
		else {
			M += 4;
			f[i] = f[i - 1];
		}
	}
	for(int i = 1; i <= T; i++) {
		if(f[i] < f[i - 1] + 17) f[i] = f[i - 1] + 17;
		if(f[i] >= S) {
			cout << "Yes\n" << i ;
			return 0;
		}
	}
	cout << "No\n" << f[T];
	return 0;
}
