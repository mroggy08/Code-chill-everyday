#include <bits/stdc++.h>
using namespace std;
string calc(string s)
{
    string a;
    for (auto x : s)
        if (isalpha(x)) a+=x;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//    freopen("INP.INP","r",stdin);
//    freopen("OUT.OUT","w",stdout);
    string s,t,kq;
    getline(cin,s);
    stringstream ss(s);
    while (ss>>t)
    {
        kq += calc(t);
    }
    cout << kq;
    return 0;
}
