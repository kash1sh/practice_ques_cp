
// // #include <bits/stdc++.h>
// // #define ll long long
// // #define pb push_back
// // #define vll vector<ll>
// // #define vpll vector<pair<ll, ll>>
// // #define fo(i, k, n) for (ll i = k; i < n; i++)
// // #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// // #define rr return
// // #define Endl endl
// // #define ff first
// // #define ss second
// // #define all(X) (X).begin(), (X).end()

// // #define setbits(x) __builtin_popcountll(x)
// // #define zrobits(x) __builtin_ctzll(x)
// // #ifndef ONLINE_JUDGE
// // #define debug(x) cerr << #x << " " << x << endl;
// // #else
// // #define debug(x)
// // #endif
// // using namespace std;

// // void io()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);
// //     // #ifndef ONLINE_JUDGE
// //     // freopen("input.txt", "r", stdin);
// //     // freopen("error.txt","w",stderr);
// //     // freopen("output.txt", "w", stdout);
// //     // #endif
// // }

// // ll mod = 1e9 + 7, mxn = 3e5 + 5;
// // void deb(vector<ll> v)
// // {
// //     for (auto t : v)
// //         cerr << t << " ";
// //     cerr << "\n";
// // }
// // ll mul(ll a, ll b, ll mod)
// // {
// //     a %= mod;
// //     b %= mod;
// //     a *= b;
// //     a += mod;
// //     return a % mod;
// // }

// // bool sortbysecdesc(const pair<int, int> &a,
// //                    const pair<int, int> &b)
// // {
// //     return a.second > b.second;
// // }
// // bool check_sorted(vll a)
// // {
// //     ll n = a.size();
// //     for (ll i = 1; i < n; i++)
// //     {
// //         if (a[i] >= a[i - 1])
// //             continue;
// //         return false;
// //     }
// //     return true;
// // }

// // ll po(ll a, ll b, ll mod)
// // {
// //     if (b == 0)
// //         return 1;
// //     if (b % 2 == 0)
// //         return po(mul(a, a, mod), b / 2, mod);
// //     return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
// // }

// // long long power(long long X, long long N)
// // {
// //     if (N == 0)
// //         return 1;
// //     if (N % 2 == 0)
// //         return power(X * X, N / 2);
// //     return X * power(X, N - 1);
// // }

// // ll fact(ll n)
// // {
// //     ll res = 1;

// //     for (ll i = 2; i <= n; i++)
// //     {
// //         res = (res * i) % mod;
// //     }
// //     return res;
// // }
// // long combi(ll n, ll k)
// // {
// //     long long ans = 1;
// //     k = k > n - k ? n - k : k;
// //     ll j = 1;
// //     for (; j <= k; j++, n--)
// //     {
// //         if (n % j == 0)
// //         {
// //             ans *= n / j;
// //         }
// //         else if (ans % j == 0)
// //         {
// //             ans = ans / j * n;
// //         }
// //         else
// //         {
// //             ans = (ans * n) / j;
// //         }
// //     }
// //     return ans;
// // }
// // // CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// // vector<int> sieveOfEratosthenes(int N)
// // {
// //     bool primes[N + 1];
// //     memset(primes, true, sizeof(primes));
// //     vector<int> arr;

// //     for (int i = 2; i * i <= N; i++)
// //         if (primes[i] == true)
// //         {
// //             for (int j = i * i; j <= N; j += i)
// //                 primes[j] = false;
// //         }

// //     for (int i = 2; i <= N; i++)
// //         if (primes[i])
// //             arr.emplace_back(i);

// //     return arr;
// // }
// // void prime_fact(ll n, vector<ll> &res)
// // {
// //     while (n % 2 == 0)
// //     {
// //         res.pb(2);
// //         n = n / 2;
// //     }

// //     for (ll i = 3; i <= sqrt(n); i = i + 2)
// //     {
// //         while (n % i == 0)
// //         {
// //             res.pb(i);
// //             n = n / i;
// //         }
// //     }
// //     if (n > 2)
// //     {
// //         res.pb(n);
// //     }
// // }
// // bool valid_coordinate(ll x, ll y, ll n, ll m)
// // {
// //     if (x < 0 || y < 0)
// //         return false;

// //     else if (x >= n || y >= m)
// //         return false;

// //     else
// //         return true;
// // }
// // int sod(int n)
// // {
// //     int sum = 0;
// //     while (n)
// //     {
// //         sum += (n % 10);
// //         n /= 10;
// //     }
// //     return sum;
// // }

// // bool isPowerOfTwo(ll n)
// // {
// //     return n && (!(n & (n - 1)));
// // }

// // void solve()
// // {
// //     ll n;
// //     cin >> n;
// //     string s;
// //     cin >> s;
// //     vll a(n);
// //     for (ll i = 0; i < n; i++)
// //     {
// //         if (s[i] == '1')
// //             a[i] = 1;
// //         else
// //             a[i] = 2;
// //     }

