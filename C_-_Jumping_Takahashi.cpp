
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
// bool f = false;
// ll dp[10005][101];
// // set<vector<ll>> ans;
// ll help(vector<ll> &a, vector<ll> &b, int i, int x, ll sum)
// {
//     // if (i == a.size())
//     // {
//     //     // ans.insert(v);
//     //     show(v);
//     // }
//     if (sum > x)
//     {
//         return false;
//     }
//     if (sum >= x && i == a.size())
//     {
//         f = true;
//         dp[x][i] = 1;
//         // return dp[x][i];
//         return true;
//     }
//     if (i >= a.size() && sum != x)
//     {
//         return false;
//     }
//     // if (x < 0 || i == a.size())
//     // {
//     //     return LONG_MIN;
//     // }
//     // if (dp[sum][i] != -1)
//     // {
//     //     return dp[sum][i];
//     // }
//     sum += a[i];
//     // v.push_back(a[i]);
//     // dp[sum][i] =
//     if (help(a, b, i + 1, x, sum))
//     {
//         return true;
//     }
//     // if (f == true)
//     //     return;
//     sum -= a[i];
//     // v.pop_back();
//     sum += b[i];
//     // v.push_back(b[i]);
//     if (help(a, b, i + 1, x, sum))
//     {
//         return true;
//     }
//     // if (v1 > 0)
//     // {
//     //     dp[sum][i] = v1;
//     //     return v1;
//     // }
//     // if (v2 > 0)
//     // {
//     //     dp[sum][i] = v2;
//     //     return v2;
//     // }
//     // if (f == true)
//     //     return;
//     // sum -= b[i];
//     return false;

//     // v.pop_back();
// }
// void solve()
// {
//     ll n, x;
//     cin >> n >> x;
//     vll a(n), b(n);
//     for (ll i = 0; i < 2 * n; i++)
//     {
//         cin >> a[i] >> b[i];
//     }
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     cin >> b[i];
//     // }
//     // ans.clear();
//     vector<ll> v;
//     // memset(dp, -1, sizeof(dp));
//     ll sum = 0;

//     if (help(a, b, 0, x, sum))
//     {
//         Yes;
//         rr;
//     }
//     No;
//     rr;
//     // for (auto i : ans)
//     // {
//     //     cout << i << " ";
//     // }
//     // if (f)
//     // {
//     //     Yes;
//     //     rr;
//     // }
//     // No;
//     // rr;
//     if (dp[n][x] == -1)
//     {
//         No;
//         rr;
//     }
//     Yes;
//     rr;
// }
// int main()
// {
//     io();
//     // solve();
//     ll t = 1;
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
#define ll long long

using namespace std;

ll gcd(ll x, ll y)
{
    return (y ? gcd(y, x % y) : x);
}

struct DSU
{
    vector<int> parent, s;
    vector<pair<int, int>> elem;
    DSU(int n)
    {
        parent = vector<int>(n);
        s = vector<int>(n, 1);
        elem = vector<pair<int, int>>(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            elem[i] = {i, i};
        }
    }
    int get(int a)
    {
        return parent[a] = (parent[a] == a ? a : get(parent[a]));
    }
    bool same(int a, int b)
    {
        return (get(a) == get(b));
    }
    void join(int a, int b)
    {
        a = get(a), b = get(b);
        if (a != b)
        {
            if (s[a] > s[b])
            {
                swap(a, b);
            }
            parent[a] = b;
            s[b] += s[a];
            elem[b].first = min(elem[b].first, elem[a].first);
            elem[b].second = max(elem[b].second, elem[a].second);
        }
    }
};

int n, k;
int DP[10001][101];

void go(vector<pair<int, int>> &v, int sum, int id, bool &flag)
{
    if (id == n)
    {
        if (sum == k)
            flag = 1;
        return;
    }
    if (sum > k)
        return;
    int &ref = DP[sum][id];
    if (~ref)
        return;
    ref = 1;
    go(v, sum + v[id].first, id + 1, flag);
    go(v, sum + v[id].second, id + 1, flag);
}

void solve()
{
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    memset(DP, -1, sizeof(DP));
    bool flag = 0;
    go(v, 0, 0, flag);
    cout << (flag ? "Yes" : "No") << '\n';
}

int main()
{
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    int t = 1; // cin >> t ;
    while (t--)
        solve();
    return 0;
}