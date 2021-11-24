
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
//     string s, t;
//     cin >> s >> t;

//     ll c0 = 0, c10 = 0, c01 = 0, c2 = 0, f1 = 0, f2 = 0, f3 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == '1' && t[i] == '0')
//             c10++;
//         if (s[i] == '0' && t[i] == '1')
//             c01++;
//         if (s[i] == '0' && t[i] == '0')
//             c0++;
//         if (s[i] == '1' && t[i] == '1')
//             c2++;
//     }

//     f1 += min(c0, c2);
//     c0 -= f1;
//     c2 -= f1;

//     f2 += min(c01, c10);
//     c01 -= f2;
//     c10 -= f2;

//     f3 += min(c2, max(c10, c01));
//     c2 -= f3;

//     cout << f1 + f2 + f3 + (c2 / 2) << endl;
//     rr;
//     // deb(a1);
//     // deb(a2);
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
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        // char p[n], e[n];
        string p, e;
        cin >> p;
        cin >> e;
        ll count1 = 0, count2 = 0, count3 = 0, count4 = 0, teams = 0;

        for (ll i = 0; i < n; i++)
        {
            if (p[i] == '0' && e[i] == '0')
                count1++;
            else if (p[i] == '0' && e[i] == '1')
                count2++;
            else if (p[i] == '1' && e[i] == '0')
                count3++;
            else
                count4++;
        }
        ll value = 0;
        value = min(count4, count1);
        teams = teams + value;
        count4 = count4 - value;
        count1 -= value;

        value = min(count2, count3);
        teams = teams + value;
        count2 = count2 - value;
        count3 = count3 - value;

        if (count2 == 0 && count3 == 0)
        {
            teams = teams + count4 / 2;
            count4 = 0;
        }
        else if (count4 > 0)
        {
            if (count2 > 0)
            {
                value = min(count2, count4);
                teams = teams + value;
                count4 -= value;
            }
            if (count3 > 0)
            {
                value = min(count3, count4);
                teams = teams + value;
                count4 -= value;
            }
        }
        // value = min(count4, max(count2, count3));
        // teams += value;
        // count4 -= value;
        // count2 -= value;
        // count3 -= value;
        // cout << teams + count4 / 2 << endl;
        cout << teams + count4 / 2 << endl;
    }
    return 0;
}