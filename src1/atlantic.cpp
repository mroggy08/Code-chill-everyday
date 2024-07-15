#include<bits/stdc++.h>
using namespace std;
int n;
long long mp[10];
void sub1()
{
    for (int i=1;i<=n;i++)
    {
        string s=to_string(i);
        for (char c:s) mp[c-'0']++;
    }
    for (int i=0;i<=9;i++) cout<<i<<' '<<mp[i]<<'\n';
}
int main()
{
    freopen("task.inp","r",stdin);
    freopen("task.ans","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    //if (n<=1000000)
        sub1();
    //else sub23();
return 0;
}

