
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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
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
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP

// vector<int> adj1[10000];
// vector<int> adj2[10000];
bool adj1[100][100] = {false};
bool adj2[100][100] = {false};
vector<bool> vis(10000, false);
vector<bool> vis2(10000, false);
void dfs1(ll node)
{
    vis[node] = true;
    for (int u : adj1[node])
        if (!vis[u])
            dfs1(u);
}
void dfs2(ll node)
{
    vis2[node] = true;
    for (int u : adj2[node])
        if (!vis2[u])
            dfs2(u);
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    // debug(n);
    // debug(m);
    // adj1.clear();
    // adj2.clear();
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        // debug(x);
        // adj1[x].pb(y);
        // debug(adj1[x][0]);
        // adj1[y].pb(x);
        adj1[x][y] = true;
        adj1[y][x] = true;
    }
    // cout << adj1[1][0];
    // for (auto i : adj1[1])
    // {
    //     cout << i << " ";
    // }
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        // debug(y);
        // adj2[x].pb(y);
        // adj2[y].pb(x);
        adj2[x][y] = true;
        adj2[x][y] = true;
    }
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        v[i] = i;
    }
    // sort(v.begin()/, v.end());
    do
    {
        //    cout << str << endl;
        bool f = true;
        for (ll i = 0; i < n; i++)
        {

            for (ll j = 0; j < n; j++)
            {
                if (adj1[i][j])
                {
                    if (adj2[v[i]][v[j]] == false)
                    {
                        // No;
                        // rr;
                        f = false;
                        break;
                    }
                }
                else
                {
                    if (adj2[v[i]][v[j]] == true)
                    {
                        // No;
                        f = false;
                        // rr;
                        break;
                    }
                }
            }
        }
        if (f)
        {
            Yes;
            rr;
        }

    } while (next_permutation(v.begin(), v.end()));
    // Yes;
    No;
    rr;
    // cout << adj2[1][0];
    // for (ll i = 1; i <= n; i++)
    // {
    //     // memset(vis.begin(), vis.end(), false);
    //     // memset(vis2.begin(), vis2.end(), false);
    //     // for (ll i = 1; i <= n; i++)
    //     // {
    //     //     vis[i] = false;
    //     //     vis2[i] = false;
    //     // }
    //     // dfs1(i);
    //     // dfs2(i);

    //     // for (ll i = 1; i <= n; i++)
    //     // {
    //     //     if (vis[i] != vis2[i])
    //     //     {
    //     //         No;
    //     //         rr;
    //     //     }
    //     // }
    //     if (adj1[i].size() != adj2[i].size())
    //     {
    //         No;
    //         rr;
    //     }
    // }
    Yes;
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
// // #include <cstdio>
// // #include <vector>

// // const int MN = 1e5 + 10;

// // int N, M, ans, rep[MN];
// // std::vector<int> adj_list[MN];
// // bool visited[MN];

// // void dfs(int node)
// // {
// //     visited[node] = true;
// //     for (int u : adj_list[node])
// //         if (!visited[u])
// //             dfs(u);
// // }
// // int count_components()
// // {
// //     int count = 0;
// //     for (int i = 1; i <= N; ++i)
// //         if (!visited[i])
// //         {
// //             rep[count++] = i;
// //             dfs(i);
// //         }
// //     return count;
// // }

// // int main()
// // {
// //     scanf("%d%d", &N, &M);
// //     for (int i = 0, u, v; i < M; ++i)
// //         scanf("%d%d", &u, &v), adj_list[u].push_back(v), adj_list[v].push_back(u);
// //     ans = count_components();
// //     printf("%d\n", ans - 1);
// //     for (int i = 1; i < ans; ++i)
// //         printf("%d %d\n", rep[i - 1], rep[i]);
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// using vi = vector<int>;
// #define ln "\n"
// #define pb push_back

// const int MXN = 3005;
// int N, M, a, b, K, ans;
// vi adjlist[MXN];
// vi adj[MXN];
// bool vis[MXN], vis2[MXN];

// void dfs(int node)
// {
//     visit[node] = true;
//     for (int x : adjlist[node])
//     {
//         if (!closed[x] && !visited[x])
//         {
//             dfs(x);
//         }
//     }
// }

// void count_comps()
// {
//     ans = 0;
//     for (int i = 1; i <= N; ++i)
//     {
//         if (!closed[i] && !visited[i])
//         {
//             dfs(i);
//             ++ans;
//         }
//     }
//     if (ans > 1)
//         cout << "NO" << ln;
//     else
//         cout << "YES" << ln;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     freopen("closing.in", "r", stdin);
//     freopen("closing.out", "w", stdout);
//     cin >> N >> M;
//     ll m = M;
//     while (m--)
//     {
//         cin >> a >> b;
//         adjlist[a].pb(b);
//         adjlist[b].pb(a);
//     }
//     m = M;
//     while (m--)
//     {
//         cin >> a >> b;
//         adj[a].pb(b);
//         adj[b].pb(a);
//     }
//     for (int i = 1; i <= N; ++i)
//     {
//         // count_comps();
//          for (int i = 1; i <= N; ++i)
//             vis[i] = false;
//              for (int i = 1; i <= N; ++i)
//             vis2[i] = false;
//         dfs(i);
//         // cin >> K;
//         // closed[K] = true;

//     }
//     return 0;
// }