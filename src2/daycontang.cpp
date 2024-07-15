#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
string s,q;
void qr1(string &s){
    int n = s.size();
    s = s[s.size()-1] + s;
    string s1 = "";
    for (int i = 0; i < n; i++) s1+=s[i];
    s=s1;
}
void qr2(string &s){
    int n = s.size();
    s = s+s[0];
    string s1 = "";
    for (int i = 1; i <= n; i++) s1+=s[i];
    s=s1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("robot.inp","r")){freopen("robot.inp","r",stdin);freopen("robot.out","w",stdout);}
    cin >> s >> q;
    for (int i = 0; i < q.size(); i++){
        if (q[i]=='R'){
            qr1(s);
            // cout << s << ' '
        } else qr2(s);
    }
    cout << s;
    return 0;
}
