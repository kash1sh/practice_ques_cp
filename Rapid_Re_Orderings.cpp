
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
// #define all(X) (X).begin(), (X).end()
clock_t startTime = clock();
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(v) v.begin(), v.end()
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
double PI = 4 * atan(1);
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
// int a = count(all(s),'A');
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
// Find Min/Max
// * Greedy/Brute Force
// * DP
// * BS

void solve()
{
    ll n;
    cin >> n;
    ll sz = 2 * n;
    ll half = n / 2;
    vll b(sz);
    map<ll, ll> m;
    set<ll> s;
    vll a1, a2;
    for (ll i = 0; i < sz; i++)
    {
        cin >> b[i];
        if (i < n)
            a1.pb(b[i]);
        else
            a2.pb(b[i]);
        m[b[i]]++;
        // s.insert(b[i]);
    }
    if (n == 1)
    {
        if (b[0] == b[1])
        {
            cout << b[1] << endl;
            rr;
        }
        cout << -1 << endl;
        rr;
    }
    vll res;
    // for (ll i = 0; i < n; i++)
    for (auto i : m)
    {
        res.pb(i.ff);
        // s.erase(s.begin());
    }
    if (res.size() < n || res.size() > n)
    {
        cout << -1
             << endl;
        rr;
    }
    ll mid = (n % 2 != 0 ? half : half - 1);
    sort(b.begin(), b.end());
    sort(a1.begin(), a1.end());
    sort(res.begin(), res.end());
    sort(a2.begin(), a2.end(), greater<>());
    // for (auto i : a2)
    // {
    //     m2[a2[i]]++;
    // }
    // deb(b);
    // deb(a1);
    // deb(a2);
    // if (m[res[0]] != 2)
    // {
    //     cout << -1 << endl;
    //     rr;
    // }

    if (m[res[mid]] != 3)
    {
        cout << -1 << endl;
        rr;
    }
    if (m[res[n - 1]] != 1)
    {
        cout << -1 << endl;
        rr;
    }
    // m[res[]]
    for (auto i : m)
    {
        if (i.ff == res[mid])
            continue;
        if (i.ff == res[n - 1])
            continue;
        // if (i.ff == res[0])
        //     continue;
        if (i.ss != 2)
        {
            // debug(i.ff);
            cout << -1 << endl;
            rr;
        }
    }
    // ll mid =
    vll a;
    // a.pb(a1[0]);
    ll last = 0;
    for (ll i = 0; i < n; i = i + 2)
    {
        last = a1[i];
        a.pb(a1[i]);
    }
    // ll len=a.size()
    vll a5;
    // a.pb(a2[0]);
    // ll val = a2[0];
    for (ll i = 1; i < n; i = i + 2)
    {
        a5.pb(a2[i]);
    }
    // deb(a5);
    // sort(a5.begin(), a5.end());
    // for (ll i = 0; i < a5.size(); i++)
    // {
    //     if (a5[i] == last)
    //         continue;
    //     // last=a5[i];
    //     a.pb(a5[i]);
    // }
    // a.pb(val);
    for (ll i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
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
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    // cout<<fixed<<setprecision(10)<<ans<<endl;
    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}