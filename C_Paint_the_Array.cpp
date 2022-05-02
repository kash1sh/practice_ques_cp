
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
// const int dx[4] = {1, -1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
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

// void solve()
// {
//     ll n;
//     cin >> n;
//     vll a(n), odd, eve;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         if (i % 2 == 0)
//             odd.pb(a[i]);
//         else
//             eve.pb(a[i]);
//     }

//     // if()

//     // for (ll i = 0; i < n; i++)
//     // {
//     //     if (i == 0)
//     //     {
//     //         if (a[0] == a[1])
//     //         {
//     //             cout << 0 << endl;
//     //             rr;
//     //         }
//     //         continue;
//     //     }
//     //     if (i == n - 1)
//     //     {
//     //         if (a[n - 1] == a[n - 2])
//     //         {
//     //             cout << 0 << endl;
//     //             rr;
//     //         }
//     //     }

//     //     if (a[i - 1] == a[i] || a[i] == a[i + 1])
//     //     {
//     //         cout << 0 << endl;
//     //         rr;
//     //     }
//     // }
//     ll gcdo = 0, gcde = 0;

//     for (ll i = 0; i < odd.size(); i++)
//     {
//         gcdo = __gcd(gcdo, odd[i]);
//     }
//     for (ll i = 0; i < eve.size(); i++)
//     {
//         gcde = __gcd(gcde, eve[i]);
//     }
//     // debug(gcde);
//     // debug(gcdo);
//     bool f = true;
//     if (gcdo != 1)
//     {
//         for (ll i = 0; i < eve.size(); i++)
//         {
//             if (eve[i] % gcdo == 0)
//             {
//                 // debug(n);
//                 // cout << 0 << endl;
//                 // rr;
//                 f = false;
//                 // break;
//             }
//         }
//         if (f)
//         {
//             cout << gcdo << endl;
//             rr;
//         }
//     }

//     if (gcde != 1)
//     {
//         f = true;
//         for (ll i = 0; i < odd.size(); i++)
//         {
//             if (odd[i] % gcde == 0)
//             {
//                 // cout << 0 << endl;
//                 // rr;
//                 // debug(n);
//                 // debug(odd[i]);
//                 f = false;
//                 // break;
//             }
//         }
//         if (f)
//         {
//             cout << gcde << endl;
//             rr;
//         }
//     }
//     // if (gcde == 1)
//     // {
//     //     cout << gcdo << endl;
//     //     rr;
//     // }
//     // if (gcdo == 1)
//     // {
//     //     cout << gcde << endl;
//     //     rr;
//     // }
//     cout << 0 << endl;
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
set<int> primeFactors(int n)
{
    set<int> f;
    // f.pb(n);
    // f.insert(n);
    for (int x = 1; x * x <= n; x++)
    {
        if (n % x == 0)
        {
            f.insert(x);
            f.insert(n / x);
        }
    }
    // if (n > 1)
    //     f.insert(n);
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
    {
        cin >> a[i];
    }
    ll g1 = 0, g2 = 0;

    for (ll i = 0; i < n; i += 2)
    {
        g2 = __gcd(g2, a[i]);
    }
    for (ll i = 1; i < n; i += 2)
    {
        g1 = __gcd(g1, a[i]);
    }

    bool f1 = true, f2 = true;
    for (ll i = 0; i < n; i += 2)
    {
        if (a[i] % g1 == 0)
        {
            f2 = false;
        }
    }
    for (ll i = 1; i < n; i += 2)
    {
        if (a[i] % g2 == 0)
        {
            f1 = false;
        }
    }
    if (f1 == false && f2 == false)
    {
        cout << 0 << endl;
        rr;
    }
    if (f1)
    {
        cout << g2 << endl;
        rr;
    }
    if (f2)
    {
        cout << g1 << Endl;
        rr;
    }
    map<ll, ll> m, m1;
    // ll odd = n / 2;
    // if (n % 2)
    // odd++;
    for (ll i = 0; i < n; i++)
    {
        set<int> f = primeFactors(a[i]);
        // if (i % 2)
        for (auto j : f)
        {
            m[j]++;
        }
    }
    // for (auto i : m)
    // {
    //     cout << i.ff << " " << i.ss << Endl;
    // }
    for (auto i : m)
    {
        bool f = true;

        for (ll j = 0; j < n; j += 2)
        {
            if (a[j] % i.ff != 0)
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            for (ll j = 1; j < n; j += 2)
            {
                if (a[j] % i.ff == 0)
                {
                    f = false;
                    break;
                }
            }
        }
        if (f)
        {
            cout << i.ff << endl;
            rr;
        }
        f = true;

        for (ll j = 1; j < n; j += 2)
        {
            if (a[j] % i.ff != 0)
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            for (ll j = 0; j < n; j += 2)
            {
                if (a[j] % i.ff == 0)
                {
                    f = false;
                    break;
                }
            }
        }
        if (f)
        {
            cout << i.ff << endl;
            rr;
        }
    }
    cout << 0 << endl;
    rr;
    // }

    for (ll i = 0; i < n; i++)
    {
        set<int> f = primeFactors(a[i]);
        if (i % 2 == 0)
            for (auto j : f)
            {
                m1[j]++;
            }
    }
    // for (auto i : m)
    // {
    //     cout << i.ff << " " << i.ss << Endl;
    // }
    ll eve = n / 2;
    if (n % 2)
        eve++;
    for (auto i : m1)
    {
        bool f = true;
        if (i.ss == eve)
        {
            for (ll j = 1; j < n; j += 2)
            {
                if ((a[j] % i.ff) == 0)
                {
                    f = false;
                    break;
                }
            }
            if (!f)
                break;
            cout << i.ss << endl;
            rr;
        }
    }
    cout << 0 << endl;
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