
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define rr return
// #define Endl endl
// #define ff first
// #define ss second
// // #define all(X) (X).begin(), (X).end()
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
// const int N = 2e5 + 5;
// // Find Min/Max
// // * Greedy/Brute Force
// // * DP
// // * BS
// vector<ll> adj[N];
// vector<bool> vis(N, false);
// // vll g0, g1;
// vll ans[2];
// vll tot(N);
// void dfs(int u, int c)
// {
//     if (vis[u] == true)
//         return;
//     vis[u] = true;
//     // col[u] = c;
//     ans[c].push_back(u);
//     for (auto &it : adj[u])
//         dfs(it, c ^ 1);
// }

// // void dfs(ll x, ll color)
// // {
// //     vis[x] = true;
// //     // if (color == 1)
// //     // g1.pb(x);
// //     // else
// //     // g0.pb(x);
// //     tot[x] = color;
// //     ans[color].pb(x);
// //     for (auto node : adj[x])
// //     {
// //         // if(vis[node]){
// //         //     if(tot[node]==color){

// //         //     }
// //         // }
// //         if (!vis[node])
// //         {
// //             dfs(1, color ^ 1);
// //         }
// //     }
// // }
// void solve()
// {
//     ll n, m;
//     cin >> n >> m;
//     ans[0].clear();
//     ans[1].clear();
//     for (ll i = 1; i <= n; i++)
//     {
//         adj[i].clear();
//     }
//     for (ll i = 0; i < m; i++)
//     {
//         ll x, y;
//         cin >> x >> y;
//         adj[y].pb(x);
//         adj[x].pb(y);
//     }
//     ll color = 0;

//     // for (ll i = 1; i <= n; i++)
//     // {
//     //     if (!vis[i])
//     //     {
//     dfs(1, color);
//     // }
//     // }
//     if (ans[1].size() < ans[0].size())
//         swap(ans[0], ans[1]);
//     cout << ans[0].size() << endl;
//     for (auto &it : ans[0])
//         cout << it << " ";
//     cout << endl;
//     // if (g0.size() > g1.size())
//     // {
//     //     cout << g1.size() << Endl;

//     //     for (ll i = 0; i < g1.size(); i++)
//     //     {
//     //         cout << g1[i] << " ";
//     //     }
//     // }
//     // else
//     // {
//     //     cout << g0.size() << Endl;

//     //     for (ll i = 0; i < g0.size(); i++)
//     //     {
//     //         cout << g0[i] << " ";
//     //     }
//     // }
//     cout << Endl;
//     rr;
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
//     // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
//     // cout<<fixed<<setprecision(10)<<ans<<endl;
//     // cout<<printf("%.8lf", hi)<<endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int tc = 0;
int vis[N], col[N];
vector<int> g[N];
vector<int> ans[2];

void dfs(int u, int c)
{
    if (vis[u] == tc)
        return;
    vis[u] = tc;
    col[u] = c;
    ans[c].push_back(u);
    for (auto &it : g[u])
        dfs(it, c ^ 1);
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        tc++;
        ans[0].clear();
        ans[1].clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        if (ans[1].size() < ans[0].size())
            swap(ans[0], ans[1]);
        cout << ans[0].size() << endl;
        for (auto &it : ans[0])
            cout << it << " ";
        cout << endl;
    }
    return 0;
}