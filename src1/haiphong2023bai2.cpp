#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int d = 0;
    cin >> s;
    for (auto x : s) if (isdigit(x)) d++;
    cout << d;
    return 0;
}
