
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
//     // if (a.ff == b.ff)
//     // {/
//     // return a.ss > b.ss;
//     // }
//     return ((double)a.ff / a.ss) > ((double)b.ff / b.ss);
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
//     vpll a(3);
//     ll n = 3;
//     ll a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a10 = 0, a11 = 0, a12 = 0;
//     fo(i, 0, 3)
//     {
//         cin >> a[i].ss;
//     }
//     fo(i, 0, 3)
//     {
//         cin >> a[i].ff;
//     }
//     sort(a.begin(), a.end(), greater<>());
//     ll sum = 0;
//     // deb(a);
//     fo(i, 0, n)
//     {
//         cerr << a[i].ff << " " << a[i].ss << Endl;
//     }
//     // for (ll i = 0; i < n; i++)
//     // {
//     // }
//     ll tot = 240;
//     ll val = 240;
//     vll v;
//     // ll n1=val/a[0].ss;
//     sum += a[0].ff * 20;
//     val -= 20 * a[0].ss;

//     ll n2 = val / a[1].ss;

//     if (val >= 20 * a[1].ss)
//     {
//         sum += 20 * a[1].ff;
//         val -= 20 * a[1].ss;

//         ll n3 = val / a[2].ss;
//         if (val >= 20 * a[2].ss)
//         {
//             sum += 20 * a[2].ff;
//             v.pb(sum);
//             val -= 20 * a[2].ss;
//         }
//         else
//         {
//             // ll rem = val/n3;
//             sum += n3 * a[2].ff;
//             // debug(sum);
//             // a1 = sum;
//             v.pb(sum);
//             // cout << sum << endl;
//             // rr;
//         }
//     }
//     else
//     {
//         sum += n2 * a[1].ff;
//         // a2 = sum;
//         v.pb(sum);
//         // cout << sum << endl;
//         // rr;
//     }
//     // ll tot = 240;
//     // val = 240;
//     // sum = 0;
//     // // ll n1=val/a[0].ss;
//     // sum += a[0].ff * 20;
//     // val -= 20 * a[0].ss;

//     // n2 = val / a[2].ss;

//     // if (val >= 20 * a[2].ss)
//     // {
//     //     sum += 20 * a[2].ff;
//     //     val -= 20 * a[2].ss;

//     //     ll n3 = val / a[1].ss;
//     //     if (val >= 20 * a[1].ss)
//     //     {
//     //         sum += 20 * a[1].ff;
//     //         v.pb(sum);
//     //         val -= 20 * a[1].ss;
//     //     }
//     //     else
//     //     {
//     //         // ll rem = val/n3;
//     //         sum += n3 * a[1].ff;
//     //         a3 = sum;
//     //         // cout << sum << endl;
//     //         // rr;
//     //     }
//     // }
//     // else
//     // {
//     //     sum += n2 * a[2].ff;
//     //     // cout << sum << endl;
//     //     a4 = sum;
//     //     // rr;
//     // }
//     // val = 240;
//     // sum = 0;
//     // // ll n1=val/a[0].ss;
//     // sum += a[1].ff * 20;
//     // val -= 20 * a[1].ss;

//     // n2 = val / a[2].ss;

//     // if (val >= 20 * a[2].ss)
//     // {
//     //     sum += 20 * a[2].ff;
//     //     val -= 20 * a[2].ss;

//     //     ll n3 = val / a[0].ss;
//     //     if (val >= 20 * a[0].ss)
//     //     {
//     //         sum += 20 * a[0].ff;
//     //         v.pb(sum);
//     //         val -= 20 * a[0].ss;
//     //     }
//     //     else
//     //     {
//     //         // ll rem = val/n3;
//     //         sum += n3 * a[0].ff;
//     //         a5 = sum;
//     //         // cout << sum << endl;
//     //         // rr;
//     //     }
//     // }
//     // else
//     // {
//     //     sum += n2 * a[2].ff;
//     //     a6 = sum;
//     //     // cout << sum << endl;
//     //     // rr;
//     // }
//     // val = 240;
//     // sum = 0;
//     // // ll n1=val/a[0].ss;
//     // sum += a[1].ff * 20;
//     // val -= 20 * a[1].ss;

//     // n2 = val / a[0].ss;

//     // if (val >= 20 * a[0].ss)
//     // {
//     //     sum += 20 * a[0].ff;
//     //     val -= 20 * a[0].ss;

//     //     ll n3 = val / a[2].ss;
//     //     if (val >= 20 * a[2].ss)
//     //     {
//     //         sum += 20 * a[2].ff;
//     //         v.pb(sum);
//     //         val -= 20 * a[2].ss;
//     //     }
//     //     else
//     //     {
//     //         // ll rem = val/n3;
//     //         sum += n3 * a[2].ff;
//     //         a7 = sum;
//     //         // cout << sum << endl;
//     //         // rr;
//     //     }
//     // }
//     // else
//     // {
//     //     sum += n2 * a[0].ff;
//     //     // cout << sum << endl;
//     //     // rr;
//     //     a8 = sum;
//     // }
//     // val = 240;
//     // sum = 0;
//     // // ll n1=val/a[0].ss;
//     // sum += a[2].ff * 20;
//     // val -= 20 * a[2].ss;

