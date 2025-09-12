#include<iostream>
#include<string>
using namespace std;

int nxt[100000];

int KMP(string s1,string s2)
{
	int i = 0,j = -1;
	//nxt 
	nxt[0] = -1;
	while(i<s2.length()) {
		if(j == -1||s2[i]==s2[j]) {
			i++;j++;
			nxt[i] = j;
		}
		else j = nxt[j];
	}
	for(int i=0;i<s2.length();i++) cout << nxt[i]<<" ";
	//KMP
	i=0;j=0;
	while(i<s1.length()&&j<s2.length()) {
		if(j==-1||s1[i]==s2[j]) {
			i++;j++;
		}
		else j = nxt[j];
	}
	if(j>=s2.length()) return i - s2.length();
	return -1;
}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int n = KMP(s1,s2);
	if(n>=0) {
		cout << n; 
	}
	else cout << "Æ¥ÅäÊ§°Ü£¡";
}
