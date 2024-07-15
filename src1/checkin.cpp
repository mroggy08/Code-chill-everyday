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
int n,k,a[N],l,r,kq,m;
bool ch(int g)
{
    int d = 0;
//    cout << g << ' ';
    f1(i,1,n) d+=g/a[i];
//    cout << g << ' ' << d << '\n';
//    cout << d << '\n';
    return (d >= k);
}
void tk()
{
    l = 1; r = 1e9;
    while (r>=l)
    {
        m = (r+l)>>1;
//        cout << m << ' ';
        if (ch(m)) kq=r,r = m-1;
        else l = m+1;
    }
//    cout << '\n';
//    cout << l << ' ' << r << ' ';
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin >> n >> k;
    f1(i,1,n) cin >> a[i];
    tk();
    return 0;
}

