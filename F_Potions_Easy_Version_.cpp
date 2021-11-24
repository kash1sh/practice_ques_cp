
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
int dp[2002][9999];
int ar[2002];
int n;
int findans(int i, int sum)
{
    if (i == n + 1)
        return 0;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    if (ar[i] >= 0)
    {
        dp[i][sum] = 1 + findans(i + 1, sum + ar[i]);
    }
    else
    {
        if (sum + ar[i] < 0)
            dp[i][sum] = findans(i + 1, sum);
        else
            dp[i][sum] = max(1 + findans(i + 1, sum + ar[i]), findans(i + 1, sum));
    }
    return dp[i][sum];
}
void solve()
{
    // int n;
    // cin >> n;
    // int i, j, t, q, a, b, m, k, ct = 0, sum = 0, flag = 0;
    cin >> n;
    fo(i, 1, n + 1)
            cin >>
        ar[i];
    memset(dp, -1, sizeof(dp));
    int m = findans(1, 0);
    cout << m << endl;
}

// ll sum = 0;
// ll dp[2001][100];
// vll a;
// ll help(ll i, ll n, ll hea)
// {
//     if (i >= n)
//         return 0;
//     // if (hea + a[i] < 0)
//     // return 0;
//     if (dp[i][hea] != -1)
//         return dp[i][hea];

//     //  =help(i+1,n,hea+a[i],cnt+1)
//     if (a[i] >= 0)
//     {
//         cerr << hea << Endl;
//         dp[i][hea] = 1 + help(i + 1, n, hea + a[i]);
//     }
//     else
//     {
//         // ll a1 = 1 + help(i + 1, n, hea + a[i]);
//         // ll a2 = help(i + 1, n, hea);
//         // dp[i] = max(a1, a2);
//         if (hea + a[i] < 0)
//         {
//             dp[i][hea] = help(i + 1, n, hea);
//         }
//         else
//         {
//             cerr << a[i] << " " << hea << Endl;
//             dp[i][hea] = max(1 + help(i + 1, n, hea + a[i]), help(i + 1, n, hea));
//         }
//     }
//     return dp[i][hea];
// }
// void solve()
// {
//     ll n;
//     cin >> n;
//     vll a(n);
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     if (a[i] >= 0)
//     //         sum += a[i];
//     // }
//     fo(i, 0, n)
//     {
//         // ll x;
//         // cin >> x;
//         // a.pb(x);
//         cin >> a[i];
//     }

//     // for(ll i=0;i<n;i++){

//     // }
//     memset(dp, -1, sizeof(dp));
//     ll health = 0, cnt = 0;
//     cout << help(0, n, health) << endl;
//     rr;
// }
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