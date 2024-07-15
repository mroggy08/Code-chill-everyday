#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kq;
priority_queue<int,vector<int>,greater<int>>q;
pair<int,int> a[1000003];
int n;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++){
        if (a[i].first > q.size()) q.push(a[i].second);
        else if (a[i].second > q.top()){
            q.pop();
            q.push(a[i].second);
        }
    }
    while (q.size()) {
        kq+=q.top();
        q.pop();
    }
    cout << kq;
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
