#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define fi first
#define se second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i = (n); i <= (m); i++)
#define f2(i,n,m) for (int i = (n); i < (m); i++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define twt int T;cin>>T;while(T--)

using namespace std;

const int mod = 1e9+7;
const ll inf = 1e12;
int doi(string c)
{
	int a = 0; for (auto t : c) a = a*10 + (t-'0'); return a;
}
int main()
{
    // freopen("INP.INP","r",stdin);
    // freopen("OUT.OUT","w",stdout);
    faster;
    twt
    {
    	string s,a,b;
    	cin >> s;
    	int n = s.size(),ok = 0;
    	f2(i,1,n)
    	{
    		a = s.substr(0,i);
    		b = s.substr(i,n-i);
    		// cout << a << ' ' << b << '\n';
    		if (b[0] != '0' && doi(a) < doi(b))
    			{
    				ok = 1;
    				break;
    			}
    	}
    	if (ok)
    	{
    		cout << doi(a) << ' ' << doi(b) << '\n';
    	}
    	else cout << -1 << '\n';
    }
    return (0^0);
}