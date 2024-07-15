#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+3;
const int mo = 1e9+7;

string s;
int d,n;
vector<int> A;
ll f[10002][101][2];

ll dp(int id, ll tong, int bol){
    if (id==n){
        if (!tong) return 1; return 0;
    }
    ll &ans = f[id][tong][bol];
    if (ans!=-1) return ans;
    ans = 0; int z = 9;
    if (bol) z=A[id];
    for (int j = 0; j <= z; j++) ans = (ans+dp(id+1,(tong+j)%d,j<z ? 0 : bol))%mo;
    return f[id][tong][bol] = ans;
}

ll sol(string s){
    for (int i = 0; i < s.size(); i++) A.pb(s[i]-'0');
    memset(f,-1,sizeof f);
    return dp(0,0,1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> s >> d;
    n = s.size();
    cout << (mo+sol(s)-1)%mo;

    return 0;
}

