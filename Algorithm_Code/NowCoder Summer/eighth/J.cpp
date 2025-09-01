#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

string division(string str, int m, int n, int & remain){
    string result = "";
    int a;
    remain = 0;

    for(int i = 0; i < str.size(); i++){
        a = (n * remain + (str[i] - '0'));
        str[i] = a / m + '0';
        remain = a % m;
    }
    int pos = 0;
    while(str[pos] == '0'){
        pos++;
    }
    return str.substr(pos);
}

string conversion(string str, int m, int n){
    string result = "";
    char c;
    int a;
    while(str.size() != 0){
        str = division(str, m , n,a);
        result = char(a + '0') +result;

    }
    return result;
}

 
//高精度加法
//只能是两个正数相加
string add(string str1,string str2)//高精度加法
{
    string str;

    int len1=str1.length();
    int len2=str2.length();
    //前面补0，弄成长度相同
    if(len1<len2)
    {
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}
//高精度减法
//只能是两个正数相减，而且要大减小
string sub(string str1,string str2)//高精度减法
{
    string str;
    int tmp=str1.length()-str2.length();
    int cf=0;
    for(int i=str2.length()-1;i>=0;i--)
    {
        if(str1[tmp+i]<str2[i]+cf)
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf=1;
        }
        else
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf=0;
        }
    }
    for(int i=tmp-1;i>=0;i--)
    {
        if(str1[i]-cf>='0')
        {
            str=char(str1[i]-cf)+str;
            cf=0;
        }
        else
        {
            str=char(str1[i]-cf+10)+str;
            cf=1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));//去除结果中多余的前导0
    return str;
}
//高精度乘法
//只能是两个正数相乘
string mul(string str1,string str2)
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    string tempstr;
    for(int i=len2-1;i>=0;i--)
    {
        tempstr="";
        int temp=str2[i]-'0';
        int t=0;
        int cf=0;
        if(temp!=0)
        {
            for(int j=1;j<=len2-1-i;j++)
              tempstr+="0";
            for(int j=len1-1;j>=0;j--)
            {
                t=(temp*(str1[j]-'0')+cf)%10;
                cf=(temp*(str1[j]-'0')+cf)/10;
                tempstr=char(t+'0')+tempstr;
            }
            if(cf!=0) tempstr=char(cf+'0')+tempstr;
        }
        str=add(str,tempstr);
    }
    str.erase(0,str.find_first_not_of('0'));
    return str;
}

int compare(string str1,string str2)
{
    if(str1.length()>str2.length()) return 1;
    else if(str1.length()<str2.length())  return -1;
    else return str1.compare(str2);
}


void solve()
{
	string A, B;
    cin >> A >> B;
    int lena = A.size(), lenb = B.size();
    string a(10,'0'),b(10,'0'),c(10,'0'),d(10,'0');
    
    for(int i = 0; i < lena; i++) {
        if(A[i] == '0') continue;
        int len = (lena - i - 1);
        if(len % 2 == 1) {
            len /= 2;
            b[len] = '1';
        } else {
            len /= 2;
            a[len] = '1';
        }
    }
    for(int i = 0; i < lenb; i++) {
        if(B[i] == '0') continue;
        int len = (lenb - i - 1);
        if(len % 2 == 1) {
            len /= 2;
            d[len] = '1';
        } else {
            len /= 2;
            c[len] = '1';
        }
    }

    //2进制转化10进制
    reverse(a.begin(),a.end());
    a = conversion(a, 10, 2);
    reverse(b.begin(),b.end());
    b = conversion(b, 10, 2);
    reverse(c.begin(),c.end());
    c = conversion(c, 10, 2);
    reverse(d.begin(),d.end());
    d = conversion(d, 10, 2);
    //cout << a << " " << b << " " << c << " " << d << "\n";
    string ac = mul(a, c);
    string bd = mul(b, d);
    bd = mul("2", bd);
    //cout << ac << " " << bd << "\n";
    string e = "";
    //cout << compare(ac,bd) << "\n";
    if(compare(ac,bd) == 1) e =  sub(ac, bd);
    else e =  "-" + sub(bd, ac);
    //cout << e << "\n";
    string ad = mul(a, d);
    string bc = mul(b, c);
    //cout << ad << " " << bc << "\n";
    string f = add(ad, bc);
    
    if(e.size() == 0) e = "0";
    else if(e.size() == 1 && e[0] == '-') e = "-0";
    if(f.size() == 0) f = "0";
    
    cout << e << "---" << f << endl;
    //10进制转2进制
    if(e[0] == '-') e = "-" + conversion(e.substr(1), 2, 10);
    else e = conversion(e, 2, 10);
    f = conversion(f, 2, 10);
    
    reverse(e.begin(),e.end());
    reverse(f.begin(),f.end());
    //cout << e << "---" << f << endl;
    string ans = string(1000,'0');
    for(int i = 0; i < e.size(); i++){
        if(e[i] == '1')  ans[i * 2 + 1] = '1';
    }
    for(int i = 0; i < f.size(); i++) {
        if(f[i] == '1') ans[i * 2] = '1';
    } 
    reverse(ans.begin(),ans.end());
    //cout << ans << "\n";
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