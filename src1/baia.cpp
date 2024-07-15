#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
using namespace std;
const int N = 1e6+3;
int ax1,ay1,ax2,ay2,bx1,by1,bx2,by2,trai1,trai2,phai1,phai2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;
    trai1 = min(ax1,bx1);
    trai2 = min(ay1,by1);
    phai1 = max(ax2,bx2);
    phai2 = max(ay2,by2);
//    cout << trai1 << ' ' << trai2 << '\n';
    int tam = max(abs(trai1 - phai1),abs(trai2 - phai2));
    cout << tam*tam;
    return 0;
}

