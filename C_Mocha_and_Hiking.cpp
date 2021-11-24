
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

ll mod = 1e9 + 7, mxn = 3e5 + 5;
void deb(vector<ll> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}

bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
bool check_sorted(vll a)
{
    ll n = a.size();
    for (ll i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            continue;
        return false;
    }
    return true;
}

ll po(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return po(mul(a, a, mod), b / 2, mod);
    return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
}

long long power(long long X, long long N)
{
    if (N == 0)
        return 1;
    if (N % 2 == 0)
        return power(X * X, N / 2);
    return X * power(X, N - 1);
}

ll fact(ll n)
{
    ll res = 1, i;

    for (ll i = 2; i <= n; i++)
    {
        res = (res * i) % mod;
    }
    return res;
}
long combi(ll n, ll k)
{
    long long ans = 1;
    k = k > n - k ? n - k : k;
    ll j = 1;
    for (; j <= k; j++, n--)
    {
        if (n % j == 0)
        {
            ans *= n / j;
        }
        else if (ans % j == 0)
        {
            ans = ans / j * n;
        }
        else
        {
            ans = (ans * n) / j;
        }
    }
    return ans;
}
// CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
vector<int> sieveOfEratosthenes(int N)
{
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));
    vector<int> arr;

    for (int i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    for (int i = 2; i <= N; i++)
        if (primes[i])
            arr.emplace_back(i);

    return arr;
}
void prime_fact(ll n, vector<ll> &res)
{
    while (n % 2 == 0)
    {
        res.pb(2);
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            res.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
    {
        res.pb(n);
    }
}
bool valid_coordinate(ll x, ll y, ll n, ll m)
{
    if (x < 0 || y < 0)
        return false;

    else if (x >= n || y >= m)
        return false;

    else
        return true;
}
int sod(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}
// vll res;
bool f = false;
// vector<ll> g[10001];
// void dfs(ll i, vector<bool> vis, vll res)
// {
//     if (vis[i])
//         rr;
//     if (res.size() == vis.size() - 1)
//     {
//         // debug(i);
//         res.pb(i + 1);
//         f = true;
//         for (auto j : res)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//         rr;
//     }
//     vis[i] = true;
//     res.pb(i + 1);
//     for (auto x : g[i])
//     {
//         // if (!vis[x])
//         // {
//         debug(x);
//         dfs(x, vis, res);
//         if (f)
//             break;
//         // }
//     }
//     vis[i] = false;
//     res.pop_back();
// }
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    // for (ll i = 1; i <= n; i++)
    // {
    // g[i].pb(i + 1);
    // }
    fo(i, 0, n)
    {
        cin >> a[i];
        // if (a[i] == 0)
        // {
        // g[i].pb(n);
        // }
        // else
        // {
        // g[n].pb(i);
        // }
        // if (i < n - 1)
        // g[i].pb(i + 1);
    }
    deb(a);
    if (a[n - 1] == 0)
    {
        for (ll i = 1; i <= n + 1; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        rr;
    }
    ll last = -1;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            last = i;
            break;
        }
    }
    for (ll i = 0; i <= last; i++)
    {
        cout << i + 1 << " ";
    }
    cout << n + 1 << " ";
    for (ll i = last + 1; i < n; i++)
        cout << i + 1 << " ";
    // if (last == -1)
    // cout << -1;

    cout << endl;
    rr;
    // vector<bool> vis(n + 1, false);
    // vll res;
    // f = false;
    // for (ll i = 0; i <= n; i++)
    // {
    //     // f = false;
    //     // res.clear();
    //     dfs(i, vis, res);
    //     if (f)
    //         break;
    // }
    // if (!f)
    //     cout << -1 << endl;
    // rr;
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

    // cout<<setprecision(10)
    return 0;
}