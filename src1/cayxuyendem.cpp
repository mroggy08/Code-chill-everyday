#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int t;
long long l,r,l1,r1;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        l1 = sqrt(l);
        r1 = sqrt(r);
        if (l1*l1!=l) l1+=1;
        cout << r1-l1+1 << '\n';
    }
    return 0;

}