//     // n2 = val / a[0].ss;

//     // if (val >= 20 * a[0].ss)
//     // {
//     //     sum += 20 * a[0].ff;
//     //     val -= 20 * a[0].ss;

//     //     ll n3 = val / a[1].ss;
//     //     if (val >= 20 * a[1].ss)
//     //     {
//     //         sum += 20 * a[1].ff;
//     //         v.pb(sum);
//     //         val -= 20 * a[1].ss;
//     //     }
//     //     else
//     //     {
//     //         // ll rem = val/n3;
//     //         sum += n3 * a[1].ff;
//     //         // cout << sum << endl;
//     //         // rr;
//     //         a9 = sum;
//     //     }
//     // }
//     // else
//     // {
//     //     sum += n2 * a[0].ff;
//     //     // cout << sum << endl;
//     //     // rr;
//     //     a10 = sum;
//     // }
//     // val = 240;
//     // sum = 0;
//     // // ll n1=val/a[0].ss;
//     // sum += a[2].ff * 20;
//     // val -= 20 * a[2].ss;

//     // n2 = val / a[1].ss;

//     // if (val >= 20 * a[1].ss)
//     // {
//     //     sum += 20 * a[1].ff;
//     //     val -= 20 * a[1].ss;

//     //     ll n3 = val / a[0].ss;
//     //     if (val >= 20 * a[0].ss)
//     //     {
//     //         sum += 20 * a[0].ff;
//     //         v.pb(sum);
//     //         val -= 20 * a[0].ss;
//     //     }
//     //     else
//     //     {
//     //         // ll rem = val/n3;
//     //         sum += n3 * a[0].ff;
//     //         // cout << sum << endl;
//     //         // rr;
//     //         a11 = sum;
//     //     }
//     // }
//     // else
//     // {
//     //     sum += n2 * a[1].ff;
//     //     // cout << sum << endl;
//     //     // rr;
//     //     a12 = sum;
//     // }

//     // v.pb(a1), v.pb(a2), v.pb(a3), v.pb(a4), v.pb(a5), v.pb(a6), v.pb(a7), v.pb(a8), v.pb(a9), v.pb(a10), v.pb(a11), v.pb(a12);
//     sort(v.begin(), v.end());
//     // cout<<v[n-]
//     ll nn = v.size();
//     cout << v[nn - 1] << endl;
//     rr;
//     // ll n1 = 240/a.ss;
//     // ll n1=20*a[0].ss;
//     // ll sum = 0;
//     // ll v1 = 240 / a[0].ss;
//     // if (v1 >= 20)
//     // {
//     //     sum += 20 * a[0].ff;
//     //     debug(sum);
//     //     debug(a[0].ff);
//     // }
//     // ll val = 240 - 20 * a[0].ss;
//     // ll va = val;
//     // ll v2 = val / a[1].ss;
//     // ll rem = va - v2 * a[1].ss;
//     // if (v2 >= 20)
//     // {
//     //     sum += 20 * a[1].ff;
//     //     debug(sum);
//     //     val -= 20 * a[1].ss;
//     // }
//     // else
//     // {
//     //     sum += a[1].ff * v2;
//     //     cout << sum << Endl;
//     //     rr;
//     // }

//     // // val=val-
//     // ll v3 = val / a[2].ss;
//     // if (v3 >= 20)
//     // {
//     //     sum += a[2].ff * 20;
//     //     cout << sum << Endl;
//     //     rr;
//     // }
//     // sum += a[2].ff * v3;
//     // cout << sum << endl;
//     // rr;
//     // else{
//     // sum+=20*
//     // }
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
#define Endl endl
#define ff first
#define ss second
#define all(X) (X).begin(), (X).end()
clock_t startTime = clock();
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
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

void solve()
{
    vpll a(3);
    ll n = 3;
    fo(i, 0, n)
    {
        cin >> a[i].ff;
    }
    fo(i, 0, n)
    {
        cin >> a[i].ss;
    }

    sort(a.begin(), a.end());
    ll ans = LONG_MIN;
    for (ll i = 0; i <= 20; i++)
    {
        for (ll j = 0; j <= 20; j++)
        {
            for (ll k = 0; k <= 20; k++)
            {
                if (a[0].ff * i + a[1].ff * j + a[2].ff * k > 240)
                    break;
                ll val = a[0].ss * i + a[1].ss * j + a[2].ss * k;
                ans = max(ans, val);
            }
        }
    }
    cout << ans << Endl;
    rr;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    // cout<<setprecision(10)
    return 0;
}