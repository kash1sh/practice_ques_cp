
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
    vll a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vpll v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        v[i].ff = a[i] - b[i];
        v[i].ss = i;
        sum += v[i].ff;
    }
    if (sum != 0)
    {
        cout << -1 << endl;
        return;
    }
    vll ans1, ans2;
    // sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i; j < n; j++)
        {
            if (v[i].ff * v[j].ff < 0)
            {
                if (v[i].ff > 0)
                {
                    ans2.pb(i + 1);
                    ans1.pb(j + 1);
                    v[i].ff--;
                    v[j].ff++;
                }
                else
                {
                    ans1.pb(i + 1);
                    ans2.pb(j + 1);
                    v[i].ff++;
                    v[j].ff--;
                }
            }
        }
    }

    // ll i = 0, j = n - 1;
    // while (i < j)
    // {
    //     ll mini = v[i].ff;
    //     ll maxa = v[j].ff;
    //     // debug(b[j]);
    //     ll num = min(abs(mini), abs(maxa));
    //     while (num)
    //     {
    //         ans1.pb(i + 1);
    //         mini++;
    //         ans2.pb(j + 1);
    //         maxa--;
    //         num--;
    //     }
    //     if (mini == 0)
    //         i++;
    //     if (maxa == 0)
    //         j--;
    // }
    // cout << ans1.size() << endl;

    for (ll i = 0; i < ans1.size(); i++)
    {
        cout << ans2[i] << " " << ans1[i] << endl;
    }
    // cout << endl;
    return;
    // for(ll i=)
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