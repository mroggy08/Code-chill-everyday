#include <bits/stdc++.h>
using namespace std;
long long a[19],b,d,t,n,k,m,l,tong,dem;
bool kt;
string s;

int main()
{
    //freopen("problemA.inp","r",stdin);freopen("problemA.out","w",stdout);
//     freopen("so.inp","r",stdin);
//    freopen("so.ans","w",stdout);
    a[1]=1;
    for (int i=2;i<=18;i++) a[i]=a[i-1]*10;
    cin>>n>>k;
    d=0;
    while (d<k)
    {
        m=1e9;
        s=to_string(n);
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
                    cout<<l<<endl;
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
        n+=m;
    }
    cout<<tong;
}

