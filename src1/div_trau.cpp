#include <bits/stdc++.h>
#define __Kai_Linh int main
#define ll long long

// Made by Kai - Duy Linh
using namespace std;
int q;
ll a, b, u;
__Kai_Linh(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("div.inp","r",stdin);
    freopen("div.ans","w",stdout);
	cin >> q;
	while (q--){
		cin >> a >> b;
		u = abs(__gcd(a, b));
		a /= u;
		b /= u;
		//cout << a << ' ' << b << '\n';
		if (a + b == 0)
			cout << "0 0\n";
		else if (a + b > 0)
			cout << a << ' ' << b << '\n';
		else cout << -a << ' ' << -b << '\n';
	}



	cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
	return 0;
}
