#include<iostream>
#include<string>
#include<vector>
using namespace std;

int f[100000][26],cnt[100000];
int n,idx;

void insert(string s)
{
	int p = 0;
	for(int i=0;i<s.size();i++) {
		int tem = s[i]-'a'+1;
		if(!f[p][tem]) f[p][tem] = ++idx;
		p = f[p][tem];
	}
	cnt[p]++;
}

bool found(string s)
{
	int p = 0;
	for(int i=0;i<s.size();i++) {
		int tem = s[i]-'a'+1;
		if(!f[p][tem]) return false;
		p = f[p][tem]; 
	}
	return cnt[p]>0;
}

int main() 
{
	vector<string> v = {"abcdefg","bcdefg","aabbccdd","qwertyuiop","zxcvbnm"};
	for(string s:v) {
		insert(s);
	}
	if(found("abcdefg")) cout << "Yes";
	else cout << "No";
	return 0;
}
