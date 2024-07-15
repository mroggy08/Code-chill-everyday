#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,sum;
int i,d;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;
    i = 1;
    while (1){
        sum += i;
        d++;
        if (sum==N){
            cout << d;
            return 0;
        } else if (sum < N){
            i++;
        } else {
            cout << "khong";
            return 0;
        }
    }


    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
