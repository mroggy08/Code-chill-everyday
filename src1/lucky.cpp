#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[1000005],k,res=0;
int main()
{
    freopen("task.inp","r",stdin);
    freopen("task.ans","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    unordered_map<long long, long long> mp;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        ll tam1=(ll)(k-a[i]);
        ll tam2=(ll)(-k-a[i]);
        if (mp.count(tam1)) res=(ll)(res+mp[(ll)(tam1)]);
        if (tam1!=tam2)
        {
            if (mp.count((ll)(tam2))) res=(ll)(res+mp[(ll)(tam2)]);
        }
        mp[a[i]]++;
    }
    cout<<res;
return 0;
}
