#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int u,v;
    cin >> u >> v;
    if ((u&1 && v&1) || (u%2==0 && v%2==0)) cout << "trang"; else cout << "den";

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
