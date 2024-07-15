#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector <int> a;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a.push_back(i*j);
    sort(a.begin(),a.end());
    cout << a[k-1];

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
