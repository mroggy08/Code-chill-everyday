#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, k;
    cin >> n >> k;

    ll sum = 0;
    ll res = 0;
    unordered_map<int, int> fre;
    while (n--)
    {
        int x;
        cin >> x;
        sum += x;
        if (sum == k) res++;
        res += fre[sum - k];
        fre[sum]++;
    }

    cout << res;
    return 0;
}
