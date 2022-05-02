
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define rr return
// #define ff first
// #define ss second
// #define Auto auto
// #define llmin LONG_MIN
// #define llmax LONG_MAX
// #define Yes cout << "Yes\n"
// #define No cout << "No\n"
// #define YES cout << "YES\n"
// #define NO cout << "NO\n"
// #define yes cout << "yes\n"
// #define no cout << "no\n"

// #define show(A)           \
//     for (auto i : A)      \
//         cout << i << " "; \
//     cout << '\n';
// #define endl "\n"
// #define Endl endl
// clock_t startTime = clock();
// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)
// #define all(v) v.begin(), v.end()
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
//     cout.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("error.txt","w",stderr);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// double PI = 4 * atan(1);
// ll mod = 1e9 + 7, mxn = 3e5 + 5;
// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, 1, 0, -1};
// void deb(vector<ll> v)
// {
//     for (auto t : v)
//         cerr << t << " ";
//     cerr << "\n";
// }
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
// vll fact(2e5 + 5, 1);
// ll binPow(ll a, ll b)
// {
//     if (b == 0)
//         return 1;
//     if (b == 1)
//         return a;
//     ll ret = binPow(a, b / 2);
//     if (b % 2 == 0)
//         return (ret * ret) % mod;
//     return ((ret * ret) % mod * a) % mod;
// }
// ll inv(ll a)
// {
//     return (binPow(a, mod - 2) % mod + mod) % mod;
// }
// ll binom(ll a, ll b)
// {
//     // before t
//     //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
//     if (b < 0 or a < 0)
//         return 0;
//     return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
// }
// // CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// // int a = count(all(s),'A');
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
// vector<int> primeFactors(int n)
// {
//     vector<int> f;
//     for (int x = 2; x * x <= n; x++)
//     {
//         while (n % x == 0)
//         {
//             f.push_back(x);
//             n /= x;
//         }
//     }
//     if (n > 1)
//         f.push_back(n);
//     return f;
// }

// bool isPrime(ll n)
// {
//     if (n < 2)
//         return false;
//     for (ll x = 2; x * x <= n; x++)
//     {
//         if (n % x == 0)
//             return false;
//     }
//     return true;
// }

// bool isPowerOfTwo(ll n)
// {
//     return n && (!(n & (n - 1)));
// }
// // Find Min/Max
// // * Greedy/Brute Force
// //* Prefix array of max/min
// // * BS
// // * DP/KNPS

// void solve()
// {
//     ll n;
//     cin >> n;
//     vll a(n);
//     map<ll, ll> m;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         m[a[i]]++;
//     }
//     vector<bool> vis(200005, false);
//     // memset(vis, false, sizeof(vis));
//     // for (ll i = 0; i < 200005; i++)
//     // {
//     //     vis[i] = false;
//     // }
//     ll maxa = LONG_MIN;
//     for (auto i : m)
//     {
//         if (i.ss > maxa)
//         {
//             maxa = i.ss;
//         }
//     }
//     if (maxa == 1)
//     {
//         cout << -1 << Endl;
//         rr;
//     }
//     if (n == 2)
//     {
//         if (a[0] == a[1])
//         {
//             cout << 1 << endl;
//             rr;
//         }
//     }
//     // vector<ll> v[150005];
//     ll ans = LONG_MAX;
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     v[a[i]].pb(i);
//     // }
//     // for (ll i = 0; i < 150005; i++)
//     // {
//     //     for (ll j = 1; j < v[i].size(); j++)
//     //     {
//     //         ans = min(ans, v[i][j] - v[i][j - 1]);
//     //     }
//     // }
//     // if (ans == LONG_MAX)
//     // {
//     //     cout << -1 << endl;
//     //     rr;
//     // }
//     // cout << n - ans << endl;
//     // rr;
//     map<ll, ll> m1;

//     for (ll i = 0; i < n; i++)
//     {
//         if (m1[a[i]] == 0)
//         {
//             m1[a[i]] = i;
//             continue;
//         }
//         // else
//         // {
//         if (vis[a[i]] == false)
//         {
//             m1[a[i]] = i - m1[a[i]];
//             ans = min(ans, m1[a[i]]);
//             vis[a[i]] = true;
//         }
//         else
//         {
//             // debug(a[i]);
//             // de   bug(i - m1[a[i]]);
//             m1[a[i]] = min(m1[a[i]], (i - m1[a[i]]));
//             // debug(a[i]);
//             // debug(m1[a[i]]);
//             ans = min(ans, m1[a[i]]);
//             // debug(ans);
//         }
//         // }
//     }
//     // cout << m1[a[1]] << endl;
//     // for (auto i : m1)
//     // {
//     //     cerr << i.ff << " " << i.ss << Endl;
//     // }
//     // debug(n);
//     // debug(ans);
//     if (ans == LONG_MAX)
//     {
//         cout << -1 << endl;
//         rr;
//     }
//     cout << n - ans << endl;
//     rr;

//     // ll lo=
// }
// int main()
// {
//     io();
//     // solve();
//     ll t = 1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

//     // cout<<fixed<<setprecision(10)<<ans<<endl;

//     // cout<<printf("%.8lf", hi)<<endl;
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

typedef vector<vector<long long>> vvll;

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
/*
vector<ll>adj[100005];
bool vis[100005];
ll dist[100005];
void bfs(ll c)
{
  vis[c]=true;
  dist[c]=0;
  queue<ll>q;
  q.push(c);
while(!q.empty())
{
    ll x=q.front();
    q.pop();

    for(auto y:adj[x])
    {
        if(!vis[y])
        {
            vis[y]=true;
            dist[y]=dist[x]+1;

            q.push(y);
        }
    }

}
}
*/
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP/KNPS
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    map<ll, ll> m1, m2;
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     m1[a[i]] = i;
    // }
    // for (ll i = n - 1; i >= 0; i--)
    // {
    //     m2[a[i]] = i;
    // }

    // ll diff = -1;

    // for (ll i = 0; i < n; i++)
    // {
    //     ll x = m1[a[i]];
    //     ll y = m2[a[i]];
    //     // debug(x);
    //     // debug(y);
    //     ll d = abs(x - y);
    //     if (d == 0)
    //         continue;

    //     ll d1 = y;
    //     ll d2 = n - x - 1;
    //     // if (d > diff)
    //     // diff = d;
    //     // if (y >= d)
    //     // {
    //     diff = max(diff, d1 + d2 + 1);
    //     // }
    // }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // ll diff = -1;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (m1.count(a[i]))
    //     {
    //         diff = max(diff, m1[a[i]] + n - i);
    //     }
    //     m1[a[i]] = i;
    // }

    // cout << diff << endl;
    // rr;
    map<ll, vll> m;
    for (ll i = 0; i < n; i++)
    {
        m[a[i]].push_back(i);
    }
    ll diff = -1;
    for (auto i : m)
    {
        // vector<ll> v = i.s;
        for (ll j = 1; j < i.ss.size(); j++)
        {
            diff = max(diff, i.ss[j - 1] + n - i.ss[j]);
        }
    }
    cout << diff << endl;
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