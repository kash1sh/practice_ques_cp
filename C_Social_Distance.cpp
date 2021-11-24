
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

void solve()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // vll pre(n, -1);
    // vll suf(n, -1);
    // if (s[0] == '1')
    //     pre[0] = 0;
    // for (ll i = 1; i < n; i++)
    // {
    //     if (s[i] == '1')
    //     {
    //         pre[i] = i;
    //     }
    //     else
    //         pre[i] = pre[i - 1];
    // }

    // if (s[n - 1] == '1')
    //     suf[n - 1] = n - 1;
    // for (ll i = n - 2; i >= 0; i--)
    // {
    //     if (s[i] == '1')
    //     {
    //         suf[i] = i;
    //     }
    //     else
    //     {
    //         suf[i] = suf[i + 1];
    //     }
    // }
    // // for (ll i = 0; i < n; i++)
    // // {
    // //     cout << pre[i] << " ";
    // // }
    // // for (ll i = n - 1; i >= 0; i--)
    // // {
    // //     cout << suf[i] << " ";
    // // }
    // ll cnt = 0;
    // ll v1, v2;
    // for (ll i = 0; i < n; i++)
    // {
    //     v1 = v2 = INT_MAX;
    //     if (pre[i] != -1)
    //     {
    //         v1 = i - pre[i];
    //     }

    //     if (suf[i] != -1)
    //     {
    //         v2 = suf[i] - i;
    //     }

    //     if (min(v1, v2) > k)
    //     {
    //         cnt++;
    //         pre[i] = i;
    //     }
    //     // if(pre[i]!=-1)
    //     // if (s[i] == '0')
    //     // {
    //     //     if (i - pre[i] > k && suf[i] - i > k)
    //     //     {
    //     //         cnt++;
    //     //         pre[i] = i;
    //     //     }
    //     // }

    //     if (pre[i] > pre[i + 1])
    //     {
    //         pre[i + 1] = pre[i];
    //     }
    // }
    // cout << cnt << endl;
    // return;
    // vll a
    set<ll> a;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            a.insert(i);
        }
    }
    ll j = 0, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            auto it = a.lower_bound(i - k);
            if (it == a.end() or *it > i + k)
            {
                ans++;
                s[i] = '1';
                a.insert(i);
            }
        }
    }
    // ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    // if (a.size() == 0 && j < n)
    // {
    //     cerr << "HI" << endl;
    //     cnt1++;
    //     j++;
    //     j = j + k;
    // }
    // if (cnt1 != 0)
    // {
    //     cout << cnt1 << endl;
    //     return;
    // }
    // if (a.size() == 1)
    // {
    //     ll place = a[0];
    //     ll kk = 0;
    //     // while (kk < place)
    //     // {
    //     ll diff = place - kk - 1;
    //     if (diff > 2 * k)
    //         cnt3 += diff / 2 * k;
    //     // }
    //     kk = n - 1;
    //     ll dif = kk - place - 1;
    //     if()
    // }
    // if (a.size() > 0)
    // {
    //     for (ll i = 1; i < a.size(); i++)
    //     {
    //         ll diff = a[i] - a[i - 1] - 1;
    //         if (diff > 2 * k)
    //             cnt2 += diff / 2 * k;
    //     }
    // }
    cout << ans << endl;
    return;
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