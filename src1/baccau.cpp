#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,sse4,avx,avx2,fma,bmi,bmi2,abm")
#include<bits/stdc++.h>
#define TrThanhDat int main()
#define ii pair<int,int>
#define fi first
#define se second
#define f1(i,n,m) for(int i=n;i<=m;i++)
#define f2(i,n,m,j) for (int i=n;i>=m;i-=j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;
void fan_manchesterunited_20nam() {ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);}
void times() {cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";}
ll gcd(ll a, ll b) {return __gcd(a,b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
const ll mod = 1e9+7;
const int N = 2e5+3;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
char duong[] = {'R', 'L', 'D', 'U'};
int n,m,u,v,f[N],kq;
int find(int u)
{
    if (u==f[u]) return u;
    return f[u]=find(f[u]);
}
void tron(int a, int b)
{
    f[b]=a;
}
TrThanhDat {
    fan_manchesterunited_20nam;
    #define name "task"
    if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
    cin >> n >> m;
    f1(i,0,n-1) f[i]=i;
    kq = n;
    f1(i,1,m)
    {
        cin >> u >> v;
        u = find(u);
        v = find(v);
        if (u!=v)
        {
            kq--;
            tron(u,v);
            if (kq==1) {
                cout << i;
                return 0;
            }
        }
    }
    times();
    return (0 ^ 0);
}
