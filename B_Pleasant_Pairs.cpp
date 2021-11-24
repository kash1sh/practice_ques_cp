
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
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // vpll v(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     v[i].ff = a[i];
    //     v[i].ss = i + 1;
    // }

    // for (ll i = 0; i < n; i++)
    // {
    //     ll num = lower_bound()
    // }
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        m[a[i]] = i + 1;
        // debug(m[a[i]]);
    }
    ll cnt = 0;
    // sort(a.begin(), a.end());
    for (ll i = 0; i < n; i++)
    {
        // for (ll j = i + 1; j < n; j++)
        // {
        //     ll prod = a[i] * a[j];
        //     ll sum = m[a[i]] + m[a[j]];
        //     if (sum == prod)
        //         cnt++;
        // }
        ll v1 = a[i];
        ll i1 = i + 1;
        // ll i1 = m[a[i]];
        // for(ll j=)
        ll last = n;
        ll sum = i1 + last;
        ll temp = sum % v1;
        // if (temp == 0)
        // {
        for (ll k = n - 1 - temp; k >= i1; k = k - v1)
        {
            ll prod = a[i] * a[k];
            ll ss = m[a[i]] + m[a[k]];
            if (ss == prod)
                cnt++;
        }
        // }
        // else
        // {
        // }
    }
    cout << cnt << endl;
    return;
    ll i = 0, j = n - 1;

    vector<ll> vis(n, 0);
    // while (i < j)
    // {
    //     // if (vis[i] != 0 && vis[j] != 0)
    //     // {
    //     //     i++;
    //     //     j--;
    //     //     continue;
    //     // }
    //     ll val = a[i] * a[j];
    //     ll sum = m[a[i]] + m[a[j]];
    //     if (val > sum)
    //     {
    //         j--;
    //     }
    //     else if (sum > val)
    //     {
    //         i++;
    //     }
    //     else
    //     {

    //         cnt++;
    //         vis[i] = j;
    //         vis[j] = i;

    //         for (ll k = i + 1; k < n; k++)
    //         {
    //             if (vis[k] != 0 && vis[i] != 0)
    //                 continue;
    //             if (a[i] * a[k] == m[a[i]] + m[a[k]])
    //             {
    //                 cnt++;
    //                 vis[k] = i;
    //                 vis[i] = k;
    //             }
    //         }
    //         for (ll k = j - 1; k >= 0; k--)
    //         {
    //             if (vis[k] != 0 && vis[j] != 0)
    //                 continue;
    //             if (a[j] * a[k] == m[a[j]] + m[a[k]])
    //             {
    //                 cnt++;
    //                 vis[k] = j;
    //                 vis[j] = k;
    //             }
    //         }
    //         i++;
    //         j--;
    //     }
    // }
    // cout << cnt - 2 << endl;
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