
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define ff first
// #define ss second

// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x << " " << x << endl;
// #else
// #define debug(x)
// #endif
// using namespace std;

// void io()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("error.txt","w",stderr);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// ll mod = 1e9 + 7, mxn = 3e5 + 5;
// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }

// bool sortbysecdesc(const pair<int, int> &a,
//                    const pair<int, int> &b)
// {
//     return a.second > b.second;
// }
// bool check_sorted(vll a)
// {
//     ll n = a.size();
//     for (ll i = 1; i < n; i++)
//     {
//         if (a[i] >= a[i - 1])
//             continue;
//         return false;
//     }
//     return true;
// }

// ll po(ll a, ll b, ll mod)
// {
//     if (b == 0)
//         return 1;
//     if (b % 2 == 0)
//         return po(mul(a, a, mod), b / 2, mod);
//     return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
// }

// long long power(long long X, long long N)
// {
//     if (N == 0)
//         return 1;
//     if (N % 2 == 0)
//         return power(X * X, N / 2);
//     return X * power(X, N - 1);
// }

// vll fac(200003);
// ll facto(ll n)
// {

//     fac[0] = 1;
//     fac[1] = 1;
//     for (ll i = 2; i <= 200003; i++)
//     {
//         fac[i] = i * fac[i - 1];
//     }
//     return fac[n];
// }
// long combi(ll n, ll k)
// {
//     long long ans = 1;
//     k = k > n - k ? n - k : k;
//     ll j = 1;
//     for (; j <= k; j++, n--)
//     {
//         if (n % j == 0)
//         {
//             ans *= n / j;
//         }
//         else if (ans % j == 0)
//         {
//             ans = ans / j * n;
//         }
//         else
//         {
//             ans = (ans * n) / j;
//         }
//     }
//     return ans;
// }
// // CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// vector<int> sieveOfEratosthenes(int N)
// {
//     bool primes[N + 1];
//     memset(primes, true, sizeof(primes));
//     vector<int> arr;

//     for (int i = 2; i * i <= N; i++)
//         if (primes[i] == true)
//         {
//             for (int j = i * i; j <= N; j += i)
//                 primes[j] = false;
//         }

//     for (int i = 2; i <= N; i++)
//         if (primes[i])
//             arr.emplace_back(i);

//     return arr;
// }
// void prime_fact(ll n, vector<ll> &res)
// {
//     while (n % 2 == 0)
//     {
//         res.pb(2);
//         n = n / 2;
//     }

//     for (ll i = 3; i <= sqrt(n); i = i + 2)
//     {
//         while (n % i == 0)
//         {
//             res.pb(i);
//             n = n / i;
//         }
//     }
//     if (n > 2)
//     {
//         res.pb(n);
//     }
// }

// void solve()
// {
//     ll n;
//     cin >> n;
//     // cerr << n << endl;
//     // v.clear();
//     // ans.clear();
//     vll a(n + 1), skill(n + 1);
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     // cerr << a[0] << endl;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> skill[i];
//     }
//     // cout << skill[0] << endl;
//     // cerr << skill[0];
//     vector<ll> v[n + 1];
//     vll ans(n + 1);
//     for (ll i = 0; i <= n; i++)
//     {
//         // debug()
//         // debug(skill[i]);
//         // debug(a[i]);
//         v[a[i]].pb(skill[i]);
//     }
//     // for (ll i = 0; i <= n; i++)
//     // {
//     //     for (ll j = 0; j < v[i].size(); j++)
//     //     {
//     //         cerr << v[i][j] << " ";
//     //     }
//     //     cerr << endl;
//     // }
//     // cerr << v[1][0] << endl;
//     for (ll i = 0; i <= n; i++)
//     {
//         // sort(i.begin(), i.end(), greater<>());
//         sort(v[i].begin(), v[i].end(), greater<>());
//     }

//     // for (auto i : v)
//     // {
//     //     for (auto j : i)
//     //     {
//     //         cerr << j << " ";
//     //     }
//     //     cerr << endl;
//     // }
//     // cerr << v[1][0] << endl;
//     ll k = 1;
//     for (ll i = 0; i <= n; i++)
//     {
//         //     v[i][0] = v[i][0];
//         for (ll j = 1; j < v[i].size(); j++)
//         {
//             v[i][j] = v[i][j - 1] + v[i][j];
//         }
//         for (ll j = 1; j <= v[i].size(); j++)
//         {
//             ll size = v[i].size() % j;
//             ans[j - 1] += v[i][v[i].size() - size - 1];
//         }

//         // }
//         // for (ll i = 0; i < n; i++)
//         // {
//         //     cout << ans[i] << " ";
//     }
//     for (ll i = 0; i < n; i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;
//     return;
// }
// int main()
// {
//     io();
//     // solve();
//     // ll t=1;
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     // cout<<setprecision(10)
//     return 0;
// }

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
void solve()
{
    ll n;
    cin >> n;
    vll u(n), s(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> u[i];
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        sum += s[i];
    }
    map<ll, multiset<ll>> m;
    map<ll, vector<ll>> m1;
    for (ll i = 0; i < n; i++)
    {
        m[u[i]].insert(s[i]);
        m1[u[i]].pb(s[i]);
    }
    vll v;
    vll pre(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (auto j : m1[i])
        {
            sum += j;
        }
        pre[i] = sum;
    }
    for (ll k = 1; k <= n; k++)
    {
        for (auto i : m1)
        {
            ll val = m[i].size() % k;
            ll sum = pre[i];
            while (val)
            {
                // sum-=m[i].begin()
            }
        }
    }
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