
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
// bool valid_coordinate(ll x, ll y, ll n, ll m)
// {
//     if (x < 0 || y < 0)
//         return false;

//     else if (x >= n || y >= m)
//         return false;

//     else
//         return true;
// }

// int sod(int n)
// {
//     int sum = 0;
//     while (n)
//     {
//         sum += (n % 10);
//         n /= 10;
//     }
//     return sum;
// }

// bool isPowerOfTwo(ll n)
// {
//     return n && (!(n & (n - 1)));
// }
// // Find Min/Max
// // * Greedy/Brute Force
// // * DP
// // * BS
// ll n, m;
// int grid[501][501];
// int point[501][501];
// bool vis[501][501] = {false};
// ll cnt1 = 0;
// ll cnt = 0;
// void floodfill(ll r, ll c, ll mid, ll maxa)
// {
//     // if (!valid_coordinate(r, c, n, m))
//     //     return;
//     if (vis[r][c])
//         return;
//     vis[r][c] = 1;
//     if (point[r][c] == 1)
//     {
//         // maxa=max(maxa,)
//         cnt++;
//         // return;
//     }
//     // floodfill(r, c - 1, curr, maxa);
//     if (c - 1 >= 0 && abs(grid[r][c - 1] - grid[r][c]) <= mid)
//     {
//         floodfill(r, c - 1, mid, maxa);
//     }
//     if (c + 1 < m && abs(grid[r][c + 1] - grid[r][c]) <= mid)
//     {
//         floodfill(r, c + 1, mid, maxa);
//     }
//     if (r - 1 >= 0 && abs(grid[r][c] - grid[r - 1][c]) <= mid)
//     {
//         floodfill(r - 1, c, mid, maxa);
//     }
//     if (r + 1 < n && abs(grid[r + 1][c] - grid[r][c]) <= mid)
//     {
//         floodfill(r + 1, c, mid, maxa);
//     }
// }
// bool check(ll mid)
// {
//     memset(vis, false, sizeof(vis));
//     ll maxa = LONG_MAX;
//     cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             ll curr;
//             if (grid[i][j] == 1)
//             {
//                 floodfill(i, j, mid, maxa);
//                 // if (cnt >= cnt1)
//                 return cnt == cnt1;
//             }
//         }
//     }
// }
// void solve()
// {
//     cin >> n >> m;

//     for (ll i = 0; i < n; i++)
//     {
//         for (ll j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     for (ll i = 0; i < n; i++)
//     {
//         for (ll j = 0; j < m; j++)
//         {
//             cin >> point[i][j];
//             if (point[i][j] == 1)
//                 cnt1++;
//         }
//     }

//     ll lo = 0, hi = 1e18;
//     while (lo < hi)
//     {
//         ll mid = lo + (hi - lo) / 2;
//         if (check(mid))
//         {
//             hi = mid;
//         }
//         else
//         {
//             lo = mid + 1;
//         }
//     }
//     cout << lo << endl;
//     rr;
// }
// int main()
// {
//     io();
//     // solve();
//     ll t = 1;
//     // ll t;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
//     // cout<<fixed<<setprecision(10)<<ans<<endl;
//     // cout<<printf("%.8lf", hi)<<endl;
//     return 0;
// }
#include "bits/stdc++.h"
using namespace std;
/*------------------------------------------------------------*/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
/*------------------------------------------------------------------*/
#define int long long
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define fix(prec)                            \
    {                                        \
        cout << setprecision(prec) << fixed; \
    }
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#define rev greater<int>()
#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))
#define imin INT_MIN
#define imax INT_MAX
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

using ld = long double;
using vi = vector<int>;
using mi = map<int, int>;
using pi = pair<int, int>;

const double Pi = acos(-1.0);
const int inf = 1e18 + 1;
const int M = 1e9 + 7;
const int MM = 998244353;

const int N1 = 2e5 + 5;
const int N2 = 2e6 + 5;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}
/*----------------------------------------------------------*/
// void setIO(string s)
// {
// freopen((s + ".in").c_str(), "r", stdin);
// freopen((s + ".out").c_str(), "w", stdout);
// }
// void local()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }
/*--------------------------------------------------------*/

int n, m;
int a[505][505];
bool vis[505][505];
int has[505][505];
int ct = 0;
int c = 0;
bool can(int i, int j, int mid)
{
    if (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j])
    {
        return 1;
    }
    return 0;
}
void dfs(int i, int j, int mid)
{
    // if (has[i][j] == 1)
    //     c++;
    // vis[i][j] = 1;
    //     return;
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    if (has[i][j] == 1)
    {
        // maxa=max(maxa,)
        c++;
        // return;
    }
    for (int k = 0; k < 4; k++)
    {
        if (can(i + dx[k], j + dy[k], mid) && abs(a[i + dx[k]][j + dy[k]] - a[i][j]) <= mid)
        {
            dfs(i + dx[k], j + dy[k], mid);
        }
    }
}
bool ok(int x)
{
    // mem0(vis);
    memset(vis, false, sizeof(vis));
    c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (has[i][j])
            {
                dfs(i, j, x);
                return (c == ct);
            }
        }
    }
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // setIO("ccski");
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> has[i][j];
            if (has[i][j] == 1)
            {
                ct++;
            }
        }
    }
    int l = 0, r = 1e9 + 5;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (ok(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}