#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
set<ll> kq;
ll sum;
int f[100003],a[1000003],n;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++){
        sum += a[i];
        for (int j = sum; j >= a[i]; j--){
            if (f[j-a[i]]==1 && f[j]==0){
                f[j] = 1;
                kq.insert(j);
            }
        }
    }
    cout << kq.size() << '\n';
    for (ll v : kq) cout << v << ' ';
    return 0;
}
//1 - n
//sum += a[i]
//sum ->a[i]
//if (f[sum]==0 && f[j-sum]==1)
//    f[sum] = 1;
//
