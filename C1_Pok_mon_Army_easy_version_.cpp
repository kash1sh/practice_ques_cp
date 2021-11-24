
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

// // vll fac(200003);
// // ll facto(ll n)
// // {

// //     fac[0] = 1;
// //     fac[1] = 1;
// //     for (ll i = 2; i <= 200003; i++)
// //     {
// //         fac[i] = i * fac[i - 1];
// //     }
// //     return fac[n];
// // }
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

// ll helper(int start, vector<int> arr, int a, int n)
// {
//     if (start == n)
//         return 0;
//     if (dp[start][a] != -1)
//         return dp[start][a];
//     ll ans1 = 0;
//     ans1 = helper(start + 1, arr, a, n);
//     ll ans2 = 0;
//     if (a == 0)
//         ans2 = arr[start] + helper(start + 1, arr, a ^ 1, n);
//     else
//         ans2 = -arr[start] + helper(start + 1, arr, a ^ 1, n);
//     dp[start][a] = max(ans1, ans2);
//     return dp[start][a];
// }
// int help(vector<int> arr, int n, int i, bool flag)
// {
//     if (i == n)
//         return 0;

//     if (dp[i][flag] != -1)
//         return dp[i][flag];
//     int su1 = 0;
//     int su = help(a, n, i + 1, flag);

//     if (flag)
//     {
//         su1 = arr[i] + help(a, n, i + 1, !flag);
//     }
//     else
//     {
//         su1 = -arr[i] + help(a, n, i + 1, !flag);
//     }

//     return dp[i][flag] = max(su1, su);
//     // return max(su1, su);
// }
void solve()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // dp[i][0] = -1;
        // dp[i][1] = -1;
    }
    ll dp[n + 1][2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    ll flag = 0;
    // cout << "H";
    for (ll i = 1; i <= n; i++)
    {
        // ll a1 = dp[i - 1][flag];
        // ll a2 = 0;
        // if (flag == 0)
        // {
        //     // dp[i][flag]
        //     a2 = -arr[i] + dp[i - 1][flag];
        //     flag = 1;
        // }
        // else
        // {
        //     // dp[i][flag]
        //     a2 = arr[i] + dp[i - 1][flag];
        //     flag = 0;
        // }
        // dp[i][flag] = max(a1, a2);
        // debug(dp[i][flag]);
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - arr[i - 1]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + arr[i - 1]);
    }

    // memset(dp, -1, sizeof(dp));
    // dp[0][0] = 0;
    // dp[0][1] = 0;
    // int sum = 0;
    cout << max(dp[n][1], dp[n][0]) << endl;
    // cout << helper(0, arr, 0, n) << endl;
    // int ans = help(a, n, 0, true);
    // debug(sum);
    // cout << ans << endl;
    return;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}