
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

ll dp[101][3];
// ll help(vll a, ll n, ll i, ll j, ll &cnt)
// {
//     if (i >= n)
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (a[i] == 0)
//     {
//         // cnt++;
//         dp[i][j] = 1 + help(a, n, i + 1, 0, cnt);
//     }
//     if (a[i] == 1)
//     {
//         if (j == 1)
//         {
//             dp[i][j] = 1 + help(a, n, i + 1, 0, cnt);
//         }
//         else
//         {
//             dp[i][j] = help(a, n, i + 1, 1, cnt);
//         }
//     }
//     if (a[i] == 2)
//     {
//         if (j == 2)
//         {
//             dp[i][j] = 1 + help(a, n, i + 1, 0, cnt);
//         }
//         else
//         {
//             dp[i][j] = help(a, n, i + 1, 2, cnt);
//         }
//     }
//     if (a[i] == 3)
//     {
//         if (j == 0)
//         {
//             dp[i][j] = min(help(a, n, i + 1, 1, cnt), help(a, n, i + 1, 2, cnt));
//         }
//         if (j == 1)
//         {
//             dp[i][j] = help(a, n, i + 1, 2, cnt);
//         }
//         if (j == 2)
//         {
//             dp[i][j] = help(a, n, i + 1, 1, cnt);
//         }
//     }
//     return dp[i][j];
//     // if (a[i] == 3)
//     // {
//     //     if (i == n - 1)
//     //     {
//     //         help(a, n, i + 1, 1 - j, cnt);
//     //     }
//     //     if (i - 1 >= 0 && a[i - 1] == 3)
//     //     {
//     //         if (i + 1 < n && a[i + 1] == 3)
//     //         {
//     //             cnt++;
//     //         }
//     //         help(a, n, i + 1, 1 - j, cnt);
//     //     }
//     //     if (j == 0)
//     //     {
//     //         if (i + 1 < n)
//     //         {
//     //             if (a[i + 1] != 2)
//     //             {
//     //                 help(a, n, i + 1, 1 - j, cnt);
//     //             }
//     //             else
//     //             {
//     //                 cnt++;
//     //                 help(a, n, i + 1, j, cnt);
//     //             }
//     //         }
//     //     }
//     //     if (j == 1)
//     //     {
//     //         if (i + 1 < n)
//     //         {
//     //             if (a[i + 1] != 1)
//     //             {
//     //                 help(a, n, i + 1, 1 - j, cnt);
//     //             }
//     //             else
//     //             {
//     //                 cnt++;
//     //                 help(a, n, i + 1, j, cnt);
//     //             }
//     //         }
//     //     }
//     // }
// }
int func(vll v, int n, int last)
{
    if (n == 0)
        return 0;
    if (dp[n][last] != -1)
        return dp[n][last];
    if (v[n - 1] == 0)
    {
        dp[n][last] = 1 + func(v, n - 1, 0);
    }
    else if (v[n - 1] == 1)
    {
        if (last == v[n - 1])
            dp[n][last] = 1 + func(v, n - 1, 0);
        else
            dp[n][last] = func(v, n - 1, 1);
    }
    else if (v[n - 1] == 2)
    {
        if (last == v[n - 1])
            dp[n][last] = 1 + func(v, n - 1, 0);
        else
            dp[n][last] = func(v, n - 1, 2);
    }
    else
    {
        if (last == 0)
            dp[n][last] = min(func(v, n - 1, 1), func(v, n - 1, 2));
        else if (last == 1)
            dp[n][last] = func(v, n - 1, 2);
        else
        {
            dp[n][last] = func(v, n - 1, 1);
        }
    }
    return dp[n][last];
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);

    fo(i, 0, n)
    {
        cin >> a[i];
    }
    ll cnt = 0;
    memset(dp, -1, sizeof(dp));
    // ll ans = help(a, n, 0, a[0], cnt);
    // cout << ans << Endl;
    cout << func(a, n, 0) << endl;
    rr;
}
int main()
{
    io();
    // solve();
    ll t = 1;
    // ll t;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}