#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long a[19],b,d,t,n,k,m,l,tong,dem;
bool kt;
string s,st,s1,k1;
ll doi(string s)
{
    ll val = 0;
    for (auto x : s) val = val*10 + (x-'0');
    return val;
}
int main()
{
//    freopen("problemA.inp","r",stdin);freopen("problemA.out","w",stdout);
//     freopen("so.inp","r",stdin);
//    freopen("so.ans","w",stdout);
    a[1]=1;
    for (int i=2;i<=18;i++) a[i]=a[i-1]*10;
    cin>>n>>k;
    s1 = to_string(n);
    if (s1.size() < k)
    {
        for (int i = 1; i <= k; i++) k1 += '6';
        ll kq = doi(k1) - n;
        cout << kq;
        return 0;
    }
    int cnt = 0;
    for (auto it : s1) if (it=='6') cnt++;
    if (cnt >= k){
        cout << 0;
        return 0;
    }
    d=0;
    while (d<k)
    {
        m=1e9;
        s=to_string(n);
//        if (k>s.size()) for (int i=1;i<=k-s.size();i++) s='0'+s;
        for (int i=s.size()-d-1;i>=0;i--)
        {
            kt=false;
            //cout<<n<<endl;
            b=s[i]-'0';
            l=6-b;
            if (l<0)
                {
                    l+=10;
                    kt=true;
                    //cout<<l<<endl;
                }
            if (m>l*a[s.size()-i])
            {
                m=l*a[s.size()-i];
//                dem=s.size()-i;
//                if (kt==true) dem+=1;
            }
        }
        d++;
        tong+=m;
        cout << m << ' ';
        cout << tong << '\n';
        n+=m;
    }
    cout<<tong;
}
