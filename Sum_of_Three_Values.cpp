
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
    // ll n, x;
    // cin >> n >> x;
    // vll a(n);
    // fo(i, 0, n)
    // {
    //     cin >> a[i];
    // }
    // if (n <= 2)
    // {
    //     cout << "IMPOSSIBLE" << Endl;
    //     rr;
    // }
    // if (n == 3)
    // {
    //     if (a[0] + a[1] + a[2] == x)
    //     {
    //         cout << 1 << " " << 2 << " " << 3 << Endl;
    //         rr;
    //     }
    //     cout << "IMPOSSIBLE" << endl;
    //     rr;
    // }
    // map<ll, ll> m;
    // for (ll i = 0; i < n; i++)
    // {
    //     m[a[i]] = i + 1;
    // }

    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = i + 1; j < n; j++)
    //     {
    //         ll sum = a[i] + a[j];
    //         ll val = x - sum;
    //         if (m[val] && (val - 1) != i && (val - 1) != j)
    //         {
    //             cout << i + 1 << " " << j + 1 << " " << m[val] << endl;
    //             rr;
    //         }
    //     }
    // }
    // cout << "IMPOSSIBLE" << endl;
    // rr;
    ll n, x;
    cin >> n >> x;
    // if (x >)
    vpll a(n);

    // map<ll, ll> m;
    // ll sum = 0;
    fo(i, 0, n)
    {

        cin >> a[i].ff;
        a[i].ss = i + 1;
        // sum += a[i];
        // m[a[i]] = i + 1;
    }
    sort(a.begin(), a.end());
    if (n <= 2)
    {
        cout << "IMPOSSIBLE" << Endl;
        rr;
    }
    if (n == 3)
    {
        if (a[0].ff + a[1].ff + a[2].ff == x)
        {
            cout << 1 << " " << 2 << " " << 3 << Endl;
            rr;
        }
        cout << "IMPOSSIBLE" << endl;
        rr;
    }

    for (ll ii = 0; ii < n; ii++)
    {
        ll val = x - a[ii].ff;
        ll i = 0, j = n - 1;

        while (i < j)
        {
            if (i != ii && j != ii && (a[i].ff + a[j].ff == val))
            {
                // cout << a[i].ss << " " << a[j].ss << endl;
                // cout << min(a[i].ss, a[j].ss) << " " << max(a[i].ss, a[j].ss) << endl;
                cout << a[i].ss << " " << a[ii].ss << " " << a[j].ss << Endl;
                rr;
            }
            else if (a[i].ff + a[j].ff > val)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    cout << "IMPOSSIBLE" << Endl;
    rr;
}
int main()
{
    io();
    // solve();
    ll t = 1;
    // ll t;
    // cin >> t;
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}