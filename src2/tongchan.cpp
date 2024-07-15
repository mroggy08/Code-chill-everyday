#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n,val,le,chan;
ll sum,kq;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
    	cin >> val;
    	// sum += val;
    	if (val%2!=0) le++;
    	else chan++;
    }
    if (le%2==0){
    	if (chan>=2) kq += 1LL*chan*(chan-1)/2;
    	if (le>=2) kq += 1LL*le*(le-1)/2;
    } else {
    	if (chan>=1 && le>=1) 
    		kq += 1LL*chan*le;
    }
    cout << kq;
    
    
    return 0;
}
