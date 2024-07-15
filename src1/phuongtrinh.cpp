#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ll a,b,c,t,d;
int main()
{
    if(fopen("cau1.inp","r")){freopen("cau1.inp","r",stdin);freopen("cau1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b >> c;
//    x = c-b*y / a
    for (int i = 1; i <= 1000000; i++){
        if (c<=b*i) break;
        t = c-b*i;
        if (t%a==0 && t!=0) {
            d++;
        }
    }
    cout << d;
    return 0;
}
