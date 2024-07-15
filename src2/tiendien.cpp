#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ll x1,x2,x3,x4,y;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> x1 >> x2 >> x3 >> x4 >> y;
   	if (y<=50){
   		cout << y*x1;
   	} else if (y>=51 && y<=100){
   		cout << 50*x1 + (y-50)*x2;
   	} else if (y>=101 && y<=200) {
   		cout << 50*x1 + 50*x2 + (y-100)*x3;
   	} else {
   		cout << 50*(x1+x2) + 100*x3 + (y-200)*x4;
   	}
    
    return 0;
}
