
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
// #define all(X) (X).begin(), (X).end()
// clock_t startTime = clock();
// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)
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

// void solve()
// {
//     ll n;
//     cin >> n;
//     vll a(n);
//     set<ll> s;
//     ll sum = 0;
//     fo(i, 0, n)
//     {
//         cin >> a[i];
//         sum += a[i];
//         s.insert(a[i]);
//     }
//     ll x = sum;
//     ll m;
//     cin >> m;
//     ll maxa = *max_element(a.begin(), a.end());
//     ll cnt = 0;
//     // f
//     for (ll i = 0; i < m; i++)
//     {
//         sum = x;
//         cnt = 0;
//         ll x, y;
//         cin >> x >> y;
//         if (x < *s.begin())
//         {
//             sum -= *s.begin();
//             if (sum >= y)
//             {
//                 cout << 0 << endl;
//                 continue;
//             }
//             else
//             {
//                 cout << y - sum << endl;
//                 continue;
//             }
//         }
//         auto val = s.upper_bound(x);
//         if (val == s.end())
//         {
//             cnt += x - maxa;
//             sum -= maxa;
//             if (sum >= y)
//             {
//                 cout << cnt << endl;
//                 continue;
//             }
//             else
//             {
//                 cout << cnt + (y - sum) << endl;
//                 // rr;
//                 continue;
//             }
//         }
//         ll pre = *prev(val);
//         ll curr = *val;
//         ll diff1 = x - pre;
//         ll diff2 = curr - x;
//         ll cur = curr;
//         ll cn = 0;
//         ll su = sum;
//         ll val1, val2;
//         // if (diff1 <= diff2)
//         // {
//         cnt += diff1;
//         sum -= pre;
//         if (sum >= y)
//         {
//             // cout << cnt << endl;
//             // continue;
//             val1 = cnt;
//         }
//         else
//         {
//             // cout << cnt + (y - sum) << endl;
//             val1 = cnt + (y - sum);
//             // rr;
//             // continue;
//         }
//         // }
//         // else
//         // {
//         su -= cur;
//         if (su >= y)
//         {
//             val2 = cn;
//             // cout << cn << endl;
//             // continue;
//         }
//         else
//         {
//             // cout << cn + (y - su) << endl;
//             val2 = cn + (y - su);
//             // rr;
//             // continue;
//         }
//         cout << min(val1, val2) << endl;
//         // }
//         // if (pre >= x)
//         // {
//         //     cout << sum - pre << endl;
//         //     continue;
//         // }
//         // else
//         // {

//         //     // if(curr<x){

//         //     // }
//         // }
//     }
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
//     // cout<<setprecision(10)
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
// * DP
// * BS

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    multiset<ll> ms;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        ms.insert(a[i]);
    }
    sort(a.begin(), a.end());
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        debug(x);
        // debug(y);
        ll sum2 = sum;
        auto mmin = ms.lower_bound(x);
        ll mini = *mmin;
        if (mini == *ms.begin())
        {
            sum2 -= mini;
            if (sum2 >= y)
            {
                cout << 0 << endl;
                // rr;
                continue;
            }
            else
            {
                cout << y - sum2 << endl;
                continue;
            }
        }
        if (mini == *ms.rbegin())
        {
            sum2 -= mini;
            debug(mini);
            debug(sum2);
            // cout<<x-mini+
            if (sum2 >= y)
            {
                cout << x - mini << endl;
                // rr;
                continue;
            }
            else
            {
                cout << y - sum2 + x - mini << endl;
                continue;
            }
        }
        ll pre = *prev(mmin);
        // if (x - pre > mini - pre){

        // }
        ll sum3 = sum2, sum4 = sum2;
        sum3 -= pre;
        ll a1 = LONG_MAX, a2 = LONG_MAX;
        if (sum3 >= y)
        {
            debug(x);

            a1 = x - pre;
            debug(a1);
            // rr;
            // continue;
        }
        else
        {
            a1 = y - sum3 + x - pre;
            // continue;
        }
        sum4 -= mini;
        if (sum4 >= y)
        {
            a2 = 0;
            // rr;
            // continue;
        }
        else
        {
            a2 = y - sum4;
            // continue;
        }
        cout << min(a1, a2) << endl;
        continue;
    }
    cout << Endl;
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