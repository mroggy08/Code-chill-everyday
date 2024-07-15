#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
string A[N],B[N],tmp,s,v,s1;
int d,d1;
string ch(string s){
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin,s);
    tmp=""; v="";
    for (int id = 0; id < s.size(); id++){
        if (s[id]==' ') v+=s[id];
        if (s[id]!=' ' && s[id-1]==' ') B[++d1] = v,v="";
        if (s[id]!=' ')  tmp += s[id];
        if ((s[id]==' '&&s[id-1]!=' ')||id==s.size()-1){
//                cout << tmp.size() << ' ';
            A[++d] = tmp;
            tmp = "";
        }
    }
    string s1="";
    int ma,k;
    for (int i = 1; i < d; i++){
        s1+=ch(A[i])+B[i];
        k = A[i].size();
        ma = max(ma,k);
    }
    k = A[d].size(); ma = max(ma,k);
    s1+=ch(A[d]);
    cout << s1 << '\n';
    int n = s1.size();
    s1 = "#" + s1 + " ";
    tmp = "";
    for (int i = 1; i <= n+1; i++){
        if (s1[i]!=' '){
            tmp += s1[i];
        }
        if  (s1[i]==' ' && s1[i-1]!=' '){
            if (tmp.size()==ma){
                cout << tmp << ' ';
                cout << i-tmp.size() << '\n';
            }
//            cout << tmp << ' ';
            tmp = "";
        }
    }
    return 0;
}
