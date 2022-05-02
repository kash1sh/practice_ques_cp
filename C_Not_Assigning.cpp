
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
struct nod
{
    int p1, p2, val;
};
set<int> adj[100005];
void solve()
{
    ll n;
    cin >> n;
    // vector<nod> v;
    map<pair<ll, ll>, ll> m;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        // nod x;
        // x.p1 = u;
        // x.p2 = v;
        // x.val = 0;
        // v.pb(x);
        m[{u, v}] = 0;
    }

    for (ll i = 1; i <= n; i++)
    {
        for (auto node : adj[i])
        {
            cerr << node << " ";
        }
        cerr << endl;
    }

    for (ll i = 1; i <= n; i++)
    {
        if (adj[i].size() > 2)
        {
            cout << -1 << endl;
            rr;
        }
    }
    vector<bool> t(n + 1, false), p(n + 1, false);
    // vector<bool>vis()
    bool vis[n][3 * n];
    // memset()
    for (ll i = 1; i <= n; i++)
    {
        for (auto node : adj[i])
        {
            // if (t)
            // {
            // if (m[{i, node}])
            if (vis[i][node] == false && vis[node][i] == false)
            {
                if (t[i] == false && t[node] == false)
                {
                    if (m.find({i, node}) != m.end())
                        m[{i, node}] = 2;
                    // if(m[{node,i}])
                    // m
                    t[i] = true;
                    t[node] = true;
                }
                else if (p[i] == false && p[node] == false)
                {
                    if (m.find({i, node}) != m.end())
                        m[{i, node}] = 5;
                    p[i] = true;
                    p[node] = true;
                }
                vis[i][node] = true;
                vis[node][i] = true;
            }
            // t[i] = true;
            // t[node] = true;
            // }
            // else if (p[i] == false && p[node] == false)
            // {
            //     if (m[{i, node}])
            //         m[{i, node}] = 5;
            //     p[i] = true;
            //     p[node] = true;
            // }
        }
    }

    for (auto i : m)
    {
        // cout << i.ff.ff << " " << i.ff.ss << endl;
        cout << i.ss << " ";
    }
    cout << endl;
    rr;
}
int main()
{
    io();
    // solve();
    ll t = 1;
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