#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll a,b,k;
string s;
ll dp(int id,int t,int tcs,bool gh){
    if (id==s.size()) return (t==0)?tcs:0;
    ll ans=0;
    if (gh==1){
        for (int i=0;i<=s[id]-'0';i++){
            ans+=dp(id+1,(t*10+i)%k,tcs+i,(i==s[id]-'0'));
        }
    }
    else {
        for (int i=0;i<=9;i++)
            ans+=dp(id+1,(t*10+i)%k,tcs+i,0);
    }
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a>>b>>k;
    s='#'+to_string(b);
    ll k1=dp(1,0,0,1);
    s='#'+to_string(a-1);
    cout<<k1-dp(1,0,0,1);
    return 0;
}
