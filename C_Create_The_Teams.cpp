
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
int dp[100001];

ll ans;
// ll help(ll mini, ll prod, ll cnt, ll i, ll j)
// {
//     if (i > j)
//         return 0;
//     if (dp[i] != -1)
//         return dp[i];
//     if (a[i] < mini)
//     {
//         mini = a[i];
//     }
//     prod++;
//     ll val = prod * mini;
//     if (val >= x)
//     {
//         ans++;
//         mini = INT_MAX;
//         prod = 1;
//         return ans;
//     }
//     ll v1 = help(mini, prod, cnt, i, j - 1);
//     ll v2 = help(mini, prod, cnt, i + 1, j);
//     if (v1 > v2)
//     {
//         dp[i] = v1;
//     }
//     else
//         dp[i] = v2;
//     return dp[i];
// }
void solve()
{
    ll n, x;
    cin >> n >> x;
    vll a;
    a.resize(n);
    // vll a(n);
    fo(i, 0, n)
    {
        cin >> a[i];
    }
    deb(a);
    sort(a.begin(), a.end(), greater<>());
    deb(a);
    ll sz = 1, cnt = 0;

    for (ll i = 0; i < n; i++)
    {
        if (sz * a[i] >= x)
        {
            cnt++;
            sz = 1;
        }
        else
            sz++;
    }
    cout << cnt << Endl;
    rr;
    // memset(dp, -1, sizeof(dp));
    // ll mini = INT_MAX;
    // ll prod = 1;
    // ll cnt = 0;
    // // help(mini, prod, cnt, 0, n - 1);
    // ll i = 0, sz = 1;
    // ll prod = 1;
    // while (i < n)
    // {
    //     if (sz * a[i] >= x)
    //     {
    //         cnt++;
    //         sz = 1;
    //         // prod = 1;
    //         i++;
    //     }
    //     else
    //     {
    //         i++;
    //         sz++;
    //         // prod = 1;
    //     }
    // }
    // cout << cnt << endl;
    // rr;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t;

    cin >> t;
    debug(t);
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}