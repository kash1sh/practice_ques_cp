
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define fir first
#define sec second
#define vll vector<ll>
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

ll getCount(vll v)
{
    ll cnt = 0;
    ll n = v.size();
    for (ll i = 1; i < n; i++)
    {
        // if (v[i - 1] > v[i])
        // cnt++;
        if (v[i] != i + 1)
            cnt++;
    }
    return cnt;
}
bool sorted(vector<ll> v)
{
    for (ll i = 0; i < v.size() - 1; i++)
    {
        if (v[i + 1] < v[i])
            return false;
    }
    return true;
}
void solve()
{
    ll n;
    cin >> n;
    vll v(2 * n);
    vll v1(2 * n);
    vll v2(2 * n);

    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        v1[i] = v[i];
        v2[i] = v[i];
    }
    for (ll i = 0; i < 2 * n; i++)
    {
        if (sorted(v) || sorted(v1))
        {
            cout << i << endl;
            return;
        }
        if (i & 1)
        {
            for (ll i = 0; i < n; i++)
            {
                swap(v[i], v[n + i]);
            }
            for (ll i = 0; i < n; i++)
            {
                swap(v1[2 * i], v1[2 * i + 1]);
            }
        }
        else
        {
            for (ll i = 0; i < n; i++)
            {
                swap(v1[i], v1[n + i]);
            }
            for (ll i = 0; i < n; i++)
            {
                swap(v[2 * i], v[2 * i + 1]);
            }
        }
    }
    cout << -1 << endl;
    // ll cnt = getCount(v);
    // if (cnt == 0)
    //     return 0;

    // ll final = 0;
    // ll cnt1 = cnt, cnt2 = cnt;
    // ll vv = 1;

    // while (cnt1 != 0 && cnt2 != 0)
    // {
    //     // cout << "HRllo";
    //     for (ll i = 1; i < 2 * n; i = i + 2)
    //     {
    //         swap(v1[i - 1], v1[i]);
    //     }
    //     for (ll i = 0; i < n; i++)
    //     {
    //         swap(v2[i], v2[i + n]);
    //     }
    //     cnt1 = getCount(v1);
    //     cnt2 = getCount(v2);
    //     // for (ll i = 0; i < 2 * n; i++)
    //     // {
    //     //     cout << v1[i] << " ";
    //     // }
    //     // cout << endl;
    //     // for (ll i = 0; i < 2 * n; i++)
    //     // {
    //     //     cout << v2[i] << " ";
    //     // }
    //     // cout << endl;
    //     cout << cnt1 << " " << cnt2;

    //     if (cnt1 == 0 || cnt2 == 0)
    //         break;
    //     if (cnt1 <= cnt2)
    //     {
    //         v = v1;
    //         final + cnt1;
    //     }

    //     else
    //     {
    //         v = v2;
    //         final += cnt2;
    //     }
    //     // vv = 0;
    //     v1 = v;
    //     v2 = v;
    // }
    // return final;
}
int main()
{
    io();
    solve();
    // ll ans = solve();
    // cout << solve() << endl;
    // cout<<setprecision(10)
    return 0;
}