// //     ll c1 = 0, c2 = 0;
// //     fo(i, 0, n)
// //     {
// //         // cin >> a[i];
// //         if (a[i] == 1)
// //             c1++;
// //         else
// //             c2++;
// //     }
// //     // deb(a);
// //     if (c2 == 2 || c2 == 1)
// //     {
// //         cout << "NO" << endl;
// //         rr;
// //     }
// //     // if (n == 2)
// //     // {
// //     //     // ll sum = a[0] + a[1];
// //     //     // if (sum == 3)
// //     //     // {
// //     //     //     cout << "NO" << endl;
// //     //     //     rr;
// //     //     // }
// //     //     if (c1 == 1 && c2 == 1)
// //     //     {
// //     //         cout << "NO" << endl;
// //     //         rr;
// //     //     }
// //     // }
// //     // if (c2 > (n / 2))
// //     // {/
// //     // cout << "NO" << endl;
// //     // rr;
// //     // }
// //     char mat[n][n];
// //     vector<bool> vis(n, false);
// //     memset(mat, '.', sizeof(mat));
// //     for (ll i = 0; i < n; i++)
// //     {
// //         bool f = false;
// //         for (ll j = i; j < n; j++)
// //         {
// //             if (i == j)
// //             {
// //                 mat[i][j] = 'X';
// //                 // vis[i]=true;
// //                 continue;
// //             }
// //             if (a[i] == 1)
// //             {
// //                 mat[i][j] = '=';
// //                 mat[j][i] = '=';
// //                 // vis[j] = true;
// //                 continue;
// //             }
// //             else
// //             {
// //                 // debug(i);
// //                 // if(vis[j])
// //                 // if (mat[j][i] == '+')
// //                 // {

// //                 //     mat[i][j] = '-';
// //                 //     continue;
// //                 // }
// //                 // if (mat[j][i] == '-')
// //                 // {

// //                 //     mat[i][j] = '+';
// //                 //     continue;
// //                 // }
// //                 if (a[j] == 2 && f == false)
// //                 {
// //                     // debug(i);
// //                     // debug(j);
// //                     // vis[k] = true;
// //                     f = true;
// //                     mat[j][i] = '-';
// //                     mat[i][j] = '+';
// //                     // break;
// //                 }
// //                 // if (f == true && a[j] != 1)else
// //                 else
// //                 {
// //                     // debug(i);
// //                     // debug(j);
// //                     char ch = '-';
// //                     // if (vis[j] == false)
// //                     // {
// //                     mat[i][j] = ch;
// //                     // if (vis[j] == false)
// //                     mat[j][i] = '+';
// //                     // continue;
// //                     // }
// //                     // else
// //                     // {
// //                     //     continue;
// //                     // }
// //                     // continue;

// //                     // continue;
// //                 }

// //                 // if()
// //                 // for (ll k = 0; k < n; k++)
// //                 // {
// //                 // debug(i);
// //                 // debug(j);
// //                 // debug(vis[2]);
// //                 // debug(vis[3]);

// //                 // }
// //             }
// //         }
// //     }
// //     cout << "YES" << Endl;
// //     for (ll i = 0; i < n; i++)
// //     {
// //         for (ll j = 0; j < n; j++)
// //         {
// //             cout << mat[i][j];
// //         }
// //         cout << endl;
// //     }
// //     rr;
// // }
// // int main()
// // {
// //     io();
// //     // solve();
// //     // ll t=1;
// //     ll t;
// //     cin >> t;
// //     while (t--)
// //     {
// //         solve();
// //     }

// //     // cout<<setprecision(10)
// //     return 0;
// // }

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

// ll fact(ll n)
// {
//     ll res = 1;

//     for (ll i = 2; i <= n; i++)
//     {
//         res = (res * i) % mod;
//     }
//     return res;
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
//     string s;
//     cin >> s;
//     vll a(n);
//     for (ll i = 0; i < n; i++)
//     {
//         if (s[i] == '1')
//             a[i] = 1;
//         else
//             a[i] = 2;
//     }

//     ll c1 = 0, c2 = 0;
//     fo(i, 0, n)
//     {
//         // cin >> a[i];
//         if (a[i] == 1)
//             c1++;
//         else
//             c2++;
//     }
//     // deb(a);
//     if (c2 == 2 || c2 == 1)
//     {
//         cout << "NO" << endl;
//         rr;
//     }
//     // if (n == 2)
//     // {
//     //     // ll sum = a[0] + a[1];
//     //     // if (sum == 3)
//     //     // {
//     //     //     cout << "NO" << endl;
//     //     //     rr;
//     //     // }
//     //     if (c1 == 1 && c2 == 1)
//     //     {
//     //         cout << "NO" << endl;
//     //         rr;
//     //     }
//     // }
//     // if (c2 > (n / 2))
//     // {/
//     // cout << "NO" << endl;
//     // rr;
//     // }
//     char mat[n][n];
//     vector<bool> vis(n, false);
//     memset(mat, '.', sizeof(mat));
//     for (ll i = 0; i < n; i++)
//     {
//         bool f = false;
//         for (ll j = 0; j < n; j++)
//         {
//             if (i == j)
//             {
//                 mat[i][j] = 'X';
//                 // vis[i]=true;
//                 continue;
//             }
//             if (a[i] == 1)
//             {
//                 mat[i][j] = '=';
//                 mat[j][i] = '=';
//                 // vis[j] = true;
//                 continue;
//             }
//             else
//             {
//                 // debug(i);
//                 // if(vis[j])
//                 if (mat[j][i] == '+')
//                 {

