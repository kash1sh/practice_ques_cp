
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
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

// // void fact0()
// // {
// //     int i,j;
// //     fact[0]=1;
// //     for(i=1;i<=200000;i++)
// //     {
// //         fact[i]=i*fact[i-1]%mod;
// //     }
// //     inv[0]=1;
// //     inv[1]=1;
// //     int p=mod;
// //     for (i=2; i<=200000; i++)
// //         inv[i] = (p - (p/i) * inv[p%i] % p) % p;

// //     for(i=2;i<=200000;i++)
// //     {
// //         inv[i]*=inv[i-1];
// //         inv[i]%=mod;
// //     }
// // }
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
// // ll dp[100001][2];
// ll a, b, n;
// string s;
// // int solve(int idx, int blow)
// // {
// //     if (idx == n)
// //         return (blow ? a : 0);

// //     if (dp[idx][blow] != -1)
// //         return dp[idx][blow];

// //     int ans;

// //     if (blow)
// //     { //  11 + 1 -> 111
// //         if (s[idx] == '1')
// //             ans = solve(idx + 1, blow);
// //         else
// //             ans = min(a + solve(idx + 1, 0), b + solve(idx + 1, blow));
// //     }
// //     else
// //     { // blow  = 0
// //         if (s[idx] == '1')
// //             ans = solve(idx + 1, !blow);
// //         else
// //             ans = solve(idx + 1, blow);
// //     }

// //     return dp[idx][blow] = ans;
// // }
// void solve()
// {
//     // ll a, b;
//     // cin >> a >> b;

//     // string s;
//     // cin >> s;
//     // ll n = s.size();
//     // ll cnt = 0;
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     if (s[i] == '1')
//     //         break;
//     //     else
//     //     {
//     //         s[i] = '1';
//     //         cnt++;
//     //     }
//     // }
//     // if (cnt == n)
//     // {
//     //     cout << 0 << endl;
//     //     return;
//     // }

//     // for (ll i = n - 1; i >= 0; i--)
//     // {
//     //     if (s[i] == '1')
//     //         break;
//     //     else
//     //     {
//     //         s[i] = '1';
//     //     }
//     // }
//     // vll ans(n);
//     // cnt = 0;
//     // ll j = 0;
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     if (s[i] == '0')
//     //         cnt++;

//     //     else
//     //     {
//     //         if (cnt != 0)
//     //         {
//     //             ans[j++] = (cnt);
//     //             cnt = 0;
//     //         }
//     //     }
//     // }
//     // if (j == 0)
//     // {
//     //     cout << a << endl;
//     //     return;
//     // }
//     // ll sum = a;
//     // for (auto i : ans)
//     // {
//     //     if (i * b > a)
//     //         sum += a;
//     //     else
//     //         sum += i * b;
//     // }
//     // cout << sum << endl;
//     // return;
//     // string in;
//     // int a, b;
//     // cin >> a >> b;
//     // cin >> in;
//     // int n = in.size();
//     // vector<int> gaps;
//     // int i;
//     // for (i = 0; i < n; i++)
//     // {
//     //     if (in.at(i) == '0')
//     //     {
//     //         in.at(i) = '1';
//     //     }
//     //     else
//     //     {
//     //         break;
//     //     }
//     // }
//     // if (i == n)
//     // {
//     //     cout << "0\n";
//     //     return;
//     // }
//     // for (int i = n - 1; i >= 0; i--)
//     // {
//     //     if (in.at(i) == '0')
//     //     {
//     //         in.at(i) = '1';
//     //     }
//     //     else
//     //     {
//     //         break;
//     //     }
//     // }

//     // int cnt = 0;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     if (in.at(i) == '1')
//     //     {
//     //         if (cnt != 0)
//     //             gaps.push_back(cnt);
//     //         cnt = 0;
//     //     }
//     //     else
//     //     {
//     //         cnt++;
//     //     }
//     // }

//     // if (cnt != 0)
//     //     gaps.push_back(cnt);
//     // //cout << in << endl;
//     // if (gaps.empty())
//     // {
//     //     cout << a << endl;
//     //     return;
//     // }
//     // else
//     // {
//     //     //for(int x:gaps)cout << x << " $ ";
//     //     int cost = a;
//     //     for (int g : gaps)
//     //     {
//     //         if ((g * b) < a)
//     //             cost += (g * b);
//     //         else
//     //             cost += a;
//     //     }

//     //     cout << cost << endl;
//     // }
//     // int a, b;
//     cin >> a >> b;

//     cin >> s;

//     ll blow = 0;
//     n = s.size();

//     // memset(dp, -1, sizeof(dp));
//     // for (int i = 0; i < n; i++)
//     // dp[i][0] = dp[i][1] = -1;
//     // cout << solve(0, 0) << endl;
//     ll dp[n + 1][2];
//     dp[0][0] = 0;
//     dp[0][1] = 0;

//     for (ll i = 1; i <= n; i++)
//     {
//         if (s[i - 1] == '0')
//         {
//             dp[i][0] = dp[i - 1][0];
//             dp[i][1] = min(a + dp[i - 1][0], b + dp[i - 1][1]);
//         }
//         else
//         {
//             dp[i][0] = min( dp[i - 1][1];
//             dp[i][1] = dp[i - 1][0];
//         }
//     }
//     cout << min(dp[n][0], dp[n][1]) << endl;
//     return;
//     // memset(dp, 0, sizeof(dp));
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     if (blow == 1)
//     //     {
//     //         if (s[i] == '1')
//     //         {
//     //             dp[i][1] = dp[i + 1][blow];
//     //         }
//     //         else
//     //         {
//     //             dp[i][1] = min(a + dp[i + 1][0], b + dp[i + 1][blow]);
//     //         }
//     //     }
//     //     else
//     //     {
//     //         if (s[i] == '1')
//     //         {
//     //             dp[i][blow] = dp[i + 1][1];
//     //         }
//     //         else
//     //         {
//     //             dp[i][blow] = dp[i + 1][0];
//     //         }
//     //     }
//     // }
//     // cout << dp[n][blow] << endl;
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
    ll res = 1, i;

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
    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll n = s.size();
    // vll a(n);
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    ll val1 = cnt * a;

    ll start = 0, len = 0;
    vpll ind;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            //    len++
            if (len == 0)
                continue;
            ind.pb({start, len});
            len = 0;
        }
        else
        {
            if (len == 0)
            {
                start = i;
                len++;
            }
            else
            {
                len++;
            }
        }
    }
    ll v3 = 0;
    for (ll i = 0; i < ind.size(); i++)
    {
        cout << ind[i].ff << " " << ind[i].ss << endl;
        v3 += a;
    }
    for (ll i = 0; i < ind.size(); i++)
    {
        // if ()
    }
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