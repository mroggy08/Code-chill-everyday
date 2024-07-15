#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
ll calc(int n){
     return n*(n-1)/2;
}
int n; ll kq;
string s;
unordered_map<char,int> mp;
set<char> se;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n >> s;
    for (char x : s) mp[x]++,se.insert(x);
    for (char x : se) if (mp[x]>1) kq+= calc(mp[x]);
    cout << kq;
    return 0;
}
