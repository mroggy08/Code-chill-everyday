#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 5e5+5;
int n,q,a[N];
ll b[N],x,vt;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i],b[i] = b[i-1] + a[i];
    while (q--){
        cin >> x;
        vt = lower_bound(b+1,b+n+1,x) - b;
        cout << vt << '\n';
    }


    return 0;
}
