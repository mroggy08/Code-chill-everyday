#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,d=0;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++){
        if (n%i==0){
            d+=2;
        }
        if (i*i==n) d-=1;
    }
    cout << d;
    return 0;
}
