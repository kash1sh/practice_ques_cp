
#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define rr return
#define Endl endl

using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;

// Find Min/Max
// * Greedy/Brute Force
// * DP
// * BS

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    map<ll, bool> m;
    // vll pre(1000001, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        // pre[a[i]]++
        m[a[i]] = true;
    }
    sort(a.begin(), a.end());

    ll cnt = n / 2;

    ll sum = 0;
    vector<pair<ll, ll>> v;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < i; j++)
        {
            // if (i == j)
            // continue;
            if (m[a[i] % a[j]] == false)
            {
                sum++;
                // v.push_back({a[i], a[j]});
                cout << a[i] << " " << a[j] << Endl;
                if (sum >= cnt)
                    rr;
            }
            if (sum >= cnt)
                rr;
        }
        if (sum >= cnt)
            rr;
    }
    // cout << v[0].first;
    // for (ll i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    //     rr;
    // }
    rr;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    // cout<<fixed<<setprecision(10)<<ans<<endl;
    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}