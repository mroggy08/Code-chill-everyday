#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6+3;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("OUT.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    double x,y,sz=10;
    for (x = 0; x < sz; x++)
    {
    	for (y = 0; y <= 4*sz; y++)
    	{
    		double d1 = sqrt(pow(x-sz,2) + pow(y - sz,2));
    		double d2 = sqrt(pow(x-sz,2) + pow(y - 3*sz,2));

    		if (d1< sz + 0.5 || d2 < sz + 0.5)
    			cout << "V";
    		else cout << " ";
    	}
    	cout << '\n';
    }
    for (x=1; x<2*sz; x++) for (y=0;y<x;y++) cout << " ";
    return ( 0 ^ 0);
}