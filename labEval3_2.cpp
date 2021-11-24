
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define ff first
#define ss second

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
}
// ll mod = 1e9 + 7, mxn = 3e5 + 5;

// ll add(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a += b;
//     if (a >= mod)
//         a -= mod;
//     if (a < 0)
//     {
//         a += mod;
//         a %= mod;
//     }
//     return a;
// }

// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }
// // ll modInverse(ll a, ll m){
// //     ll x, y;
// //     ll g = gcdExtended(a, m, &x, &y);
// //         ll res = (x%m + m) % m;
// //         return res;
// // }
// ll binary_Search(vector<ll> &arr, ll key)
// {
//     ll l = 0, r = arr.size() - 1;
//     ll ans;
//     while (l <= r)
//     {
//         ll mid = (l + r) / 2;
//         ll value = arr[mid];
//         if (value > key)
//         {
//             r = mid - 1;
//         }
//         else if (value == key)
//         {
//             return mid;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return -1;
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

// int fact[200003];
// int inv[200003];

// void fact0()
// {
//     int i, j;
//     fact[0] = 1;
//     for (i = 1; i <= 200000; i++)
//     {
//         fact[i] = i * fact[i - 1] % mod;
//     }
//     inv[0] = 1;
//     inv[1] = 1;
//     int p = mod;
//     for (i = 2; i <= 200000; i++)
//         inv[i] = (p - (p / i) * inv[p % i] % p) % p;

//     for (i = 2; i <= 200000; i++)
//     {
//         inv[i] *= inv[i - 1];
//         inv[i] %= mod;
//     }
// }
// int Comb(int a, int b)
// {
//     // cout<<a<<" "<<b<<endl;
//     int an = fact[a];
//     //cout<<an<<endl;
//     an *= inv[b];
//     an %= mod;
//     an *= inv[a - b];
//     an %= mod;
//     return an;
// }

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
#define mod 1000000007

vector<int> ans = {0};
// vector<int> res(1001);
vector<int> se;
bool flag = true;
void dfs(vector<int> adj[], vector<bool> vis, int n, int m, int s, int k)
{
    if (s == k)
    {

        if (se.size() == 0 || ans.size() < se.size())
        {
            se.clear();
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == 0)
                    continue;
                se.pb(ans[i]);
            }

            se.pb(k);
        }
        // }
        return;
    }
    // else
    // {
    vis[s] = true;
    ans.pb(s);

    for (auto v : adj[s])
    {
        if (!vis[v])
        {
            dfs(adj, vis, n, m, v, k);
        }
    }
    // }
    vis[s] = false;
    ans.pop_back();
}
void help(vector<bool> vis)
{

    se.clear();
    ans.clear();
    for (int i = 0; i < vis.size(); i++)
        vis[i] = false;
}
void solve()
{
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> adj[n * m + 2];
    for (int i = 1; i <= n * m; i++)
    {
        ll num;
        cin >> num;
        ll x;

        for (int j = 0; j < 8; j++)
        {
            cin >> x;
            if (j == 0 && x == 1)
            {
                adj[num].pb(num - m);
                // adj[num - m].pb(num);
            }
            if (j == 1 && x == 1)
            {
                adj[num].pb(num - m + 1);
                // adj[num - m + 1].pb(num);
            }
            if (j == 2 && x == 1)
            {
                adj[num].pb(num + 1);
                // adj[num + 1].pb(num);
            }
            if (j == 3 && x == 1)
            {
                adj[num].pb(num + m + 1);
                // adj[num + m + 1].pb(num);
                // cout<<adj[1][]
            }
            if (j == 4 && x == 1)
            {
                adj[num].pb(num + m);
                // adj[num + m].pb(num);
            }
            if (j == 5 && x == 1)
            {
                adj[num].pb(num + m - 1);
                // adj[num + m - 1].pb(num);
            }
            if (j == 6 && x == 1)
            {
                adj[num].pb(num - 1);
                // adj[num - 1].pb(num);
            }
            if (j == 7 && x == 1)
            {
                adj[num].pb(num - m - 1);
                // adj[num - m - 1].pb(num);
            }
        }
    }

    vector<bool> vis(n * m + 1, false);
    dfs(adj, vis, n, m, s, 1);
    // se.pb(1);
    for (auto i : se)
        cout << i << " ";
    cout << endl;

    help(vis);
    dfs(adj, vis, n, m, s, m);
    // se.pb(m);
    for (auto i : se)
        cout << i << " ";
    cout << endl;

    help(vis);
    dfs(adj, vis, n, m, s, n * m - m + 1);
    // se.pb(n * m - m + 1);
    for (auto i : se)
        cout << i << " ";
    cout << endl;

    help(vis);
    dfs(adj, vis, n, m, s, n * m);
    // se.pb(n * m);
    for (auto i : se)
        cout << i << " ";
    cout << endl;
    // ans.clear();
}
int main()
{
    io();

    solve();

    // cout<<setprecision(10)
    return 0;
}
// 20 12 3 2 1
// 20 28 36 29 21 13 6 7 8
// 20 12 3 10 17 25 33
// 20 28 36 29 21 13 6 15 22 30 39 40