
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vint vector<int>
#define vpint vector<pair<int, int>>
#define fo(i, k, n) for (int i = k; i < n; i++)
#define fo1(i, k, n) for (int i = k; i <= n; i++)
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
#define setbits(x) __builtin_popcountint(x)
#define zrobits(x) __builtin_ctzint(x)
#define aint(v) v.begin(), v.end()
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
int mod = 1e9 + 7, mxn = 3e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
void deb(vector<int> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
int mul(int a, int b, int mod)
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
bool check_sorted(vint a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            continue;
        return false;
    }
    return true;
}
vint fact(2e5 + 5, 1);
int binPow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
int inv(int a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
int binom(int a, int b)
{
    // before t
    //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}
// CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// int a = count(aint(s),'A');
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
bool valid_coordinate(int x, int y, int n, int m)
{
    if (x < 0 || y < 0)
        return false;

    else if (x >= n || y >= m)
        return false;

    else
        return true;
}

bool prime(int n)
{
    if (n < 2)
        return false;
    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(int n)
{
    return n && (!(n & (n - 1)));
}
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP
bool bitAtGivenPosSetOrUnset(unsigned int n,
                             unsigned int k)
{
    int new_num = n >> (k - 1);

    // if it results to '1' then bit is set,
    // else it results to '0' bit is unset
    return (new_num & 1);
}
void solve()
{
    int l, r;
    cin >> l >> r;

    vint a;

    for (int i = l; i <= r; i++)
    {
        a.pb(i);
    }
    int ans = a[0];

    for (int i = 0; i < r - l + 1; i++)
    {
        ans = (ans & a[i]);
    }
    if (ans != 0)
    {
        cout << 0 << endl;
        rr;
    }

    // bitset<32> b1(l);
    // map<string, int> m;
    // for (int i = l + 1; i <= r; i++)
    // {
    //     bitset<32> b(i);
    //     b = b & b1;
    //     m[b]++;
    // }
    // int maxa = INT_MIN;
    // for (auto i : m)
    // {
    //     if (i.ss > maxa)
    //     {
    //         maxa = i.ss;
    //     }
    // }
    // cout << maxa << endl;
    // rr;
    vint v;
    for (int j = 31; j >= 0; j--)
    {
        if (bitAtGivenPosSetOrUnset(l, j + 1))
            v.pb(j);
    }
    // debug(v.size());
    // deb(v);
    map<ll, ll> mm;
    int maxa = INT_MIN;
    for (ll i = l + 1; i <= r; i++)
    {
        // int cnt = 0;
        for (ll j = 0; j < v.size(); j++)
        {
            if ((i >> v[j]) & 1)
            {
                // cnt++;
                mm[v[j]]++;
            }
        }
        // maxa = max(cnt, maxa);
    }
    for (auto i : mm)
    {
        if (i.ss > maxa)
        {
            maxa = i.ss;
        }
    }
    if (maxa == INT_MIN)
    {
        cout << 1 << endl;
        rr;
    }
    int n = r - l;
    cout << n - maxa << Endl;
    rr;
    // cout << r - l + 1 - maxa << endl;
    // rr;
    // vpint m(32);
    // for (int i = l; i <= r; i++)
    // {
    //     for (int j = 31; j >= 0; j--)
    //     {
    //         if ((i >> j) & (1))
    //         {
    //             m[j].ss++;
    //         }
    //     }
    // }
    // int maxa = INT_MIN;
    // for (auto i : m)
    // {
    //     if (i.ss >= maxa)
    //     {
    //         maxa = i.ss;
    //     }
    // }
}
int main()
{
    io();
    // solve();
    // int t=1;
    int t;
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