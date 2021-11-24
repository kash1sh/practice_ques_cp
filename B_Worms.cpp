
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define fir first
// #define sec second

// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)

// using namespace std;

// void io()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// ll mod = 1e9 + 7, mxn = 3e5 + 5;

// ll add(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a += b;
//     if (a >= mod)
//         a -= mod;
//     if (a < 0)
//     {
//         a += mod;
//         a %= mod;
//     }
//     return a;
// }

// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }
// // ll modInverse(ll a, ll m){
// //     ll x, y;
// //     ll g = gcdExtended(a, m, &x, &y);
// //         ll res = (x%m + m) % m;
// //         return res;
// // }
// ll binary_Search(vector<ll> &arr, ll key)
// {
//     ll l = 0, r = arr.size() - 1;
//     ll ans;
//     while (l <= r)
//     {
//         ll mid = (l + r) / 2;
//         ll value = arr[mid];
//         if (value > key)
//         {
//             r = mid - 1;
//         }
//         else if (value == key)
//         {
//             return mid;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return -1;
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

// void fact0()
// {
//     int i, j;
//     fact[0] = 1;
//     for (i = 1; i <= 200000; i++)
//     {
//         fact[i] = i * fact[i - 1] % mod;
//     }
//     inv[0] = 1;
//     inv[1] = 1;
//     int p = mod;
//     for (i = 2; i <= 200000; i++)
//         inv[i] = (p - (p / i) * inv[p % i] % p) % p;

//     for (i = 2; i <= 200000; i++)
//     {
//         inv[i] *= inv[i - 1];
//         inv[i] %= mod;
//     }
// }
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
// #define mod 1000000007

// void solve()
// {
//     ll n;
//     cin >> n;

//     ll arr[n];

//     fo(i, 0, n)
//             cin >>
//         arr[i];
//     ll m;
//     cin >> m;

//     vector<ll> juicy(m);
//     fo(i, 0, m)
//             cin >>
//         juicy[i];
//     // ll pre[n];
//     vector<pair<ll, ll>> v(n);
//     // pre[0] = arr[0];
//     v.push_back({0, 0});
//     // v[0].first = 1;
//     // v[0].second = arr[0];
//     fo(i, 1, n)
//     {
//         v[i].first = v[i - 1].second + 1;
//         v[i].second = arr[i - 1] - 1 + v[i].first;
//     }

//     for (ll i = 0; i < m; i++)
//     {
//         pair<ll, ll> p = {juicy[i], juicy[i]};

//         //    if(juicy[i] )
//         ll upp = lower_bound(v.begin(), v.end(), p) - v.begin();
//         // if (upp == 0)
//         // cout << 1 << endl;
//         // else
//         cout << upp << endl;
//     }
//     // fo(i, 0, n)
//     // {
//     //     //     // cout << "HEY" << endl;
//     //     cout
//     //         << v[i].first << " " << v[i].second << endl;
//     // }
// }
// int main()
// {
//     io();

//     solve();
//     // cout<<setprecision(10)
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, m, j, cnt = 0, ans, x, sum = 0;
    cin >> n;
    int a[n], c[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        c[i] = sum;
    }
    cin >> m;
    int b[m];
    for (i = 0; i < m; i++)
        cin >> b[i];
    for (j = 0; j < m; j++)
    {
        cout << lower_bound(c, c + n, b[j]) - c + 1 << endl;
    }

    return 0;
}