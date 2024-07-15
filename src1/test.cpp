#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const int N = 1e6+3;
const int M = 1e3+3;
const int mod = 1e9+7;

string a[2]{"Nam","Nu"};
int main()
{
    fastIO;
    for (int i = 1; i <= 29; i++)
        if (i%3==0 && i%5!=0 || i%2==0) cout << a[0] << '\n';
    else  cout << a[1] << '\n';
    return (0^0);
}
