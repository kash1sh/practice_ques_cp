
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
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

// ll dp[101][2];
// ll sum = 0;
// string s;
// ll help(ll n, ll a, ll b, ll i, ll j)
// {
//     if (i == n)
//     {
//         return sum;
//     }
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     ll v1 = INT_MIN, v2 = INT_MIN;
//     if (j == 0)
//     {
//         // ll v11 =
//         if (s[i] == '0')
//         {
//             dp[i][0] =
//         }
//     }
//     else
//     {
//     }
// }
void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;
    // ll x = (ll)s[0];

    ll v1;
    if (b > 0)
    {
        cout << a * n + n * b << endl;
        return;
    }
    // a *n + b;
    ll ans = n * a;
    ll cnt0 = 0, cnt1 = 0, cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        // if (s[i] == s[i - 1])
        // {
        //     if (s[i] == '0')
        //         cnt0++;
        //     else
        //         cnt1++;
        // }
        char val = s[i];
        if (val == '0')
        {
            while (i < n && val == s[i])
            {
                i++;
            }
            cnt0++;
            i--;
        }
        else
        {
            while (i < n && val == s[i])
            {
                i++;
            }
            cnt1++;
            i--;
        }
        // i--;
        // cnt++;
    }
    v1 = min(cnt1, cnt0) * b + b;
    // ;

    cout << v1 + ans << Endl;
    return;
    // for (ll i = 0; i < v.size(); i++)
    // {
    //     cerr << v[i].ff << " " << v[i].ss;
    //     cerr << Endl;
    // }
    // ll sum = 0, semi = 0;
    // for (ll i = 0; i < v.size(); i++)
    // {
    //     for (ll j = 0; j < n; j++)
    //     {
    //         ll val = a * v[j].ff + b;
    //         // semi = max(semi, val);
    //         if (val > semi)
    //         {
    //             semi = val;
    //             ind = v[j].ss;
    //         }
    //     }
    //     sum += semi;
    //     v.erase(v.begin() + i, v.begin() + cnt - 1);
    //     if (s[j - 1] == s[j + 1])
    //     {
    //     }
    // }
    // memset(dp, -1, sizeof(dp));
    // help(n, a, b, 0, x);
    // vll v(n + 1);

    // for (ll i = 1; i <= n; i++)
    // {
    //     v[i] = a * i + b;
    // }
    // vpll arr(n + 1);
    // for (ll i = 0; i <= n + 1; i++)
    // {
    //     arr[i].ff = INT_MIN;
    // }

    // // memset(arr, INT_MIN, sizeof(arr));
    // // map<ll, ll> m;
    // for (ll i = 1; i <= n; i++)
    // {
    //     arr[i].ff = v[i];
    //     // debug(v[i]);
    //     arr[i].ss = i;
    //     // m[v[i]] = i;
    // }
    // sort(arr.begin(), arr.end(), greater<>());
    // for (auto i : arr)
    // {
    //     cerr << i.ff << " " << i.ss;
    //     cerr << endl;
    // }
    // ll nn = n, sum = 0;
    // bool f = true;
    // while (nn)
    // {
    //     if (nn < arr[0].ss)
    //     {
    //         f = false;
    //         break;
    //     }
    //     // break;
    //     nn -= arr[0].ss;
    //     sum += arr[0].ff;
    // }
    // if (f == false)
    // {
    //     for (ll i = 1; i <= n; i++)
    //     {
    //         if (nn >= arr[0].ss)
    //         {
    //             nn -= arr[0].ss;
    //             sum += arr[0].ff;
    //         }
    //     }
    // }
    // cout << sum << endl;
    // return;
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