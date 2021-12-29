
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
// const int dx[4] = {1, -1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// // Find Min/Max
// // * Greedy/Brute Force
// // * DP
// // * BS
// ll n;
// ll grid[101][101];
// map<pair<int, int>, vector<pair<int, int>>> turnon;
// // map<ll, ll> x;
// // map<ll, ll> y;
// ll cnt = 1;
// bool vis[101][101] = {false};

// void floodfill(ll r, ll c)
// {
//     // if (vis[r][c])
//     // return;
//     vis[r][c] = true;

//     for (ll k = 0; k < 4; k++)
//     {
//         if (r + dx[k] >= 0 && r + dx[k] < n && c + dy[k] >= 0 && c + dy[k] < n && !vis[r + dx[k]][c + dy[k]])
//         {
//             if (turnon.find(make_pair(r + dx[k], c + dy[k])) != turnon.end())
//             {
//                 for (auto i : turnon[make_pair(r + dx[k], c + dy[k])])
//                 {
//                     if (vis[i.ff][i.ss])
//                         break;
//                     cnt++;
//                     vis[i.ff][i.ss] = true;
//                     for (int j = 0; j < 4; j++)
//                     {
//                         int newrow = i.ff + dx[j];
//                         int newcol = i.ss + dy[j];
//                         if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n)
//                         {
//                             if (!vis[newrow][newcol])
//                             {
//                                 floodfill(i.ff, i.ss);
//                             }
//                         }
//                     }
//                 }
//             }
//             // else
//             // {
//             //     // for(int i = 0; i < 4; i++){
//             //     floodfill(r + dx[k], c + dy[k]);
//             // }
//         }
//     }
// }
// // }
// void solve()
// {
//     ll m;
//     cin >> n >> m;
//     // x.clear();
//     // y.clear();
//     for (ll i = 0; i < m; i++)
//     {
//         ll x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         x1--, y1--, x2--, y2--;
//         // x[x1]=x2;
//         // y[y1]=y2;
//         pair<ll, ll> p = {x1, y1};
//         turnon[p].pb({x2, y2});
//         // xy[p] = {x2, y2};
//     }
//     vis[0][0] = true;
//     floodfill(0, 0);
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
// Problem: Problem 1. Switching on the Lights
// Contest: USACO - USACO 2015 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=570
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file lightson.in
// Output: stdout
// Attempted: 2021-08-07 17:53:56 EST
// AC

#include <bits/stdc++.h>
using namespace std;

inline namespace fastio
{
    const int BSZ = 1 << 15;
    char ibuf[BSZ];
    int ipos, ilen;
    char nc()
    {
        if (ipos == ilen)
        {
            ipos = 0;
            ilen = fread(ibuf, 1, BSZ, stdin);
            if (!ilen)
                return EOF;
        }
        return ibuf[ipos++];
    }
    template <class T>
    void ri(T &x)
    { // read int or ll
        char ch;
        int sgn = 1;
        while (!isdigit(ch = nc()))
            if (ch == '-')
                sgn *= -1;
        x = ch - '0';
        while (isdigit(ch = nc()))
            x = x * 10 + (ch - '0');
        x *= sgn;
    }
    template <class T>
    void rc(T &x)
    { // read char
        x = nc();
        while (isspace(x))
        {
            x = nc();
        }
    }
    template <class T, class... Ts>
    void ri(T &t, Ts &...ts)
    {
        ri(t);
        ri(ts...);
    } // read ints
    template <class str>
    void rs(str &x)
    { // read str
        char ch;
        while (isspace(ch = nc()))
            ;
        do
        {
            x += ch;
        } while (!isspace(ch = nc()) && ch != EOF);
    }
}

typedef long long ll;
const ll INF = 1e18;
const int MOD = 1e9 + 7, MN = 1e5 + 5;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define debug(x) cout << #x << " = " << x << "\n"
#define print(x) cout << x << "\n"
#define mp(x, y) make_pair(x, y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n;
bool grid[100][100];
bool visited[100][100];
map<pair<int, int>, vector<pair<int, int>>> turnon;
int ans = 1;

void floodfill(int row, int col)
{
    if (row < 0 || row >= n || col < 0 || col >= n || !grid[row][col])
        return;
    if (visited[row][col])
        return;
    visited[row][col] = true;

    // if (turnon.find(mp(row, col)) != turnon.end())
    // {
    for (auto i : turnon[mp(row, col)])
    {
        if (!grid[i.F][i.S])
        {
            grid[i.F][i.S] = true;
            ans++;
            for (int j = 0; j < 4; j++)
            {
                int newrow = i.F + dx[j];
                int newcol = i.S + dy[j];
                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n)
                {
                    if (visited[newrow][newcol])
                    {
                        floodfill(i.F, i.S);
                    }
                }
            }
        }
    }
    // }

    for (int i = 0; i < 4; i++)
    {
        floodfill(row + dx[i], col + dy[i]);
    }
}

void doStuff()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int k;
    ri(n, k);
    grid[0][0] = true;

    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        ri(a, b, c, d);
        turnon[mp(a - 1, b - 1)].push_back(mp(c - 1, d - 1));
    }

    floodfill(0, 0);
    print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    doStuff();

    return 0;
}

// you should actually read the stuff at the bottom and not submit the same wrong code

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing
	* maybe just stop being dumb lol
*/