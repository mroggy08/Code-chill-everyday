#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5+3;
int n,q,u,v,d;
ll x,a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> x >> q;
    f1(i,1,n) cin >> v,a[i]=a[i-1]+v;
    while (q--){
    	cin >> u >> v;
    	if (a[v]-a[u-1] < x) d++;
    }
    cout << d;
    return 0;
}
