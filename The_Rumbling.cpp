
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

void solve()
{

    ll n;
    cin >> n;
    // debug(n);
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    // debug(x);
    vll e(n, 0), w(n, 0);
    map<char, ll> m;
    char ch = 'S';
    m[ch] = min(y, 3 * x);
    m['W'] = min(2 * x, 2 * y);
    m['N'] = min(3 * y, x);
    m['E'] = 0;

    // // if (s[0] == 'E')
    // //     e[0] = 0;
    // // if (s[0] == 'N')
    // //     e[0] = x;
    // // if (s[0] == 'W')
    // //     e[0] = min(2 * x, 2 * y);
    // // if (s[0] == 'S')
    // //     e[0] = min(3 * x, y);
    for (ll i = 0; i < n; i++)
    {
        if (i == 0)
        {
            e[i] = m[s[i]];
            // debug(m[s[i]]);
            continue;
        }
        e[i] = e[i - 1] + m[s[i]];
    }
    map<char, ll> m1;
    m1['W'] = 0;
    m1['N'] = min(3 * x, y);
    m1['S'] = min(3 * y, x);
    m1['E'] = min(2 * x, 2 * y);
    for (ll i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            w[i] = m1[s[i]];
            continue;
        }
        w[i] = w[i + 1] + m1[s[i]];
    }
    ll v1 = 0, v2 = 0;
    for (ll i = 0; i < n; i++)
    {
        v1 += m[s[i]];
        v2 += m1[s[i]];
    }
    // // deb(e);
    // // deb(w);
    // ll v1 = e[n - 1];
    // ll v2 = w[0];
    ll val = min(v1, v2);
    ll ans = LONG_MAX;
    for (ll i = 0; i < n - 1; i++)
    {
        ans = min(ans, e[i] + w[i + 1]);
    }
    cout << min(ans, val) << Endl;
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
