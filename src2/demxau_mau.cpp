#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    int ma=0;
    for (int i=1;i<=26;i++)
    {
        int tam=i+96;
        // doi ki tu thanh a,b,c,d...
        int l=0,d=0,khac=0;
        int mp[201];
        for (int j=1;j<=200;j++) mp[j]=0;
        for (int j=1;j<=n;j++)
        {
            int tamm=(int)s[j];
            // ki tu cua day
            if (tamm==tam) d++;
            else 
            {
                mp[tamm]++;
                if (mp[tamm]==1) khac++;
            }
            while (khac>k)
            {
                int tammm=(int)s[l];
                if (tammm==tam) d--;
                else
                {
                    mp[tammm]--;
                    if (mp[tammm]==0) khac--;
                }
                l++;
            }
            ma=max(ma,d);
        }
    }
    cout<<ma;
//cout<<(char)(97+25);
    return 0;
}