//                     mat[i][j] = '-';
//                     continue;
//                 }
//                 if (mat[j][i] == '-')
//                 {

//                     mat[i][j] = '+';
//                     continue;
//                 }
//                 for (ll k = 0; k < j; k++)
//                 {
//                     if (mat[i][k] == '+')
//                     {
//                         // debug(i);
//                         // debug(k);
//                         f = true;
//                         continue;
//                     }
//                 }
//                 if (a[j] == 1)
//                 {
//                     // debug(i);
//                     // debug(j);
//                     mat[i][j] = '=';
//                     mat[j][i] = '=';
//                     continue;
//                 }
//                 if (f == true && a[j] != 1)
//                 {
//                     // debug(i);
//                     // debug(j);
//                     char ch = '-';
//                     if (vis[j] == false)
//                     {
//                         mat[i][j] = ch;
//                         // if (vis[j] == false)
//                         mat[j][i] = '+';
//                         continue;
//                     }
//                     // else
//                     // {
//                     //     continue;
//                     // }
//                     // continue;

//                     // continue;
//                 }

//                 // if()
//                 for (ll k = 0; k < n; k++)
//                 {
//                     // debug(i);
//                     // debug(j);
//                     // debug(vis[2]);
//                     // debug(vis[3]);
//                     if (a[k] == 2 && vis[k] == false && i != k)
//                     {
//                         // debug(i);
//                         // debug(j);
//                         vis[k] = true;
//                         f = true;
//                         mat[j][k] = '-';
//                         mat[i][j] = '+';
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     cout << "YES" << Endl;
//     for (ll i = 0; i < n; i++)
//     {
//         for (ll j = 0; j < n; j++)
//         {
//             cout << mat[i][j];
//         }
//         cout << endl;
//     }
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
#define all(X) (X).begin(), (X).end()

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

ll fact(ll n)
{
    ll res = 1;

    for (ll i = 2; i <= n; i++)
    {
        res = (res * i) % mod;
    }
    return res;
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
    string s;
    cin >> s;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
            a[i] = 1;
        else
            a[i] = 2;
    }

    ll c1 = 0, c2 = 0;
    fo(i, 0, n)
    {
        // cin >> a[i];
        if (a[i] == 1)
            c1++;
        else
            c2++;
    }
    // deb(a);
    if (n == 2)
    {
        // ll sum = a[0] + a[1];
        // if (sum == 3)
        // {
        //     cout << "NO" << endl;
        //     rr;
        // }
        if ((c1 == 1 && c2 == 1) || c2 == 2)
        {
            cout << "NO" << endl;
            rr;
        }
    }
    // if (c2 > (n / 2))
    // {/
    // cout << "NO" << endl;
    // rr;
    // }
    char mat[n][n];
    vector<bool> vis(n, false);
    for (ll i = 0; i < n; i++)
    {
        bool f = false;
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
            {
                mat[i][j] = 'X';
                // vis[i]=true;
                continue;
            }
            if (a[i] == 1)
            {
                mat[i][j] = '=';
                mat[j][i] = '=';
                // vis[j] = true;
                continue;
            }
            else
            {
                // debug(i);
                // if(vis[j])
                if (mat[j][i] == '+')
                {

                    mat[i][j] = '-';
                    continue;
                }
                if (mat[j][i] == '-')
                {

                    mat[i][j] = '+';
                    continue;
                }
                for (ll k = 0; k < j; k++)
                {
                    if (mat[i][k] == '+')
                    {
                        // debug(i);
                        // debug(k);
                        f = true;
                        continue;
                    }
                }
                if (a[j] == 1)
                {
                    // debug(i);
                    // debug(j);
                    mat[i][j] = '=';
                    mat[j][i] = '=';
                    continue;
                }
                if (f == true && a[j] != 1)
                {
                    // debug(i);
                    // debug(j);
                    char ch = '-';
                    if (vis[j] == false)
                    {
                        mat[i][j] = ch;
                        // if (vis[j] == false)
                        mat[j][i] = '+';
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                    // continue;

                    // continue;
                }

                // if()
                for (ll k = 0; k < n; k++)
                {
                    // debug(i);
                    // debug(j);
                    // debug(vis[2]);
                    // debug(vis[3]);
                    if (a[k] == 2 && vis[k] == false && i != k)
                    {
                        // debug(i);
                        // debug(j);
                        vis[k] = true;
                        f = true;
                        mat[j][k] = '-';
                        mat[i][j] = '+';
                        break;
                    }
                }
            }
        }
    }
    cout << "YES" << Endl;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
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