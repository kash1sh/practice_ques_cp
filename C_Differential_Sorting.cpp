
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

// typedef vector<vector<long long>> vvll;

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
// /*
// vector<ll>adj[100005];
// bool vis[100005];
// ll dist[100005];
// void bfs(ll c)
// {
//   vis[c]=true;
//   dist[c]=0;
//   queue<ll>q;
//   q.push(c);
// while(!q.empty())
// {
//     ll x=q.front();
//     q.pop();

//     for(auto y:adj[x])
//     {
//         if(!vis[y])
//         {
//             vis[y]=true;
//             dist[y]=dist[x]+1;

//             q.push(y);
//         }
//     }

// }
// }
// */
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
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     // if (n == 3)
//     // {
//     //     if (is_sorted(all(a)))
//     //     {
//     //         cout << 0 << endl;
//     //         return;
//     //     }
//     //     else
//     //     {
//     //         cout << -1 << endl;
//     //         return;
//     //     }
//     // }
//     // if (is_sorted(all(a)))
//     // {
//     //     cout << 0 << endl;
//     //     rr;
//     // }
//     vll pmax(n), pmin(n);
//     pmax[n - 1] = n - 1;
//     pmin[n - 1] = n - 1;
//     for (ll i = n - 2; i >= 0; i--)
//     {
//         // pmax[i] = max(a[i], pmax[i + 1]);
//         if (a[i] > pmax[i + 1])
//         {
//             pmax[i] = i;
//         }
//         else
//             pmax[i] = pmax[i + 1];
//     }
//     for (ll i = n - 2; i >= 0; i--)
//     {
//         // pmin[i] = min(a[i], pmin[i + 1]);
//         if (a[i] < pmin[i + 1])
//         {
//             pmin[i] = i;
//         }
//         else
//             pmin[i] = pmin[i + 1];
//     }
//     ll maxa = *max_element(all(a));
//     ll mini = *min_element(all(a));
//     ll cnt = 0;
//     // vpll v;
//     vector<vector<ll>> v;
//     // if (a[n - 1] == mini || a[n - 2] == mini)
//     // {
//     //     cout << -1 << endl;
//     //     rr;
//     // }
//     if (a[n - 1] < a[n - 2])
//     {
//         cout << -1 << endl;
//         rr;
//     }
//     // for (ll i = 0; i < n - 1; i++)
//     // {
//     //     cnt++;
//     //     a[i] = a[pmin[i + 1]] - a[pmax[i + 1]];
//     //     v.pb({i, pmin[i + 1], pmax[i + 1]});
//     //     // v.pb({pmin[i + 1], pmax[i + 1]});
//     // }
//     ll val = a[n - 1];
//     if (val < 0)
//     {
//         if (is_sorted(all(a)))
//         {
//             cout << 0 << endl;
//             rr;
//         }
//         else
//         {
//             cout << -1 << endl;
//             rr;
//         }
//     }
//     cnt = n - 2;

//     cout << cnt << endl;
//     for (ll i = 0; i < n - 1; i++)
//     {
//         if (i == 0)
//             continue;
//         cout << i << " " << n - 1 << " " << n << endl;
//     }
//     rr;
//     // for (auto i : v)
//     // {
//     //     cout << i << endl;
//     // }
//     // for (auto i : v)
//     // {
//     //     cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] + 1 << endl;
//     // }
//     // rr;
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
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    if (is_sorted(a.begin(), a.end()))
    {
        cout << 0 << endl;
        rr;
    }
    if (a[n - 2] > a[n - 1])
    {
        cout << -1 << endl;
        rr;
    }
    ll val = a[n - 2] - a[n - 1];

    if (val > a[n - 2] || val > a[n - 1])
    {
        cout << -1 << endl;
        rr;
    }
    ll cnt = 0;
    vector<pair<ll, pair<ll, ll>>> v;
    for (ll i = 0; i < n - 2; i++)
    {
        // if (a[i] > a[i + 1])
        // {
        cnt++;
        // v.pb({i + 1, n - 1, n});
        v.pb({i + 1, {n - 1, n}});
        // v.push_back(make_pair(i + 1, make_pair(n - 1, n)));
        // }
    }
    cout << cnt << Endl;
    for (auto i : v)
    {
        cout << i.ff << " " << i.ss.ff << " " << i.ss.ss << endl;
    }
    // cout << endl;
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