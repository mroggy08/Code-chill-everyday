#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)

using namespace std;

const int N = 1e6+3;
const ll inf = 1e18;
const int mo = 1e9+7;
const int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
//int n,m,u,v,w;
ll l,r,d,s,s1;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> l >> r;
    l++; r--;
    if (l%3==2) l++;
    if (r%3==2) r--;
    d = r-l+1;
    s = (r+l)*d/2;
//    cout << l << ' ' << r << ' ' << s << '\n';
    if (l%3==0) l+=2;
    else if (l%3==1) l++;
    if (r%3==0) r--;
    else if (r%3==1) r-=2;
    d = (r-l)/3 + 1;
    s1 = (r+l)*d/2;
//    cout << l << ' ' << r << ' ' << s1 << '\n';
    cout << s-s1;
    return 0;
}
