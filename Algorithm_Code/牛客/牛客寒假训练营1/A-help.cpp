#include<bits/stdc++.h>
using namespace std;

bool is_prime(long long i)
{
	for(long long j = 2; j * j <= i; j++) {
			if(i % j == 0) return false;
		}
	return true;
}

int main()
{
	for(long long i = 1e18; i >= 0; --i) {
		if(is_prime(i)) {
			cout << i;
			return 0;	
		}
	}
}
