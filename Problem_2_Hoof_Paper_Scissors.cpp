
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
#ifndef ONLINE_JUDGE
    freopen("hps.in", "r", stdin);
    // freopen("error.txt","w",stderr);
    freopen("hps.out", "w", stdout);
#endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
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
vector<int> factors(int n)
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
bool valid_coordinate(ll x, ll y, ll n, ll m)
{
    if (x < 0 || y < 0)
        return false;

    else if (x >= n || y >= m)
        return false;

    else
        return true;
}

bool prime(ll n)
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
vll a(100005);
ll help(ll val, ll ind)
{
    if (val == 0 && a[ind] == 2)
        rr 1;
    if (val == 1 && a[ind] == 0)
        rr 1;
    if (val == 2 && a[ind] == 1)
        rr 1;
    rr 0;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    // a.resize(3);
    for (ll i = 1; i < n + 1; i++)
    {
        char x;
        cin >> x;
        // cerr << x;
        if (x == 'P')
        {
            a[i] = 1;
        }
        else if (x == 'H')
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 2;
        }
        // cin >> a[i];
    }
    // deb(a);
    ll dp[100005][25][3];
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k + 1; j++)
        {
            ll add = help(0, i);
            dp[i][j][0] = max(dp[i - 1][j][0] + add, max(add + dp[i - 1][j - 1][1], add + dp[i - 1][j - 1][2]));

            add = help(1, i);
            dp[i][j][1] = max(dp[i - 1][j][1] + add, max(add + dp[i - 1][j - 1][0], add + dp[i - 1][j - 1][2]));

            add = help(2, i);
            dp[i][j][2] = max(dp[i - 1][j][2] + add, max(add + dp[i - 1][j - 1][1], add + dp[i - 1][j - 1][0]));

            // if (i == n)
            // {
            //     ans = max(ans, max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2])));
            // }
        }
    }

    // for (ll i = 1; i <= k + 1; i++)
    // {
    // ans = max(ans, max(dp[n][i][0], max(dp[n][i][1], dp[n][i][2])));
    // }
    cout << max(dp[n][k + 1][0], max(dp[n][k + 1][1], dp[n][k + 1][2])) << endl;
    // cout << ans << endl;
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
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}