
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
//     ll n, a, b;
//     cin >> n >> a >> b;

//     if (a + b > n)
//     {
//         cout << -1 << endl;
//         rr;
//     }
//     if (a + b + 1 > n - 1)
//     {
//         cout << -1 << endl;
//         rr;
//     }
//     // if (n == 2)
//     // {
//     //     if (a == 0 && b == 0)
//     //     {
//     //         cout << 1 << " " << 2 << endl;
//     //         rr;
//     //     }
//     //     // if(a==1 && b==1){
//     //     cout << -1 << endl;
//     //     rr;
//     //     // }
//     // }

//     // if (a >= ceil((double)n / 2) || b >= ceil((double)n / 2))
//     // {
//     //     cout << -1 << endl;
//     //     rr;
//     // }
//     if (a > b && a - b > 1)
//     {
//         cout << -1 << endl;
//         rr;
//     }
//     if (b > a && b - a > 1)
//     {
//         cout << -1 << endl;
//         rr;
//     }
//     // if (n == 3)
//     // {
//     //     if (a >= 1 && b >= 1)
//     //     {
//     //         cout << -1 << endl;
//     //         rr;
//     //     }
//     //     if (a == 1)
//     //     {
//     //         cout << 1 << " " << 3 << " " << 2 << endl;
//     //         rr;
//     //     }
//     //     if (b == 1)
//     //     {
//     //         cout << 2 << " " << 1 << " " << 3 << endl;
//     //         rr;
//     //     }
//     //     if (a == 0 && b == 0)
//     //     {
//     //         cout << 1 << " " << 2 << " " << 3 << endl;
//     //         rr;
//     //     }
//     // }
//     // if (n == 2)
//     // {
//     //     cout << 1 << endl;
//     //     rr;
//     // }

//     vll arr(n), v;
//     for (ll i = 0; i < n; i++)
//     {
//         arr[i] = i + 1;
//     }
//     if (a == 0 && b == 0)
//     {
//         for (auto i : arr)
//         {
//             cout << i << " ";
//         }
//         cout << Endl;
//         rr;
//     }
//     // deb(arr);
//     // cout << "HE";
//     ll tot = 0;
//     ll lo = 1, hi = n;
//     if (b == a)
//     {

//         v.pb(lo++);
//         // for (; i < n; i += 2)
//         // {
//         //     if (i + 1 > n)
//         //         break;
//         //     // debug(i);
//         //     swap(arr[i], arr[i + 1]);
//         //     // debug(arr[i]);
//         //     a--;
//         //     if (a == 0)
//         //         break;
//         // }
//         while (tot < a)
//         {
//             v.pb(hi--);
//             v.pb(lo++);
//             tot++;
//         }

//         for (ll i = lo; i <= hi; i++)
//             v.pb(i);
//         // i -= 2;
//         // for (; i < n; i += 2)
//         // {

//         //     swap(arr[i], arr[i - 1]);
//         //     b--;
//         //     if (b == 0)
//         //         break;
//         // }
//         for (auto i : v)
//         {
//             cout << i << " ";
//         }
//         cout << Endl;
//         rr;
//     }
//     if (b > a)
//     {
//         // if (a != b / 2)
//         // {
//         //     cout << -1 << endl;
//         //     rr;
//         // }
//         tot = 0;
//         v.pb(hi--);
//         while (tot < b - 1)
//         {
//             v.pb(lo++);
//             v.pb(hi--);
//             tot++;
//         }
//         for (ll i = lo; i <= hi; i++)
//             v.pb(i);
//         for (ll i = 1; i < n; i += 2)
//         {

//             swap(arr[i], arr[i - 1]);
//             b--;
//             if (b == 0)
//                 break;
//         }
//         for (auto i : v)
//         {
//             cout << i << " ";
//         }
//         cout << Endl;
//         rr;
//     }
//     else if (a > b)
//     {
//         tot = 0;
//         v.pb(lo++);

//         // if (b != a / 2)
//         // {
//         //     cout << -1 << endl;
//         //     rr;
//         // }
//         while (tot < a - 1)
//         {
//             v.pb(hi--);
//             v.pb(lo++);
//             tot++;
//         }
//         for (ll i = 1; i < n; i += 2)
//         {

//             swap(arr[i], arr[i + 1]);
//             a--;
//             if (a == 0)
//                 break;
//         }

//         for (ll i = hi; i >= lo; i--)
//             v.pb(i);
//     }
//     for (auto i : v)
//     {
//         cout << i << " ";
//     }
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
vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
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
    ll n, a, b;
    cin >> n >> a >> b;

    ll sum = a + b;

    if (sum > n - 2)
    {
        cout << -1 << Endl;
        rr;
    }
    ll diff = abs(a - b);

    if (diff > 1)
    {
        cout << -1 << endl;
        rr;
    }
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    if (a == 0 && b == 0)
    {
        show(v);
        rr;
    }

    if (a >= b)
    {
        for (ll i = n - 2 * a + 1; i < n; i++)
        {
            // debug(i);
            swap(v[i - 1], v[i]);
            i++;
        }
        if (a == b)
        {
            swap(v[0], v[1]);
        }
        show(v);
        rr;
    }
    for (ll i = 1; i < 2 * b; i++)
    {
        swap(v[i - 1], v[i]);
        i++;
    }
    show(v);
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