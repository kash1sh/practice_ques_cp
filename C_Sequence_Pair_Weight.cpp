
#include <bits/stdc++.h>
#define ll long long
#define l long
#define pb push_back
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define fir first
#define sec second

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
}
ll mod = 1e9 + 7, mxn = 3e5 + 5;

ll add(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a += b;
    if (a >= mod)
        a -= mod;
    if (a < 0)
    {
        a += mod;
        a %= mod;
    }
    return a;
}

ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}
// ll modInverse(ll a, ll m){
//     ll x, y;
//     ll g = gcdExtended(a, m, &x, &y);
//         ll res = (x%m + m) % m;
//         return res;
// }
ll binary_Search(vector<ll> &arr, ll key)
{
    ll l = 0, r = arr.size() - 1;
    ll ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll value = arr[mid];
        if (value > key)
        {
            r = mid - 1;
        }
        else if (value == key)
        {
            return mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
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

int fact[200003];
int inv[200003];

void fact0()
{
    int i, j;
    fact[0] = 1;
    for (i = 1; i <= 200000; i++)
    {
        fact[i] = i * fact[i - 1] % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    int p = mod;
    for (i = 2; i <= 200000; i++)
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;

    for (i = 2; i <= 200000; i++)
    {
        inv[i] *= inv[i - 1];
        inv[i] %= mod;
    }
}
int Comb(int a, int b)
{
    // cout<<a<<" "<<b<<endl;
    int an = fact[a];
    //cout<<an<<endl;
    an *= inv[b];
    an %= mod;
    an *= inv[a - b];
    an %= mod;
    return an;
}

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
#define mod 1000000007

void solve()
{
    // ll n;
    // cin >> n;
    // ll arr[n + 1];
    // map<ll, ll> m;
    // for (ll i = 0; i < n; i++)
    // {
    //     ll x;
    //     cin >> x;
    //     arr[i] = x;
    //     m[arr[i]]++;
    // }
    // // cin >> arr[i];
    // bool flag = true;
    // for (auto iv : m)
    // {
    //     if (iv.second > 1)
    //     {
    //         flag = false;
    //         break;
    //     }
    // }
    // if (flag == true)
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    // ll unique = 0;
    ll n;
    cin >> n;
    vector<ll> v(n), ans(n);
    fo(i, 0, n) cin >> v[i];
    for (ll i = 1; i < n; i++)
    {
        ans[i] = count(v.begin(), v.begin() + i - 1, v[i]);
    }
    for (ll i = 1; i < n; i++)
    {
        ans[i] = ans[i] + ans[i - 1];
    }
    cout << accumulate(ans.begin(), ans.end(), 0LL) << endl;

    // ll i = 0, j = 0;

    // unordered_map<ll, ll> freq;
    // for (j = 0; j < n; j++)
    // {
    //     freq[arr[j]]++;

    //     if (freq[arr[j]] >= 2)
    //     {
    //         i++;
    //         while (arr[i] != arr[j])
    //         {
    //             freq[arr[i]]--;
    //             i++;
    //         }
    //         freq[arr[i]]--;
    //         unique = unique + (j - i);
    //     }
    //     else
    //         unique = unique + (j - i);
    // }

    // ll total = n * (n + 1) / 2;

    // cout << unique << endl;
    // return;
    // ll cnt = 0;
    unordered_map<ll, ll> freq;
    // for (j = 0; j < n; j++)
    // {
    //     freq[arr[j]]++;

    //     if (freq[arr[j]] >= 2)
    //     {
    //         i = 0;
    //         while (i < j)
    //         {
    //             // freq[arr[i]]--;
    //             if (freq[arr[i]] >= 2)
    //             {
    //                 // cnt = cnt + freq[arr[i]];
    //                 // freq[arr[i]]--;
    //             }

    //             i++;
    //         }
    //         // freq[arr[i]]--;
    //         // unique = unique + (j - i);
    //     }
    //     // else
    //     // unique = unique + (j - i);
    // }

    // ll total = n * (n + 1) / 2;
    // ll cnt = 0;
    // ll res[n];
    // vector<ll> v;
    // for (ll i = 0; i < n; i++)
    //     v[i] = arr[i];
    // for (ll ii = 1; ii < n; ii++)
    // {
    //     res[ii] = count(arr, arr + ii - 1, arr[ii]);
    // }
    // for (ll ii = 1; ii < n; ii++)
    // {
    //     res[ii] += res[ii - 1];
    // }
    // for (ll ii = 1; ii < n; ii++)
    //     cnt += res[ii];
    // // cout << cnt << endl;
    // cout << accumulate(res, res + n, 0LL) << endl;
    // return;
}
int main()
{
    io();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}