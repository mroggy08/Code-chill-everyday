#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
string s,t,s1;
string xau;
vector <string> res;
int kq;

int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin,s1);
//    s=s+" ";
    stringstream ss(s1);
    while (ss>>t){
        s+=t;
        s += " ";
    }
//    cout << s << '\n';
    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i])) kq+=(s[i]-'0');
        else if (isdigit(s[i])==0 && s[i]!= ' '){
            xau += s[i];
        } else if (s[i]==' ' && s[i-1]!=' ' && xau != "" && i!=0){
            res.pb(xau);
//            cout << xau << ' ';
            xau = "";
        }
    }
    cout << kq << ' ';
////    cout << res.size() << ' ';
    for (string it : res) reverse(it.begin(),it.end()), cout << it << ' ';
//    cout << s1;
    return 0;
}
