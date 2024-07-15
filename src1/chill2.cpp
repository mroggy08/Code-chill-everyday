#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
string s,v;
string mx;
string ss(string a,string b){
    if (a[0]=='-' && b[0]!='-') return b;
    else if (a[0]!='-' && b[0]=='-') return a;
//    string a1="",b1="";
//    if (a.size()!=b.size()){
//        if (a.size()>b.size()) return a;
//        else return b;
//    }
    if (a[0]=='-'){
        string a1="",b1="",a2="",b2="";
        for (int i = 1; i < a.size(); i++) a1+=a[i];
        for (int i = 1; i < b.size(); i++) b1+=b[i];
        // xl so sanh
        int id1,id2;
        for (int i = 0; i < a1.size(); i++){
            if (a1[i]!='0') {
                id1 = i;
                break;
            }
        }
        for (int i = id1; i < a1.size(); i++) a2+=a1[i];
        for (int i = 0; i < b1.size(); i++){
            if (b1[i]!='0') {
                id2 = i;
                break;
            }
        }
        for (int i = id2; i < b1.size(); i++) b2+=b1[i];
        if (a2.size()<b2.size()) return b2;
        else return a2;
        for (int index = 0; index < a2.size(); index++){
            if ((a2[index]-'0') <(b2[index]-'0'))
                return b2;
            else if ((a2[index]-'0') > (b2[index]-'0'))
                return a2;
        }
        return a2;
    } else {
        int id1,id2;
        string a2="",b2="";
        for (int i = 0; i < a.size(); i++){
            if (a[i]!='0') {
                id1 = i;
                break;
            }
        }
        for (int i = id1; i < a.size(); i++) a2+=a[i];
        for (int i = 0; i < b.size(); i++){
            if (b[i]!='0') {
                id2 = i;
                break;
            }
        }
        for (int i = id2; i < b.size(); i++) b2+=b[i];
//        cout << a2 << ' ' << b2 << '\n';
        if (a2.size()<b2.size()) return b2;
        else if (a2.size()>b2.size())return a2;
        for (int index = 0; index < a2.size(); index++){
//            cout << a2[index] - '0' << ' ' << b2[index] - '0' << '\n';
            if ((a2[index]-'0') < (b2[index]-'0'))
                return b2;
            else if ((a2[index]-'0') > (b2[index]-'0'))
                return a2;
        }
        return a2;
    }
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin,s);
    s = s + '#';
    v = "";
    mx = "";
    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i]) || s[i]=='-'){
            v += s[i];
        }
        else if (isdigit(s[i])==0 && isdigit(s[i-1])==1){
            mx = ss(mx,v);
//            cout << v << ' ';
            v = "";
        }
    }
    cout << (mx!=""?mx:"0");
    return 0;
}
