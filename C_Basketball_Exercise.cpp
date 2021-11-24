
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define Endl endl
#define ff first
#define ss second
#define all(X) (X).begin(), (X).end()

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif
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
// vector<vector<ll>> dp(100001, vector<ll>(2, -1));
ll dp[3][100001];
ll help(vpll a, ll n, ll i, ll j)
{
    // cout << "H";
    if (j >= n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == 0)
    {
        // if (a[i] > b[i])
        // {
        dp[i][j] = max(a[j].ff + help(a, n, 1 - i, j + 1), help(a, n, i, j + 1));
        // }
    }
    else
    {
        // debug(dp[i][j]);
        dp[i][j] = max(a[j].ss + help(a, n, 1 - i, j + 1), help(a, n, i, j + 1));
    }
    return dp[i][j];
}
void solve()
{
    ll n;
    cin >> n;
    // vll a(n), b(n);
    vpll a(n);
    fo(i, 0, n)
    {
        cin >> a[i].ff;
    }
    fo(i, 0, n)
    {
        cin >> a[i].ss;
    }

    memset(dp, -1, sizeof(dp));
    cout << max(help(a, n, 1, 0), help(a, n, 0, 0)) << Endl;
    rr;
}
int main()
{
    io();
    // solve();
    // ll t = 1;
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }

    // cout<<setprecision(10)
    return 0;
}