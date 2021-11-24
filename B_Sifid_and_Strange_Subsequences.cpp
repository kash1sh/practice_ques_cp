
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
//     vll arr(n);
//     ll pos = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         if (arr[i] > 0)
//             pos++;
//     }
//     if (pos == n)
//     {
//         cout << 1 << endl;
//         return;
//     }
//     ll mini = INT_MAX;

//     for (ll i = 0; i < n - 1; i++)
//     {
//         if (abs(arr[i] - arr[i + 1]) < mini)
//         mini=abs(arr[i] - arr[i + 1];
//     }
//     // cout << "H";
//     // vll ans;
//     // queue<ll> q;
//     // queue<ll> q2;
//     // vll supp;
//     // ll cnt = 0;
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     if (arr[i] <= 0)
//     //     {
//     //         cnt++;
//     //         if (q.empty())
//     //         {
//     //             q.push(arr[i]);

//     //             // q2.push(arr[i]);
//     //         }

//     //         else
//     //         {

//     //             while (q.size())
//     //             {
//     //                 int front = q.front();
//     //                 q2.push(front);

//     //                 q.pop();
//     //                 ll diff = abs(arr[i] - front);
//     //                 supp.pb(diff);
//     //             }
//     //             while (!q2.empty())
//     //             {
//     //                 q.push(q2.front());
//     //                 q2.pop();
//     //             }
//     //             q2.push(arr[i]);
//     //         }
//     //         // ans.pb(arr[i]);
//     //     }
//     // }
//     // for (auto i : supp)
//     //     cout << i << " ";
//     // for (ll i = 0; i < n; i++)
//     // {
//     //     if (arr[i] > 0)
//     //     {
//     //         // cout << [i] << " ";
//     //         ll mini = *min_element(supp.begin(), supp.end());
//     //         // cout << mini << " ";
//     //         if (mini >= arr[i])
//     //             cnt++;
//     //     }
//     // }
//     cout << cnt << endl;
//     return;
// }
// int main()
// {
//     io();
//     // solve();

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
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

lli power(lli a, lli n)
{
    lli res = 1;
    a %= mod;

    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;

        n >>= 1;
        a = (a * a) % mod;
    }

    return res;
}
int n;
int ar[100001];

bool isValid(int m)
{
    for (int i = 2; i <= m; i++)
        if (ar[i] - ar[i - 1] < ar[m])
            return false;

    return true;
}

int getAns()
{
    int L = 1;
    int R = n;
    int res = 0;

    while (L <= R)
    {
        int mid = (L + R) / 2;

        if (isValid(mid))
            L = mid + 1, res = max(res, mid);
        else
            R = mid - 1;
    }

    return res;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        // REP(i, n)
        // cin >> ar[i];
        for (int i = 1; i <= n; i++)
            cin >> ar[i];
        sort(ar + 1, ar + n + 1);

        cout << getAns() << endl;
    }
}