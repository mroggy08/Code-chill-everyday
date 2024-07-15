    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    long double a,b,kq;
    int main()
    {
        if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        cin >> a >> b;
        kq = ((a*a)+(b*b))/4;
        cout << setprecision(2) << fixed << kq;


        cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
        return 0;
    }
