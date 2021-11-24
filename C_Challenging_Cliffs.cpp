
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define Endl endl
#define ff first
#define ss second

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

vll fac(200003);
ll facto(ll n)
{

    fac[0] = 1;
    fac[1] = 1;
    for (ll i = 2; i <= 200003; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    return fac[n];
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

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    ll cnt = 1;
    ll x;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll diff = INT_MAX;
    ll v1 = -1, v2 = -1, val1, val2;
    for (ll i = 1; i < n; i++)
    {
        if (abs(a[i - 1] - a[i]) < diff)
        {
            diff = abs(a[i - 1] - a[i]);
            v1 = i - 1;
            v2 = i;
            val1 = a[i - 1];
            val2 = a[i];
        }
    }

    vll ans;
    ans.pb(val1);
    for (ll i = v2 + 1; i < n; i++)
    {
        ans.pb(a[i]);
    }
    for (ll i = 0; i < v1; i++)
        ans.pb(a[i]);
    ans.pb(val2);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return;
    // vll v, ans;
    // ans.pb(val1);
    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[i] == val1 || a[i] == val2)
    //         continue;
    //     v.pb(a[i]);
    // }
    // ll small = -1, big = -1;
    // big = lower_bound(a.begin(), a.end(), val1);
    // for (ll i = 0; i < v.size(); i++)
    // {
    //     if (v[i] < val2)
    //     {
    //         small = v[i];
    //     }
    // }

    // ans.pb(val2);
    // for (ll i = 0; i < n; i++)
    // {
    //     if (i == 0)
    //     {
    //         x = a[0];
    //     }
    //     cin >> a[i];
    //     if (i > 0 && a[i] == x)
    //     {
    //         cnt++;
    //     }
    // }
    // if (n == 2)
    // {
    //     cout << *min_element(a.begin(), a.end()) << " " << *max_element(a.begin(), a.end());
    //     cout << endl;
    //     return;
    // }
    // sort(a.begin(), a.end());
    // pair<ll, ll> p;
    // p.ff = -1;
    // for (ll i = 1; i < n; i++)
    // {
    //     if (a[i] == a[i - 1])
    //     {
    //         p.ff = a[i - 1];
    //         p.ss = a[i];
    //     }
    // }
    // if (p.ff != -1)
    // {
    //     vll v;
    //     if (n > 4)
    //     {
    //         v.pb(p.ff);
    //         for (ll i = 0; i < n; i++)
    //         {
    //             if (a[i] == p.ff)
    //             {
    //                 continue;
    //             }
    //             v.pb(a[i]);
    //         }
    //         v.pb(p.ss);
    //     }
    //     else if (n == 4)
    //     {
    //         v.pb(p.ff);
    //         for (ll i = n - 1; i >= 0; i--)
    //         {
    //             if (a[i] == p.ff)
    //             {
    //                 continue;
    //             }
    //             v.pb(a[i]);
    //         }
    //         v.pb(p.ss);
    //     }
    //     else if (n == 3)
    //     {
    //         v.pb(p.ff);
    //         for (ll i = n - 1; i >= 0; i--)
    //         {
    //             if (a[i] == p.ff)
    //             {
    //                 continue;
    //             }
    //             v.pb(a[i]);
    //         }
    //         v.pb(p.ss);
    //     }
    //     for (ll i = 0; i < v.size(); i++)
    //     {
    //         cout << v[i] << " ";
    //     }
    //     cout << endl;
    //     return;
    // }
    // else
    // {
    //     vll v;
    //     ll diff = INT_MAX;
    //     ll v1 = -1, v2 = -1;
    //     for (ll i = 1; i < n; i++)
    //     {
    //         if (abs(a[i - 1] - a[i]) < diff)
    //         {
    //             diff = abs(a[i - 1] - a[i]);
    //             v1 = i - 1;
    //             v2 = i;
    //         }
    //     }
    //     v.pb(a[v1]);
    //     if (n > 4)
    //     {

    //         for (ll i = 0; i < n; i++)
    //         {
    //             if (a[i] == p.ff)
    //             {
    //                 continue;
    //             }
    //             v.pb(a[i]);
    //         }
    //     }
    //     else if (n == 4)
    //     {

    //         for (ll i = n - 1; i >= 0; i--)
    //         {
    //             if (a[i] == p.ff)
    //             {
    //                 continue;
    //             }
    //             v.pb(a[i]);
    //         }
    //     }
    //     else if (n == 3)
    //     {

    //         for (ll i = n - 1; i >= 0; i--)
    //         {
    //             if (a[i] == p.ff)
    //             {
    //                 continue;
    //             }
    //             v.pb(a[i]);
    //         }
    //     }
    //     v.pb(a[v2]);
    //     for (ll i = 0; i < v.size(); i++)
    //     {
    //         cout << v[i] << " ";
    //     }
    //     cout << endl;
    //     return;

    // for (ll i = 1; i < n; i++)
    // {
    //     v.pb(a[i]);
    // }
    // v.pb(a[0]);

    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // return;
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