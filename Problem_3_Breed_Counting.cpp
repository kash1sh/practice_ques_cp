
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
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
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
    // ll n, q;
    // cin >> n >> q;

    // vll a(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    // // vll pre(n);
    // // pre[0]=a[0];
    // // for(ll i=1;i<n;i++){
    // // pre[i]=pre[i-1]+a[i];
    // // }
    // // deb(pre);
    // vll a1(n + 1, 0), a2(n + 1, 0), a3(n + 1, 0);
    // // if (a[0] == 1)
    // //     a1[0] = 1;
    // // if (a[0] == 2)
    // //     a2[0] = 1;
    // // if (a[0] == 3)
    // //     a3[0] = 1;
    // for (ll i = 1; i <= n; i++)
    // {
    //     if (a[i] == 1)
    //     {
    //         a1[i] = a1[i - 1] + 1;
    //         a2[i] = a2[i - 1];
    //         a3[i] = a3[i - 1];
    //     }
    //     else if (a[i] == 2)
    //     {
    //         a1[i] = a1[i - 1];
    //         a2[i] = a2[i - 1] + 1;
    //         a3[i] = a3[i - 1];
    //     }
    //     else
    //     {
    //         a1[i] = a1[i - 1];
    //         a2[i] = a2[i - 1];
    //         a3[i] = a3[i - 1] + 1;
    //     }
    // }
    // for (ll i = 0; i < q; i++)
    // {
    //     ll l, r;
    //     cin >> l >> r;
    //     ll val = (l - 1);
    //     ll v1 = a1[r] - a1[val];
    //     ll v2 = a2[r] - a2[val];
    //     ll v3 = a3[r] - a3[val];

    //     cout << v1 << " " << v2 << " " << v2 << endl;
    // }
    // rr;
    ll n, q;
    cin >> n >> q;
    vll v(n + 1);
    fo(i, 1, n + 1)
    {
        cin >> v[i];
    }
    vll a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        if (v[i] == 1)
        {
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1];
            c[i] = c[i - 1];
        }
        else if (v[i] == 2)
        {
            b[i] = b[i - 1] + 1;
            a[i] = a[i - 1];
            c[i] = c[i - 1];
        }
        else
        {
            c[i] = c[i - 1] + 1;
            b[i] = b[i - 1];
            a[i] = a[i - 1];
        }
    }
    // deb(v);
    // deb(a);
    // deb(b);
    // deb(c);
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << " " << b[r] - b[l - 1] << " " << c[r] - c[l - 1] << endl;
    }
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