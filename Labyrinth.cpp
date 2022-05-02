
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define ff first
#define ss second
#define Auto auto
#define llmin LONG_MIN
#define llmax LONG_MAX
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yes cout << "yes\n"
#define no cout << "no\n"

#define show(A)           \
    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';
#define endl "\n"
#define Endl endl
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
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
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
vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP/KNPS
// vector<pair<ll, ll>> adj[1005];
char mat[1002][1002];
string stepDir = "URDL";
ll dis[1001][1001];
bool vis[1000][1000];
ll previousStep[1000][1000];
void solve()
{
    ll n, m;
    cin >> n >> m;
    queue<pair<ll, ll>> q;
    ll sx, sy, ex, ey;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
            {
                sx = i, sy = j;
            }
            if (mat[i][j] == 'B')
            {
                ex = i, ey = j;
            }
        }
    }
    pair<ll, ll> beg = {sx, sy};
    pair<ll, ll> end = {ex, ey};
    q.push(beg);
    vis[beg.ff][beg.ss] = true;
    memset(dis, LONG_MAX, sizeof(dis));
    dis[beg.ff][beg.ss] = 0;
    while (!q.empty())
    {
        pair<ll, ll> fc = q.front();
        q.pop();

        for (ll i = 0; i < 4; i++)
        {
            ll v1 = fc.ff + dx[i];
            ll v2 = fc.ss + dy[i];
            pair<ll, ll> v = {v1, v2};

            if (v.ff < 0 || v.ff >= n || v.ss < 0 || v.ss >= m || mat[v.ff][v.ss] == '#')
            {
                continue;
            }
            if (vis[v.ff][v.ss] != false)
                continue;

            vis[v.ff][v.ss] = true;
            dis[v.ff][v.ss] = dis[fc.ff][fc.ss] + 1;
            previousStep[v.ff][v.ss] = i;
            q.push(v);
        }
    }

    if (dis[end.ff][end.ss] == LONG_MAX)
    {
        NO;
        rr;
    }
    YES;

    vector<ll> v;

    while (end != beg)
    {
        ll p = previousStep[end.ff][end.ss];
        v.pb(p);
        end = {end.ff - dx[p], end.ss - dy[p]};
    }

    reverse(v.begin(), v.end());
    cout << v.size() << endl;

    for (char c : v)
    {
        cout << stepDir[c];
    }
    cout << endl;
    rr;

    return;
}
int main()
{
    io();
    // solve();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}