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
int l,r,kq,f[1000003];
void sang(int r)
{
	for (int i = 2; i <= r; i++)
		if (!f[i])
			for (int j = i; j <= r; j+=i)
				f[j] = i;
}
unordered_map <int,int> mp;
void tsnt(int n)
{
    int h,s=1;
    while (n>1)
    {
        h = f[n];
        while (n%h==0)
            n/=h;
        s*=h;
    }
    mp[s]++;
}
int main()
{
    faster;
    cin >> l >> r;
    sang(r);
    for (int i = l; i <= r; i++)
        tsnt(i);
    for (auto it : mp)
        kq += (it.se*(it.se-1)/2);
    cout << kq;
    return (0^0);
}
