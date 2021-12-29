
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
// vll res;
// void decToBinary(ll n, ll maxa)
// {
//     // array to store binary number
//     ll binaryNum[32];

//     // counter for binary array
//     ll i = 0;
//     while (n > 0)
//     {

//         // storing remainder in binary array
//         binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }

//     // printing binary array in reverse order
//     vll ans;
//     for (ll j = i - 1; j >= 0; j--)
//     {
//         ans.pb(binaryNum[j]);
//     }
//     ll nn = ans.size(), num = 0;
//     ll ns = maxa - nn;
//     debug(ns);
//     vll fin(maxa);
//     ll k = 0;
//     for (ll i = 0; i < maxa - nn; i++)
//     {
//         fin[k++] = 0;
//     }

//     // fin.pb(0);
//     // for (ll i = 0; i < ns; i++)
//     // {
//     //     fin.pb(0);
//     // }
//     ll j = 0;
//     // while (j < ns)
//     // {
//     //     fin.pb(0);
//     //     j++;
//     // }
//     for (ll i = 0; i < nn; i++)
//     {
//         fin[k++] = (ans[i]);
//     }
//     // for (ll i = 0; i < fin.size(); i++)
//     // {
//     //     cerr << fin[i] << " ";
//     // }
//     // cerr << endl;
//     for (ll i = 0; i < fin.size(); i++)
//     {
//         ll powe = power(2, nn - i - 1);
//         if (fin[i] == 0)
//         {
//             num += powe;
//         }
//     }
//     res.pb(num);
//     // cout << binaryNum[j];
// }
// void solve()
// {
//     res.clear();
//     ll n;
//     cin >> n;
//     vll a(n);
//     ll maxa = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         ll bits = (ll)log2(a[i]) + 1;
//         if (bits > maxa)
//             maxa = bits;
//     }
//     for (ll i = 0; i < n; i++)
//     {

//         decToBinary(a[i], maxa);
//     }
//     for (ll i = 0; i < res.size(); i++)
//     {
//         if (i == 0)
//         {
//             cout << 0 << " ";
//             continue;
//         }
//         cout << res[i] << " ";
//     }
//     cout << endl;
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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
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
bool valid_coordinate(ll x, ll y, ll n, ll m)
{
    if (x < 0 || y < 0)
        return false;

    else if (x >= n || y >= m)
        return false;

    else
        return true;
}

int sod(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP
vll bin;
void decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            bin.pb(1);
        // cout << "1";
        else
            bin.pb(0);
        // cout << "0";
    }
}
void solve()
{
    ll n;
    cin >> n;

    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vll v;
    v.pb(0);
    decToBinary(a[0]);

    string res;
    // ; = to_string();
    for (ll i = 0; i < bin.size(); i++)
    {
        res += to_string(bin[i]);
    }
    // cerr << res << endl;
    bin.clear();
    for (ll i = 1; i < n; i++)
    {
        decToBinary(a[i]);
        string curr;
        for (ll i = 0; i < bin.size(); i++)
        {
            curr += to_string(bin[i]);
        }
        cerr << curr << endl;
        // rr;
        // cerr << curr[31] << endl;
        bin.clear();
        ll sum = 0;
        for (ll j = 31; j >= 0; j--)
        {
            if (res[j] == '1' && curr[j] != '1')
            {
                sum += (pow(2, 31 - j));
            }
        }
        v.pb(sum);
        for (ll j = 31; j >= 0; j--)
        {
            if (res[j] != '1' && curr[j] == '1')
            {
                // sum += (pow(2, j));
                res[j] = '1';
            }
        }
    }
    show(v);
    // cout << endl;
    rr;
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
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}