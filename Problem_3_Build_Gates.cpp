
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

// bool vis[2001][2001] = {false};
// // vector<ll> dir(1001);
// void solve()
// {
//     ll n;
//     cin >> n;
//     string s;
//     cin >> s;
//     ll cnt = 0;
//     ll y = 0, x = 0;
//     vis[0][0] = true;
//     for (ll i = 0; i < n; i++)
//     {
//         if (s[i] == 'N')
//         {
//             y += 2;
//             if (!vis[1000 + x][1000 + y] && vis[1000 + x][1000 + y - 1])
//                 cnt++;
//             vis[1000 + x][1000 + y] = true;
//             vis[1000 + x][1000 + y - 1] = true;
//         }
//         if (s[i] == 'E')
//         {
//             x += 2;
//             if (!vis[1000 + x][1000 + y] && vis[1000 + x - 1][1000 + y])
//                 cnt++;
//             vis[1000 + x][1000 + y] = true;
//             vis[1000 + x - 1][1000 + y] = true;
//         }

//         if (s[i] == 'S')
//         {
//             y -= 2;
//             if (!vis[1000 + x][1000 + y] && vis[1000 + x][1000 + y + 1])
//                 cnt++;
//             vis[1000 + x][1000 + y] = true;
//             vis[1000 + x][1000 + y + 1] = true;
//         }
//         if (s[i] == 'W')
//         {
//             x -= 2;
//             if (!vis[1000 + x][1000 + y] && vis[1000 + x + 1][1000 + y])
//                 cnt++;
//             vis[1000 + x][1000 + y] = true;
//             vis[1000 + x + 1][1000 + y] = true;
//         }
//     }
//     cout << cnt << endl;
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
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef long long ll;
#define FIO                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define F1R(i, a) FOR(i, 1, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define mp make_pair
#define pb push_back
// #pragma once
const int MOD = 1e9 + 7;

// void setIO(string name = "")
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     if (sz(name))
//     {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.f == b.f)
        return a.s < b.s;

    return a.f < b.f;
}
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
const int SZ = 2005;
bool g[SZ][SZ];
ll n;
string s;
void ff(int x, int y)
{ // flood fill!
    if (x < 0 || x >= SZ || y < 0 || y >= SZ || g[x][y])
        return;
    g[x][y] = 1;
    //cout<<x<<' '<<y<<endl;
    F0R(i, 4)
    ff(x + xd[i], y + yd[i]);
}
int main()
{
    // setIO("gates");
    // cin >> n >> s;
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
            g[i][j] = 0;

    int x = SZ / 2, y = SZ / 2;
    for (int i = 0; i < s.length(); i++)
    {
        g[x][y] = 1;
        if (s[i] == 'N')
        {
            y += 2;
            g[x][y - 1] = 1;
        }
        if (s[i] == 'E')
        {
            x += 2;
            g[x - 1][y] = 1;
        }
        if (s[i] == 'S')
        {
            y -= 2;
            g[x][y + 1] = 1;
        }
        if (s[i] == 'W')
        {
            x -= 2;
            g[x + 1][y] = 1;
        }
        g[x][y] = 1;
    }

    int ans = 0;
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
        {
            if (!g[i][j])
            {
                ff(i, j);
                ans++;
                //cout<<ans<<endl;
            }
        }
    cout << ans - 1 << endl;
}