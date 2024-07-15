#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define __ThanhDat int main

//            ______________Code_______________

using namespace std;

const int maxd = 1e3;
const int maxn = maxd*maxd;
const ll mo = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

//             ______________Start_______________

void print(string s)
{
    while (s[0]=='0') s.erase(0,1);
    cout << s;
    exit(0);
}
string n,tg;
int k,d;
__ThanhDat()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    n = '0' + n;
    if (n.size() <= k)
    {
        f1(i,1,k) cout << '5';
        return 0;
    }
    // dem 5
    for (int i = 0; i < n.size(); i++) d += (n[i]=='5');
    if (d == k)
        print(n);
    else if (d < k)
    {
        // tg = n;
        for (int i = n.size() - 1; i >= 0&&d<k; i--)
        {
            if (n[i]=='5') continue;
            n[i]='5'; d++;
        }
        int k = n.size() - 1;
        while (k >= 0)
        {
            if (n[k]!='5')
                break;
            k--;
        }
        // cout << k << ' ';
        n[k]++;
        if (n[k]=='5') n[k+1]='0';
        else if (n[k]>'9')
        {
            while (n[k]>'9'&&k>=0)
            {
                n[k]='0';
                n[k-1]++;
                k--;
            }
        }
       print(n);
    }
    else 
    {
        int m = n.size() - 1;
        while (d>k)
        {
            if (n[m]=='5') d--;
            m--;
        }      
        n[m]='6'; m++;
        for (int i = m; i < n.size(); i++) n[i] = '0';
        print(n);
    }
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return (0 ^ 0);
}
