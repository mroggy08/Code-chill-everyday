#include <bits/stdc++.h>
#define file(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define fd(i,n) for (int i = n; i > 0; i--)
#define ii pair<int,int>
#define lli pair<ll,int>
#define pb push_back
#define ll long long
#define VI vector<int>
#define VII vector<ii>
#define VLLI vector<lli>
#define ALL(a) a.begin(),a.end()
using namespace std;
const int N = 1e5+5;
VII a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    int n; cin >> n;
    f1(i,1,n){
    	int x,y;
    	cin >> x >> y;
    	a[i] = ii(x,y);
    	cout << a[i].first << ' ' << a[i].second << '\n';
    }
    return 0;
}

