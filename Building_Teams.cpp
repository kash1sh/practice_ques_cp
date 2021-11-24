
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
// // Find Min/Max
// // * Greedy/Brute Force
// // * DP
// // * BS
// vector<ll> adj[100005];
// vector<bool> vis(100005, false);
// vll grp(100005);
// bool color = true;
// bool bad = false;
// void dfs(ll x)
// {
//     vis[x] = true;
//     grp[x] = color;

//     for (auto node : adj[x])
//     {
//         if (!vis[node])
//         {
//             color = !color;
//             dfs(node);
//         }
//         else
//         {
//             if (grp[node] == color)
//             {
//                 bad = true;
//                 rr;
//             }
//         }
//     }
// }
// void solve()
// {
//     ll n, m;
//     cin >> n >> m;

//     for (ll i = 0; i < m; i++)
//     {
//         ll x, y;
//         adj[x].pb(y);
//         adj[y].pb(x);
//     }
//     // grp.resize(n);
//     for (ll i = 1; !bad && i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             dfs(i);
//         }
//     }
//     if (bad)
//     {
//         cout << "IMPOSSIBLE" << Endl;
//         rr;
//     }
//     for (ll i = 1; i <= n; i++)
//     {
//         cout << grp[i] + 1 << " ";
//     }
//     cout << Endl;
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
#include <cstdio>
#include <vector>

const int MN = 1e5 + 10;

int N, M;
bool bad, vis[MN], group[MN];
std::vector<int> a[MN];

void dfs(int n = 1, bool g = 0)
{
    vis[n] = 1;
    group[n] = g;
    for (int u : a[n])
        if (vis[u])
        {
            if (group[u] == g)
                bad = 1;
        }
        else
            dfs(u, !g);
}
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0, u, v; i < M; ++i)
        scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
    for (int i = 1; !bad && i <= N; ++i)
        if (!vis[i])
            dfs(i);
    if (bad)
        printf("IMPOSSIBLE\n");
    else
        for (int i = 1; i <= N; ++i)
            printf("%d%c", group[i] + 1, " \n"[i == N]);
    return 0;
}