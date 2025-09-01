#include<bits/stdc++.h>
#include<string>
using namespace std;
int T;
void solve(){
    string s;cin>>s;
    if(s[0]=='-'){
        string ss=s.substr(1);
        if(ss.length()>=2&&ss[0]=='1'){
            int key=1;
            for(int i=1;i<ss.length();i++){
                if(ss[i]!='0'){
                    key=0;break;
                }
            }
            if(key){
                cout<<s;cout<<'1'<<endl;return;
            }
        }
        int ind=-1;
        for(int i=0;i<ss.length();i++){
            if(ss[i]>'1'){
                ind=i;break;
            }
        }
        if(ind==-1) ss=ss+'1';
        else ss.insert(ind, "1");
        cout<<'-'<<ss<<endl;return;
    }
    else{
        int ind=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]>'1'){
                ind=i;break;
            }
        }
        if(ind==-1) s=s+'1';
        else s.insert(ind,"1");
        cout<s<<endl;return;
    }
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}