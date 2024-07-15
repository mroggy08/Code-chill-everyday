#include <bits/stdc++.h>
#define ll long long
#define rand rd
using namespace std;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r)
{
    assert (l<=r);
    return l + rd()*1LL*rd()%(r-l+1);
}
int main()
{
    srand(time(NULL));
    int tc = 100;
    for (int it = 1; it <= tc; it++)
    {
        ofstream inp("task.inp");
        int a = 1e3, b = Rand(1,1e6);
        inp << min(a,b) << ' ' << max(a,b);
        inp.close();
        system("manhghep.exe");
        system("manhghep_trau.exe");
//        int d = 0;
        if (system("fc task.out task.ans")!=0)
        {
//            d++;
            cout << it << " :s\n";
            return 0;
        }
//        cout << d;
        cout << it << " :ac\n";
    }
        return 0;
}
