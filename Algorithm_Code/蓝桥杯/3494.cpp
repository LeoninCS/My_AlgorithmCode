#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<string> v;
  while(1) {
    string s;
    getline(cin,s);
    if(s.size() == 1) break;
    else v.push_back(s);
  }
  sort(v.begin(),v.end());
  long long ans = 0;
  for(int i = 0; i < v.size(); i += 2) {
  	string first = v[i];
  	string second = v[i + 1];
  	int a = 
  }
  return 0;
}