
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

// void solve()
// {
//     ll n;
//     cin >> n;
//     string s;
//     cin >> s;
//     ll cnt = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         if (s[i] == '*')
//             cnt++;
//     }
//     ll sum = 0;
//     // debug(cnt);
//     ll mid;
//     if (cnt % 2)
//         mid = (cnt / 2) + 1;
//     else
//         mid = cnt / 2;
//     ll idx = 0, op = 0;
//     cnt = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         // if (op == mid)
//         // {
//         //     idx = i;
//         //     idx--;
//         //     break;
//         // }
//         // else if (s[i] == '*')
//         //     op++;
//         if (s[i] == '*')
//         {
//             if (op == mid)
//             {
//                 idx = op;
//                 break;
//             }
//             op++;
//         }
//     }
//     // idx--;
//     debug(mid);
//     debug(idx);
//     for (ll i = 0; i < idx; i++)
//     {
//         if (s[i] == '*')
//         {
//             sum +=
//         }
//     }
//     for (ll i = idx + 1; i < n; i++)
//     {
//         if (s[i] == '*')
//         {
//             sum += i - idx + 1;
//         }
//     }
//     cout << sum << endl;
//     return;
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
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define ff first
#define ss second
#define Auto auto
#define llmin LONG_MIN
#define llmax LONG_MAX
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yes cout << "yes\n"
#define no cout << "no\n"

#define show(A)           \
    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';
#define endl "\n"
#define Endl endl
clock_t startTime = clock();
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(v) v.begin(), v.end()
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
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void deb(vector<ll> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
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
vll fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    // before t
    //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}
// CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// int a = count(all(s),'A');
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
vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP/KNPS
ll n;
string s;
// map<ll, ll> m;
bool check(ll mid, ll center)
{
}
void solve()
{
    // ll n;
    cin >> n;
    // string s;
    cin >> s;

    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            cnt++;
            // m[i] = 1;
        }
    }
    if (cnt == 1 || cnt == 0 || cnt == n)
    {
        cout << 0 << endl;
        rr;
    }

    vll pre(n), suf(n);
    ll c = 0;
    if (s[0] == '*')
        c++;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == '*')
        {
            c++;
            pre[i] = pre[i - 1];
        }
        else
        {
            pre[i] = pre[i - 1] + c;
        }
    }
    c = 0;
    if (s[n - 1] == '*')
        c++;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            c++;
            suf[i] = suf[i + 1];
        }
        else
        {
            suf[i] = suf[i + 1] + c;
        }
    }

    ll diff = 1e18;

    for (ll i = 0; i < n; i++)
    {
        diff = min(diff, pre[i] + suf[i]);
    }
    cout << diff << endl;
    rr;
    // ll center = cnt / 2;
    // ll cent = center, cen = center;
    // if (cnt % 2 == 1)
    //     center++;
    // // debug(center);
    // ll ind = 0;

    // ll sum = 0, i = 0, diff = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (s[i] == '*')
    //         sum++;
    //     if (sum == center)
    //     {
    //         ind = i;
    //         break;
    //     }
    // }
    // debug(ind);

    // // for (; i < n; i++)
    // // {
    // //     // if (sum == center)
    // //     // break;
    // //     // if (i == center)
    // //     // continue;
    // //     if (s[i] == '*')
    // //     {
    // //         ll tot = abs(i - ind);
    // //         tot -= cent;
    // //         debug(tot);
    // //         // tot--;
    // //         cent--;
    // //         diff += tot;
    // //         if (cent = 0)
    // //             cent = cen;
    // //     }
    // //     // sum++;
    // // }
    // for (; i < ind; i++)
    // {
    //     if (s[i] == '*')
    //     {
    //         ll tot = ind - i;
    //         tot -= cent;
    //         cent--;
    //         diff += tot;
    //     }
    // }
    // cent = cen;
    // for (i = n - 1; i > ind; i--)
    // {
    //     if (s[i] == '*')
    //     {
    //         ll tot = i - ind;
    //         tot -= cent;
    //         cent--;
    //         diff += tot;
    //     }
    // }
    // if (diff < 0)
    // {
    //     cout << 0 << endl;
    //     rr;
    // }
    // // for (auto i : m)
    // // {
    // //     if (i.ss == 1)
    // //     {
    // //         diff += abs(i.ss - center);
    // //     }
    // // }
    // cout << diff << endl;
    // rr;
    // ll lo = 0, hi = 1e18;
    // while (lo < hi)
    // {
    //     ll mid = lo + (hi - lo) / 2;

    //     if (check(mid, center))
    //     {
    //         lo = mid;
    //     }
    //     hi = mid - 1;
    // }
    // cout << lo << endl;
    rr;
}
int main()
{
    io();
    // solve();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}