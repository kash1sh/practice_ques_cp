// #include <bits/stdc++.h>
// #define REP(i, n) for (int i = 1; i <= n; i++)
// #define mod 1000000007
// #define pb push_back
// #define ff first
// #define ss second
// #define ii pair<int, int>
// #define vi vector<int>
// #define vii vector<ii>
// #define lli long long int
// #define INF 1000000000
// #define endl '\n'
// const double PI = 3.141592653589793238460;
// typedef std::complex<double> Complex;
// typedef std::valarray<Complex> CArray;

// using namespace std;
// string st;

// bool isValid(int k)
// {
//     int ar[4] = {0};
//     for (int i = 0; i < k - 1; i++)
//     {
//         int idx = st[i] - '0';
//         ar[idx]++;
//     }

//     for (int i = k - 1; i < st.size(); i++)
//     {
//         int idx = st[i] - '0';
//         ar[idx]++;

//         if ((ar[1] > 0) && (ar[2] > 0) && (ar[3] > 0))
//             return true;

//         idx = st[i - k + 1] - '0';
//         ar[idx]--;
//     }

//     return false;
// }

// int getAns()
// {
//     int res = INF;
//     int L = 3;
//     int R = st.size();

//     while (L <= R)
//     {
//         int mid = (L + R) / 2;

//         if (isValid(mid))
//             res = min(res, mid), R = mid - 1;
//         else
//             L = mid + 1;
//     }

//     if (res == INF)
//         return 0;
//     else
//         return res;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> st;
//         cout << getAns() << endl;
//     }
// }

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
//     string s;
//     cin >> s;
//     // store number changes
//     int sz = INT_MAX;
//     vector<pair<char, int>> v;
//     ll k = -1;
//     // for (int i = 0; i < s.size(); i++)
//     // {
//     //     if (k == -1 || v[k].first != s[i])
//     //     {
//     //         v[k].push_back({s[i], 1});
//     //         k++;
//     //     }
//     //     else
//     //         v[k].ss++;
//     // }
//     for (auto ch : s)
//     {
//         if (k == -1 || ch != v[k].first)
//             v.push_back({ch, 1}), k++;
//         else
//             v[k].second++;
//     }

//     for (int i = 0; i < k; i++)
//     {
//         if (v[i - 1].first != v[i + 1].first)
//             sz = min(sz, v[k].ss + 2);
//     }
//     if (sz == INT_MAX)
//     {
//         cout << 0 << endl;
//         return;
//     }

//     cout << sz << endl;
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
using namespace std;
#define ll long long int
string s;
bool isValid(ll mid)
{
    int arr[4] = {0};
    for (ll i = 0; i < mid - 1; i++)
    {
        ll idx = s[i] - '0';
        arr[idx]++;
    }
    for (ll i = mid - 1; i < s.size(); i++)
    {
        ll idx = s[i] - '0';
        arr[idx]++;

        if (arr[3] > 0 && arr[1] > 0 && arr[2] > 0)
            return true;

        idx = s[i - mid + 1] - '0';
        arr[idx]--;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // string s;
        cin >> s;
        // cout << s;
        ll n = s.size();
        ll L = 3;
        ll R = n;
        ll res = INT_MAX;

        while (L <= R)
        {
            ll mid = (L + R) / 2;

            if (isValid(mid))
                R = mid - 1, res = min(res, mid);
            else
                L = mid + 1;
        }
        if (res == INT_MAX)
            cout << 0 << endl;
        else
            cout << res << endl;

        // return res;
        // int sz = INT_MAX;
        // //112222333133222
        // /* 1->2     1
        // 		2->4
        // 		3->3     1
        // 		1->1
        // 		3->2
        // 		2->3*/
        // vector<pair<char, int>> vt;
        // int k = -1;
        // for (auto ch : s)
        // {
        //     if (k == -1 || ch != vt[k].first)
        //         vt.push_back({ch, 1}), k++;
        //     else
        //         vt[k].second++;
        // }
        // for (int i = 1; i < k; i++)
        // {
        //     if (vt[i - 1].first != vt[i + 1].first)
        //         sz = min(sz, vt[i].second + 2);
        // }
        // if (sz == INT_MAX)
        //     cout << "0\n";
        // else
        //     cout << sz << "\n";
    }
    return 0;
}