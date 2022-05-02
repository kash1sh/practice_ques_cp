
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
vll fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    // before t
    //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
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

void solve()
{
    ll n;
    cin >> n;
    // if (n == 4 || n < 3)
    // {
    //     cout << -1 << endl;
    //     rr;
    // }
    // if (n % 3 == 0)
    // {
    //     cout << n / 3 << " " << 0 << " " << 0 << endl;
    //     rr;
    // }
    // if (n % 5 == 0)
    // {
    //     cout << 0 << " " << n / 5 << " " << 0 << endl;
    //     rr;
    // }
    // if (n % 7 == 0)
    // {
    //     cout << 0 << " " << 0 << " " << n / 7 << endl;
    //     rr;
    // }
    // if (n == 8)
    // {
    //     cout << 1 << " " << 1 << " " << 0 << endl;
    //     rr;
    // }
    // // if(n==16){

    // // }
    // bool f = false;
    // ll num = n;

    // ll rem = n % 10;
    // if (rem == 3)
    // {
    //     n -= 3;
    //     cout << 1 << " " << n / 5 << " " << 0 << Endl;
    //     rr;
    // }
    // if (rem == 7)
    // {
    //     n -= 7;
    //     cout << 0 << " " << n / 5 << " " << 1 << Endl;
    //     rr;
    // }
    // if (rem == 1)
    // {
    //     n -= 6;
    //     cout << 2 << " " << n / 5 << " " << 0 << Endl;
    //     rr;
    // }
    // if (rem == 2)
    // {
    //     n -= 7;
    //     cout << 0 << " " << n / 5 << " " << 1 << Endl;
    //     rr;
    // }
    // if (rem == 4)
    // {
    //     n -= 9;
    //     cout << 3 << " " << n / 5 << " " << 0 << Endl;
    //     rr;
    // }
    // if (rem == 6)
    // {
    //     n -= 6;
    //     cout << 2 << " " << n / 5 << " " << 0 << endl;
    //     rr;
    // }
    // if (rem == 8)
    // {
    //     n -= 3;
    //     cout << 1 << " " << n / 5 << " " << 0 << Endl;
    //     rr;
    // }
    // if (rem == 9)
    // {
    //     n -= 14;
    //     cout << 0 << " " << n / 5 << " " << 2 << endl;
    //     rr;
    // }
    if (n < 3)
    {
        cout << -1 << endl;
        rr;
    }

    for (ll i = 0; i <= n / 7; i++)
    {
        for (ll j = 0; j <= n / 5; j++)
        {
            for (ll k = 0; k <= n / 3; k++)
            {
                ll val = 7 * i + 5 * j + 3 * k;
                if (val == n)
                {
                    cout << k << " " << j << " " << i << endl;
                    rr;
                }
            }
        }
    }
    cout << -1 << endl;
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

    // cout<<setprecision(10)
    return 0;
}