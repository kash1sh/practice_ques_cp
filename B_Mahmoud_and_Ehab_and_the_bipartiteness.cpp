
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
// int n;
// vector<int> graph[100000];
// char col = 'r';
// vector<bool> visited(100000);
// vector<char> color(100000);
// void dfs(int x, char col)
// {

//     visited[x] = true;
//     color[x] = col;
//     if (col == 'r')
//         col = 'b';
//     else
//         col = 'r';
//     for (auto node : graph[x])
//     {
//         // if(vis[node]){
//         // if(color[node]==)
//         // }
//         if (!visited[node])
//         {
//             dfs(node, col);
//             // dfs(node, color[x] == 'r' ? 'b' : 'r');
//         }
//     }
// }
// void solve()
// {
//     cin >> n;
//     for (int i = 0; i < n - 1; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         graph[a - 1].pb(b - 1);
//         graph[b - 1].pb(a - 1);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (visited[i])
//         {
//             continue;
//         }
//         else
//         {
//             dfs(i, col);
//         }
//     }
//     int blue = 0, red = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (color[i] == 'b')
//             blue++;
//         else
//             red++;
//     }
//     ll ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int nblue = 0, nred = 0;
//         for (int neigh : graph[i])
//         {
//             if (color[neigh] == 'b')
//                 nblue++;
//             else
//                 nred++;
//         }
//         if (color[i] == 'b')
//         { //blue
//             ans += (red - nred);
//         }
//         else
//         { //red
//             ans += (blue - nblue);
//         }
//     }
//     cout << ans / 2 << endl;
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
// #define int long long
vector<int> col(1e5 + 5, -1);
vector<int> vis(1e5 + 5, false);
vector<vector<int>> adj(1e5 + 5);
// void dfs(int i, int p)
// {
//     if (p == -1)
//         col[i] = 0;
//     else
//         col[i] = 1 - col[p];
//     for (int c : adj[i])
//         if (c != p)
//             dfs(c, i);
// }
void dfs(int n = 1, bool g = 0)
{
    vis[n] = 1;
    col[n] = g;
    for (int u : adj[n])
        if (vis[u])
        {
            // if (col[u] == g)
            // bad = 1;
        }
        else
            dfs(u, !g);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (col[i] == 1)
            cnt++;
    cout << (abs(cnt * (n - cnt)) - n + 1);
    return 0;
}