
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
int coeff[200002];
// void vietaFormula(int roots[], int n)
// {
//     // Declare an array for
//     // polynomial coefficient.

//     // Set all coefficients as zero initially
//     memset(coeff, 0, sizeof(coeff));

//     // Set highest order coefficient as 1
//     coeff[n] = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = n - i - 1; j < n; j++)
//         {
//             coeff[j] = coeff[j] + (-1) *
//                                       roots[i - 1] * coeff[j + 1];
//         }
//     }
// }
void solve()
{
    ll n, q;
    cin >> n >> q;

    // ll roots[n + 1];
    vll roots(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> roots[i];
    }
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        m[roots[i]]++;
    }
    // vietaFormula(roots, n);
    // for (int i = 0; i <= n; i++)
    // {
    //     cerr << coeff[i] << " ";
    // }
    // vll sign(n);
    map<ll, ll> sign;
    for (ll i = 0; i < n; i++)
    {
        ll num = n - i - 1;
        if (num % 2)
            sign[roots[i]] = -1;
        else
            sign[roots[i]] = 1;
    }
    // sort(roots, roots + n);
    sort(roots.begin(), roots.end());
    while (q--)
    {
        ll x;
        cin >> x;
        // debug(x);
        ll cnt0 = 0, cnt1 = 0;
        if (m[x] > 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (x > roots[n - 1])
        {
            cout << "POSITIVE" << endl;
            continue;
        }
        ll bound = lower_bound(roots.begin(), roots.end(), x) - roots.begin();
        // debug(roots[bound]);
        // ll cnt = n - bound - 1;
        // if (cnt % 2)
        // {
        //     cout << "POSITIVE" << endl;
        //     continue;
        // }
        // cout << "NEGATIVE" << Endl;
        // continue;
        if (sign[roots[bound]] >= 1)
        {
            cout << "NEGATIVE" << Endl;
            continue;
        }
        cout << "POSITIVE" << Endl;

        // for (ll i = 0; i < n; i++)
        // {
        //     ll v1 = x - roots[i];
        //     if (v1 < 0)
        //         cnt0++;
        //     else
        //         cnt1++;
        // }
        // if (cnt0 % 2)
        // {
        //     cout << "NEGATIVE" << Endl;
        //     continue;
        // }
        // cout << "POSITIVE" << Endl;

        // ll sum = 0;
        // for (ll i = 0; i <= n; i++)
        // {
        //     sum += (coeff[i] * pow(x, n - i));

        //     debug(sum);
        // }
        // if (sum > 0)
        // {
        //     cout << "POSITIVE" << Endl;
        //     continue;
        // }
        // else if (sum < 0)
        // {
        //     cout << "NEGATIVE" << endl;
        //     continue;
        // }
        // else
        //     cout << 0 << endl;
    }
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}