#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
int n;
ll a[N],kq,ma;
unordered_map <ll,int> mp;
bool cp(ll n){
    ll k = sqrt(n);
    return k*k==n;
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (cp(a[i])) mp[a[i]] = 1;
        ma = max(ma,a[i]);
    }
    for (int i = 0; i <= 100000; i++){
        if (i*i > ma) break;
        if (mp[i*i]==0) kq+=i*i;
    }
    cout << kq;


    return 0;
}
