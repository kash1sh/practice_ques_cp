
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

// vll fac(200003);
// ll facto(ll n)
// {

//     fac[0] = 1;
//     fac[1] = 1;
//     for (ll i = 2; i <= 200003; i++)
//     {
//         fac[i] = i * fac[i - 1];
//     }
//     return fac[n];
// }
// long combi(ll n, ll k)
// {
//     long long ans = 1;
//     k = k > n - k ? n - k : k;
//     ll j = 1;
//     for (; j <= k; j++, n--)
//     {
//         if (n % j == 0)
//         {
//             ans *= n / j;
//         }
//         else if (ans % j == 0)
//         {
//             ans = ans / j * n;
//         }
//         else
//         {
//             ans = (ans * n) / j;
//         }
//     }
//     return ans;
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
//     if (n <= 6)
//     {
//         cout << 15 << endl;
//         rr;
//     }
//     // while (n > 10)
//     // {
//     //     n /= 10;
//     //     cnt += 25;
//     // }
//     ll v1 = n / 10;

//     // while(/)
//     ll a1 = floor((double)n / 6);
//     ll a2 = floor((double)n / 8);
//     // // ;
//     ll a3 = floor((double)n / 10);
//     ll cnt = 25 * a3, cnt1 = 20 * a2, cnt2 = a1 * 15;
//     ll cnt4 = (a1 - 1) * 15;
//     ll rem = n % 10;
//     ll r2 = n % 8;
//     ll r3 = n % 6;
//     ll r4 = r3 + 6;
//     cnt2 += 15;
//     if (r4 == 11)
//     {
//         cnt4 += 30;
//     }
//     else if (r4 <= 8)
//     {
//         cnt4 += 20;
//     }
//     else if (r4 <= 10)
//     {
//         cnt4 += 25;
//     }
//     if (r2 == 7)
//     {
//         cnt1 += 20;
//     }
//     else if (r2 <= 6)
//     {
//         cnt1 += 15;
//     }
//     if (rem == 9)
//     {
//         cnt += 25;
//     }
//     else if (rem <= 6)
//     {
//         cnt += 15;
//     }
//     else if (rem <= 8)
//     {
//         cnt += 20;
//     }
//     if (n % 6 == 0)
//     {
//         cout << (n / 6) * 15 << endl;
//         rr;
//     }
//     if (n % 8 == 0)
//     {
//         cout << (n / 8) * 20 << endl;
//         rr;
//     }
//     // ans--;
//     // ll rem = n - ans * 6;
//     // ll r2 = n - a2 * 8;
//     // ll r3 = n - a3 * 10;
//     // // ans--, a2--, a3--;
//     // // ll rrem = n - ans * 6;
//     // // ll rr2 = n - a2 * 8;
//     // // ll rr/3 = n - a3 * 10;
//     // // while (rem)
//     // // {
//     // //     if (rem < 6)
//     // // }
//     // // ll mini=min(rem,r1,)
//     // ll cnt = ans * 15, cnt1 = a2 * 20, cnt2 = a3 * 25;
//     // while (rem)
//     // {
//     //     if (rem == 11)
//     //     {
//     //         cnt += 40;
//     //     }
//     //     else if (rem <= 8)
//     //         cnt += 20;
//     //     else if (rem <= 10)
//     //     {
//     //         cnt += 25;
//     //     }
//     //     break;
//     // }
//     // while (r2)
//     // {
//     //     if (r2 == 7)
//     //     {
//     //         cnt1 += 20;
//     //     }
//     //     else
//     //     {
//     //         cnt1 += 15;
//     //     }
//     //     break;
//     // }
//     // while (r3)
//     // {
//     //     if (r3 <= 6)
//     //     {
//     //         cnt2 += 15;
//     //     }
//     //     else if (r3 <= 8)
//     //     {
//     //         cnt2 += 20;
//     //     }
//     //     if (r3 == 9)
//     //     {
//     //         cnt2 += 30;
//     //     }
//     //     break;
//     // }
//     ll res = min(cnt, min(cnt1, min(cnt2, cnt4)));
//     cout << res << endl;
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

ll po(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return po(mul(a, a, mod), b / 2, mod);
    return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
}

long long power(long long X, long long N)
{
    if (N == 0)
        return 1;
    if (N % 2 == 0)
        return power(X * X, N / 2);
    return X * power(X, N - 1);
}

vll fac(200003);
ll facto(ll n)
{

    fac[0] = 1;
    fac[1] = 1;
    for (ll i = 2; i <= 200003; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    return fac[n];
}
long combi(ll n, ll k)
{
    long long ans = 1;
    k = k > n - k ? n - k : k;
    ll j = 1;
    for (; j <= k; j++, n--)
    {
        if (n % j == 0)
        {
            ans *= n / j;
        }
        else if (ans % j == 0)
        {
            ans = ans / j * n;
        }
        else
        {
            ans = (ans * n) / j;
        }
    }
    return ans;
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
    ll n;
    cin >> n;
    if (n <= 6)
    {
        cout << 15 << endl;
        rr;
    }
    // while(/)
    ll ans = floor((double)n / 6);
    ll a2 = floor((double)n / 8);
    // ;
    ll a3 = floor((double)n / 10);
    if (n % 6 == 0)
    {
        cout << (n / 6) * 15 << endl;
        rr;
    }
    ans--;
    ll rem = n - ans * 6;
    ll r2 = n - a2 * 8;
    ll r3 = n - a3 * 10;
    // while (rem)
    // {
    //     if (rem < 6)
    // }
    // ll mini=min(rem,r1,)
    ll cnt = ans * 15, cnt1 = a2 * 20, cnt2 = a3 * 25;
    while (rem)
    {
        if (rem == 11)
        {
            cnt += 30;
        }
        else if (rem <= 8)
            cnt += 20;
        else if (rem <= 10)
        {
            cnt += 25;
        }
        break;
    }
    while (r2)
    {
        if (r2 == 7)
        {
            cnt1 += 20;
        }
        else
        {
            cnt1 += 15;
        }
        break;
    }
    while (r3)
    {
        if (r3 <= 6)
        {
            cnt2 += 15;
        }
        else if (r3 <= 8)
        {
            cnt2 += 20;
        }
        if (r3 == 9)
        {
            cnt2 += 30;
        }
        break;
    }
    ll res = min(cnt, min(cnt1, cnt2));
    cout << res << endl;
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

    // cout<<setprecision(10)
    return 0;
}