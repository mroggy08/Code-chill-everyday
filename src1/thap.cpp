#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
const int N = 5003;
void sw(int a, int b){
    if (a < b) swap(a,b);
}
struct hcn{
    int dai, rong, cao, id;
};
int x,y,z,n,tv[N],vt;
ll f[N],kq;
hcn a[N];
bool cmd1(hcn a, hcn b){
    return (a.dai*a.rong > b.dai*b.rong);
}
bool cm2(hcn a, hcn b)
{
    return ((a.dai >= b.dai) && (a.rong >= b.rong));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #define task "inp"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x >> y >> z;
        if (x>y) swap(x,y);
        if (x>z) swap(x,z);
        if (y>z) swap(y,z);
        a[i] = {y,z,x,i};
    }
    sort(a+1,a+n+1,cmd1);
//    for (int i = 1; i <= n; i++) cout << a[i].dai << ' ' << a[i].rong << ' ' << a[i].cao << '\n';
    a[0] = {10000,10000,10000,0};
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
//            f[i] = max(f[i],f[j] + a[i].cao)
           if (cm2(a[j],a[i]))
           {
//               cout << i << ' ' << j << '\n';
                if (f[i] < f[j] + a[i].cao)
                {
                    f[i] = f[j] + a[i].cao;
//                    cout << f[i] << ' ';
                    tv[i] = j;
//                cout << i << ' ';
                }
//                f[i] = max(f[i],f[j] + a[i].cao);
           }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] > kq){
            kq = f[i];
            vt = i;
        }
    }
    cout << kq << '\n';
//    cout << f[1] << ' ' << f[4] << ' ' << f[5] << ' ' << f[8];
    stack<int> s;
//    cout << vt << '\n';
    while (vt){
        s.push(vt);
        vt = tv[vt];
    }
    cout << s.size() << '\n';
    while (s.size()){
        int t = s.top(); s.pop();
        cout << a[t].id << ' ' << a[t].dai << ' '<< a[t].rong << ' ' << a[t].cao << '\n';
    }
    return 0;
}

